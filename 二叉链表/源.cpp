#include<stdio.h>
#include<stdlib.h>
typedef struct TREE
{
	int date = -1;
	struct TREE* Lchild = NULL;
	struct TREE* Rchild = NULL;
}Tree, * Ptree;
typedef struct ELME
{
	int fa;
	int ch;
	int side;
}Elme;
typedef struct NODE
{
	Elme elme;
	struct NODE* next = NULL;
}Node,* Pnode;
typedef struct QUEUE
{
	Pnode head = NULL;
	Pnode tail = NULL;
}Queue;
void T_InQueue(Queue* Q, Elme elme)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->elme = elme;
	Q->tail->next = p;
	Q->tail = p;
}
void T_OutQueue(Queue* Q)
{
	Pnode p = Q->head->next;
	Q->head->next = p->next;
	free(p);
}
void T_Creat(Tree* root)
{
	Elme elme;
	Queue Q;
	{
		Q.head = (Node*)malloc(sizeof(Node));
		Q.head->next = NULL;
		Q.tail = Q.head;
	}//初始化队列
	Ptree t = NULL;
	Ptree s = NULL;
	printf("父 子 边：以子为-1停止\n");
	scanf_s("%d%d%d", &elme.fa, &elme.fa, &elme.side);
	T_InQueue(&Q, elme);
	t = (Tree*)malloc(sizeof(Tree));
	t->date = elme.fa;
	root = t;
	while (1)
	{
		scanf_s("%d%d%d", &elme.fa, &elme.ch, &elme.side);
		s = (Tree*)malloc(sizeof(Tree));
		s->date = elme.ch;
		T_InQueue(&Q, elme);
		while (elme.fa != t->date)
		{
			
		}
		if (elme.fa == t->date)
		{
			if (elme.side == 0)
				t->Lchild = s;
			else if (elme.side == 1)
				t->Rchild = s;
		}
		if (elme.ch == -1)
			break;
	}
}