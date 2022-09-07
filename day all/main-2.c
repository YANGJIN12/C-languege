#include<stdio.h> //포함시키다 Standard Input Ouput
int main() {
	//printf("Hello World!");
	//int a = 5;
	//char a[50] = "김씨";
	//a = 'A';
	//a = 65;
	//short c = 3;
	//float d = 2;
		
	// d>정수 , c> 글자 ,s> 문장, f> 실수
	// printf("a = %d \nb = %d \nd = %f",a,b,d);
	//int a;
	//float c;
	//scanf_s("%d",&a);
	//printf("%d", a);
	//printf("%p = %d",&a,a); //주소 확인 &p
	//scanf_s("%f",&c);
	//printf("%p = %f" ,&c,c)
	//%(number)prefix
	//매크로 Macro > 글자 치환 > #define
	// ## > 이어붙임
	// 
//#define p printf
//#define s scanf_s
//#define print(text) printf(text)
//#define scan(type, value) scanf_s(type, value)
//#define scani(value) scan("%d", value)
//#define scans(value) scanf_s("%s", value, 50)
//#define scanf(value) scan("%f", value)
//#define ENTER printf("\n")
//#define scan(value) scanf_s("%d",&##value##age); scanf_s("%d",&##value##kg);
//#define printage(age) printf("AGE : %d\n" ,value##age);
//#define printdata(value, data) printf("AGE : %d\n",value##data);
//#define printage(value) printdata(value,age);
//#define printkg(value)

	//int myage, otherage, mykg, otherkg;
	//scan(my);
	//scan(other);
	//printage(my);
	//printkg(my);


#define printi(value) printf("%s <> %d\n", #value,value);
#define prints(value) printf("%s <> %s\n", #value,value);
#define printff(value) printf("%s <> %f\n", #value,value);

#define scan(type, value) scanf_s(#type, &##value);
#define scani(value) scan("%d", value);
#define scans(value) scanf_s("%s",value,50);
#define scanf(value) scan("%f",value);



	int age;
	char name[50];
	float kg;
	scani(age); scans(name); scanf(kg);
	printi(age); prints(name); printff(kg);


	




	//int age;
	//char name[50];
	//float kg;
	//printf("%-6s:", "AGE");
	//scanf_s("%d", &age);
	
	//printf("%-6s:","이름");
	//scanf_s("%s" ,name,30);
	
	//printf("%-6s:","몸무게");
	//scanf_s("%f", &kg);

	//printf("%-6s <> %6s\n", "이름", name);
	//printf("%-6s <> %06d\n", "AGE", age);
	//printf("%-6s <> %6.2f\n", "몸무게", kg);

	
}





















