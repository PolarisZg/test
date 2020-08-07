#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,*Pnode;
int N_creat(Pnode* L)
{
	(*L) = (Node*)malloc(sizeof(Node));
	if ((*L) == NULL)
		return 0;
	(*L)->next = NULL;
	int size, i;
	Pnode p = NULL;
	scanf_s("%d", &size);
	for (i = 0; i < size; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
			return 0;
		scanf_s("%d", &(p->elem));
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return 1;
}
void N_out(Pnode L)
{
	Pnode p = NULL;
	p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}
void N_MERGE(Pnode La, Pnode Lb, Pnode* Lc)//small->big
{
	(*Lc) = (Node*)malloc(sizeof(Node));
	(*Lc)->next = NULL;
	Pnode p = La->next;
	Pnode q = Lb->next;
	Pnode r = NULL;
	while (p != NULL && q != NULL)
	{
		r = (Node*)malloc(sizeof(Node));
		if (p->elem > q->elem)
		{
			r->elem = p->elem;
			p = p->next;
		}
		else
		{
			r->elem = q->elem;
			q = q->next;
		}
		r->next = (*Lc)->next;
		(*Lc)->next = r;
	}
	while (p != NULL)
	{
		r = (Node*)malloc(sizeof(Node));
		r->elem = p->elem;
		p = p->next;
		r->next = (*Lc)->next;
		(*Lc)->next = r;
	}
	while (q != NULL)
	{
		r = (Node*)malloc(sizeof(Node));
		r->elem = q->elem;
		q = q->next;
		r->next = (*Lc)->next;
		(*Lc)->next = r;
	}
}
int main()
{
	Pnode La, Lb, Lc;
	La = Lb = Lc = NULL;
	N_creat(&La);
	N_out(La);
	N_creat(&Lb);
	N_out(Lb);
	N_MERGE(La, Lb, &Lc);
	N_out(Lc);
}