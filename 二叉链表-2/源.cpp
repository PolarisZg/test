#include<stdio.h>
#include<stdlib.h>
//定义树
typedef struct TREE
{
	int date = -1;
	struct TREE* Lchild = NULL;
	struct TREE* Rchild = NULL;
}Tree, * Ptree;

//定义队列，队列中元素为树
typedef struct NODE
{
	Ptree t;
	struct NODE* next = NULL;
}Node, * Pnode;
typedef struct QUEUE
{
	Pnode head = NULL;
	Pnode tail = NULL;
}Queue;

//入队
void T_InQueue(Queue* Q, Ptree t)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->t = t;
	p->next = NULL;
	Q->tail->next = p;
	Q->tail = p;
}

//出队
void T_OutQueue(Queue* Q)
{
	Pnode p = Q->head->next;
	Q->head->next = p->next;
	free(p);
}

//基于读边法创建单链表
void T_Creat(Ptree* root)
{
	int fa, ch, side;
	Queue Q;
	{
		Q.head = (Node*)malloc(sizeof(Node));
		Q.head->next = NULL;
		Q.tail = Q.head;
	}//初始化队列
	Ptree t = NULL;
	Ptree s = NULL;
	printf("父 子 边：以子为-1停止\n");
	scanf_s("%d%d%d", &fa, &ch, &side);
	t = (Tree*)malloc(sizeof(Tree));
	t->date = ch;
	t->Lchild = t->Rchild = NULL;
	T_InQueue(&Q, t);
	*root = t;
	while (1)
	{
		s = NULL;
		scanf_s("%d%d%d", &fa, &ch, &side);
		if (ch == -1)
			break;
		s = (Tree*)malloc(sizeof(Tree));
		s->date = ch;
		s->Lchild = s->Rchild = NULL;
		T_InQueue(&Q, s);
		while (fa != t->date)
		{
			T_OutQueue(&Q);
			t = Q.head->next->t;
		}
		if (fa == t->date)
		{
			if (side == 0)
				t->Lchild = s;
			else if (side == 1)
				t->Rchild = s;
		}
	}
}

//树的叶子数
int T_leavesNum(Ptree t)
{
	if (t == NULL)
		return 0;
	else if (t->Lchild == NULL && t->Rchild == NULL)
		return 1;
	else
		return (T_leavesNum(t->Lchild) + T_leavesNum(t->Rchild));
}

//树的结点数
int T_nodeNum(Ptree t)
{
	if (t == NULL)
		return 0;
	else if (t->Lchild == NULL && t->Rchild == NULL)
		return 1;
	else
		return (1 + T_nodeNum(t->Lchild) + T_nodeNum(t->Rchild));
}

//树的深度
int T_deepth(Ptree t)
{
	if (t == NULL)
		return 0;
	else if (t->Lchild == NULL && t->Rchild == NULL)
		return 1;
	else
		return ((T_deepth(t->Lchild) > T_deepth(t->Rchild)) ? 1 + T_deepth(t->Lchild) : 1 + T_deepth(t->Rchild));
}

//层次遍历输出二叉树的结点值
void T_output(Ptree root)
{
	Queue Q;
	{
		Q.head = (Node*)malloc(sizeof(Node));
		Q.head->next = NULL;
		Q.tail = Q.head;
	}//初始化队列
	Ptree t = NULL;
	Ptree s = NULL;
	t = root;
	T_InQueue(&Q, t);
	while (Q.head->next != NULL)
	{
		s = Q.head->next->t;
		printf("%d ", s->date);
		if (s->Lchild != NULL)
			T_InQueue(&Q, s->Lchild);
		if (s->Rchild != NULL)
			T_InQueue(&Q, s->Rchild);
		T_OutQueue(&Q);
	}
}

void T_DLR(Ptree t, int deepth)
{
	if (t != NULL)
	{
		for (int i = 0; i <= deepth; i++)
			printf("  ");
		printf("%d", t->date);
		printf("\n");
		T_DLR(t->Lchild, deepth + 1);
		printf("\n");
		T_DLR(t->Rchild, deepth + 1);
	}
}

int main()
{
	Tree* root = NULL;
	T_Creat(&root);
	printf("Num of leaves is %d\n", T_leavesNum(root));
	printf("Num of nodes is %d\n", T_nodeNum(root));
	printf("Deepth of tree is %d\n", T_deepth(root));
	printf("层次遍历:");
	T_output(root);
	printf("\nDLR:\n");
	T_DLR(root, 0);
}