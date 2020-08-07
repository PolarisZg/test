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
	int flag = 0;
}Node;

typedef struct Graph
{
	Vex V[50];
	Node N[20];
	int NodeNum = 0;
	int VexNum = 0;
}Graph;

typedef struct GraphPath
{
	int VE[20];
	int VL[20];
	int E[50];
	int L[50];
	int PathN[20];
}GraphPath;

void Graph_in(Graph* G)
{
	scanf_s("%d%d", &G->NodeNum, &G->VexNum);
	for (int i = 0; i < G->NodeNum; i++)
	{
		G->N[i].name = i;
	}
	for (int i = 0; i < G->VexNum; i++)
	{
		scanf_s("%d%d%d", &G->V[i].before, &G->V[i].next, &G->V[i].length);
	}
}

int Graph_Topo_search_Bef(Graph G)
{
	int Node[20];
	for (int i = 0; i < G.NodeNum; i++)
		Node[i] = G.N[i].flag;
	for (int i = 0; i < G.VexNum; i++)
		if (G.N[G.V[i].before].flag == 0)
			Node[G.V[i].next] = 1;
	for (int i = 0; i < G.NodeNum; i++)
		if (Node[i] == 0)
			return i;
	return -1;
}

void Graph_Topo_out(Graph G)
{
	printf("------Topo-------\n");
	int NoneBef = Graph_Topo_search_Bef(G);
	while (NoneBef != -1)
	{
		printf("%d	", G.N[NoneBef].name);
		G.N[NoneBef].flag = 1;
		NoneBef = Graph_Topo_search_Bef(G);
	}
	printf("\n");
}

int Path_out(GraphPath P, int start, int end)
{
	if (start == end)
	{
		printf("%d	", start);
		return 1;
	}
	if (P.PathN[end] != -1)
		if (Path_out(P, start, P.PathN[end]) == 1)
		{
			printf("%d	", end);
			return 1;
		}
	return 0;
}
void Graph_AOE_Path(Graph G, GraphPath* P)
{
	{
		for (int i = 0; i < G.NodeNum; i++)
			P->PathN[i] = -1;
		for (int i = 0; i < G.NodeNum; i++)
			P->VE[i] = P->VL[i] = -1;
		for (int i = 0; i < G.VexNum; i++)
			P->E[i] = P->L[i] = -1;
	}
	int NoneBef = Graph_Topo_search_Bef(G);
	while (NoneBef != -1)
	{
		G.N[NoneBef].flag = 1;
		P->VE[NoneBef] = 0;
		for (int i = 0; i < G.VexNum; i++)
			if (G.V[i].next == NoneBef)
				if (G.N[G.V[i].before].flag == 1)
					if (P->VE[NoneBef] < P->VE[G.V[i].before] + G.V[i].length)
					{
						P->VE[NoneBef] = P->VE[G.V[i].before] + G.V[i].length;
						P->PathN[NoneBef] = G.V[i].before;
					}
		printf("起点到 %d 的关键路径为:",NoneBef);
		if(Path_out(*P,0,NoneBef))
			printf("\n关键路径的长度为: %d", P->VE[NoneBef]);
		printf("\n");
		NoneBef = Graph_Topo_search_Bef(G);
	}
}

int main()
{
	Graph G;
	Graph_in(&G);
	Graph_Topo_out(G);
	GraphPath P;
	Graph_AOE_Path(G, &P);
}