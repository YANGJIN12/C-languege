#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

// Stack -> 데이터의 관리법 x, 데이터의 삽입 삭제 방식
// 데이터의 삽입 순서 삭제 순서 반대



struct DataSlot {
	int number;
	char oper;
};

typedef struct DataSlot ControlType;

struct Node {
	ControlType data;
	struct Node* next;
};

typedef struct Node Node;
typedef Node* pNode;

struct Stack {
	pNode root;
	int length;
};

typedef struct Stack Stack;
typedef Stack* pStack;

pStack CreateStack() {
	pStack result = (pStack)malloc(sizeof(Stack));
	memset(result, 0, sizeof(Stack));
	return result;
}


void __del_node_from_stack__(pNode now) {
	if (now == 0) return;
	__del_node_from_stack__(now->next);
	free(now);
}


void ReleaseStack(pStack stack) {
	__del_node_from_stack__(stack->root);
	free(stack);

}

void Push(pStack stack, ControlType* data) {
	pNode node = (pNode)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	memcpy(&node->data, data, sizeof(ControlType));
	node->next = stack->root;
	stack->root = node;
	stack->length += 1;

}

ControlType* CTT() {
	static ControlType temp[10];
	static int ctt = 0;
	++ctt;
	if (ctt == 10) ctt = 0;
	return &temp[ctt];
}

ControlType* Pop(pStack stack) {
	if (stack->length == 0) return 0;
	pNode result = stack->root;
	ControlType* pre = CTT();
	memcpy(pre, &result->data, sizeof(ControlType));
	stack->root = stack->root->next;
	free(result);
	stack->length -= 1;
	return pre;

}
// 1 + 1 = 2; 중위 표현식 > 숫자 연산자 숫자
// 1 1 + = 2; 후위 표현식 > 숫자 숫자 연산자

ControlType* Last(pStack stack) {
	if (stack->length == 0) return 0;
	return &stack->root->data;
}

int OperatorOrder(char oper) {
	switch (oper) {
	case '-': case '+': return 1;
	case '*': case '/': return 2;
	case '%': return 2;
	case '^': return 5;
	case '(': return 9;
	case ')': return 0;
	}
}

int Eval(int left, int right, char oper) {
	switch (oper) {
	case '-': return left - right;
	case '+': return left + right;
	case '*': return left * right;
	case '/': return left / right;
	case '%': return left % right;
	case '^': return pow(left, right);
	}
}




int main() {
	pStack stack[4] = { CreateStack(),CreateStack(),CreateStack(),CreateStack() };
	char math[512];
	char previousoperator = 1;
	fgets(math, 512, stdin);

	for (int i = 0; math[i]; ++i) {
		if ('0' <= math[i] && math[i] <= '9') {
			if (previousoperator) {
				ControlType* temp = CTT();
				memset(temp, 0, sizeof(ControlType));
				temp->number = math[i] - '0';
				Push(stack[0], temp);
			}
			else {
				ControlType* temp = Last(stack[0]);
				temp->number = temp->number * 10 + math[i] - '0';
			}
			previousoperator = 0;
		}
		else if (
			math[i] == '+' || math[i] == '-' ||
			math[i] == '*' || math[i] == '/' ||
			math[i] == '%' || math[i] == '^' ||
			math[i] == '(' || math[i] == ')' ||
			math[i] == '{' || math[i] == '}' ||
			math[i] == '[' || math[i] == ']'
			) {
			if (math[i] == '{' || math[i] == '[') math[i] = '(';
			if (math[i] == '}' || math[i] == ']') math[i] = ')';
			ControlType* temp = CTT();
			memset(temp, 0, sizeof(ControlType));
			temp->oper = math[i];
			if (Last(stack[1]) != 0) {
				while (1) {
					ControlType* top = Last(stack[1]);
					if (top == 0) break;
					if (OperatorOrder(top->oper) >= OperatorOrder(math[i]) && top->oper != '(') {

						Push(stack[0], Pop(stack[1]));
					}
					else break;
				}
			}
			if (temp->oper == ')' ) Pop(stack[1]);
			else Push(stack[1], temp);
			previousoperator = 1;
		}
	}
	while (stack[1]->length != 0) {
		Push(stack[0], Pop(stack[1]));
	}
	while (stack[0]->length != 0) {
		Push(stack[2], Pop(stack[0]));
	}
	while (stack[2]->length != 0) {
		if (Last(stack[2])->oper == 0)
			printf("%d", Last(stack[2])->number);
		else
			printf("%c", Last(stack[2])->oper);
		if (Last(stack[2])->oper == 0) Push(stack[0], Pop(stack[2]));
		else {
			ControlType* right = Pop(stack[0]);
			ControlType* left  = Pop(stack[0]);
			ControlType* oper  = Pop(stack[2]);
			right->number = Eval(left->number, right->number, oper->oper);
			Push(stack[0], right);
		}
	}
	printf(" = %d\n", Last(stack[0])->number);

	for (int i = 0; i < 4; ++i) {
		ReleaseStack(stack);

	}
	
}