#include <stdio.h>
#include <string.h> // 문자열에 관한 미리 만든 기능
#pragma warning(disable:6054) //경고표시 제거
//#pragma warning(error:6054) //에러표시 생성


// 포인터(Pointer) > 숫자(주소)를 저장하는 변수 > 주소를 받기위한 변수

//#define PTR(type, value) type value; type *p##value = &value;
	//typedef int number_4byte;
	//typedef int number_32bit;
	//typedef int* pint;
//#define ABCD(X) _Generic((X), int:"int",default:"unkonwn")



int main() { 
	//printf("%s", ABCD(1));
	
	
	// 문자열 토큰
	// Garbage > 쓰레기값 > 
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
	//	p = p + strlen(p) + 1; // 해당 주소부터 널문자까지 몇 글자 있는지 체크
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
	////pa를 배열처럼 쓸수 있음
	////컴퓨터가 쓰는 방식(주소 방식)
	//pa[0];
	//*(pa + 0) = 5; // &pa[0]


	// 사용자 정의 자료형
	// 자료형 재정의
	
	/*number_4byte a ,b , c;
	pint pa, pb, pc;
	pa = &a;
	pa = &b;
	pa = &c;
	printf("%p\n", pa);
	printf("%p\n", pb);
	printf("%p\n", pc);*/

	////포포인터
	//int a;
	//int* p = &a; // int 형 변수의 *(주소) p
	//int** pp = &p; // int 형 변수의 *(주소)의 *(주소) pp
	//int*** ppp = &pp;
	////&와 *d은 서로 상쇄됨
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
	////지역(Location)
	//{// A 지역
	//	//지역에 따른 시야
	//	int a;
	//	a = 5;
	//	*p = 5;
	//	printf("A지역 출력\n");
	//}
	//{// B 지역
	//	//지역에 따른 시야
	//	int a;
	//	a = 4;
	//	printf("B지역 출력\n");
	//}

	//int arr[5]; // 배열의 주소 == 배열 첫번째 칸의 주소
	//printf("%p\n", arr);
	//printf("%d\n", *arr);

	//int* ptr = arr;
	//ptr[0] = 1; //해당하는 주소에서 변수 크기만큼 0번 이동
	//ptr[1] = 1;
	//printf("%d\n", arr[0]);
	//printf("%d\n", arr[1]);


	// 배열
	//int arr[5]; // 정수형 변수 5개 묶은 배열
	//printf("%p\n", arr); // 배열의 주소
	// 주소를 통한 동작
	//arr[0], arr[1] > 주소이동
	//int *ptr = arr;
	//printf("%p\n", ptr); // 배열의 주소



	//char P;
	//long int* PP = &P; // 잘못된 문법
	// pointer PP = &P;
	// 모든 포인터는 동일함 > 크기가 동일함
	//char *PP = &P;
	// PP라는 포인터가 가진 주소에 찾아가면 char형 변수가 있음
	// PP라는 포인터는 char형 변수의 주소를 담는다


	//long int Kim; // int > 4byte long int > 8byte
	//printf("%p\n", &Kim); // 변수의 주소 > 기계어 
	//Kim = 5;
	//long int *Lee = &Kim; //Lee라는 포인터 변수
	//printf("%p\n", &Lee);
	//printf("%p\n", Lee);
	//printf("%d\n", *Lee); // * 곱하기 > 이항연산자, * 주소연산 > 단항연산자 


}