#include <stdio.h>



//�Լ� Function > printf(); / scanf_s(); / malloc();
//���� ���α׷���
//�Լ� ������ ���� 2����
//����, ����
//���� > �̷��� �Լ��� ������
	//int A(int a, int b, int c) {
	//int A(int a, int b, int c);  //int[��ȯŸ��] A[�Լ��̸�](int a[�ʿ��� �Է°�]); > ����
	//	printf("%d\n", a);
	//	printf("%d\n", b);
	//	printf("%d\n", c);
	//	return a + b + c; // return X; ����� X�� �������

	//	

	//}//����
//void showgugu(); // void > ������� ������
//void showgugu() {
//
//}

// ���ڿ� ���� �Լ�

//int strlen(char* arr) {
//	int len = 0;
//	while (arr[len] != '\0') {
//		++len;
//	}
//	return len;
//	
//}
//// ���ڿ� ����
//// ������ > �ּ�
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
//// ���ڿ� ���ϱ�
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
//// ���ڿ� ��
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
	
// �Ǻ���ġ A* , Deep Learning
//��� �Լ�
//�Լ����� �ڽ��� �� ȣ���Ҷ� > ����Լ� 

//void A(int n) {
//	printf("ABCD");
//	if (n > 0)
//		A(n - 1);
//}
// 
// 
// 
// 
// �Լ��� ���� ����
// Create by �������� 2022.09.05


/// <summary>
/// �Ǻ���ġ ���� ���� �ΰ��� ���ϴ� ����
/// </summary>
/// <param name="n">ó�����ڿ� �ι�° ���ڸ� ���Ѱ�</param>
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
 /// �빮�ڸ� �ҹ��ڷ� ����
 /// </summary>
 /// <param name="c">���� 1��</param>
 /// <returns>����� ����</returns>
// char lower(char c) {
//		return ('a' <= c && c <= 'z') ? c : c + 32;
//}
// void lowerstr(char* str) {
//	 for (int i = 0; str[i]; ++i) {
//		 str[i] = lower(str[i]);
//	 }
// }

 
 
 /// <summary>
 /// �ҹ��ڸ� �빮�ڷ� ����
 /// </summary>
 /// <param name="c">���� 1��</param>
 /// <returns>����� ����</returns>
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
// /// ���ڿ��� ����ϴ� �Լ�
// /// </summary>
// /// <param name="str">����� ���ڿ�</param>
// /// <param name="length">����� ���ڿ� ����</param>
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
	//	printf("�������� ������ �� �����̴�\n");
	//	break;
	//case -1:
	//	printf("������ ������ �� �����̴�.\n");
	//	break;
	//case 0:
	//	printf("�� ���ڿ��� ����\n");

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
	//printf[�Լ��̸�]("ABCD"[�Է°�]);
	//�Լ��̸�(���ڰ�); // �Լ� ȣ�� Function Call


}