#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//Binary Tree > 이진 트리



struct Data {
	char name[256];
	int price;

};

typedef struct Data Data;
typedef Data* pData;
typedef void(*DataAction)(pData);
//typedef int(*DataChecker)(pData);

struct TreeData {
	int idx;
	pData data;
};

typedef struct TreeData TD;
typedef TD* pTD;

struct TreeNode {
	pTD td;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* parent;
};

typedef struct TreeNode TN;
typedef TN* pTN;

struct Tree {
	pTN root;
};

typedef struct Tree Tree;
typedef Tree* pTree;


pTree CreateTree() {
	pTree tree = (pTree)malloc(sizeof(Tree));
	memset(tree, 0, sizeof(Tree));
	return tree;
}

// 재귀 함수


void __insert_tree_node__(pTN parent, pTN insert) {
	if (parent->td->idx < insert->td->idx) {
		if (parent->right != 0) __insert_tree_node__(parent->right, insert);
		else {
			parent->right = insert;
			insert->parent = parent;
		}
	}
	else if(parent->td->idx > insert->td->idx) {
		if (parent->left != 0) __insert_tree_node__(parent->left, insert);
		else {
			parent->left = insert;
			insert->parent = parent;
		}
	}
	else {
		free(parent->td->data);
		free(parent->td);
		parent->td = insert->td;
		free(insert);
	}
}

void Insert(pTree tree, int idx, pData data) {
	pTD td = (pTD)malloc(sizeof(TD));
	memset(td, 0, sizeof(TD));
	td->data = data;
	td->idx = idx;
	pTN tn = (pTN)malloc(sizeof(TN));
	memset(tn, 0, sizeof(TN));
	tn->td = td;
	if (tree->root == 0) tree->root = tn;
	else __insert_tree_node__(tree->root, tn);
};

void __remove_tree_node__(pTN node) {
	if (node == 0) return;
	__remove_tree_node__(node->left);
	__remove_tree_node__(node->right);
	free(node->td->data);
	free(node->td);
	free(node);

}

void ReleaseTree(pTree tree) {
	__remove_tree_node__(tree->root);
	free(tree);

}

pData GetData(const char* text, int price) {
	pData data = (pData)malloc(sizeof(Data));
	memset(data, 0, sizeof(Data));
	strcpy_s(data->name, 256, text);
	data->price = price;
	return data;
}

int MinIdx(pTN tn) {
	if (tn->left != 0) return MinIdx(tn->left);
	else return tn->td->idx;
}

pTD __del_tn__(pTree tree, pTN tn, int target) {
	if (tn == 0) return 0;
	if (tn->td->idx < target) return __del_tn__(tree, tn->right, target);
	else if (tn->td->idx > target) return __del_tn__(tree, tn->left, target);
	else {
		if (tn->left == 0 && tn->right == 0) { // 양쪽 다 데이터가 없을 때
			pTD td = tn->td;
			if (tn->parent != 0) {
				if (tn->parent->left == tn) tn->parent->left = 0;
				else tn->parent->right = 0;
			}
			else tree->root = 0;
			free(tn);
			return td;
		}
		else if (tn->left == 0) { // 오른쪽에 데이터가 있을 때
			if (tn->parent != 0) {
				if (tn->parent->left == tn) {
					tn->parent->left = tn->right;
					tn->right->parent = tn->parent;
				}
				else {
					tn->parent->right = tn->right;
					tn->right->parent = tn->parent;
				}
			}
			else {
				tree->root = tn->right;
				tn->right->parent = 0;
			}
			pTD td = tn->td;
			free(tn);
			return td;
		}
		else if (tn->right == 0) { // 왼쪽에 데이터가 있을 때
			if (tn->parent != 0) {
				if (tn->parent->left == tn) {
					tn->parent->left = tn->left;
					tn->left->parent = tn->parent;
				}
				else {
					tn->parent->right = tn->left;
					tn->left->parent = tn->parent;
				}
			}
			else {
				tree->root = tn->left;
				tn->left->parent = 0;
			}
			pTD td = tn->td;
			free(tn);
			return td;
		}
		else { // 양쪽 다 데이터가 있을 때
			int idx = MinIdx(tn->right);
			pTD td = __del_tn__(tree, tn->right, idx);
			pTD td2 = tn->td;
			tn->td = td;
			return td2;
		}
	}
}

void Remove(pTree tree, int idx) {
	pTD td = __del_tn__(tree, tree->root, idx);
	free(td->data);
	free(td);

}

void __action_node_all__(pTN tn, DataAction action) {
	if (tn == 0) return;
	__action_node_all__(tn->left, action);
	action(tn->td->data);
	__action_node_all__(tn->right, action);
}

void ActionAll(pTree tree, DataAction action) {
	__action_node_all__(tree->root, action);
}

void Show(pData data) {
	printf("|%32s|%7d|\n", data->price);
}


//시간 복잡도 - 자료구조의 데이터 검색 시간
//최선, 평균, 최악

double Timer() {
	static clock_t before, after;
	after = clock();
	double result = (after - before) / 1000.0;
	before = after;
	return result;
}

//void BI(pTree tree, int now, int gap) {
//	char temp[256];
//	sprintf_s(temp, 256, "%3d", now);
//	Insert(tree, now, GetData(temp));
//	if (gap == 0) return;
//	BI(tree, now - gap, gap / 2);
//	BI(tree, now + gap, gap / 2);
//
//}

//pTN __find_idx__(pTN tn, Datachecker checker) {
//	if (tn == 0) return 0;
//	pTN result;
//	result = __find_idx__(tn->left, checker);
//	if (result != 0) return result;
//	result = __find_idx__(tn->right, checker);
//	if (result != 0) return result;
//	if (checker(result->td->data)) return tn;
//	return 0;
//	
//}
//
//int FindIdx(pTree tree, DataChecker checker) {
//	pTN tn = __find_idx__(tree->root, checker);
//	if (tn == 0) return -1;
//	return tn->td->idx;
//
//}

int main() {
	pTree tree = CreateTree();
	int select;
	


	/*BI(tree, 20, 10);
	Remove(tree, 10);
	ActionAll(tree, Show);*/

	while (1) {
		printf("1.책 추가 2. 책 전체 출력 3. 책 삭제 4. 종료 >>>");
		scanf_s("%d", &select);
		if (select == 4) break;
		else if (select == 1) {
			int number, price;
			char name[256];
			printf("책 번호 >>>");
			scanf_s("%d", &number);
			printf("책 이름 >>>");
			scanf_s("%s", name, 256);
			printf("책 가격 >>>");
			scanf_s("%d", &price);
			Insert(tree, number, GetData(name, price));

		}
		else if (select == 2) ActionAll(tree, Show);
		else if (select == 3) {
			printf("책 번호 >>>");
			scanf_s("%d", &select);
			Remove(tree, select);

		}
	}

	ReleaseTree(tree);
}