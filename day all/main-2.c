#include<stdio.h> //���Խ�Ű�� Standard Input Ouput
int main() {
	//printf("Hello World!");
	//int a = 5;
	//char a[50] = "�达";
	//a = 'A';
	//a = 65;
	//short c = 3;
	//float d = 2;
		
	// d>���� , c> ���� ,s> ����, f> �Ǽ�
	// printf("a = %d \nb = %d \nd = %f",a,b,d);
	//int a;
	//float c;
	//scanf_s("%d",&a);
	//printf("%d", a);
	//printf("%p = %d",&a,a); //�ּ� Ȯ�� &p
	//scanf_s("%f",&c);
	//printf("%p = %f" ,&c,c)
	//%(number)prefix
	//��ũ�� Macro > ���� ġȯ > #define
	// ## > �̾����
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
	
	//printf("%-6s:","�̸�");
	//scanf_s("%s" ,name,30);
	
	//printf("%-6s:","������");
	//scanf_s("%f", &kg);

	//printf("%-6s <> %6s\n", "�̸�", name);
	//printf("%-6s <> %06d\n", "AGE", age);
	//printf("%-6s <> %6.2f\n", "������", kg);

	
}





















