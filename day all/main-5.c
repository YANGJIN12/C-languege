#include <stdio.h>

//�迭 > array > ���� 
//�迭 > ���α׷� > �Ѱ��� ������
//�迭 > ������ ������ ���� ��


int main() {
	char math[1024];
	scanf_s("%s", math, 1024);
	//�Ҽ��� x, 10+10+10 > 30, 10+10*2 > 40
	int number1 = 0, number2 = 0;
	int operatorchar = '\0';
	for (int i = 0; math[i]; ++i) {
		if ('0' <= math[i] && math[i] <= '9') {
			number2 = number2 * 10 + math[i] - '0';
		}
		else {
			if (math[i] != '+' && math[i] != '-' && math[i] != '*' && math[i] != '/' && math[i] != '%') continue;
			switch (operatorchar) {
			case '\0':
				number1 = number2;
				break;
			case '+':
				number1 = number1 + number2;
				break;
			case '-':
				number1 = number1 - number2;
				break;
			case '*':
				number1 = number1 * number2;
				break;
			case '/':
				number1 = number1 / number2;
				break;
			case '%':
				number1 = number1 % number2;
				break;
			}
			number2 = 0;
			operatorchar = math[i];
		}
		
	}switch (operatorchar) {
	case '+':
		number1 = number1 + number2;
		break;
	case '-':
		number1 = number1 - number2;
		break;
	case '*':
		number1 = number1 * number2;
		break;
	case '/':
		number1 = number1 / number2;
		break;
	case '%':
		number1 = number1 % number2;
		break;
	}
	printf("=%d\n", number1);
	//char arr1[10] = "ABCD";
	//char arr2[10] = "ABC";
	////int equal = 1;
	////int i;
	////for (int i = 0; arr1[i] && arr2[i]; ++i) {
	////	if (arr1[i] != arr2[i]) {
	////		equal = 0;
	////		break;
	////	}
	////}
	////if (arr1[i] != arr2[i]) equal = 0;

	//strcpy_s(arr1, 10, "ABCD");
	//strcpy_s(arr2, 10, "ABCD");
	//arr2[8] = 'a';

	//printf("%s %s", arr1, arr2);
	//if



	//strcpy; // arr1 = arr2 
	//memcpy;// ��ü��
	//strcmp;// �ι��ڱ��� ��
	//strcat; // ���ڿ� �ձ�


	/*strcpy_s(arr1, 10, "ABCDEFG");

	//if (strcmp(arr1, arr2)== 0) {
	//	printf("�� ���ڿ��� �����ϴ�.");
	//}
	//else {
	//	printf("�� ���ڿ��� ���� �ʽ��ϴ�.");
	//}

}











	//char a = 'a';
	//char Arr[500] = "ABCDE";
	//scanf_s("%s", Arr, 500);
	//int number = 0;
	//int dot = 0;
	//int dotcount = 0;
	//for (int i = 0; Arr[i]; ++i) {
	//	if (Arr[i] == '.') dot = 1;
	//	if (Arr[i] < '0' || '9' < Arr[i]) continue;
	//	//if('0' <= Arr[i] && Arr[i] <= '9')
	//	number = number * 10 + Arr[i] - '0';
	//	if (dot == 1) ++dotcount;
	//}
	//if(dotcount == 0) printf("%d\n", number * 2);
	//else {
	//	float fnumber = number;
	//	for (int i = 0; i < dotcount; ++i) {
	//	}
	//	printf("%f\n", fnumber * 2);
	//}

	/*for (int i = 0; Arr[i]; ++i) {
		if ('a' <= Arr[i] && Arr[i] <= 'z')
			printf("%c", Arr[i] - 32);
		else if ('A' <= Arr[i] && Arr[i] + 32);
			printf("%c", Arr[i]);

	}*/

	//char A = 'a'; 
	////\0 > �ι���
	////��� > �������� �ѱ��ڸ� �߰� > �ι���
	//scanf_s("%s", Arr, 500);
	//for(int i = 0; Arr[i]; ++i){
	//	if ('A' <= Arr[i] && Arr[i] <= 'Z') 
	//		printf("%c", Arr[i] + 32);
	//	else
	//		printf("%c", Arr[i]);
	//	
	//}


	//"ABCD"; //�迭, �������� �����Ͱ� ���� ��




	//������ ������� �迭�� �Է��ϰ� �迭 ��ü ����ϴ� ���α׷�
	//�Է��ϴ� ������� ���� �Է��� �ܸ� �Է��Ѵ�
	//ex) 2�Է�
	//int arr[9];
	//int input;
	//scanf_s("%d", &input);
	//for (int i = 0; i < 9; ++i) {
	//	arr[i] = input * (i + 1);
	//}
	//for (int i = 0; i < 9;++i) {
	//	printf("%d, ", arr[i]);
	//}
	/*int arr[5];
	for (int i = 0; i <= 5; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i <= 5; ++i) {
		printf("%p\n", &arr[i]);
	}*/

	//int arr[5];
	//arr; //�迭 ��ü�� ��ǥ�ϴ� �̸�
	//printf("%p\n", arr);
	//arr[0];
	//printf("%p\n", &arr[0]);

}

