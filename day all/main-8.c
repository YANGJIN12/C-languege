#include <stdio.h>
#include <stdlib.h> // Standard Library
#include <memory.h> // memory Library

// �Ҵ�(������ ����� ���°�)
// �����Ҵ� vs �����Ҵ�
// �����Ҵ� > ����(�������� �ʴ� ��) > � ��Ȳ � �ð� � ���¿����� �����ϰ� �Ҵ�Ǵ� �� > �ҽ��ڵ忡 ������ ������ �ۼ��� ����
// �����Ҵ� > ����(�����̴� ��) > ��Ȳ������ �ð������� ���¿����� �ٸ��� �Ҵ�Ǵ� �� > �ҽ��ڵ忡 ������ ������ �ۼ�

//#define MALOC(type, value, count) type *value = (type*)malloc(sizeof(type) * count)
//#define FOR(indexer, count) for(int indexer = 0; indexer < count; ++indexer)
int main() {
	// �����Ҵ��� �̸� ������ ����� ���� ����
	// �����Ҵ� > �ҽ��ڵ带 ���� ��Ȳ�� ũ�⸦ �ۼ�
	// int b = 5;
	// b��� ������ ������
	// 4����Ʈ�� ������ �Ҵ��ض�
	// �Ҵ��� ������ ���������� ����ض�
	// b��� ������ 5�� �־��
	/*int a[b];*/
	// a��� ������ ������ 
	// b������ �迭�� ������
	// 4����Ʈ ������ b�� �Ҵ��ض� > N����Ʈ ������ �Ҵ��ض�
	// �Ҵ��� ������ ���������� ����ض�
	// �ҽ��ڵ��� �м�

	// ���� �Ҵ�
	// ���� Ÿ�̹�
	// ���� �Ҵ� > �����ϴ� ������ ũ�⸦ �Ҵ�
	// 4����Ʈ�� ������ �Ҵ��ض�

	//int a;
	//malloc(a); // memory allocation

	// �����Ҵ縸 ����ϸ� > ���ʿ��� ������ ���
	// ���α׷� �ۼ� > ���� > exe ���� > ����
	// ���� �Ҵ� > �ʿ��� ��ŭ ����ÿ� ������ ����
	// ���� �Ҵ� > ������ ���


	//int a;
	//int *p = malloc(4);// N��ŭ�� ũ�⸦ �Ҵ��ض�
	//char* pp = p;
	//pp[0] = 1;
	//pp[1] = 1;
	//pp[2] = 1;
	//pp[3] = 1;
	//printf("%d\n", *p);
	/**p = 4.5;
	printf("%f\n", *p);*/

	//���� > �޸� ���� > �޸𸮰� ����
	// ���� �Ҵ�
	//int a; // ���� �Ҵ� ����
	/*int* p = malloc(4);
	free(p);*/

	//int Count;
	//scanf_s("%d", &Count);
	//int* Arr = malloc(sizeof(int) * Count); // sizeof > ������ ũ��
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

