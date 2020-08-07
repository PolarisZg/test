#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	char elem;
	struct NODE* next;
}Node,* Pnode;
void PUSH(Pnode* L, char c)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->elem = c;
	p->next = (*L)->next;
	(*L)->next = p;
}
char POP(Pnode* L)
{
	Pnode p = (*L)->next;
	(*L)->next = p->next;
	char c = p->elem;
	free(p);
	return c;
}
int main()
{
	char c;
	char e;
	Pnode L;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	c = getchar();
	while (c != '\n')
	{
		if (c == '[' || c == '{' || c == '(')
			PUSH(&L, c);
		if (c == ']' || c == '}' || c == ')')
		{
			if (L->next == NULL)
			{
				printf("error!");
				break;
			}
			e = POP(&L);
			if ((c == ']' && e != '[') || (c == '}' && e != '{') || (c == ')' && e != '('))
			{
				printf("error!");
				break;
			}
		}
		c = getchar();
	}
	if (c == '\n')
		printf("right!");
	return 0;
}