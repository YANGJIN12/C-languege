#include <stdio.h>
#include <string.h> // ���ڿ��� ���� �̸� ���� ���
#pragma warning(disable:6054) //���ǥ�� ����
//#pragma warning(error:6054) //����ǥ�� ����


// ������(Pointer) > ����(�ּ�)�� �����ϴ� ���� > �ּҸ� �ޱ����� ����

//#define PTR(type, value) type value; type *p##value = &value;
	//typedef int number_4byte;
	//typedef int number_32bit;
	//typedef int* pint;
//#define ABCD(X) _Generic((X), int:"int",default:"unkonwn")



int main() { 
	//printf("%s", ABCD(1));
	
	
	// ���ڿ� ��ū
	// Garbage > �����Ⱚ > 
	//char dump[1024], spilter[40];
	//char* p;
	//scanf_s("%s", dump, 1024);
	//scanf_s("%s", spilter, 40);
	//strcpy_s(spilter, 40, "=,|.<>?/^&%#@!\\+*");
	//p = dump;
	//p[strlen(p) + 1] = '\0';
	//while (*p != '\0') {
	//	/*if (*p == ',' || *p == '=' || *p == '|' || *p == '&' || *p == '^') */
	//	for (int i = 0; spilter[i]; ++i) {
	//		if(spilter[i] == *p) *p = '\0';
	//	}
	//	++p;
	//}
	//p = dump;
	//for (int i = 1; *p != '\0';++i) {
	//	printf("#%s", p);
	//	if (i % 4 == 0) printf("\n");
	//	p = p + strlen(p) + 1; // �ش� �ּҺ��� �ι��ڱ��� �� ���� �ִ��� üũ
	//}



	/*char temp[50] = "This is Array";
	char* p = temp;
	while (*p != '\0') {
		printf("%s\n", p);
		++p;
	}*/
	/*for (int i = 0; p[i] != '\0'; ++i) {
		printf("%s\n", &p[i]);
	}*/





	////int a, b; 
	//int a[5];
	//int* pa;
	//pa = a;
	////pb = &b;
	////pa�� �迭ó�� ���� ����
	////��ǻ�Ͱ� ���� ���(�ּ� ���)
	//pa[0];
	//*(pa + 0) = 5; // &pa[0]


	// ����� ���� �ڷ���
	// �ڷ��� ������
	
	/*number_4byte a ,b , c;
	pint pa, pb, pc;
	pa = &a;
	pa = &b;
	pa = &c;
	printf("%p\n", pa);
	printf("%p\n", pb);
	printf("%p\n", pc);*/

	////��������
	//int a;
	//int* p = &a; // int �� ������ *(�ּ�) p
	//int** pp = &p; // int �� ������ *(�ּ�)�� *(�ּ�) pp
	//int*** ppp = &pp;
	////&�� *d�� ���� ����
	//printf("%p\n", &pp); // none
	//printf("%p\n", &p);	// pp
	//printf("%p\n", &a); // p, *pp
	//printf("%d\n", a); // *p, *pp



	//PTR(int, a);
	//int a, b, c, d, e;
	//int* pa[5];
	//pa[0] = &a;
	//pa[1] = &b;
	//pa[2] = &c;
	//pa[3] = &d;
	//pa[4] = &e;

	//for (int i = 0; i < 5; ++i) {
	//	scanf_s("%d", &pa[i]);
	//}
	//for (int i = 0; i < 5; ++i) {
	//	printf("%d\n", pa[i]);
	//}
	/*int* ptr1,* ptr2, * ptr3,* ptr4,* ptr5;

	*ptr1 = 5;
	*ptr2 = 6;
	*ptr3 = 7;
	*ptr4 = 8;
	*ptr5 = 9;

	printf("%d\n", *ptr1);
	printf("%d\n", *ptr2);
	printf("%d\n", *ptr3);
	printf("%d\n", *ptr4);
	printf("%d\n", *ptr5);*/


	//int a;
	//int* p = &a;
	//
	////����(Location)
	//{// A ����
	//	//������ ���� �þ�
	//	int a;
	//	a = 5;
	//	*p = 5;
	//	printf("A���� ���\n");
	//}
	//{// B ����
	//	//������ ���� �þ�
	//	int a;
	//	a = 4;
	//	printf("B���� ���\n");
	//}

	//int arr[5]; // �迭�� �ּ� == �迭 ù��° ĭ�� �ּ�
	//printf("%p\n", arr);
	//printf("%d\n", *arr);

	//int* ptr = arr;
	//ptr[0] = 1; //�ش��ϴ� �ּҿ��� ���� ũ�⸸ŭ 0�� �̵�
	//ptr[1] = 1;
	//printf("%d\n", arr[0]);
	//printf("%d\n", arr[1]);


	// �迭
	//int arr[5]; // ������ ���� 5�� ���� �迭
	//printf("%p\n", arr); // �迭�� �ּ�
	// �ּҸ� ���� ����
	//arr[0], arr[1] > �ּ��̵�
	//int *ptr = arr;
	//printf("%p\n", ptr); // �迭�� �ּ�



	//char P;
	//long int* PP = &P; // �߸��� ����
	// pointer PP = &P;
	// ��� �����ʹ� ������ > ũ�Ⱑ ������
	//char *PP = &P;
	// PP��� �����Ͱ� ���� �ּҿ� ã�ư��� char�� ������ ����
	// PP��� �����ʹ� char�� ������ �ּҸ� ��´�


	//long int Kim; // int > 4byte long int > 8byte
	//printf("%p\n", &Kim); // ������ �ּ� > ���� 
	//Kim = 5;
	//long int *Lee = &Kim; //Lee��� ������ ����
	//printf("%p\n", &Lee);
	//printf("%p\n", Lee);
	//printf("%d\n", *Lee); // * ���ϱ� > ���׿�����, * �ּҿ��� > ���׿����� 


}