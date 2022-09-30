#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>


// ť FIFO -> �������� �ڷᱸ��
// �ܹ��� ���Ḯ��Ʈ -> �Ϲ� ť
// �迭 -> ��ȯ ť

//�Ϲ� ť
//struct ControlType {
//	char name[32];
//	int price;
//	
//	
//};
//
//typedef struct ControlType CT;
//typedef CT* pCT;
//
//
//struct Node {
//	pCT data;
//	struct Node* next;
//};
//
//typedef struct Node Node;
//typedef Node* pNode;
//
//struct Que {
//	pNode root;
//	pNode end;
//};
//
//typedef struct Que Que;
//typedef Que* pQue;
//
//pQue CreateQue() {
//	pQue que = (pQue)malloc(sizeof(Que));
//	memset(que, 0, sizeof(Que));
//	return que;
//}
//
//void ReleaseQue(pQue que) {
//	pNode node = que->root;
//	pNode remover;
//	while (node != 0) {
//		remover = node;
//		node = node->next;
//		free(remover->data);
//		free(remover);
//	}
//	free(que);
//}
//
//void PushQue(pQue que, pCT ct) {
//	pNode node = (pNode)malloc(sizeof(Node));
//	memset(node, 0, sizeof(Node));
//	node->data = ct;
//	if (que->end != 0) que->end->next = node;
//	else que->root = node;
//	que->end = node;
//}
//
//pCT PopQue(pQue que) {
//	if (que->root == 0) return 0;
//	pCT ct = que->root->data;
//	pNode remover = que->root;
//	que->root = que->root->next;
//	if (que->root == 0) que->end = 0;
//	free(remover);
//	return ct;
//}
//
//pCT CreateCT(char* name, int price) {
//	pCT ct = (pCT)malloc(sizeof(CT));
//	memset(ct, 0, sizeof(CT));
//	strcpy_s(ct->name, 32, name);
//	ct->price = price;
//	return ct;
//}
//
//int EmptyQue(pQue que) {
//	return que->root == 0;
//}
//
//int main() {
//	pQue que = CreateQue();
//	char name[32];
//	int price, select;
//	while (1) {
//		printf("1. ��ǰ �԰� 2. ��ǰ �Ǹ� 3. ���� >>>");
//		scanf_s("%d", &select);
//		if (select == 3) break;
//		else if (select == 1) {
//			printf("��ǰ �� >>>");
//			scanf_s("%s", name, 32);
//			printf("��ǰ ���� >>>");
//			scanf_s("%d", price);
//			PushQue(que, CreateCT(name, price));
//		}
//		else if (select == 2) {
//			pCT ct = PopQue(que);
//			if (ct == 0) printf("�Ǹ��� ��ǰ�� �����ϴ�.\n");
//			else {
//				printf("%s ��ǰ�� %d �������� �ǸŵǾ����ϴ�.\n", ct->name, ct->price);
//				free(ct);
//			}
//
//		}
//	}
//
//
//	ReleaseQue(que);
//
//}

//Ű���� ����
// �����ڷε� ������ �Է½� ��� �빮�ڷ� �����Ͽ� ���
// �빮�ڷε� Ű �Է½� ����
// Ư������ �Է½� ����
// �ִ� 16���� ���� �Է� ����
// ���� �Է� �ð��� 2�� ����
// ���ҹ��� �տ� %�� �پ������� �ҹ��� �״�� ���

//��ȯ ť
struct ControlType{
	char data;
};
typedef struct ControlType CT;
typedef CT* pCT;

struct Que {
	pCT datas;
	int length;
	int push, pop;
};

typedef struct Que Que;
typedef Que* pQue;

pQue CreateQue(int size) {
	pQue que = (pQue)malloc(sizeof(Que));
	memset(que, 0, sizeof(Que));
	que->datas = (pCT)malloc(sizeof(CT) * size);
	que->length = size;
	return que;
}

void ReleaseQue(pQue que) {
	free(que->datas);
	free(que);
}

int QueIndex(pQue que, int index) {
	return index % que->length;

}

int PushQue(pQue que, pCT ct) {
	if (QueIndex(que, que->push + 1) == QueIndex(que, que->pop)) return 0;
	memcpy(&que->datas[que->push], ct, sizeof(CT));
	que->push = QueIndex(que, que->push + 1);
}

pCT PopQue(pQue que) {
	if (que->pop == que->push) return 0;
	pCT ct = &que->datas[que->pop];
	que->pop = QueIndex(que, que->pop + 1);
	return ct;
}

pCT CreateCT(char data) {
	static CT temp;
	memset(&temp, 0, sizeof(CT));
	temp.data = data;
	return &temp;
}

double Timer() {
	static clock_t before, after;
	double result;
	after = clock();
	result = (after - before) / 1000.0;
	before = after;
	return result;
}

int main() {
	pQue que = CreateQue(17);
	double timer = 0, poptimer = 2.0;
	Timer();
	while (1) {
		timer += Timer();
		if (timer >= poptimer) {
			pCT bct = 0;
			pCT ct = PopQue(que);
			while (ct != 0) {
				if ('a' <= ct->data && ct->data <= 'z')
					if (bct != 0 && bct->data == '%')
						_putch(ct->data);
					else
						_putch(ct->data - 32);
				else
					_putch(ct->data);
				bct = ct;
				ct = PopQue(que);
			}
			_putch('\n');
			timer -= poptimer;
		}
		else if (_kbhit()) { // kbhit > Ű���� �Է� ����
			char temp = _getch();
			if (('a' <= temp && temp <= 'z') || temp == '%')PushQue(que, CreateCT(temp));
			else if (('A' <= temp && temp <= 'Z') || temp == '|' || temp  == '&' || temp == '^');
		}
	}
	ReleaseQue(que);

}
	//pQue que = CreateQue(32);
	//char name[32];
	//int price, select;
	//while (1) {
	//	printf("1. ��ǰ �԰� 2. ��ǰ �Ǹ� 3. ���� >>>");
	//	scanf_s("%d", &select);
	//	if (select == 3)break;
	//	else if (select == 1) {
	//		printf("��ǰ �� >>");
	//		scanf_s("%s", name, 32);
	//		printf("��ǰ ���� >>");
	//		scanf_s("%d", &price);
	//		PushQue(que, CreateCT(name, price));
	//	}
	//	else if (select == 2) {
	//		pCT ct = PopQue(que);
	//		if (ct == 0) printf("�Ǹ��� ��ǰ�� �����ϴ�.\n");
	//		else {
	//			printf("%s ��ǰ�� %d �������� �ǸŵǾ����ϴ�.\n", ct->name, ct->price);
	//		
	//		}
	//	}
	//}
	//ReleaseQue(que);



