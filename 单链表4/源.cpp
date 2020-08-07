#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node, * Pnode;
void P_creat(Pnode* L)
{
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	int i;
	Pnode p = NULL;
	for (i = 0; i < 10; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->elem = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
void P_out(Pnode L)
{
	Pnode p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}
void P_move(Pnode* L)
{
	int i, pos;
	printf("Î»ÖÃÎª£º");
	scanf_s("%d", &pos);
	Pnode p = (*L)->next;
	while (p->next != NULL)
		p = p->next;
	p->next = (*L)->next;
	for (i = 1; i < pos ; i++)
		p = p->next;
	(*L)->next = p->next;
	p->next = NULL;
}
int main()
{
	Pnode L;
	P_creat(&L);
	P_out(L);
	P_move(&L);
	P_out(L);
}