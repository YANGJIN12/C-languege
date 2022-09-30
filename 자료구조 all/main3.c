#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// �ڷ�����  > Ư���� ���
// ������ ���� > ������, ���������͸� ������ ������ 
// List > Linked List(���� ����Ʈ), Double Linked List(����� ���� ����Ʈ)

#define ControlType struct Animal

struct Animal {
	char name[32];
	char kind[32];
	int age;
};

struct Node {
	ControlType data;
	struct Node* next;
};


struct LinkedList {
	struct Node* root;
};

struct Option {
	char data[16];
};


typedef int Int;
typedef Int* Pint;
typedef struct Node Node;
typedef Node* PNode;
typedef PNode* PPNode;
typedef struct LinkedList LinkedList;
typedef LinkedList* PLinkedList;
typedef PLinkedList* PPLinkedList;
typedef struct Option Option;
typedef void(*NodeAct)(ControlType);
typedef void(*NodeActOp)(ControlType, Option);
typedef int(*NodeCheckOp)(ControlType, Option);





PLinkedList CreateLinkedList() {
	PLinkedList result = (PLinkedList)malloc(sizeof(LinkedList));
	memset(result, 0, sizeof(LinkedList));
	return result;
}

void ReleaseLinkedList(PLinkedList list) {
	PNode now = list->root;
	PNode remover;
	while (now != 0) {
		remover = now;
		now = now->next;
		free(remover);
	}
	free(list);
}

void AppendLinkedList(PLinkedList list, ControlType data) {
	PNode node = (PNode)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	memcpy(&node->data, &data, sizeof(ControlType));
	if (list->root == 0) list->root = node;
	else {
		PNode now = list->root;
		while (now->next != 0) now = now->next;
		now->next = node;
	}
}

void RemoveLinkedList(PLinkedList list, NodeCheckOp action , Option option) {
	PNode now = list->root;
	PNode prev = 0;
	while (now != 0) {
		if (action(now->data, option)) { 
			if (prev != 0) prev->next = now->next;
			else list->root = now->next;
			free(now);
			if (prev == 0) now = list->root;
			else now = prev->next;
			continue;

		}
		prev = now;
		now = now->next;
	}
}

void LinkedListAction(PLinkedList list, NodeAct action) {
	PNode now = list->root;
	while (now != 0) {
		action(now->data);
		now = now->next;
	}
}

void Show(ControlType data) {
	printf("|%32s|%32s|%5d|\n", data.name, data.kind, data.age);
}

void ShowKind(ControlType data, Option kind) {
	if (strcmp(data.kind, kind.data) == 0) Show(data);
}

void ShowAge(ControlType data, Option age) {
	void* ptr = age.data;
	if (data.age >= *((int*)ptr)) Show(data);
	}


int Check(ControlType data, Option kind) {
	return strcmp(data.kind, kind.data) == 0;
}

#define TypeSTR 0
#define TypeINT 1
Option InputOption(int type) {
	Option result;
	if (type == TypeSTR) scanf_s("%s", result.data, 32);
	else if (type == TypeINT) scanf_s("%d", result.data);
	return result;
}



void LinkedListActionOption(PLinkedList list, NodeActOp action, Option option) {
	PNode now = list->root;
	while (now != 0) {
		action(now->data, option);
		now = now->next;
	}
}


ControlType DataInput() {
	ControlType data;
	printf("�̸� >>");
	scanf_s("%s", data.name, 32);
	printf("���� >>");
	scanf_s("%s", data.kind, 32);
	printf("���� >>");
	scanf_s("%d", &data.age);
	return data;
}

int main() {
	PLinkedList list = CreateLinkedList();
	int select;
	while (1) {
		printf("1.�߰� 2.��� 3.���� 4.���� >>>");
		scanf_s("%d", &select);
		if (select == 4) break;
		else if (select == 1) AppendLinkedList(list, DataInput());
		else if (select == 2) {
			printf("1. ��ü 2. Ư�� �� 3. ���� �̻� 4.�ǵ��� ���� >>>");
			scanf_s("%d", &select);
			if (select == 4);
			else if (select == 1) LinkedListAction(list, Show);
			else if (select == 2) LinkedListActionOption(list, ShowKind, InputOption(TypeSTR));
			else if (select == 3) LinkedListActionOption(list, ShowAge, InputOption(TypeINT));

		}
		else if (select == 3) RemoveLinkedList(list, Check, InputOption(TypeSTR));
	}

	ReleaseLinkedList(list);
}