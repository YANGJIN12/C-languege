#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//포인터, 주소
//배열과의 유사점
//배열과 포인터의 차이점 
//다차원 배열
//동적할당, 함수
//int arr[5];
//int *ptr;
//배열의 이름(arr) > 주소
//포인터 변수의 이름(ptr) > 주소
//주소[N] > 해당하는 주소에서 변수 1개의 크기만큼 N번 이동한 위치의 변수
//주소 + N > 해당하는 주소에서 변수 1개의 크기만큼 N번 이동한 위치의 주소

//#define Arr(arr,y,x, maxx) arr[(x) + (y) * (maxx)]

#define MAGICNUMBER 4
#define MAGICNUMBER_X 4
#define MAGICNUMBER_Y 5
#define Random(tiny, big) (rand() % ((big) - (tiny) +1) + (tiny))
// 0 ~ 엄청큰 숫자 % big - tiny + 1, tiny = 3, big = 5
// 0 ~ 2 + tiny 3 ~ 5


int main() {
	//마방진
	int seed;
	scanf_s("%d", &seed);
	srand(seed);
	int map[MAGICNUMBER_X][MAGICNUMBER_Y] = { 0 }; // 배열에 데이터를 넣을때 안넣은 부분은 자동으로 0
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
		// rand() > 무작위 숫자를 구하는 공식
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
				printf("마법진 성공 합: %d\n", result);
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


	//포인터 - 배열 비슷
	//다차원 배열 - 포인터 비슷 x
	//포인터 > 새로 변수를 만들고 그곳에 주소를 저장하는 방식
	// 배열 > 이미 변수는 존재하고 그 위치를 주소로 편하게 쓰는 방식
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
	//printf("%p\n", ptr[0]); // 1차원 배열을 쓰는것처럼 사용이 가능
	//printf("%p\n", arr[0]);
	
	//이론상 다차원 배열은 무한히 사용가능함

	/*int map[3][3] = {0,0,0,
					 0,0,0,
					 0,0,0 };
	map[0][0]; map[0][1]; map[0][2];
	map[0][0]; map[1][0]; map[2][0];*/

	/*int map[9];
	map[0]; map[1]; map[2];
	map[0]; map[3]; map[6];*/

	//int arr[5]; // arr[][][] > arr은 변수가 아님
	//배열은 이미 존재하는 변수의 위치를 주소로 나타내는 방식
	//여러개로 쪼개는것이 가능
	//int arr[2][3], arr2[6];
	//arr2[5];// 변수 1개를 선택 X > 묶음 중에 1개 선택
	//arr[1][1]; // 변수 1개를 선택 X > 묶음 중에 1개 선택
	//printf("%p\n", arr);
	//printf("%p\n", &arr[0]);
	//printf("%p\n", &arr[0][0]);
	//printf("%p\n", arr[0][0]);
	

	//arr[1] > 결과물 > 묶음이 나옴 > 주소
	//배열 변수의 이름 > 주소인이유
	//배열은 여러개의 변수를 묶은 대표


	////배열을 묶은것을 한번더 묶는것 > 2차원 배열
	////여러개의 배열을 묶은것 >  다차원 배열
	//int* ptr; // ptr[주소] > 주소[]
	////포인터는 변수의 위치(주소)를 저장하는 방식
	//ptr = arr; // ptr에 어떤 주소이던지 넣을수 있음
	//arr = ptr; // arr에 어떤 주소이던지 넣을수 없음
