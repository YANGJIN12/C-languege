#include "headers.h"

struct Node {
	pVoid data;
	Str key;
};

struct HashMap {
	pNode datas;
	uInt size;
};


Void Load(pHashMap this, pChar path) {
	FILE* fp = fopen(path, "rt");
	if (fp == 0) return;
	pAccount acc;
	while (!feof(fp)) {
		acc = CreateAccount();
		fscanf(fp, "%s%s%d", acc->id, acc->pw, &acc->money);
		C(this, SetHashData, acc->id, acc);
	}
	fclose(fp);
}

Void Save(pHashMap this, pChar path) {
	FILE* fp = fopen(path, "wt");
	pAccount acc;
	Str accstr;
	for (uInt i = 0; i < this->size; ++i) {
		if (this->datas[i].data != 0) {
			acc = this->datas[i].data;
			AccToStr(acc, accstr);
			fprintf(fp, accstr);
		}
	}
	fclose(fp);
}

uInt Hash(pHashMap this, pChar str) {
	uInt hash = 247;
	while (*str != '\0') {
		hash = ((hash << 4) % this->size) + *str;
		++str;
	}
	return hash % this->size;
}

Void SetHashData(pHashMap this, pChar key, pVoid data) {
	uInt index = C(this, Hash, key);
	while (this->datas[index].data != 0) {
		if (strcmp(this->datas[index].key, key) == 0) {
			if (this->datas[index].data != 0)
				free(this->datas[index].data);
			this->datas[index].data = data;
			return;
		}
		++index;
		index = index % this->size;
	}
	this->datas[index].data = data;
	strcpy(this->datas[index].key, key);
}

pVoid GetHashData(pHashMap this, pChar key) {
	uInt index = C(this, Hash, key);
	while (this->datas[index].data != 0) {
		if (strcmp(this->datas[index].key, key) == 0) {
			return this->datas[index].data;
			++index;
			index = index % this->size;
		}
		uInt index = C(this, Hash, key);
		return &this->datas[index];
	}
}

pHashMap CreateHashMap(uInt size) {
	pHashMap hash = (pHashMap)malloc(sizeof(HashMap));
	memset(hash, 0, sizeof(HashMap));
	hash->size = size;
	hash->datas = (pNode)malloc(sizeof(Node) * size);
	memset(hash->datas, 0, sizeof(Node) * size);
	return hash;
}

Void RemoveHashMap(pHashMap this) {
	for (uInt i = 0; i < this->size; ++i) {
		if (this->datas[i].data != 0) free(this->datas[i].data);
	}
	free(this->datas);
	free(this);
}