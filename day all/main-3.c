#include <stdio.h>



//	//연산자 > 연산하는 단어
//	//단항 연산자, 이항 연산자, 삼항 연산자
//	//이항 연산자 > 사칙연산,관계연산, 논리연산, 비트연산



//삼항 연산자 > 선택 연산자

int main() {
	//(논리값)  ? (맞았을때) : (틀렸을때)
	//int a = (1 < 3) ? 1 : 3;
	//int a = (1 > 3) ? 1 : 3;
	//printf("%d\n", a);
	//int a = 3;
	//(a > 5) ? printf("a는 5보다 큽니다.\n") : printf("a는 5보다 크지 않습니다.\n");
	//int a;
	//scanf_s("%d", &a);
	//(a == 1) ? printf("a=1") : (a == 2) ? printf("a=2") : printf("a=3");
	int a;
	scanf_s("%d", &a);
	((a % 1) ==0) ? printf("a는 짝수입니다.\n") : printf("a는 홀수입니다.\n");



	int a;
	int b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("%d가 더 큽니다.\n");
	printf("두 수가 똑같습니다.");
		(a > b) ? a : b;
	











}



//단항 연산자

//int main() {
//	//int a = 5;
//	//printf("%d\n", a);
//	//a = a + 1;
//	//printf("%d\n", a);
//	//--a; // 앞에 붙일 때(나중에 더함)랑 뒤에 붙일 때(먼저 더함) 계산 순서가 다름
//	//printf("%d\n", a);
//	// a++ > 더느림 , ++a > 더빠름
//	int a = 5;
//	int b;
//	b = (a++) + 1;
//	//a를 증가 , a 증가 전의값
//	printf("%d\n", b);
//	b = (++a) + 1;
//	printf("%d\n", b);
//}







//#define OpPrint(op, a ,b) printf("%d" #op "%d = %d\n", a,b,a op b)
//
//int main() {
//	int a ,b;
//	//printf("%d + %d =%d", a, b, a + b);
//	//printf("%d + %d =%d", a, b, a - b);
//	//printf("%d + %d =%d", a, b, a * b);
//	//printf("%d + %d =%d", a, b, a / b);
//	//printf("%d + %d =%d", a, b, a % b);
//	//printf("%d + %d =%d", a, b, a = b);
//	//printf("%d", a <  b);
//	//printf("%d", a >  b);
//	//printf("%d", a >= b);
//	//printf("%d", a <= b);
//	//printf("%d", a != b);
//	//printf("%d", a == b);
//	//printf("%d %d", a, b);
//	//printf("%d %d", a, b);
//	//printf("%d %d", a, b);
//	//printf("%d\n", a & b);
//	//printf("%d\n", a | b);
//	//printf("%d\n", ~a);
//	OpPrint(+, a, b);
//	OpPrint(-, a, b);
//	OpPrint(*, a, b);
//	OpPrint(/, a, b);
//	OpPrint(%, a, b);
//	OpPrint(=, a, b);
//	OpPrint(<, a, b);
//	OpPrint(>, a, b);
//	OpPrint(<=, a, b);
//	OpPrint(>=, a, b);
//	OpPrint(!=, a, b);
//	OpPrint(==, a, b);
//	OpPrint(&&, a, b);
//	OpPrint(||, a, b);
//	OpPrint(&, a, b);
//	OpPrint(|, a, b);
//	printf("%d\n", ~a);
//}








//비트 시프트
//속도가 빠름
//00000000000000000000000000000001 << 1 
//00000000000000000000000000000010 > 왼쪽 시프트
//2의 배수식으로 동작
//00000000000000000000000000000101 >> 1
//00000000000000000000000000000010 > 오른쪽 시프트
//2의 배수의 절반으로 동작

//int main() {
//	int a = 1;
//	//printf("%d\n", a << 1);
//	//printf("%d\n", a << 2);
//	//printf("%d\n", a << 3);
//	printf("%d\n", a >> 1);
//	printf("%d\n", a >> 2);
//	printf("%d\n", a >> 3);
//
//
//}





//비트(기계어 한 자릿수) 연산자, 비트 시프트 
	//컴퓨터가 쓰는 연산 > 비트 연산 > 번역 과정 X
	// BIT AND, BIT OR, BIT NOT
	//논리연산과 기능은 동일
	//비트 단위 연산
//int main() {
//	int a = 15, b = 13;
//	printf("%d\n", a & b);
//	printf("%d\n", a | b);
//	printf("%d\n", ~a); // (n+1) * -1
//
//
//
//}




	//논리 연산자 > A AND B, A OR B, NOT A > 맞다(Not 0), 틀리다(0)
	//우선 순위 > 관계연산 > 논리 연산
//int main() {
//	int a = 0 && 1; //0
//	int b = 2 || 0; //1
//	printf("%d %d", a, b);
//
//	//int a = 1 < 3 && 2 < 3; // 1 < 3 AND 2 < 3; > 둘다 맞느냐?
//	//int b = 1 > 3 || 2 < 3; // 1 > 3 OR 2 < 3; > 둘중 하나라도 맞느냐?
//	//int c = !(1 < 3); // NOT 1 < 3; > 결과를 반대로 바꾸겠다
//	//printf("%d %d %d\n", a, b, c);
//
//
//}









	//관계 연산자 > 데이터의 관계에 따라 판단하는 기능
	//>, <, >=, <=, !=, ==
	//관계 연산할때는 실수를 안쓰는것이 좋음 > 계산할 때 오차가 생기는 경우가 있음
	// 
//int main() {
//	//연산자 > 모양이 정해져있음
//	// <=, >=
//	//0 > false
//	//그외 숫자 > true
//	printf("%d", 1 > 3);
//	printf("%d", 1 < 3);
//	
// 
// 
//
//}


//	//이항 연산 > 항이 2개
//	//사칙 연산자 > +,-,*,/,%,=
//	// 정수 + 정수 > 정수
//	// 실수 + 실수 > 실수
//	// 정수 + 실수 > 실수
//	// = > 자동 형변환
//  // 연산자 우선순위
//	// +,-,*,/,% > 왼쪽 > 오른쪽
//	// = > 오른쪽 > 왼쪽
//int main() {
//	int a = 5; float b = 3.0;
//	scanf_s("%d", &a); scanf_s("%f", &b);
//	printf("%d + %f =%f", a, b, a + b);
//	printf("%d + %f =%f", a, b, a - b);
//
//
//}



//int main() { // 지역 연산자 > {}
//	int a,b; // 구분 연산자 > ,
//	scanf_s("%d", &a);
//	scanf_s("%d", &b);
//	
//
//
//
//}