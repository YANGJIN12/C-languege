#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <memory.h>
#include <time.h>

// 동적할당 그래프, 배열 그래프
// 4가지 
// 가치, 방향
// 무뱡향 그래프, 방향 그래프
// 무가치 그래프, 가치 그래프


struct GraphData {
	char name[32];
};

typedef struct GraphData GD;
typedef GD* pGD;
typedef int Int;
typedef Int* pInt;

struct Graph {
	pGD gds;
	pInt lines;
	Int size;
};

typedef struct Graph Graph;
typedef Graph* pGraph;

struct Node {
	Int index;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node Node;
typedef Node* pNode;

struct LinkedList {
	pNode root, end;
};

typedef struct LinkedList LL;
typedef LL* pLL;

#pragma warning(disable:6011)
#pragma warning(disable:6387)

pLL CreateLinkedList() {
	pLL ll = (pLL)malloc(sizeof(LL));
	memset(ll, 0, sizeof(LL));
	return ll;
}

void ReleaseLinkedList(pLL ll) {
	pNode now = ll->root;
	pNode remover;
	while (now != 0) {
		remover = now;
		now = now->next;
		free(remover);
	}
	free(ll);
}

void PushFrontLL(pLL ll, Int data) {
	pNode node = (pNode)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	node->index = data;
	if (ll->root != 0) ll->root->prev = node;
	node->next = ll->root;
	ll->root = node;

}

void PushBackLL(pLL ll, Int data) {
	pNode node = (pNode)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	node->index = data;
	if (ll->end != 0) ll->end->next = node;
	else ll->root = node;
	node->prev = ll->end;
	ll->end = node;
}

Int PopFront(pLL ll) {
	if (ll->root == 0) return -1;
	Int result = ll->root->index;
	if (ll->root == ll->end) {
		free(ll->root);
		ll->root = 0;
		ll->end = 0;
	}
	else {
		pNode remover = ll->root;
		ll->root = ll->root->next;
ll->root->prev = 0;
free(remover);
	}
	return result;
}

Int PopBack(pLL ll) {
	if (ll->end == 0) return -1;
	Int result = ll->end->index;
	if (ll->root == ll->end) {
		free(ll->end);
		ll->root = 0;
		ll->end = 0;
	}
	else {
		pNode remover = ll->end;
		ll->end = ll->end->prev;
		ll->end->next = 0;
		free(remover);
	}
	return result;
}

Int CheckLL(pLL ll, Int index) {
	pNode now = ll->root;
	while (now != 0) {
		if (now->index == index) return 1;
		now = now->next;
	}
	return 0;
}

void  CopyLL(pLL origin, pLL copy) {
	pNode now = origin->root;
	while (now != 0) {
		PushBackLL(copy, now->index);
		now = now->next;
	}
}

void ClearLL(pLL ll) {
	while (PopBack(ll) > -1);
}

pGraph CreateGraph(Int size) {
	pGraph graph = (pGraph)malloc(sizeof(Graph));
	graph->gds = (pGD)malloc(sizeof(GD) * size);
	graph->lines = (pInt)malloc(sizeof(Int) * size * size);
	graph->size = size;
	memset(graph->gds, 0, sizeof(GD) * size);
	memset(graph->lines, 0, sizeof(Int) * size * size);
	return graph;
}

void ReleaseGraph(pGraph graph) {
	free(graph->lines);
	free(graph->gds);
	free(graph);
}

pGD GetGraphData(pGraph graph, Int index) {
	return &graph->gds[index];
}

pInt GetGraphLine(pGraph graph, Int begin, Int end) {
	return &graph->lines[begin + end * graph->size];
}

void ConnectLine(pGraph graph, Int begin, Int end, Int weight) {
	*GetGraphLine(graph, begin, end) = weight;
	//*GetGraphLine(graph, end, begin) = weight;
}

void ShowConnectGraph(pGraph graph) {
	printf("=======================================\n");
	for (Int i = 0; i < graph->size; ++i) {
		printf("|%10s|", graph->gds[i].name);
		for (Int x = 0; x < graph->size; ++x) {
			if (i == x) continue;
			if (*GetGraphLine(graph, i, x) != 0) {
				printf(" > %10s[%2d]", graph->gds[x].name, *GetGraphLine(graph, i, x));
			}
		}
		printf("\n");
	}
	printf("=======================================\n");
}

Int GetLLWeights(pGraph graph, pLL ll) {
	if (ll->root == 0) return -1;
	Int result = 0;
	pNode before = ll->root;
	while (before->next != 0) {
		result += *GetGraphLine(graph, before->index, before->next->index);
		before = before->next;
	}
	return result;
}

Int Random(Int min, Int max) {
	return rand() % (max - min + 1) + min;
}

void GraphRandomLineConnect(pGraph graph, Int ConnectLines) {
	Int begin;
	Int end;
	Int weight;
	for (Int i = 0; i < ConnectLines; ++i) {
		begin = Random(0, graph->size - 1);
		end = Random(0, graph->size - 1);
		weight = Random(1, 20);

		ConnectLine(graph, begin, end, weight);
		ConnectLine(graph, end, begin, weight);
			
	}
}


void ShowLL(pGraph graph, pLL ll) {
	pNode node = ll->root;
	while (node != 0) {
		printf(">%10s", GetGraphData(graph, node->index)->name);
		node = node->next;
	}
	printf(" [%5d] \n", GetLLWeights(graph, ll));
}

void FindConnect(pGraph graph, Int before, Int goal, pLL befores, pLL result) {
	PushBackLL(befores, before);
	for (Int i = 0; i < graph->size; ++i) {
		if (!CheckLL(befores, i)) {
			if (*GetGraphLine(graph, before, i) > 0) {
				if (i == goal) {
					PushBackLL(befores, goal);
					Int llweight = GetLLWeights(graph, result);
					if (llweight > -1) {
						ShowLL(graph, result);
						if (GetLLWeights(graph, befores) < llweight) {
							ClearLL(result);
							CopyLL(befores, result);
						}
					}
					else CopyLL(befores, result);
					PopBack(befores);
				}
				else {
					FindConnect(graph, i, goal, befores, result);
				}
			}
		}
	}

	PopBack(befores);
}

	/*if (*GetGraphLine(graph, before, goal) < 1) {
		PushBackLL(befores, before);
		for (Int i = 0; i < graph->size; ++i) {
			if (!CheckLL(befores, i)) {
				if (GetGraphLine(graph, before, i) > 0) {
					FindConnect(graph, i, goal, befores); 
				}
			}
		}
		PopBack(befores);

	}
	else {
		pLL copy = CopyLL(befores);
		Int index = PopFront(copy);
		while (index != 0) {
			printf(">%10s ", GetGraphData(graph, index)->name);
			index = PopFront(copy);
		}
		printf(">%10s ", GetGraphData(graph, before)->name);
		printf(">%10s \n", GetGraphData(graph, goal)->name);
		ReleaseLinkedList(copy);

	}*/

void AtoBConnect(pGraph graph, Int begin, Int end) {
	pLL befores = CreateLinkedList();
	pLL result = CreateLinkedList();

	FindConnect(graph, begin, end, befores, result);
	ShowLL(graph, result);
	ReleaseLinkedList(befores);
	ReleaseLinkedList(result);

}


int main() {
	srand(time(0));
	pGraph graph = CreateGraph(10);
	strcpy_s(GetGraphData(graph, 0)->name, 32, "노원역");
	strcpy_s(GetGraphData(graph, 1)->name, 32, "창동역");
	strcpy_s(GetGraphData(graph, 2)->name, 32, "쌍문역");
	strcpy_s(GetGraphData(graph, 3)->name, 32, "수유역");
	strcpy_s(GetGraphData(graph, 4)->name, 32, "미아역");
	strcpy_s(GetGraphData(graph, 5)->name, 32, "미아사거리역");
	strcpy_s(GetGraphData(graph, 6)->name, 32, "길음역");
	strcpy_s(GetGraphData(graph, 7)->name, 32, "성신여대역");
	strcpy_s(GetGraphData(graph, 8)->name, 32, "한성대입구역");
	strcpy_s(GetGraphData(graph, 9)->name, 32, "청량리역");
	GraphRandomLineConnect(graph, (graph->size / 2)* (graph->size / 2));
	ShowConnectGraph(graph);

	Int A, B;
	printf(" A >>"); scanf_s("%d", &A);
	printf(" B >>"); scanf_s("%d", &B);
	AtoBConnect(graph, 3, 8);

	ReleaseGraph(graph);

	

	 
}