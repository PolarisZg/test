#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	char elem[30];
	struct NODE* next;
}Node,*Pnode;
void P_creat(Pnode* L, int size)
{
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	Pnode p;
	int i;
	for (i = 0; i < size; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		gets_s((*L)->elem);
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
		printf("%s\n", (p->elem));
		p = p->next;
	}
}
int main()
{
	Pnode L;
	P_creat(&L, 3);
	P_out(L);
}