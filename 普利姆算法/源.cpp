#include<stdio.h>
#include<stdlib.h>

typedef struct Graph
{
	int size = 0;
	int vex[50][50];
}Graph;

typedef struct Prime
{
	Graph G;
	int Node[50][3];
}Prime;

void Graph_in(Graph* G)
{
	int VexNum = 0;
	scanf_s("%d%d", &G->size, &VexNum);
	for (int i = 0; i < G->size; i++)
		for (int j = 0; j < G->size; j++)
		{
			G->vex[i][j] = -1;
			G->vex[i][i] = 0;
		}
	for (int i = 0; i < VexNum; i++)
	{
		int n, m;
		scanf_s("%d%d", &n, &m);
		scanf_s("%d", &G->vex[n - 1][m - 1]);
		G->vex[m - 1][n - 1] = G->vex[n - 1][m - 1];
	}
}

void Graph_Pri_ini(Graph G, Prime* P)
{
	/*
	辅助点集：
	二维数组第一个下标：结点的标号
	二维数组的第二个下标：
						0：点是否在普利姆树内，是为1
						1：该点所连边的另一端点的标号
						2：边的权重
	*/
	for (int i = 0; i < G.size; i++)
	{
		for (int j = 0; j < G.size; j++)
			P->G.vex[i][j] = -1;
		P->G.vex[i][i] = 0;
		P->Node[i][0] = 0;
		P->Node[i][1] = -1;
		P->Node[i][2] = -1;
	}
}
void Graph_Pri(Graph G, Prime* P, int NewNode)
{
	if (P->G.size != G.size - 1)//原树与新建立的普利姆树结点个数不同时，普利姆树开始生长
	{
		{
			//用新节点去刷新普利姆算法的辅助点集
			P->Node[NewNode][0] = 1;
			//P->Node[NewNode][2] = 999;
			for (int i = 0; i < G.size; i++)
			{
				if (P->Node[i][0] == 0)//该节点没被加入普利姆树
					if (G.vex[i][NewNode] != -1)//新节点与该节点之间有边
						if (G.vex[i][NewNode] < P->Node[i][2] || P->Node[i][2] == -1)//新节点与该节点之间的边更小或之前该节点就没连上其他点
						{
							P->Node[i][1] = NewNode;
							P->Node[i][2] = G.vex[i][NewNode];
						}

			}
		}
		int MinNode = -1;
		{
			//找出辅助点集中权重最小的边
			for (int i = 0; i < G.size; i++)
				if (P->Node[i][0] == 0)
					if (P->Node[i][2] != -1)
					{
						if (MinNode == -1)
							MinNode = i;
						else if (P->Node[MinNode][2] > P->Node[i][2])
							MinNode = i;
					}
		}
		P->G.size++;//普利姆树的结点个数+1
		P->G.vex[MinNode][P->Node[MinNode][1]] = P->Node[MinNode][2];
		P->G.vex[P->Node[MinNode][1]][MinNode] = P->Node[MinNode][2];//树长出一个结点
		Graph_Pri(G, P, MinNode);
	}
}

void Graph_out(Graph G)
{
	printf("--------------------\n    ");
	for (int i = 0; i < G.size; i++)
		printf("%4d", i + 1);
	for (int i = 0; i < G.size; i++)
	{
		printf("\n%4d", i + 1);
		for (int j = 0; j < G.size; j++)
			printf("%4d", G.vex[i][j]);
	}
	printf("\n--------------------\n");
}
int main()
{
	Graph G;
	Graph_in(&G);
	Graph_out(G);
	Prime P;
	Graph_Pri_ini(G, &P);
	Graph_Pri(G, &P, 0);
	Graph_out(P.G);
}