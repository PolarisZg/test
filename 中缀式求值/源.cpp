#include<stdio.h>
#include<stdlib.h>
typedef struct SC
{
	char elem;
	struct SC* next;
}StackChar, * Pchar;
void STACK_CHAR_INI(Pchar* L)
{
	(*L) = (StackChar*)malloc(sizeof(StackChar));
	Pchar p = NULL;
	p = (StackChar*)malloc(sizeof(StackChar));
	(*L)->next = p;
	p->next = NULL;
	p->elem = '#';
}
void STACK_CHAR_PUSH(Pchar* L, char c)
{
	Pchar p = NULL;
	p = (StackChar*)malloc(sizeof(StackChar));
	p->next = (*L)->next;
	(*L)->next = p;
	p->elem = c;
}
char STACK_CHAR_POP(Pchar* L)
{
	char c;
	Pchar p = (*L)->next;
	c = p->elem;
	(*L)->next = p->next;
	free(p);
	return c;
}
char STACK_CHAR_TOP(Pchar L)
{
	char c;
	Pchar p = L->next;
	c = p->elem;
	return c;
}
typedef struct SN
{
	int elem;
	struct SN* next;
}StackNum,* Pnum;
void STACK_NUM_INI(Pnum* L)
{
	(*L) = (StackNum*)malloc(sizeof(StackNum));
	(*L)->next = NULL;
}
void STACK_NUM_PUSH(Pnum* L, int elem)
{
	Pnum p = NULL;
	p = (StackNum*)malloc(sizeof(StackNum));
	p->elem = elem;
	p->next = (*L)->next;
	(*L)->next = p;
}
int STACK_NUM_POP(Pnum* L)
{
	Pnum p = (*L)->next;
	int elem = p->elem;
	(*L)->next = p->next;
	free(p);
	return elem;
}
void Operate(Pchar* C, Pnum* N)
{
	int a[2];
	a[0] = STACK_NUM_POP(N);
	a[1] = STACK_NUM_POP(N);
	switch (STACK_CHAR_POP(C))
	{
	case '+':
		STACK_NUM_PUSH(N, a[1] + a[0]); break;
	case '-':
		STACK_NUM_PUSH(N, a[1] - a[0]); break;
	case '*':
		STACK_NUM_PUSH(N, a[1] * a[0]); break;
	case '/':
		STACK_NUM_PUSH(N, a[1] / a[0]); break;
	}
}
void STACK_CHAR_OUT(Pchar* C, Pnum* N)
{
	Pchar p = (*C)->next;
	char c = p->elem;
	while (STACK_CHAR_TOP((*C)) != '#')
		Operate(C, N);
}
int main()
{
	char s[100];
	gets_s(s);
	int i, j, k;
	int temp;
	Pchar C;
	Pnum N;
	STACK_CHAR_INI(&C);
	STACK_NUM_INI(&N);
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
			STACK_NUM_PUSH(&N, temp);
		}
		else
		{
			switch (s[i])
			{
			case '+':
				while (STACK_CHAR_TOP(C) != '#' && STACK_CHAR_TOP(C) != '(')
					Operate(&C, &N);
				STACK_CHAR_PUSH(&C, s[i]);
				break;
			case '-':
				while (STACK_CHAR_TOP(C) != '#' && STACK_CHAR_TOP(C) != '(')
					Operate(&C, &N);
				STACK_CHAR_PUSH(&C, s[i]);
				break;
			case '*':
				while (STACK_CHAR_TOP(C) == '/' || STACK_CHAR_TOP(C) == '*')
					Operate(&C, &N);
				STACK_CHAR_PUSH(&C, s[i]);
				break;
			case '/':
				while (STACK_CHAR_TOP(C) == '/' || STACK_CHAR_TOP(C) == '*')
					Operate(&C, &N);
				STACK_CHAR_PUSH(&C, s[i]);
				break;
			case ')':
				while (STACK_CHAR_TOP(C) != '(')
					Operate(&C, &N);
				STACK_CHAR_POP(&C);
				break;
			case '(':
				STACK_CHAR_PUSH(&C, s[i]);
				break;
			}
		}
	}
	STACK_CHAR_OUT(&C, &N);
	printf("%d", STACK_NUM_POP(&N));
	return 0;
}