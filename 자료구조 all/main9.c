#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>


// 해시 맵 > 배열 > 속도는 일반 배열에 비해 조금 느릴지라도 평균 속도는 비슷하게 보장
#define CLS(value, function,...) value->function(value,##__VA_ARGS__)
#define MAINTHREAD INT main() {
#define MAINTHTEADEND }
#define INFINITEWHILE while(1){
#define INFINITEWHILEEND }


typedef unsigned int UINT;
typedef UINT* PUINT;
typedef int INT;
typedef INT* PINT;
typedef char CHAR;
typedef CHAR* PCHAR;
typedef char STR[256];
typedef struct DATA DATA;
typedef DATA* PDATA;
typedef struct NODE NODE;
typedef NODE* PNODE;
typedef struct HASHMAP HASHMAP;
typedef HASHMAP* PHASHMAP;
typedef UINT(*HASHING)(PHASHMAP, PCHAR);
typedef PDATA(*GETTER)(PHASHMAP, PCHAR);
typedef UINT(*SIZING)(PHASHMAP);

struct DATA;
struct HASHMAP;
struct NODE;



struct DATA {
	STR descript;
};


struct NODE {
	STR key;
	PDATA data;
};



struct HASHMAP {
	PNODE datas;
	UINT size;
	HASHING hashing;
	GETTER getter;
	SIZING getsize;
};

UINT GetSize (PHASHMAP this){
	return this->size;
}

UINT Hashing(PHASHMAP this, PCHAR str) {
	UINT index = 487;
	while (*str != '\0') {
		index = index << 4;
		index %= /*this->size*/ CLS(this, getsize);
		index += *str;
		++str;
	}
	return index % /*this->size*/ CLS(this, getsize);
}

PDATA Getter(PHASHMAP this, PCHAR str) {
	UINT index = CLS(this, hashing, str);
	while (this->datas[index].data != 0) {
		if (strcpy_s(this->datas[index].key, 256, str) == 0) {
			return this->datas[index].data;
			index = (index + 1) % /*this->size*/ CLS(this, getsize);
		}

	}
	this->datas[index].data = (PDATA)malloc(sizeof(DATA));
	memset(this->datas[index].data, 0, sizeof(DATA));
	strcpy_s(this->datas[index].key, 256, str);
	return this->datas[index].data;
}


PHASHMAP CreateHashMap(UINT size) {
	if (size < 1) return 0;
	PHASHMAP hash = (PHASHMAP)malloc(sizeof(HASHMAP));
	memset(hash, 0, sizeof(HASHMAP));
	hash->datas = (PNODE)malloc(sizeof(NODE) * size);
	memset(hash->datas, 0, sizeof(NODE) * size);
	hash->size = size;
	hash->hashing = Hashing;
	hash->getter = Getter;
	hash->getsize = GetSize;
	return hash;
}

void RemoveHashMap(PHASHMAP hash) {
	for (int i = 0; i < CLS(hash->size); ++i) {
		if(hash->datas[i].data != 0)
			free(hash->datas[i].data);
	}
	free(hash->datas);
	free(hash);

}

MAINTHREAD
	PHASHMAP hash = CreateHashMap(70);
	INT select;
	//STR temp;
	STR list[10][2] = {
		{"ABCD", "DEFG"},
		{"ABCD", "DEFG"},
		{"ABCD", "DEFG"},
		{"ABCD", "DEFG"},       
		{"ABCD", "DEFG"},
		{"ABCD", "DEFG"},       
		{"ABCD", "DEFG"},
		
	};
	for(UINT i = 0; i < 10; ++i){
		strcpy_s(CLS(hash,getter, list[i][0])->descript, 256, list[i][1]);
	}
	INFINITEWHILE

		/*printf("1.단어 추가 2. 번역 3. 종료 >>>");
		scanf_s("%d", &select);
		if (select == 3) break;
		else if (select == 1) {
			printf("수정할 단어 >>");
			scanf_s("%s", temp, 256);
			printf("수정할 번역 >>");
			scanf_s("%s", CLS(hash, getter, temp)->descript, 256);
		}*/
		printf("1.번역 2. 종료 >>>");
		scanf_s("%d", &select);
		if (select == 2) break;
		else if (select == 1) {
			printf("번역할 단어 >>");
			scanf_s("%s", temp, 256);
			printf("번역한 단어 >> %s\n", CLS(hash, getter, temp)->descript);
		}

	INFINITEWHILEEND

	RemoveHashMap(hash);
	return 0;
	

MAINTHTEADEND


}
