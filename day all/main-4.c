#include <stdio.h>

//�ڵ带 �ۼ��� �� �߿��ϰ� ����°� > ������

int main() {
	
	/*int a;
	scanf_s("%d", &a);
	printf0((a % 2 == 0) ? "¦���Դϴ�." : "Ȧ�� �Դϴ�.");*/

	//���ǹ�
	// if 
	//if (����(�Ǵܽ�)1 < 2) /*���϶��� ���� ���϶� �������*/ {
	//	printf("ù���� �ܶ�");
	//	printf("�ι��� �ܶ�");
	//	printf("������ �ܶ�");
	//	printf("�׹��� �ܶ�");
	//}
	//else/*���϶� ����*/ {
	//	printf("�ټ���° �ܶ�");
	//	printf("������° �ܶ�");
	//}
	//int number;
	//scanf_s("%d", &number);
	//if (number % 2 = 0) 
	//	if (number % 5 = 0) 
	//		printf("¦���̸鼭 5�� ����Դϴ�.\n");
	//	else 
	//		printf("¦�������� 5�� ����� �̴մϴ�.\n");

	//else 
	//	if (number % 5 == 0) 
	//		printf("Ȧ���̸鼭 5�� ����Դϴ�.\n");
	//	else 
	//		printf("Ȧ�������� 5�� ����� �ƴմϴ�.\n");
	//if (number == 1) printf("1���Դϴ�.\n");
	//else if (number == 2) printf("2���Դϴ�.\n");
	//else if (number == 3) printf("3���Դϴ�.\n");
	//else if (number == 4) printf("4���Դϴ�.\n");
	
	// switch > �����Ѵ� > ���ù�
	//int number;
	//scanf_s("%d", &number);
	//switch (/*����*/ number) {
	//case 0:
	//	printf("0���Դϴ�.\n");
	//	break;
	//case 1:
	//	printf("1���Դϴ�.\n");
	//	break;
	//case 2:
	//	printf("2���Դϴ�.\n");
	//	break;
	//case 3:
	//	printf("3���Դϴ�.\n");
	//	break;
	//case 5:
	//case 6:
	//	printf("5���Ǵ� 6���Դϴ�.\n");
	//	break;
	//default://���� ���� ��ȣ�� �ƴϸ�
	//	printf("�𸣴� ��ȣ�Դϴ�.\n");
	//	break;

	// }

	//�ڵ��� �ݺ�
	//1	Tick or 1 Frame

	//do {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "¦��" : "Ȧ��");
	//} while (/*����(�Ǵܽ�)*/ number > 0);

	////���� �ݺ���
	////Ʋ�������� �ݺ�
	//while(/*����(�Ǵܽ�)*/ number > 0) {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "¦��" : "Ȧ��");
	//}

	//int number = 1;//�ʱ⹮
	//while (number < 9) { //���ǹ�
	//	printf("%d", number);
	//	++number;//������
	//}
	//for (/*�ʱ⹮*//*���ǹ�*//*������*/int number = 0; number < 9; ++number) {
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

	//Ȧ¦ �Ǵ� 10���ϴ� ���α׷�
	////for (int i = 0; i < 10; ++i) {
	////FOR(int, i , 0 ,10){
	//FORN(10){
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "¦��" : "Ȧ��");
	//	}

	//Ȧ¦ �Ǵ� ������ �ϴ� ���α׷�(��, ������ ������ ���α׷� ����)
	//while(number > -1) {
	//	scanf_s("%d", &number);
	//	printf(number % 2 == 0 ? "¦��" : "Ȧ��");
	//}

	//������ 2�� ~ 9�ܱ��� ����ϴ� ���α׷�
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

	//����
	//���� 2�� / �Է� �� / ������ ����(���� 1�� / �Է�) / ���Ȱ� ���
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

	//���ڸ� 1 ~ 1000���� ��� ����ϴ� ���α׷�
	//�� ���α׷����� ¦���� ����ϱ�
	//�� ���α׷����� 8�� ��� �����ϱ�
	
	//int number;
	FOR(int, i, 1, 1001) {
		CONTINUEFOR(i % 2 == 1);
		CONTINUEFOR(i % 8 == 0);
		/*if (i % 2 == 0 && i % 8 != 0);*/
		printf("%5d", i);
	}
		


	


}