#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE
{
	int elme;
	int length;
	struct NODE* next;
}Node,*Pnode;
typedef struct graph
{
	char name[50][50];
	int NodeNum = 0;
	Node node[50];
}Graph;
typedef struct SET
{
	int length = 0;//已经计算的结点个数
	int NewNode = -1;//新加入结点的位置
	int Node[50][2];//0结点权重，1结点是否被读取
}Set;
void D_graph_in(Graph* G)
{
	//printf("图结点个数:");
	scanf_s("%d", &G->NodeNum);
	getchar();
	for (int i = 0; i < G->NodeNum; i++)
	{
		gets_s(G->name[i]);
		G->node[i].elme = i;
		G->node[i].next = NULL;
		G->node[i].length = 0;
	}
	for (int i = 0; i < G->NodeNum; i++)
	{
		//printf("与%s相连的点及权重:\n");
		char a[50];
		while (1)
		{
			gets_s(a);
			if (a[0] == '#')
				break;
			for(int j=0;j<G->NodeNum;j++)
				if (strcmp(a, G->name[j]) == 0)
				{
					Pnode p = NULL;
					p = (Node*)malloc(sizeof(Node));
					p->next = G->node[i].next;
					p->elme = j;
					//printf("%s与%s之间的权重为:");
					scanf_s("%d", &p->length);
					getchar();
					G->node[i].next = p;
					break;
				}
		}
	}
}
void D_graph_out(Graph G)
{
	printf("---------------------\n");
	for (int i = 0; i < G.NodeNum; i++)
	{
		printf("%s:", G.name[i]);
		Pnode p = G.node[i].next;
		while (p != NULL)
		{
			printf("%s %d	", G.name[p->elme], p->length);
			p = p->next;
		}
		printf("\n");
	}
	printf("---------------------\n");
}
void D_ini(Graph G, Set* s)
{
	char a[50];
	//printf("输入起点:");
	gets_s(a);
	int i = 0;
	int j = 0;
	Pnode p = NULL;
	for (i = 0; i < G.NodeNum; i++)
	{
		if (strcmp(a, G.name[i]) == 0)
		{
			s->Node[i][0] = 0;
			s->Node[i][1] = 1;
			s->length = 1;
			s->NewNode = i;
			p = G.node[i].next;
		}
		else
		{
			s->Node[i][0] = -1;
			s->Node[i][1] = 0;
		}
	}
	while (p != NULL)
	{
		s->Node[p->elme][0] = p->length;
		p = p->next;
	}
}
int D_search_Min(Set s,Graph G)
{
	int MinLocation = -1;
	for(int i=0;i<G.NodeNum;i++)
		if(s.Node[i][0]>0)
			if (s.Node[i][1] == 0)
				if (MinLocation == -1|| s.Node[MinLocation][0] > s.Node[i][0])
					MinLocation = i;
	return MinLocation;
}
void D_Refresh(Graph G, Set* s)
{
	Pnode p = G.node[s->NewNode].next;
	while (p != NULL)
	{
		if (s->Node[p->elme][1] == 0)
			if (s->Node[p->elme][0]<0 || s->Node[p->elme][0]>(p->length + s->Node[s->NewNode][0]))
				s->Node[p->elme][0] = (p->length + s->Node[s->NewNode][0]);
		p = p->next;
	}
}
void D(Graph G, Set* s)
{
	if (s->length != G.NodeNum)
	{
		int MinLocation = D_search_Min(*s, G);
		if (MinLocation != -1)
		{
			s->NewNode = MinLocation;
			s->Node[MinLocation][1] = 1;
			s->length++;
			D_Refresh(G, s);
			D(G, s);
		}
	}
}
void D_out(Graph G, Set s)
{
	printf("----------------\n");
	for (int i = 0; i < s.length; i++)
		if (s.Node[i][1] == 1)
			printf("%s %d\n", G.name[i], s.Node[i][0]);
}
int main()
{
	Graph G;
	Set s;
	D_graph_in(&G);
	D_graph_out(G);
	D_ini(G, &s);
	D(G, &s);
	D_out(G, s);
}
/*
代码中已经将printf注释掉。
输入的数据，测试的图为：
7
A
B
C
D
E
F
G
B
12
F
16
G
14
#
A
12
F
7
C
10
#
B
10
F
6
E
5
D
3
#
C
3
E
4
#
D
4
C
5
F
2
G
8
#
A
16
B
7
C
6
E
2
G
9
#
E
8
F
9
A
14
#
按下回车，然后会显示以邻接表存储的图：
---------------------
A:G 14  F 16    B 12
B:C 10  F 7     A 12
C:D 3   E 5     F 6     B 10
D:E 4   C 3
E:G 8   F 2     C 5     D 4
F:G 9   E 2     C 6     B 7     A 16
G:A 14  F 9     E 8
---------------------
接下来输入起点，测试所用：
D
按下回车，接下来显示为各店到起点的最短距离：
----------------
A 22
B 13
C 3
D 0
E 4
F 6
G 12
*/