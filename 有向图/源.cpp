#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct NODE
{
	int location;
	struct NODE* next;
}Node,* Pnode;
typedef struct Graph
{
	char name[50][50];
	Node node[50];
	int Node_num;
}Graph;
void G_creat(Graph* G)
{
	printf("结点个数:");
	scanf_s("%d", &G->Node_num);
	getchar();
	for (int i = 0; i < G->Node_num; i++)
	{
		printf("第%d个结点名称:", i + 1);
		gets_s(G->name[i]);
		G->node[i].location = i;
		G->node[i].next = NULL;
	}
	char a[50];
	for (int i = 0; i < G->Node_num; i++)
	{
		printf("输入与%s连接的结点:\n", G->name[i]);
		while (1)
		{
			gets_s(a);
			if (a[0] == '#')
				break;
			for (int j = 0; j < G->Node_num; j++)
				if (strcmp(a, G->name[j]) == 0)
				{
					Pnode n = NULL;
					n = (Node*)malloc(sizeof(Node));
					n->location = j;
					n->next = G->node[i].next;
					G->node[i].next = n;
					break;
				}
		}
	}
}
void G_out(Graph G)
{
	printf("输出:\n");
	for (int i = 0; i < G.Node_num; i++)
	{
		printf("%s: ", G.name[i]);
		Pnode p = G.node[i].next;
		while (p != NULL)
		{
			printf("%s ", G.name[p->location]);
			p = p->next;
		}
		printf("\n");
	}
}
int G_nodeNum(Graph G, char* target)
{

	for (int i = 0; i < G.Node_num; i++)
		if (strcmp(G.name[i], target) == 0)
		{
			int NodeNum = 0;
			Pnode p = G.node[i].next;
			while (p != NULL)
			{
				NodeNum++;
				p = p->next;
			}
			return NodeNum;
		}
}
void G_DFS(Graph G, char* target, int* flag)
{
	printf("%s ", target);
	for(int i=0;i<G.Node_num;i++)
		if (strcmp(G.name[i], target) == 0)
		{
			flag[i] = 1;
			Pnode p = G.node[i].next;
			while (p != NULL)
			{
				if (flag[p->location] == 0)
					G_DFS(G, G.name[p->location], flag);
				p = p->next;
			}
			break;
		}
}
void G_BFS(Graph G, char* target, int* flag)
{
	for (int i = 0; i < G.Node_num; i++)
		if (strcmp(G.name[i], target) == 0)
		{
			flag[i] = 1;
			int Queue[50];
			int head = 0;
			int tail = 0;
			Queue[tail] = i;
			tail++;
			printf("%s ", target);
			while (head != tail)
			{
				Pnode p = G.node[Queue[head]].next;
				while (p != NULL)
				{
					if (flag[p->location] == 0)
					{
						printf("%s ", G.name[p->location]);
						flag[p->location] = 1;
						Queue[tail] = p->location;
						tail++;
					}
					p = p->next;
				}
				head++;
			}
			break;
		}
}
int main()
{
	Graph G;
	G_creat(&G);
	G_out(G);
	printf("给定节点为:");
	char target[50];
	gets_s(target);
	int NodeNum = G_nodeNum(G, target);
	printf("给定结点%s的度为%d\n",target,NodeNum);
	int flag[50];
	for (int i = 0; i < G.Node_num; i++)
		flag[i] = 0;
	printf("DFS:");
	for (int i = 0; i < G.Node_num; i++)
		if (flag[i] == 0)
			G_DFS(G, G.name[i], flag);
	printf("\n");
	for (int i = 0; i < G.Node_num; i++)
		flag[i] = 0;
	printf("BFS:");
	for (int i = 0; i < G.Node_num; i++)
		if (flag[i] == 0)
			G_BFS(G, G.name[i], flag);
	printf("\n");
}