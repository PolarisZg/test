#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Graph
{
	char name[50][50];
	int Matrix[50][50];
	int Node_num = 0;
}Graph;
void undiricted_graph_in(Graph* G)
{
	printf("结点个数:");
	scanf_s("%d", &G->Node_num);
	getchar();
	for (int i = 0; i < G->Node_num; i++)
	{
		printf("第%d个结点名称:", i + 1);
		gets_s(G->name[i]);
		for (int j = 0; j < G->Node_num; j++)
			G->Matrix[i][j] = 0;
	}
	char a[50];
	for (int i = 0; i < G->Node_num; i++)
	{
		printf("输入与%s连接的结点:\n",G->name[i]);
		while(1)
		{
			gets_s(a);
			if (a[0] == '#')
				break;
			for(int j=0;j<G->Node_num;j++)
				if (strcmp(a, G->name[j]) == 0)
				{
					G->Matrix[i][j] = 1;
					break;
				}
		}
	}
}
void undiricted_graph_out(Graph G)
{
	printf("图例:\n");
	for (int i = 0; i < G.Node_num; i++)
		printf("%c: %s\n", 'A' + i, G.name[i]);
	printf("   ");
	for (int i = 0; i < G.Node_num; i++)
		printf("%c ", 'A' + i);
	printf("\n");
	for (int i = 0; i < G.Node_num; i++)
	{
		printf("%c  ", 'A' + i);
		for (int j = 0; j < G.Node_num; j++)
			printf("%d ", G.Matrix[i][j]);
		printf("\n");
	}
}
int undiricted_graph_NodeNum(Graph G, char* target)
{
	int NodeNum = 0;
	for (int i = 0; i < G.Node_num; i++)
		if (strcmp(G.name[i], target) == 0)
		{
			for (int j = 0; j < G.Node_num; j++)
				if (G.Matrix[i][j] == 1)
					NodeNum++;
			return NodeNum;
		}
}
void undiricted_graph_DFS(Graph G, char* target, int* flag)
{
	printf("%s ", target);
	for (int i = 0; i < G.Node_num; i++)
		if (strcmp(G.name[i], target) == 0)
		{
			flag[i] = 1;
			for (int j = 0; j < G.Node_num; j++)
				if (G.Matrix[i][j] == 1 && flag[j] == 0)
					undiricted_graph_DFS(G, G.name[j], flag);
			break;
		}
}
void undiricted_graph_BFS(Graph G, char* target,int* flag)
{
	for (int i = 0; i < G.Node_num; i++)
		if (strcmp(G.name[i], target) == 0)
		{
			int head = 0;
			int tail = 0;
			int Queue[50];
			Queue[tail] = i;
			tail++;
			flag[i] = 1;
			printf("%s ", target);
			while (head != tail)
			{
				for (int j = 0; j < G.Node_num; j++)
					if (G.Matrix[Queue[head]][j] == 1 && flag[j] == 0)
					{
						printf("%s ", G.name[j]);
						Queue[tail] = j;
						tail++;
						flag[j] = 1;
					}
				head++;
			}
		}
}
int main()
{
	Graph G;
	undiricted_graph_in(&G);
	undiricted_graph_out(G);
	char target[50];
	printf("给定结点为:");
	gets_s(target);
	int NodeNum = undiricted_graph_NodeNum(G, target);
	printf("给定结点“%s”的度为%d\n", target, NodeNum);
	int flag[50];
	for (int i = 0; i < G.Node_num; i++)
		flag[i] = 0;
	printf("DFS:");
	for (int i = 0; i < G.Node_num; i++)
	{
		if(flag[i]==0)
			undiricted_graph_DFS(G, G.name[i], flag);
	}
	printf("\n");
	printf("BFS:");
	for (int i = 0; i < G.Node_num; i++)
		flag[i] = 0;
	for (int i = 0; i < G.Node_num; i++)
	{
		if (flag[i] == 0)
			undiricted_graph_BFS(G, target, flag);
	}
}