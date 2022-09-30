#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>


// 구조체 > 구조화시킨 정보
// 크기를 미리 결정 > 단점 > 속도, 메모리

// 자료구조  > 대용량의 데이터 > 쪼개서 관리
// Vector > 배열 > 크기 변경 가능
// List

// 동물 관리 프로그램
// 동물 이름, 동물 종, 동물 몸무게 관리 프로그램
// 동물 추가, 동물 출력

#define GV(vector, index) (vector->data[(index)%vector->length])
#define VectorType struct Student




struct Student {
	char name[32];
	int year;
	int score;
	

};
struct Vector {
	VectorType* data; // int* data;
	int length; // 배열의 크기


};
typedef struct Vector VECT;
typedef VECT* PVECT;
typedef void(*FUNC)(PVECT);


PVECT CreateVector(int size) {
	PVECT result = (PVECT)malloc(sizeof(VECT));
	result->data =
		(VectorType*)malloc(sizeof(VectorType) * size);
	result->length = size;
	memset(result->data, 0, sizeof(VectorType) * size);

	return result;
}

void ReleaseVector(PVECT vector) {
	free(vector->data);
	free(vector);
}

VectorType* GetValue(PVECT vector, int index) {
	return &vector->data[index % vector->length];
}

PVECT ChangeVector(PVECT vector, int size) {
	VectorType* newdata = (VectorType*)malloc(sizeof(VectorType) * size);
	memset(newdata, 0, sizeof(VectorType) * size);
	memcpy(newdata, vector->data, sizeof(VectorType) * ((size < vector->length)? size : vector->length));
	free(vector->data);
	vector->data = newdata;
	vector->length = size;
}

void ShowData(VectorType* data) {
	if (data == 0) return;
	printf("|%32s|%3d|%4d|\n", data->name, data->year, data->score);

}
void AddVector(PVECT vector) {
	ChangeVector(vector, vector->length + 1);
	printf("이름 >>>");  scanf_s("%s", GV(vector, vector->length - 1).name, 32);
	printf("학년 >>>");	 scanf_s("%d", &GV(vector, vector->length - 1).year);
	printf("점수 >>>");  scanf_s("%d", &GV(vector, vector->length - 1).score);

}

void ShowFull(PVECT vector) {
	for (int i = 0; i < vector->length; ++i) {
		ShowData(&GV(vector, i));
	}
}
void ShowFullHigh(PVECT vector) {
	VectorType* high = 0;
	for (int i = 0; i < vector->length; ++i) {
		if (high == 0) high = &GV(vector, i);
		if (high->score < GV(vector, i).score) high = &GV(vector, i);
	}
	ShowData(high);
}

void ShowYearHigh(PVECT vector) {
	VectorType* high[10] = { 0 };
	for (int x = 0; x < 10; ++x) {
		for (int i = 0; i < vector->length; ++i) {
			if (high[x] == 0 && x == GV(vector, i).year) high[x] = &GV(vector, i);
			if (high[x] != 0) {
				if (high[x]->score < GV(vector, i).score &&
					x == GV(vector, i).year) high[x] = &GV(vector, i);
			}
		}
		ShowData(high[x]);
	}
}


int main() {
	PVECT vector = CreateVector(0);
	int select;
	FUNC action = 0;

	while (1) {
		action = 0;
		printf("1.학생 추가 2. 학생 전체 3. 전체학년 최고점수 4.각학년 최고점수 5. 종료\n >>>");
		scanf_s("%d", &select);
		if (select == 5) break;
		else if (select == 1) action = AddVector;
		else if (select == 2) action = ShowFull;
		else if (select == 3) action = ShowFullHigh;
		else if (select == 4) action = ShowYearHigh;
		if (action != 0) action(vector);
	}
	if (vector != 0) ReleaseVector(vector);
		
}

















//#define VectorType int
//
//
//struct Vector {
//	VectorType* data; // int* data;
//	int length; // 배열의 크기
//
//};
//typedef struct Vector VECT;
//typedef VECT* PVECT;
//
//PVECT CreateVector(int size) {
//	PVECT result = (PVECT)malloc(sizeof(VECT));
//	result->data =
//		(VectorType*)malloc(sizeof(VectorType) * size);
//	result->length = size;
//	memset(result->data, 0, sizeof(VectorType) * size);
//
//	return result;
//}
//
//void ReleaseVector(PVECT vector) {
//	free(vector->data);
//	free(vector);
//}
//
//VectorType* GetValue(PVECT vector, int index) {
//	return &vector->data[index % vector->length];
//}
//
//PVECT ChangeVector(PVECT vector, int size) {
//	VectorType* newdata = (VectorType*)malloc(sizeof(VectorType) * size);
//	memset(newdata, 0, sizeof(VectorType) * size);
//	memcpy(newdata, vector->data, sizeof(VectorType) * ((size < vector->length)? size : vector->length));
//	free(vector->data);
//	vector->data = newdata;
//	vector->length = size;
//}
//
//int main() {
//	PVECT vector = CreateVector(10);
//
//	for (int i = 0; i < vector->length; ++i) {
//		*GetValue(vector, i) = i;
//	}
//	for (int i = 0; i < vector->length; ++i) {
//		printf("%d >", *GetValue(vector, i));
//	}
//	printf("\n");
//	ChangeVector(vector, 5);
//	for (int i = 0; i < vector->length; ++i) {
//		printf("%d > ", *GetValue(vector, i));
//	}
//	printf("\n");
//	ChangeVector(vector, 15);
//	for (int i = 0; i < vector->length; ++i) {
//		printf("%d > ", *GetValue(vector, i));
//	}
//	printf("\n");
//
//
//	*GetValue(vector, 3) = 5;
//	
//
//	ReleaseVector(vector);
//	
//
//}