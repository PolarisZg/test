#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,* Pnode;
int N_creat(Pnode* L, int size)
{
	(*L) = (Node*)malloc(sizeof(Node));
	if ((*L) == NULL)
		return 0;
	(*L)->next = NULL;
	int i = 0;
	Pnode p = NULL;
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
int N_out(Pnode L)
{
	if (L == NULL)
		return 0;
	Pnode p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
	return 0;
}
int N_insert(Pnode* L, int position, int elem)
{
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L);
	int i = 1;
	while (i < position && p != NULL)
	{
		p = p->next;
		i = i + 1;
	}
	if (p == NULL)
		return 0;
	Pnode q = NULL;
	q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
		return 0;
	q->elem = elem;
	q->next = p->next;
	p->next = q;
	return 1;
}
int N_del(Pnode* L, int position)
{
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L);
	int i = 1;
	while (i < position && p->next != NULL)
	{
		p = p->next;
		i = i + 1;
	}
	if (p->next == NULL)
		return 0;
	Pnode q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
int N_move(Pnode* L, int position)
{
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L);
	int i = 1;
	while (i < position && p->next != NULL)
	{
		p = p->next;
		i = i + 1;
	}
	if (p->next == NULL)
		return 0;
	Pnode q = (*L);
	while (q->next != NULL)
		q = q->next;
	q->next = (*L)->next;
	(*L)->next = p->next;
	p->next = NULL;
	return 1;
}
int main()
{
	Pnode head;
	N_creat(&(head), 3);
	N_out(head);
	int elem;
	scanf_s("%d", &elem);
	N_insert(&(head), 1, elem);
	N_out(head);
	N_del(&(head), 4);
	N_out(head);
}
