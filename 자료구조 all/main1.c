#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
// �ڷ�(����) > ��ġȭ �� �� �ִ� ����
// ����(Structure) > ü��ȭ�� ��� 
// �ڷᱸ�� >  ��ġȭ �� 
// �� �ִ� ����(����)�� ü��ȭ ��Ų �� > ���� �Ϻ� ���� �Ϻ�
// �޸� ���� �����Ҵ� 0 �Ҵ���ü

//#define MAL(type, value, count) type* value = (type*)malloc(sizeof(type)* count)
//#define REL(value) if(value != 0) {free(value); value = 0;}

//struct Peopleinfo {
//	char name[20];
//	int age;
//	int ar;
//	float kg;
//};
//��ǰ���� ���α׷�
//��ǰ ����
//��ǰ �̸�, ��ǰ ����, ��ǰ ���

struct Product {
	char name[40];
	int price;
	int stock;
};

typedef struct Product Product;
typedef Product* pProduct;
typedef pProduct* ppProduct;
typedef int* pint;

void InputProduct()
	printf("��ǰ �̸� >>>");
	scanf_s("%s", newproducts[*count].name, 10);
	printf("��ǰ ���� >>>");
	scanf_s("%d", newproducts[*count].price);
	printf("��ǰ ��� >>>");
	scanf_s("%d", newproducts[*count].stock);
	*count += 1;
	if (*pproducts != 0) free(*pproducts);
	*iproducts = newproducts;


#define MAL(type, count) (type*)malloc(sizeof(type)*(count))

	void ProductAppend(ppProduct pproducts, pint count) {
		pProduct newproducts = MAL(Product, *count + 1);
		for (int i = 0; i < *count; ++i) {
			memcpy(&newproducts[i], &(*pproducts)[i], sizeof(struct Product));
		}
		InputProduct(&newproducts[*count]);
		*count += 1;
		if (*pproducts != 0) free(*pproducts);
		*pproducts = newproducts;
	}

void ProductRemove(ppProduct pproducts, pint count) {
	char target[40];
	printf("������ ��ǰ�� >>>");
	scanf_s("%s", target);
	pProduct newproducts = MAL(Product, *count + 1);
		int ischeck = 0;
		for (int i = 0; i < *count; ++i) {
			if (strcmp(target, (*pproducts[i].name) == 0) {
				++ischeck;
					continue;
			}
			memcpy(&newanimals[i - ischeck], &(*pproducts)[i], sizeof(struct Animal));
		}
		*count += 1;
		if (*pproducts != 0) free(*pproducts);
		*pproducts = newproducts;
	}

void ProductShow(struct Product* products, int count) {
	for (int i = 0; i < count; ++i) {
		printf("|%20s|%20s|%8s|\n", products[i].name, products[i].price, products[i].stock);
	}
}
int main() {

}



//���� ���� ���α׷�
//���� ����
//���� �̸�, ���� ��, ���� ����

//struct Animal {
//	char name[20];
//	char kind[30];
//	float kg;
//};
//
//void AnimalAppend(struct Animal** panimals, int* count) {
//	struct Animal* newanimals = (struct Animal*)malloc(sizeof(struct Animal) * (*count + 1));
//	for (int i = 0; i < *count; ++i) {
//	/*	newanimals[i].kg, (*panimals)[i].kg;
//		newanimals[i].kind, (*panimals)[i].kind;
//		newanimals[i].name, (*panimals)[i].name;*/
//		memcpy(&newanimals[i], &(*panimals)[i], sizeof(struct Animal));
//	}
//	printf("�̸� >>>");
//	scanf_s("%s", newanimals[*count].name, 20);
//	printf("�� >>>");
//	scanf_s("%s", newanimals[*count].kind, 20);
//	printf("������ >>>");
//	scanf_s("%f", newanimals[*count].kg);
//	*count += 1;
//	if(*panimals != 0) free(*panimals);
//	*panimals = newanimals;
//}
//
//void AnimalRemove(struct Animal** panimals, int* count) {
//	char target[20];
//	printf("������ ��� >>>");
//	scanf_s("%s", target, 20);
//	struct Animal* newanimals =
//		(struct Animal*)malloc(sizeof(struct Animal) * (*count + 1));
//	int ischeck = 0;
//	for (int i = 0; i < *count; ++i) {
//		if (strcmp(target, (*panimals)[i].name) == 0) {
//			++ischeck;
//			continue;
//		}
//		memcpy(&newanimals[i - ischeck], &(*panimals)[i], sizeof(struct Animal));
//	}
//	*count -= 1;
//	if (*panimals != 0) free(*panimals);
//	*panimals = newanimals;
//}
//
//void AnimalShow(struct Animal* animals, int count) {
//	for (int i = 0; i < count; ++i) {
//		printf("|%20s|%20s|%8.2f|\n", animals[i].name, animals[i].kind, animals[i].kg);
//	}
//
//}



//int main() {
	//struct Product* products = 0;
	//int count = 0, select;

	//while (1) {
	//	printf("1. ���� ��ǰ �߰� 2. ���� ��ǰ ����"
	//		"3. ���� ��ǰ ��� 4.����\n >>>");
	//scanf_s("%d", &select);
	//if (select == 4) break;
	//else if (select == 1) ProductAppend(&products, &count);
	//else if (select == 2) ProductAppend(&products, &count);
	//else if (select == 3) ProductAppend(&products, &count);

	//}
	//if (products != 0) {
	//	free(products);
	//	products = 0;
	//}



	//struct Animal* animals = 0;
	//int count = 0, select;
	//

	//while (1) {
	//	printf("1.���� ���� �߰� 2. ���� ���� ����"
	//		"3. ���� ���� ��� 4.����\n >>>");
	//	scanf_s("%d", &select);
	//	if (select == 4) break;
	//	else if (select == 1) AnimalAppend(&animals, &count);
	//	else if (select == 2) AnimalRemove(&animals, &count);
	//	else if (select == 3) AnimalShow(animals, count);
	//}



	//if (animals != 0) {
	//	free(animals);
	//	animals = 0;
	//}



		//MAL(struct Peopleinfo, p, 1);// malloc(sizeof(struct Peopelinfo)*1);
		//
		//	(*p).age = 15;
		//	p ->age = 15;

		//	REL(p);


			



	/*MAL(char, p, 1000);
		REL(p);*/
	/*int* p = (int*)malloc(sizeof(int));
	MAL(inflt, 0, 1);
	* p= 5;*/

	//int a, b, c; // �ٷ��� ���� ���� x 
	//int arr[50]; // �迭 > �������� ������ �����ϱ����� ��� > ���� ���̴� ���� x

	//int cnt = 10;
	//int* ptr = malloc(sizeof(int) * cnt);
	//ptr[0] = 5;
	//cnt = 15;
	//ptr = realloc(ptr, sizeof(int) * cnt);

	//free(ptr);




//}
