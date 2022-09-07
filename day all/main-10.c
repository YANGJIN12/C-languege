//#include <mystring.h>
//#include <mymath.h>
//#include <stdio.h>
//void PRINT(const char* p) {
	//p[0] = "A";
	//printf("A");
//}



//typedef unsigned short Date;
//const Date TUE = 0x0001;
//const Date WED = 0x0002;
//const Date THU = 0x0004;
//const Date FRI = 0x0008;
//const Date MON = 0x0010;
//const Date SAT = 0x0020;
//const Date SUN = 0x0040;

//typedef unsigned short Month;
//#define JAN = 0b0000000000000001;
//#define FEB = 0b0000000000000010;
//#define MAR = 0b0000000000000100;
//#define APR = 0b0000000000001000;
//#define MAY = 0b0000000000010000;
//#define JUN = 0b0000000000100000;
//#define JUR = 0b0000000001000000;
//#define AUG = 0b0000000010000000;
//#define SEP = 0b0000000100000000;
//#define OCT = 0b0000001000000000;
//#define NOV = 0b0000010000000000;
//#define DEC = 0b0000100000000000;
//
//#define SWITCH(type, value){ type switchcomp = value;
//#define ENDSWITCH }
//#define BCACE(value) if(switchcomp == value)
//#define CACE(value) if(switchcomp == value)

//int Count() {
//	static int a = 5; 
//	++a;
//	return a;
//}

#include <stdio.h>
#include <string.h>
char* token(char* data, char set) {
	static char* begin = 0;
	if (data != 0) begin = data;
	char* result = begin;
	begin = begin + strlen(begin) + 1;
	return result;

}






int main() {
	char ABCD[50] = "ABCD\0DEFG\0EKFN";
	printf("%s\n", token(ABCD));

	/*printf("%d", Count());*/
	//A();
	//Month ThisMonth = MAR;

	//SWITCH(Month, ThisMonth);
	//	BCACE(SEP) printf("Sep");
	//	CACE(NOV) printf("Nov");

	//switch (ThisMonth) {
	//case JAN: printf("JAN"); break;
	//case 1: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;
	//case JAN: printf("JAN"); break;

	//}
	
	
	
	//Date Today = WED; // short Today = 4;
	//Today = Today << 4 & THU;
	//if ((Today | Today >> 4) & (WED | THU | FRI)){
	//}


	/*printf("%d\n", Fibonachi(1));*/
	//const int a = 5; // 값을 바꿀수 없는 변수
	//PRINT("ABCD");
	//printf("%d", sqrt(2, 3));
	

}