#include <stdio.h>



//함수 Function > printf(); / scanf_s(); / malloc();
//단위 프로그래밍
//함수 제작을 위한 2가지
//선언, 정의
//선언 > 이러한 함수가 존재함
	//int A(int a, int b, int c) {
	//int A(int a, int b, int c);  //int[반환타입] A[함수이름](int a[필요한 입력값]); > 선언
	//	printf("%d\n", a);
	//	printf("%d\n", b);
	//	printf("%d\n", c);
	//	return a + b + c; // return X; 결과값 X를 돌려줘라

	//	

	//}//정의
//void showgugu(); // void > 결과값이 없을때
//void showgugu() {
//
//}

// 문자열 관련 함수

//int strlen(char* arr) {
//	int len = 0;
//	while (arr[len] != '\0') {
//		++len;
//	}
//	return len;
//	
//}
//// 문자열 복사
//// 포인터 > 주소
//void strcpy(char* dest, char* sourc) {
//	int i = -1;
//	do {
//		++i;
//		dest[i] = sourc[i];
//
//	} while (sourc[i] != '\0');
//
//	}
//
//// 문자열 더하기
//
//int strcat(char* dest, char* sour, char* result) {
//	char dest[50] = "AB";
//	char sour[50] = "CD";
//	char result[50];
//	int i = 0;
//	
//		for (int x = 0; dest[x] != '\0'; ++x, ++i) {
//			result[i] = dest[x];
//		}
//		for (int x = 0; sour[x] != '\0'; ++x, ++i) {
//			result[i] = sour[x];
//	}
//		result[i] = '\0';
//		
//	}
//
//char lower(char c) {
//	return ('a' <= c && c <= 'z') ? c : c + 32;
//}
//char upper(char c) {
//	return ('A' <= c && c <= 'Z') ? c : c - 32;
//}
//
//
//// 문자열 비교
//int strcmp(char*dest, char*sour) {
//	char dest[50] = "ABCD";
//	char sour[50] = "ABCD";
//	for (int i = 0; !(dest[i] == '\0' && sour[i] == '\0'); ++i) {
//		char sde = dest[i], sso = sour[i];
//		sde = lower(sde);
//		sso = upper(sso);
//		if (sde > sso) return  -1;
//		if (sde < sso) return 1;
//	}
//	return 0;
//}
	
// 피보나치 A* , Deep Learning
//재귀 함수
//함수에서 자신을 또 호출할때 > 재귀함수 

//void A(int n) {
//	printf("ABCD");
//	if (n > 0)
//		A(n - 1);
//}
// 
// 
// 
// 
// 함수에 대한 설명
// Create by 누구누구 2022.09.05


/// <summary>
/// 피보나치 수열 숫자 두개를 더하는 수열
/// </summary>
/// <param name="n">처음숫자와 두번째 숫자를 구한것</param>
/// <returns></returns>
//int Fibonachi(int n) {
//	if (n < 1) return -1;
//	if (n == 1 || n == 2) return 1;
//	return Fibonachi(n - 1) + Fibonachi(n - 2);
//}
//int ThreeBeforeAdded(int n) { 
//	if (n < 1) return -1;
//	if (n == 1 || n == 2 || n == 3) return 1;
//	return ThreeBeforeAdded(n - 1) + ThreeBeforeAdded(n - 2) + ThreeBeforeAdded(n - 3);
//
//}
//int Three(int n) { 
//	if (n < 1) return -1;
//	if (n == 1 || n == 2 || n == 3) return 1;
//	return Three(n - 1) * (Three(n - 2) + Three(n - 3));
//}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	/// 

 /// <summary>
 /// 대문자를 소문자로 변경
 /// </summary>
 /// <param name="c">문자 1개</param>
 /// <returns>변경된 문자</returns>
// char lower(char c) {
//		return ('a' <= c && c <= 'z') ? c : c + 32;
//}
// void lowerstr(char* str) {
//	 for (int i = 0; str[i]; ++i) {
//		 str[i] = lower(str[i]);
//	 }
// }

 
 
 /// <summary>
 /// 소문자를 대문자로 변경
 /// </summary>
 /// <param name="c">문자 1개</param>
 /// <returns>변경된 문자</returns>
// char upper(char c) {
//		return ('A' <= c && c <= 'Z') ? c : c - 32;
//}
// void upperstr(char* str) {
//	 for (int i = 0; str[i]; ++i) {
//		 str[i] = upper(str[i]);
//	 }
// }
//
// /// <summary>
// /// 문자열을 출력하는 함수
// /// </summary>
// /// <param name="str">출력할 문자열</param>
// /// <param name="length">출력할 문자열 길이</param>
// void showster(char* str, int length) {
//	 for (int i = 0; i < length && str[i]; ++i) {
//		 putc(str[i], stdin);
//	 }
// }





int main() {
	/*showstr("ABCD", 3);*/
	//for (int i = 1; i < 10; ++i) {
	//	printf("%d > ", Fibonachi(i));
	//}
	//printf("\n");
	//for (int i = 1; i < 10; ++i) {
	//	printf("%d > ", ThreeBeforeAdded(i));
	//}
	//printf("\n");
	//for (int i = 1; i < 10; ++i) {
	//	printf("%d > ", Three(i));
	//}
	//A(3);
	//char temp[50] = "ABCD", temp2[50] = "DEFG", temp3[50];
	//switch (strcmp(temp, temp2)) {
	//case 1:
	//	printf("오른쪽이 사전상 더 나중이다\n");
	//	break;
	//case -1:
	//	printf("왼쪽이 사전상 더 나중이다.\n");
	//	break;
	//case 0:
	//	printf("두 문자열이 같다\n");

	//}

	/*strcat(temp, temp2, temp3);
	printf("%s\n", temp3);*/


	/*printf("ABCD Length : %d\n",strlen("ABCD"));
	char A[6] = "AB", B[6] = "CD";
	pirntf("%s\n", A);
	pirntf("%s\n", B);
	strcpy(A, B);*/

	//printf("%d\n", A(1, 2, 3)); // 1 + 2 + 3
	//A(4, 5, 6);
	/*int a, b, c;*/
	/*printf("ABCD");
	scanf_s();
	memcpy();
	strcpy();*/
	//printf[함수이름]("ABCD"[입력값]);
	//함수이름(인자값); // 함수 호출 Function Call


}