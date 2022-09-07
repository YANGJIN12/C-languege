#include <stdio.h>
#include <stdlib.h> // Standard Library
#include <memory.h> // memory Library

// 할당(변수를 만들어 내는것)
// 정적할당 vs 동적할당
// 정적할당 > 정적(움직이지 않는 것) > 어떤 상황 어떤 시간 어떤 상태에서든 동일하게 할당되는 것 > 소스코드에 변수를 만들라고 작성한 내용
// 동적할당 > 동적(움직이는 것) > 상황에따라 시간에따라 상태에따라 다르게 할당되는 것 > 소스코드에 변수를 만들라고 작성

//#define MALOC(type, value, count) type *value = (type*)malloc(sizeof(type) * count)
//#define FOR(indexer, count) for(int indexer = 0; indexer < count; ++indexer)
int main() {
	// 정적할당은 미리 변수를 만들어 놓는 과정
	// 정적할당 > 소스코드를 적는 상황에 크기를 작성
	// int b = 5;
	// b라는 변수를 만들어라
	// 4바이트의 공간을 할당해라
	// 할당한 공간을 정수형으로 사용해라
	// b라는 변수에 5를 넣어라
	/*int a[b];*/
	// a라는 변수를 만들어라 
	// b개수의 배열로 만들어라
	// 4바이트 공간을 b개 할당해라 > N바이트 공간을 할당해라
	// 할당한 공간을 정수형으로 사용해라
	// 소스코드의 분석

	// 동적 할당
	// 생성 타이밍
	// 동적 할당 > 실행하는 순간에 크기를 할당
	// 4바이트의 공간을 할당해라

	//int a;
	//malloc(a); // memory allocation

	// 정적할당만 사용하면 > 불필요한 변수의 사용
	// 프로그램 작성 > 빌드 > exe 배포 > 실행
	// 동적 할당 > 필요한 만큼 실행시에 변수를 생성
	// 동적 할당 > 포인터 사용


	//int a;
	//int *p = malloc(4);// N만큼의 크기를 할당해라
	//char* pp = p;
	//pp[0] = 1;
	//pp[1] = 1;
	//pp[2] = 1;
	//pp[3] = 1;
	//printf("%d\n", *p);
	/**p = 4.5;
	printf("%f\n", *p);*/

	//누수 > 메모리 누수 > 메모리가 샌다
	// 정적 할당
	//int a; // 변수 할당 해제
	/*int* p = malloc(4);
	free(p);*/

	//int Count;
	//scanf_s("%d", &Count);
	//int* Arr = malloc(sizeof(int) * Count); // sizeof > 변수의 크기
	//for (int i = 0; i < Count; ++i) {
	//	printf("%d Number <<", i + 1);
	//	scanf_s("%d", &Arr[i]);
	//}
	//int Countsp = Arr[0];
	//for (int i = 0; i < Count; ++i) {
	//	Countsp = (Countsp < Arr[i] || Countsp > Arr[i]) ? Arr[i] : Countsp;
	//}
	//
	//int big = Arr[0];
	//for (int i = 0; i < Count; ++i) {
	//	big = (big < Arr[i]) ? Arr[i] : big;
	//}
	//int small = Arr[0];
	//for (int i = 0; i < Count; ++i) {
	//	small = (small > Arr[i]) ? Arr[i] : small;
	//}
	//for (int i = 0; i < Count; ++i) {
	//	printf("%d > ", Arr[i]);
	//}
	//printf("BIG >> %d\n", big);
	//printf("SMALL >> %d\n", small);
	//printf("Countsp >> %d\n", Countsp);
	//free(Arr);

	/*int count;
	scanf_s("%d", &count);
	MALOC(int, arr, count);
	FOR(i, count) {
		scanf_s("%d", &arr[i]);
	}
	int big = arr[0], small = arr[0] , sum = 0;
	FOR(i, count) {
		big = (big < arr[i]) ? arr[i] : big;
		small = (small > arr[i]) ? arr[i] : small;
		sum += arr[i];
	}
	printf("BIG : %d SMALL : %d\n", big, small);

	for (int i = small; i <= big; ++i) {
		printf("%d > ", i);
	}
	printf('\n');
	printf("Summary : %d Summary - BIG - SMALL : %d\n", sum, sum - big - small);

	free(arr);*/

	//int count = 0;
	//int input;
	//int* arr = 0;
	//while (1) {
	//	scanf_s("%d", &input);
	//	if(input == 0) break;
	//	arr = (arr = 0) ? malloc(sizeof(int) * 1):
	//	 realloc(arr, sizeof(int) * (count + 1));
	//	/*else {
	//		int* newarr = malloc(sizeof(int) * (count + 1));
	//		memcpy_s(newarr, sizeof(int) * count, arr, sizeof(int) * count);
	//		free(arr);
	//		arr = newarr;
	//		}*/
	//	arr[count] = input;
	//	++count;
	//for (int i = 0; i < count; ++i) {
	//	printf("%d > ", arr[i]);
	//}
	//free(arr);
	//int count = 1;
	//char* math = malloc(1);
	//char input;
	//while (1) {
	//	input = _getch();
	//	_putch(input);
	//	if (input == 13) break;
	//	math = realloc(math, count + 1);
	//	math[count - 1] = input;
	//	math[count] = '\0';
	//	++count;
	//}
	//printf("%d = ", math);

	//int number1 = -1, number2 = -1;
	//int befororeoperator = 1;
	//char oper = '+';

	//for (int i = 0; math[i]; ++i) {
	//	if ('0' <= math[i] && math[i] <= '9') {
	//		if (befororeoperator) {
	//			befororeoperator = 0;
	//			number2 = 0;
	//		}
	//		number2 = number2 * 10 + (math[i] - '0');
	//	}
	//	else if (math[i] == '*' || math[i] == '/' || math[i] == '+' || math[i] == '-' || math[i] == '%' || math[i] == '^') {
	//		if (number1 == -1) {
	//			number1 = number2;
	//		}
	//		else {
	//			number1 = (oper == '*') ? number1 * number2 : number1;
	//			number1 = (oper == '/') ? number1 / number2 : number1;
	//			number1 = (oper == '+') ? number1 + number2 : number1;
	//			number1 = (oper == '-') ? number1 - number2 : number1;
	//			number1 = (oper == '%') ? number1 % number2 : number1;
	//			if (oper == '^') {
	//				int temp = 1;
	//				for (int i = 0; i < number2; ++i) {
	//					temp *= number1;
	//				}
	//				number1 = temp;
	//			}

	//		}
	//		oper = math[i];
	//		befororeoperator = 1;
	//	}
	//}
	//number1 = (oper == '*') ? number1 * number2 : number1;
	//number1 = (oper == '/') ? number1 / number2 : number1;
	//number1 = (oper == '+') ? number1 + number2 : number1;
	//number1 = (oper == '-') ? number1 - number2 : number1;
	//number1 = (oper == '%') ? number1 % number2 : number1;
	//number1 = (oper == '^') ? number1 ^ number2 : number1;
	//if (oper == '^') {
	//	int temp = 1;
	//	for (int i = 0; i < number2; ++i) {
	//		temp *= number1;
	//	}
	//	number1 = temp;
	//}

	//printf("%d\n", number1);

	//free(math);

	//realloc > re allocation
	//calloc > clear allocation

	//int* p = calloc(1, 4);
	//printf("%d", *p);
	//free(p);

}

