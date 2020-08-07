#include<stdio.h>
#include<stdlib.h>
typedef struct BOOK
{
	int num;
	char s[100];
}book;
typedef struct NODE
{
	book elem;
	struct NODE* next;
}Node,* Pnode;
void P_creat(Pnode* L)
{
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	Pnode tail = (*L);
	tail->next = NULL;
	Pnode p;
	Node q;
	int num, i;
	for (i = 0; i < 3; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		scanf_s("%d", &(q.elem.num));
		gets_s(q.elem.s);
		*p = q;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}
void P_out(Pnode L)
{
	Pnode p = L->next;
	while (p != NULL)
	{
		printf("%d %s\n", p->elem.num, p->elem.s);
		p = p->next;
	}
}
void P_insert(Pnode* L)
{
	Node q;
	Pnode p = (*L);
	printf("图书信息：");
	scanf_s("%d", &q.elem.num);
	gets_s(q.elem.s);
	while (p->next!=NULL&&q.elem.num > p->next->elem.num )
		p = p->next;
	Pnode t;
	t = (Node*)malloc(sizeof(Node));
	t->elem = q.elem;
	t->next = p->next;
	p->next = t;
}
void P_del(Pnode* L)
{
	int num;
	printf("书号：");
	scanf_s("%d", &num);
	Pnode p = (*L);
	while (num != p->next->elem.num)
		p = p->next;
	Pnode q = p->next;
	p->next = q->next;
	free(q);
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