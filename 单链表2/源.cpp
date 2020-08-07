#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,* Pnode;
int N_creat_head(Pnode* L, int size)
{
	(*L) = (Node*)malloc(sizeof(Node));
	if ((*L) == NULL)
		return 0;
	(*L)->next = NULL;
	Pnode p = NULL;
	int i = 0;
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
	return 1;
}
int N_lenth(Pnode L)
{
	if (L == NULL)
		return 0;
	Pnode p = L->next;
	int i;
	for (i = 0; p != NULL; i++)
		p = p->next;
	return i;//i的值为链表中含有元素的个数
}
void N_del_all(Pnode* L)
{
	Pnode p = (*L);
	Pnode q = NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}

}
int N_insert(Pnode* L, int elem, int i)
{
	int j = i;
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L);
	for (; j > 1 && p != NULL; j--)
		p = p->next;
	if (j > 0 && p == NULL)
		return 0;
	Pnode q = NULL;
	q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
		return 0;
	q->next = p->next;
	q->elem = elem;
	p->next = q;
	return 1;
}
int N_search_elem(Pnode* L, int elem)
{
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L)->next;
	while(p != NULL&&elem!=p->elem)
		p = p->next;
	if (p == NULL)
		return 0;
	return 1;
}
int N_del_elem(Pnode* L, int elem)
{
	if ((*L) == NULL)
		return 0;
	Pnode p = (*L);
	while (p->next != NULL && elem != p->next->elem)
		p = p->next;
	if (elem == p->next->elem)
	{
		Pnode q = p->next;
		p->next = q->next;
		free(q);
		return 1;
	}
	return 0;
}
int main()
{
	Pnode L;
	N_creat_head(&L, 3);
	N_out(L);
	N_insert(&L, 666, 1);
	N_out(L);
	N_del_elem(&L, 1);
	N_out(L);
	return 0;
}