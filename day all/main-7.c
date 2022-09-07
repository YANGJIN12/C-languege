#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//������, �ּ�
//�迭���� ������
//�迭�� �������� ������ 
//������ �迭
//�����Ҵ�, �Լ�
//int arr[5];
//int *ptr;
//�迭�� �̸�(arr) > �ּ�
//������ ������ �̸�(ptr) > �ּ�
//�ּ�[N] > �ش��ϴ� �ּҿ��� ���� 1���� ũ�⸸ŭ N�� �̵��� ��ġ�� ����
//�ּ� + N > �ش��ϴ� �ּҿ��� ���� 1���� ũ�⸸ŭ N�� �̵��� ��ġ�� �ּ�

//#define Arr(arr,y,x, maxx) arr[(x) + (y) * (maxx)]

#define MAGICNUMBER 4
#define MAGICNUMBER_X 4
#define MAGICNUMBER_Y 5
#define Random(tiny, big) (rand() % ((big) - (tiny) +1) + (tiny))
// 0 ~ ��ûū ���� % big - tiny + 1, tiny = 3, big = 5
// 0 ~ 2 + tiny 3 ~ 5


int main() {
	//������
	int seed;
	scanf_s("%d", &seed);
	srand(seed);
	int map[MAGICNUMBER_X][MAGICNUMBER_Y] = { 0 }; // �迭�� �����͸� ������ �ȳ��� �κ��� �ڵ����� 0
	int succeed = 1;
	int result = 0;
	char input[256];
	do {
		system("cls"); // Clear Screen
		for (int x = 0; x < MAGICNUMBER_X; ++x) {
			for (int y = 0; y < MAGICNUMBER_Y; ++y) {
				printf("%4d", map[x][y]);
			}
			printf("\n");
		}
		// rand() > ������ ���ڸ� ���ϴ� ����
		int x = Random(0, MAGICNUMBER_X), y = Random(0, MAGICNUMBER_Y - 1);
		map[x][y] = Random(1, 100);
		Sleep(250);
		//printf("Map <<");
		//fgets(input, 256, stdin); // file get string
		//for (int i = 0; input[i]; ++i)
		//{
		//	if (input[i] == ' ') input[i] = "\0";

		//}
		//char* second = input + strlen(input) + 1;
		//char* third = second + strlen(second) + 1;
		//map[atoi((input)][atoi(second)] = atoi(third);

		/*printf(input);
		Sleep(5000);*/

		result = 0;
		for (int i = 0; i < MAGICNUMBER_Y; ++i)
			result += map[0][i];
		succeed = 1;
#if MAGICNUMBER_X == MAGICNUMBER_Y
		int resulta = result, resultb = result;
		for (int x = 0; x < MAGICNUMBER_X; ++x) {
			int temp = 0;
			for (int i = 0; i < MAGICNUMBER; ++i) {
				temp += map[x][i] + map[i][x];
				//temp += map[i][x];
				if (temp != result * 2) succeed = 0;
				resulta -= map[x][x];
				resultb -= map[x][MAGICNUMBER_X - 1 - x];
			}
			if (resulta || resultb) {
				succeed = 0;
			}
	}
#else  
		
		for (int x = 0; x < MAGICNUMBER_X; ++x) {
			int temp = 0;
			for (int i = 0; i < MAGICNUMBER_Y; ++i) {
				temp += map[i][x];
				if (temp != result) succeed = 0;
			}
		}
		for (int x = 0; x < MAGICNUMBER_X; ++x) {
			int temp = 0;
			for (int i = 0; i < MAGICNUMBER_Y; ++i) {
				temp += map[x][i];
				if (temp != result) succeed = 0;
			}
		}
#endif
	} while (!succeed);
				system("cls"); // Clear Screen
				for (int x = 0; x < MAGICNUMBER_X; ++x) {
					for (int y = 0; y < MAGICNUMBER_Y; ++y) {
						printf("%4d", map[x][y]);
					}
					printf("\n");
				}
				printf("������ ���� ��: %d\n", result);
			}
		
	//int ptr[6] = { 1,2,3,4,5,6 };
	///*int arr[2][3] = { 1,2,3,4,5,6 };
	//int* ptr = arr;*/
	//printf("%d\n",Arr(ptr, 0, 0, 3));
	//printf("%d\n",Arr(ptr, 0, 1, 3));
	//printf("%d\n",Arr(ptr, 0, 2, 3));
	//printf("%d\n",Arr(ptr, 1, 0, 3));
	//printf("%d\n",Arr(ptr, 1, 1, 3));
	//printf("%d\n",Arr(ptr, 1, 2, 3));


	//������ - �迭 ���
	//������ �迭 - ������ ��� x
	//������ > ���� ������ ����� �װ��� �ּҸ� �����ϴ� ���
	// �迭 > �̹� ������ �����ϰ� �� ��ġ�� �ּҷ� ���ϰ� ���� ���
	//int arr[2][3], arr2[5], arr3;
	//int* ptr[3];
	//int** pptr;
	//arr[0][1] = 5;
	//ptr[0] = &arr[0][0];
	//ptr[1] = &arr[0][1];
	//ptr[2] = &arr[0][2 ];
	//pptr = &ptr;
	//printf("%d\n",pptr[0][1]);
	//ptr = arr;
	//printf("%p\n", ptr[0]); // 1���� �迭�� ���°�ó�� ����� ����
	//printf("%p\n", arr[0]);
	
	//�̷л� ������ �迭�� ������ ��밡����

	/*int map[3][3] = {0,0,0,
					 0,0,0,
					 0,0,0 };
	map[0][0]; map[0][1]; map[0][2];
	map[0][0]; map[1][0]; map[2][0];*/

	/*int map[9];
	map[0]; map[1]; map[2];
	map[0]; map[3]; map[6];*/

	//int arr[5]; // arr[][][] > arr�� ������ �ƴ�
	//�迭�� �̹� �����ϴ� ������ ��ġ�� �ּҷ� ��Ÿ���� ���
	//�������� �ɰ��°��� ����
	//int arr[2][3], arr2[6];
	//arr2[5];// ���� 1���� ���� X > ���� �߿� 1�� ����
	//arr[1][1]; // ���� 1���� ���� X > ���� �߿� 1�� ����
	//printf("%p\n", arr);
	//printf("%p\n", &arr[0]);
	//printf("%p\n", &arr[0][0]);
	//printf("%p\n", arr[0][0]);
	

	//arr[1] > ����� > ������ ���� > �ּ�
	//�迭 ������ �̸� > �ּ�������
	//�迭�� �������� ������ ���� ��ǥ


	////�迭�� �������� �ѹ��� ���°� > 2���� �迭
	////�������� �迭�� ������ >  ������ �迭
	//int* ptr; // ptr[�ּ�] > �ּ�[]
	////�����ʹ� ������ ��ġ(�ּ�)�� �����ϴ� ���
	//ptr = arr; // ptr�� � �ּ��̴��� ������ ����
	//arr = ptr; // arr�� � �ּ��̴��� ������ ����
