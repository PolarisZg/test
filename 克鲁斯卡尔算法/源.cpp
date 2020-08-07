#include<stdio.h>
#include<stdlib.h>

typedef struct Vex
{
	int before = -1;
	int next = -1;
	int length = -1;;
}Vex;

typedef struct Node
{
	int name = -1;
	struct Node* next = NULL;
}Node;

typedef struct Graph
{
	Vex V[50];
	Node N[20];
	int NodeNum = 0;
	int VexNum = 0;
}Graph;

void Graph_in(Graph* G)
{
	scanf_s("%d%d", &G->NodeNum, &G->VexNum);
	for (int i = 0; i < G->NodeNum; i++)
	{
		G->N[i].name = i;
		G->N[i].next = &G->N[i];
	}
	for (int i = 0; i < G->VexNum; i++)
	{
		scanf_s("%d%d%d", &G->V[i].before, &G->V[i].next, &G->V[i].length);
	}
}

void Graph_V_Sort(Graph* G)
{
	for(int i=0;i<G->VexNum-1;i++)
		for(int j=0;j<G->VexNum-1-i;j++)
			if (G->V[j].length > G->V[j + 1].length)
			{
				Vex V = G->V[j];
				G->V[j] = G->V[j + 1];
				G->V[j + 1] = V;
			}
}



int main()
{
	Graph G;
	Graph_in(&G);
	Graph_V_Sort(&G);
}