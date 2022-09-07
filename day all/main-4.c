#include <stdio.h>

//코드를 작성할 때 중요하게 여기는것 > 가독성

int main() {
	
	/*int a;
	scanf_s("%d", &a);
	printf0((a % 2 == 0) ? "짝수입니다." : "홀수 입니다.");*/

	//조건문
	// if 
	//if (조건(판단식)1 < 2) /*참일때만 실행 불일때 실행안함*/ {
	//	printf("첫번쨰 단락");
	//	printf("두번쨰 단락");
	//	printf("세번쨰 단락");
	//	printf("네번쨰 단락");
	//}
	//else/*불일때 실행*/ {
	//	printf("다섯번째 단락");
	//	printf("여섯번째 단락");
	//}
	//int number;
	//scanf_s("%d", &number);
	//if (number % 2 = 0) 
	//	if (number % 5 = 0) 
	//		printf("짝수이면서 5의 배수입니다.\n");
	//	else 
	//		printf("짝수이지만 5의 배수가 이닙니다.\n");

	//else 
	//	if (number % 5 == 0) 
	//		printf("홀수이면서 5의 배수입니다.\n");
	//	else 
	//		printf("홀수이지만 5의 배수가 아닙니다.\n");
	//if (number == 1) printf("1번입니다.\n");
	//else if (number == 2) printf("2번입니다.\n");
	//else if (number == 3) printf("3번입니다.\n");
	//else if (number == 4) printf("4번입니다.\n");
	
	// switch > 선택한다 > 선택문
	//int number;
	//scanf_s("%d", &number);
	//switch (/*정수*/ number) {
	//case 0:
	//	printf("0번입니다.\n");
	//	break;
	//case 1:
	//	printf("1번입니다.\n");
	//	break;
	//case 2:
	//	printf("2번입니다.\n");
	//	break;
	//case 3:
	//	printf("3번입니다.\n");
	//	break;
	//case 5:
	//case 6:
	//	printf("5번또는 6번입니다.\n");
	//	break;
	//default://내가 만든 번호가 아니면
	//	printf("모르는 번호입니다.\n");
	//	break;

	// }

	//코드의 반복
	//1	Tick or 1 Frame

	//do {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "짝수" : "홀수");
	//} while (/*조건(판단식)*/ number > 0);

	////무한 반복문
	////틀릴때까지 반복
	//while(/*조건(판단식)*/ number > 0) {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "짝수" : "홀수");
	//}

	//int number = 1;//초기문
	//while (number < 9) { //조건문
	//	printf("%d", number);
	//	++number;//증감문
	//}
	//for (/*초기문*//*조건문*//*증감문*/int number = 0; number < 9; ++number) {
	//	printf("%d", number);
	//}
	
	/*for (int number = 2; number < 9; ++number) {
		printf("%d * 2 = %d", number, number * 2);
	}*/


#define FOR(type, value, begin, end) for(type value = begin; value != end; ++value)
#define FORN(end) FOR(int, __temp__value__, 0, end)
#define INFINITEWHILE while(1)
#define ENTER printf("\n")
#define EXITFOR(exist) if(exsit) break
#define CONTINUEFOR(exsit) if(exsit) continue
#define INTINPUT(value) int value; printf(">>>"); scanf_s("%d", &value)


	//int number;

	//홀짝 판단 10번하는 프로그램
	////for (int i = 0; i < 10; ++i) {
	////FOR(int, i , 0 ,10){
	//FORN(10){
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "짝수" : "홀수");
	//	}

	//홀짝 판단 무한히 하는 프로그램(단, 음수가 들어오면 프로그램 종료)
	//while(number > -1) {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "짝수" : "홀수");
	//}

	//구구단 2단 ~ 9단까지 출력하는 프로그램
	/*for (int dan = 2; dan != 10; ++dan) {
		for (int hang = 2; hang != 10; ++hang) {
			printf("%2d * %2d = %2d\n", dan, hang, dan * hang);
		}
	}*/
	//FOR(int, dan, 2, 10) {
	//	FOR(int, hang, 2, 10) {
	//		//if (hang % 2 == 0) continue;
	//		printf("%2d * %2d = %2d\n", dan, hang, dan * hang);
	//	}
	//}

	//계산기
	//숫자 2개 / 입력 후 / 연산자 선택(숫자 1개 / 입력) / 계산된값 출력
	//while (1) {
	//	INTINPUT(number1);
	//	INTINPUT(number2);
	//	EXITFOR(number2 == 0);

	//	printf("0. +1. -2. *3. /\n");
	//	INTINPUT(select);

	//	if (select == 0) printf("%d + %d =%d\n", number1, number2, number1 + number2);
	//	else if (select == 1)printf("%d - %d = %d\n", number1, number2, number1 - number2);
	//	else if (select == 2)printf("%d * %d = %d\n", number1, number2, number1 * number2);
	//	else if (select == 3)printf("%d / %d = %d\n", number1, number2, number1 / number2);

	//}

	/*int n = 0;
	formaker:
	printf("%3d", n);
	++n;
	if (n < 10)
		goto formaker;*/

	//숫자를 1 ~ 1000까지 모두 출력하는 프로그램
	//위 프로그램에서 짝수만 출력하기
	//위 프로그램에서 8의 배수 제외하기
	
	//int number;
	FOR(int, i, 1, 1001) {
		CONTINUEFOR(i % 2 == 1);
		CONTINUEFOR(i % 8 == 0);
		/*if (i % 2 == 0 && i % 8 != 0);*/
		printf("%5d", i);
	}
		


	


}