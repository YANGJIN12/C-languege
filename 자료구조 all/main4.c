#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <conio.h>
#include <stdarg.h>
#include <windows.h>
#include <time.h>
#include <string.h>

//Double LinkedList(양방향 연결리스트)

//#define  CTT int
//typedef CTT* PCTT;
//
//struct ND {
//	CTT data;
//	struct ND* next;
//	struct ND* prev;
//};
//
//typedef struct ND ND;
//typedef ND* PND;
//
//struct DLL {
//	PND first;
//	PND end;
//};
//
//typedef DLL DLL;
//typedef DLL* PDLL;
//typedef void(*Action)(CTT);
//
//
//PDLL CDLL() {
//	PDLL result = (PDLL)malloc(sizeof(DLL));
//	memset(result, 0, sizeof(DLL));
//	return result;
//}
//
//
//void RDLL(PDLL list) {
//	PND now = list->first;
//	PND removers = 0;
//	while (now != 0) {
//		removers = now;
//		now = now->next;
//		free(removers);
//	}
//	free(list);
//
//}
//
//void INDLL(PDLL list, CTT data) {
//	PND node = (PND)malloc(sizeof(ND));
//	memset(node, 0, sizeof(ND));
//	memcpy(&node->data, &data, sizeof(CTT));
//	if (list->first == 0) {
//		list->first = node;
//		list->end = node;
//	}
//	else {
//		list->end->next = node;
//		list->prev = list->end;
//		list->end = node;
//
//	}
//}
//
//void RMDLL(PDLL list, CTT removers) {
//	PND now = list->root;
//	while (now != 0) {
//		if (now->data == removers) {
//			if (now->prev != 0) now->prev->next = now->next;
//			else list->root = now->next;
//			if (now->next != 0) now->next->prev = now->prev;
//			else list->end = now->prev;
//			free(now);
//			break;
//		}
//		now = now->next;
//	}
//}
//
//void ACDLL(PDLL list, Action action) {
//	PND now = list->root;
//	while (now != 0) {
//		action(now->data);
//		now = now->next;
//	}
//}
//
//void Show(CTT data) {
//	printf("%d >", data);
//}





typedef struct Student Student;

typedef Student ControlType;
typedef ControlType* PControlType;



struct Student {
	char name[32];
	int score;
};


struct Node {
	ControlType data;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node Node;
typedef Node* PNode;

struct DoubleLinkedList {
	PNode root;
	PNode end;
};

typedef struct DoubleLinkedList DoubleLinkedList;
typedef DoubleLinkedList* PDoubleLinkedList;
typedef void(*Action)(ControlType);





PDoubleLinkedList CreateDoubleLinkedList() {
	PDoubleLinkedList result = (PDoubleLinkedList)malloc(sizeof(DoubleLinkedList));
	memset(result, 0, sizeof(DoubleLinkedList));
	return result;
}

void ReleaseDoubleLinkedList(PDoubleLinkedList list) {
	PNode now = list->root;
	PNode remover = 0;
	while (now != 0) {
		remover = now;
		now = now->next;
		free(remover);
	}
	free(list);
}

void InsertDLL(PDoubleLinkedList list, ControlType data) {
	PNode node = (PNode)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	memcpy(&node->data, &data, sizeof(ControlType));
	if (list->root == 0) {
		list->root = node;
		list->end = node;
	}
	else {
		list->end->next = node;
		node->prev = list->end;
		list->end = node;
	}
}

void RemoveDLL(PDoubleLinkedList list, ControlType remover) {
	PNode now = list->root;
	while (now != 0) {
		if (memcmp(&now->data, &remover, sizeof(ControlType)) == 0) {
			if (now->prev != 0) now->prev->next = now->next;
			else list->root = now->next;
			if (now->next != 0) now->next->prev = now->prev;
			else list->end = now->prev;
			free(now);
			break;
		}
		now = now->next;
	}
}

//void ActionDLL(PDoubleLinkedList list, Action action) {
//	PNode now = list->root;
//	while (now != 0) {
//		action(now->data);
//		now = now->next;
//	}
//}
//
//void Show(ControlType data) {
//	
//	
//}
//
//#define ListAction(list, node) { PNode node = list->root; while(node !=0){
//#define ListActionEnd(node) node = node->next;}}

#define LAction(list, value) {PNode __values__now__ = list->root; \
PControlType value; while(__values__now__ != 0) { value = &__values__now__->data;
#define LActionEnd __values__now__ = __values__now__->next;}}
#define LIFAction(list, value, comp) LAction(list,value); if(comp){ 
#define LIFActionEnd }LActionEnd;

int Random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

const char* Name(int n) {
	switch (n) {
	case 0: return "김양진";
	case 1: return "김철수";
	case 2: return "김짱구";
	case 3: return "김유리";
	}
	return "김맹구";
}

ControlType ReturnControlType() {
	ControlType result;
	strcmp(result.name, Name(Random(0, 3)));
	result.score = Random(0, 100);
	return result;
}

int Scan() {
	int result;
	scanf_s("%d", &result);
	return result;

}


int main() {
	srand(time(0));
	PDoubleLinkedList list = CreateDoubleLinkedList();
	int select;
	while (1) {
		printf("1.추가 2.출력 3. 종료 >>>");
		select = Scan();
		if (select == 3) break;
		else if (select == 1) InsertDLL(list, ReturnControlType());
		else if (select == 2) {
			pritnf("1. 전체 2. 점수 이상 3. 최고 점수 >>>");
			select = Scan();
			if (select == 1) {
				LAction(list, now);
				printf("|%32s|%4d|\n", now->name, now->score);
				LActionEnd;
			}
			else if (select == 2) {
				printf("몇점 >>>");
				int score = Scan();
				LIFAction(list, now, now->score >= score);
				printf("|%32s|%4d|\n", now->name, now->score);
				LIFActionEnd;
			}
			else if (select == 3) {
				if (list->root != 0) {
					int large = list->root->data.score;
					LIFAction(list, now, now->score > large);
					large = now->score;
					LIFActionEnd;
					printf("최고 점수 : %d\n", large);
				}
			}

		}
	}

	for (int i = 0; i < 10; ++i) InsertDLL(list, ReturnControlType());

	

	//for (int i = 0; i < 10; ++i) InsertDLL(list, i);
	//ListAction(list, now); // {PND	now = list->root; while(now != 0) {
	//if(*now % 2 == 0)
	//printf("%d >", now->data);
	//ListActionEnd(now);// now = now->next;}}

	/*for (int i = 0; i < 10; ++i);
	LIFAction(list, now, *now % 2 == 0);
	printf("%d >", *now);
	LIFActionEnd;
	
	
	LAction(list, now); 
	*now = *now * 2;
	LActionEnd;
	
		
	LAction(list, now);
	printf("%d >", now->data);
	LActionEnd;*/


	ReleaseDoubleLinkedList(list);


	//PDoubleLinkedList list = CreateDoubleLinkedList();
	//InsertDLL(list, 1);
	//InsertDLL(list, 2);
	//InsertDLL(list, 3);
	//InsertDLL(list, 4);
	//InsertDLL(list, 5);

	//RemoveDLL(list, 1);
	//RemoveDLL(list, 5);
	//RemoveDLL(list, 2);

	//ActionDLL(list, Show);
	//ReleaseDoubleLinkedList(list);


}
