#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	char elme;
	struct NODE* next = NULL;
}Node,* Pnode;
typedef struct Queue
{
	Pnode head = NULL;
	Pnode tail = NULL;
}Queue;
void PUSH(Pnode* L, char elme)
{
	Pnode q = NULL;
	q = (Node*)malloc(sizeof(Node));
	q->next = (*L)->next;
	(*L)->next = q;
	q->elme = elme;
}
char POP(Pnode* L)
{
	Pnode p = (*L)->next;
	char elme = p->elme;
	(*L)->next = p->next;
	free(p);
	return elme;
}
void IN(Queue* s, char elme)
{
	Pnode p;
	p = (Node*)malloc(sizeof(Node));
	p->elme = elme;
	Pnode q = s->tail;
	q->next = p;
	s->tail = p;
}
char OUT(Queue* s)
{
	Pnode p = s->head->next;
	char elme = p->elme;
	s->head->next = p->next;
	free(p);
	return elme;
}
int main()
{
	char elme, c;
	Pnode L = NULL;
	Queue s;
	L = (Node*)malloc(sizeof(Node));
	s.head = (Node*)malloc(sizeof(Node));
	L->next = s.head->next = NULL;
	s.tail = s.head;
	for (c = getchar(); c != '\n'; c = getchar())
	{
		PUSH(&L, c);
		IN(&s, c);
	}
	int i = 0;
	while(L->next != NULL)
	{
		if (POP(&L) == OUT(&s))
			i = 1;
		else
		{
			i = 0;
			break;
		}
	}
	if (i)
		printf("1");
	else
		printf("0");
}