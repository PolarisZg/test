#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int name;
	int flag;
	struct Node* next;
//	int length;
}Node;

typedef struct Graph
{
	Node G[50];
	int size;
}Graph;

void Graph_in(Graph* G)
{
	scanf_s("%d", &G->size);
	int m, n, length;
	for (int i = 0; i < G->size; i++)
	{
//		G->G[i].length = 0;
		G->G[i].name = i;
		G->G[i].flag = 0;
		G->G[i].next = NULL;
	}
	while (1)
	{
		scanf_s("%d", &m);
		if (m == -999)
			break;
		scanf_s("%d", &n);
//		scanf_s("%d", &length);
		Node* p = NULL;
		p = (Node*)malloc(sizeof(Node));
		p->name = n;
//		p->length = length;
		p->next = G->G[m].next;
		G->G[m].next = p;
	}
}

int Graph_search(Graph G)//寻找入度为0的点
{
	if (G.size == 0)
		return -1;
	int node[50];
	for (int i = 0; i < G.size; i++)
		node[i] = G.G[i].flag;
	for (int i = 0; i < G.size; i++)
		if (node[i] == 0)
		{
			Node* p = NULL;
			p = G.G[i].next;
			while (p != NULL)
			{
				node[p->name] = 1;
				p = p->next;
			}
		}
	for (int i = 0; i < G.size; i++)
		if (node[i] == 0)
			return i;
	return -1;
}

void Graph_Topo(Graph* G)
{
	while (Graph_search(*G) != -1)
	{
		int TopoNode = Graph_search(*G);
		printf("%d	", TopoNode);
		G->G[TopoNode].flag = 1;
		Graph_Topo(G);
	}
}

int main()
{
	Graph G;
	Graph_in(&G);
	Graph_Topo(&G);
}