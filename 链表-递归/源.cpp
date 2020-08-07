#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elme = 0;
	struct NODE* next;
}Node,* Pnode;
void Reini(Pnode* L)
{
	(*L) = NULL;
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
}
void Renew(Pnode p, int n, int size)
{
	if (n < size)
	{
		n = n + 1;
		Node* q;
		q = NULL;
		q = (Node*)malloc(sizeof(Node));
		q->elme = n;
		p->next = q;
		Renew(q, n, size);
	}
	else
		p->next = NULL;
}
void Reout(Pnode p)
{
	if (p != NULL)
	{
		printf("%d\n", p->elme);
		Reout(p->next);
	}
}
void Renum(Pnode p, int n)
{
	if (p->next != NULL)
		Renum(p->next, ++n);
	else
		printf("%d", n);
}
void RedelALL(Pnode* L)
{
	if ((*L)->next != NULL)
	{
		Pnode p = (*L)->next;
		(*L)->next = p->next;
		free(p);
		RedelALL(L);
	}
}
/*void Resum(Pnode p, int sum)
{
	if (p != NULL)
	{
		sum = sum + p->elme;
		Resum(p->next, sum);
	}
	else
		printf("\n%d\n", sum);
}*/
void sum(Pnode p, int sum1)
{
	if (p == NULL)
	{

	}
	else
	{
		sum1 = sum1 + p->elme;
		sum(p->next, sum1);
		printf("%d", sum1);
	}
}
int main()
{
	Pnode L;
	Reini(&L);
	Renew(L, 0, 5);
	Reout(L->next);
	printf("----------\n");
	Renum(L, 0);
//	Resum(L->next, 0);
	sum(L->next, 0);
	RedelALL(&L);
	return 0;
}