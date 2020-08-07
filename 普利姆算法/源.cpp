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
	�����㼯��
	��ά�����һ���±꣺���ı��
	��ά����ĵڶ����±꣺
						0�����Ƿ�������ķ���ڣ���Ϊ1
						1���õ������ߵ���һ�˵�ı��
						2���ߵ�Ȩ��
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
	if (P->G.size != G.size - 1)//ԭ�����½���������ķ����������ͬʱ������ķ����ʼ����
	{
		{
			//���½ڵ�ȥˢ������ķ�㷨�ĸ����㼯
			P->Node[NewNode][0] = 1;
			//P->Node[NewNode][2] = 999;
			for (int i = 0; i < G.size; i++)
			{
				if (P->Node[i][0] == 0)//�ýڵ�û����������ķ��
					if (G.vex[i][NewNode] != -1)//�½ڵ���ýڵ�֮���б�
						if (G.vex[i][NewNode] < P->Node[i][2] || P->Node[i][2] == -1)//�½ڵ���ýڵ�֮��ı߸�С��֮ǰ�ýڵ��û����������
						{
							P->Node[i][1] = NewNode;
							P->Node[i][2] = G.vex[i][NewNode];
						}

			}
		}
		int MinNode = -1;
		{
			//�ҳ������㼯��Ȩ����С�ı�
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
		P->G.size++;//����ķ���Ľ�����+1
		P->G.vex[MinNode][P->Node[MinNode][1]] = P->Node[MinNode][2];
		P->G.vex[P->Node[MinNode][1]][MinNode] = P->Node[MinNode][2];//������һ�����
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