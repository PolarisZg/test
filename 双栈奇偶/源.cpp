#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,* Pnode;
void S_PUSH(Pnode* L, int e)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = (*L)->next;
	(*L)->next = p;
}
int S_POP(Pnode* L)
{
	Pnode p = (*L)->next;
	int e = p->elem;
	(*L)->next = p->next;
	free(p);
	return e;
}
void S_DelAll(Pnode* L)
{
	Pnode p = (*L)->next;
	while (p != NULL)
	{
		(*L)->next = p->next;
		free(p);
		p = (*L)->next;
	}
}
int main()
{
	int e = 0;
	Pnode L_odd = NULL;
	L_odd = (Node*)malloc(sizeof(Node));
	L_odd->next = NULL;
	Pnode L_even = NULL;
	L_even = (Node*)malloc(sizeof(Node));
	L_even->next = NULL;
/*	Pnode L = NULL;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;*/
	printf("输入数据,以999结尾：");
	while (e != 999)
	{
		scanf("%d", &e);
		if (e % 2)
			S_PUSH(&L_odd, e);
		else
			S_PUSH(&L_even, e);
	}
}