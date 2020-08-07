#include<stdio.h>
#include<stdlib.h>
typedef struct SC
{
	char elem;
	struct SC* next;
}StackChar,* Pchar;
void STACK_INI(Pchar* L)
{
	(*L) = (StackChar*)malloc(sizeof(StackChar));
	Pchar p = NULL;
	p = (StackChar*)malloc(sizeof(StackChar));
	(*L)->next = p;
	p->next = NULL;
	p->elem = '#';
}
void STACK_PUSH(Pchar* L, char c)
{
	Pchar p = NULL;
	p = (StackChar*)malloc(sizeof(StackChar));
	p->next = (*L)->next;
	(*L)->next = p;
	p->elem = c;
}
char STACK_POP(Pchar* L)
{
	char c;
	Pchar p = (*L)->next;
	c = p->elem;
	(*L)->next = p->next;
	free(p);
	return c;
}
char STACK_TOP(Pchar L)
{
	char c;
	Pchar p = L->next;
	c = p->elem;
	return c;
}
void STACK_OUT(Pchar* L)
{
	Pchar p = (*L)->next;
	char c = p->elem;
	while (STACK_TOP((*L)) != '#')
		printf("%c ", STACK_POP(L));
}
int main()
{
	char s[100];
	gets_s(s);
	int i, j, k;
	int temp;
	Pchar L;
	STACK_INI(&L);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//获取数字
		{
			temp = s[i] - '0';
			while (s[i + 1] != '\0')
			{
				if (s[i + 1] >= '0' && s[i + 1] <= '9')//下一位依然是数字
				{
					temp = temp * 10 + (s[i + 1] - '0');
					i++;
				}
				else
					break;
			}
			printf("%d ", temp);
		}
		else 
		{
			switch (s[i])
			{
			case '+':
				while (STACK_TOP(L) != '#' && STACK_TOP(L) != '(')
					printf("%c ", STACK_POP(&L));
				STACK_PUSH(&L, s[i]);
				break;
			case '-':
				while (STACK_TOP(L) != '#' && STACK_TOP(L) != '(')
					printf("%c ", STACK_POP(&L));
				STACK_PUSH(&L, s[i]);
				break;
			case '*':
				while (STACK_TOP(L) == '/' || STACK_TOP(L) == '*')
					printf("%c ", STACK_POP(&L));
				STACK_PUSH(&L, s[i]);
				break;
			case '/':
				while (STACK_TOP(L) == '/' || STACK_TOP(L) == '*')
					printf("%c ", STACK_POP(&L));
				STACK_PUSH(&L, s[i]);
				break;
			case ')':
				while (STACK_TOP(L) != '(')
					printf("%c ", STACK_POP(&L));
				STACK_POP(&L);
				break;
			case '(':
				STACK_PUSH(&L, s[i]);
				break;
			}
		}
	}
	STACK_OUT(&L);
	return 0;
}