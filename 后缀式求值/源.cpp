#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elem;
	struct NODE* next;
}Node,* Pnode;
void STACK_OUT(Pnode* L)
{
	Pnode p = (*L)->next;
	while (p != NULL)
	{
		printf("%d", p->elem);
		p = p->next;
	}
	printf("\n");
}
void STACK_PUSH(Pnode* L, int elem)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->next = (*L)->next;
	p->elem = elem;
	(*L)->next = p;
//	STACK_OUT(L);
}
int STACK_POP(Pnode* L)
{
	int elem;
	Pnode p = (*L)->next;
	(*L)->next = p->next;
	elem = p->elem;
	free(p);
	return elem;
}
int getANSWER(Pnode* L, char* s)
{
	(*L) = NULL;
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	int i;
	for (i = 0; s[i] != '#'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			STACK_PUSH(&(*L), s[i] - '0');
		if (s[i] == '+')
			STACK_PUSH(&(*L), STACK_POP(&(*L)) + STACK_POP(&(*L)));
		if (s[i] == '-')
			STACK_PUSH(&(*L), 0 - STACK_POP(&(*L)) + STACK_POP(&(*L)));
		if (s[i] == '*')
			STACK_PUSH(&(*L), STACK_POP(&(*L)) * STACK_POP(&(*L)));
		if (s[i] == '/')
			STACK_PUSH(&(*L), (1.0 / (1.0 * STACK_POP(&(*L))) * (1.0 * STACK_POP(&(*L)))));
	}
	return STACK_POP(&(*L));
}
int main()
{
	char s[100];
	Pnode L;
	gets_s(s);
	printf("%d", getANSWER(&L, s));
	return 0;
}