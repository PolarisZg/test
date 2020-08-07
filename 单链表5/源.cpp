#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,* Pnode;
void P_creat(Pnode* L)
{
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	int i;
	Pnode p = NULL;
	for (i = 0; i < 3; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->elem = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
void P_out(Pnode L)
{
	Pnode p;
	p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}
void P_insert(Pnode* L)
{
	Pnode p;
	p = (Node*)malloc(sizeof(Node));
	p->elem = 666;
	p->next = (*L)->next;
	(*L)->next = p;
}
void P_del(Pnode* L)
{
	Pnode p = (*L)->next;
	(*L)->next = p->next;
	free(p);
}
int main()
{
	Pnode L;
	P_creat(&L);
	P_out(L);
	P_insert(&L);
	P_out(L);
	P_del(&L);
	P_out(L);
}