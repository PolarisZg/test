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
		printf("输入与%s连接的结点:\n", G->name[i]);
		while (1)
		{
			gets_s(a);
			if (a[0] == '#')
				break;
			for (int j = 0; j < G->Node_num; j++)
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
	printf("        ");
	for (int i = 0; i < G.Node_num; i++)
		printf("%s ", G.name[i]);
	printf("\n");
	for (int i = 0; i < G.Node_num; i++)
	{
		printf("%s ", G.name[i]);
		for (int j = 0; j < G.Node_num; j++)
			printf("%6d", G.Matrix[i][j]);
		printf("\n");
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

void undiricted_graph_BFS(Graph G, char* target, int* flag)
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

void undiricted_graph_InsNode(Graph* G)
{
	printf("新加入结点为:");
	gets_s(G->name[G->Node_num]);
	G->Node_num++;
	for (int i = 0; i < G->Node_num; i++)
		G->Matrix[G->Node_num - 1][i] = G->Matrix[i][G->Node_num - 1] = 0;
}

void undiricted_graph_InsMa(Graph* G)
{
	char name[50];
	printf("新加入边的一个端点为:");
	gets_s(name);
	int m, n;
	for (int i = 0; i < G->Node_num; i++)
		if (strcmp(G->name[i], name) == 0)
			m = i;
	printf("新加入边的另一个端点为:");
	gets_s(name);
	for (int i = 0; i < G->Node_num; i++)
		if (strcmp(G->name[i], name) == 0)
			n = i;
	G->Matrix[m][n] = G->Matrix[n][m] = 1;
}

int SearchNode(Graph G, int* Flag, int start, int end, int* Path, int length, int* Length)
{
	if (start == end)
	{
		Path[length] = start;
		*Length = length;
		return 1;
	}
	else
	{
		Flag[start] = 1;
		Path[length] = start;
		for (int i = 0; i < G.Node_num; i++)
		{
			if (G.Matrix[start][i] == 1)
			{
				if (Flag[i] == 0)
				{
					if (SearchNode(G, Flag, i, end, Path, length + 1,Length) == 1)
						return 1;
				}
			}
		}
		return 0;
	}
}
void undiricted_graph_searchPath(Graph G)
{
	char StartNode[50];
	char EndNode[50];
	printf("start:");
	gets_s(StartNode);
	while (StartNode[0] != '#')
	{
		printf("end:");
		gets_s(EndNode);
		int start;
		int end;
		int Path[50];
		int Flag[50];
		int Length;
		int PathNum = 0;
		for (int i = 0; i < G.Node_num; i++)
		{
			if (strcmp(G.name[i], StartNode) == 0)
				start = i;
			if (strcmp(G.name[i], EndNode) == 0)
				end = i;
			Flag[i] = 0;
		}
		if (SearchNode(G, Flag, start, end, Path, 0, &Length))
			for (int i = 0; i <= Length; i++)
				printf("%s	", G.name[Path[i]]);
		else
			printf("不存在");
		printf("\nstart:");
		gets_s(StartNode);
	}
}
void BFS_AND_DFS(Graph G)
{
	int flag[50];
	{
		for (int i = 0; i < G.Node_num; i++)
			flag[i] = 0;
		printf("DFS:");
		for (int i = 0; i < G.Node_num; i++)
		{
			if (flag[i] == 0)
				undiricted_graph_DFS(G, G.name[i], flag);
		}
		printf("\n");
		printf("BFS:");
		for (int i = 0; i < G.Node_num; i++)
			flag[i] = 0;
		for (int i = 0; i < G.Node_num; i++)
		{
			if (flag[i] == 0)
				undiricted_graph_BFS(G, G.name[i], flag);
		}
		printf("\n");
	}//DFS与BFS
}

int main()
{
	Graph G;
	undiricted_graph_in(&G);
	undiricted_graph_out(G);
	BFS_AND_DFS(G);
	undiricted_graph_InsNode(&G);
	BFS_AND_DFS(G);
	undiricted_graph_InsMa(&G);
	BFS_AND_DFS(G);
	undiricted_graph_searchPath(G);
}