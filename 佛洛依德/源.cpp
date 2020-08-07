#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct MGraph
{
	char name[50][50];
	int vex[50][50];
	int FloVex[50][50];
	int G_Path[50][50];
	int size = 0;
}MGraph;

void Graph_in(MGraph* G)
{
	//printf("输入结点个数:");
	scanf_s("%d", &G->size);
	getchar();
	for (int i = 0; i < G->size; i++)
	{
		//printf("输入第%d个结点名称:\n", i);
		gets_s(G->name[i]);
		for (int j = 0; j < G->size; j++)
		{
			G->vex[i][j] = G->FloVex[i][j] = -1;
			G->G_Path[i][j] = -1;
		}
		G->vex[i][i] = G->FloVex[i][i] = 0;
	}
	for (int i = 0; i < G->size; i++)
	{
		char name[50];
		//printf("输入与%s相连的结点名称:\n");
		gets_s(name);
		while (name[0] != '#')
		{
			for(int j=0;j<G->size;j++)
				if (strcmp(name, G->name[j]) == 0)
				{
					//printf("输入权重:");
					scanf_s("%d", &G->vex[i][j]);
					getchar();
					G->FloVex[i][j] = G->vex[i][j];
					break;
				}
			gets_s(name);
		}
	}
}

void Graph_out(MGraph G)
{
	printf("--------------------------\n     ");
	for (int i = 0; i < G.size; i++)
		printf("%5s", G.name[i]);
	for (int i = 0; i < G.size; i++)
	{
		printf("\n%5s", G.name[i]);
		for (int j = 0; j < G.size; j++)
			printf("%5d", G.FloVex[i][j]);
	}
	printf("\n--------------------------\n");
}

void Graph_Flo(MGraph* G)
{
	for (int midNode = 0; midNode < G->size; midNode++)
		for(int i=0;i<G->size;i++)
			for (int j = 0; j < G->size; j++)
				if(G->FloVex[i][midNode]!=-1&&G->FloVex[midNode][j]!=-1)
					if (G->FloVex[i][midNode] + G->FloVex[midNode][j] < G->FloVex[i][j] || G->FloVex[i][j] == -1)
					{
						G->FloVex[i][j] = G->FloVex[i][midNode] + G->FloVex[midNode][j];
						G->G_Path[i][j] = midNode;
					}
}

void Graph_Path(MGraph G, int start, int end)
{
	if (G.G_Path[start][end] == -1)
		printf("--->%s", G.name[end]);
	else
	{
		int MidNode = G.G_Path[start][end];
		Graph_Path(G, start, MidNode);
		Graph_Path(G, MidNode, end);
	}
}
int main()
{
	MGraph G;
	Graph_in(&G);
	Graph_out(G);
	Graph_Flo(&G);
	printf("佛洛依德算法后:\n");
	//Graph_out(G);
	for(int i=0;i<G.size;i++)
		for (int j = 0; j < G.size; j++)
		{
			printf("路径:");
			printf("%s", G.name[i]);
			Graph_Path(G, i, j);
			printf("	路径长度:%d", G.FloVex[i][j]);
			printf("\n");
		}
}