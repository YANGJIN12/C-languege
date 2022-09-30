#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
// 자료(정보) > 수치화 할 수 있는 정보
// 구조(Structure) > 체계화된 모양 
// 자료구조 >  수치화 할 
// 수 있는 정보(결정)를 체계화 시킨 것 > 단점 일부 장점 일부
// 메모리 누수 동적할당 0 할당해체

//#define MAL(type, value, count) type* value = (type*)malloc(sizeof(type)* count)
//#define REL(value) if(value != 0) {free(value); value = 0;}

//struct Peopleinfo {
//	char name[20];
//	int age;
//	int ar;
//	float kg;
//};
//상품관리 프로그램
//상품 정보
//상품 이름, 상품 가격, 상품 재고

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
	printf("상품 이름 >>>");
	scanf_s("%s", newproducts[*count].name, 10);
	printf("상품 가격 >>>");
	scanf_s("%d", newproducts[*count].price);
	printf("상품 재고 >>>");
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
	printf("삭제할 제품명 >>>");
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



//동물 관리 프로그램
//동물 정보
//동물 이름, 동물 종, 동물 무게

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
//	printf("이름 >>>");
//	scanf_s("%s", newanimals[*count].name, 20);
//	printf("종 >>>");
//	scanf_s("%s", newanimals[*count].kind, 20);
//	printf("몸무게 >>>");
//	scanf_s("%f", newanimals[*count].kg);
//	*count += 1;
//	if(*panimals != 0) free(*panimals);
//	*panimals = newanimals;
//}
//
//void AnimalRemove(struct Animal** panimals, int* count) {
//	char target[20];
//	printf("삭제할 대상 >>>");
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
	//	printf("1. 관리 상품 추가 2. 관리 상품 삭제"
	//		"3. 관리 상품 출력 4.종료\n >>>");
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
	//	printf("1.관리 동물 추가 2. 관리 동물 삭제"
	//		"3. 관리 동물 출력 4.종료\n >>>");
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

	//int a, b, c; // 다량의 정보 관리 x 
	//int arr[50]; // 배열 > 여러개의 변수를 관리하기위한 기능 > 자주 쓰이는 구조 x

	//int cnt = 10;
	//int* ptr = malloc(sizeof(int) * cnt);
	//ptr[0] = 5;
	//cnt = 15;
	//ptr = realloc(ptr, sizeof(int) * cnt);

	//free(ptr);




//}
