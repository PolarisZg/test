#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct NODE
{
	char elem;
	struct NODE* next;
}Node, * Pnode;
void C_PUSH(Pnode* L, char e)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = (*L)->next;
	(*L)->next = p;
}
void C_OUT(Pnode L)
{
	Pnode p = L->next;
	while (p != NULL)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
void C_DelAll(Pnode* L)
{
	Pnode p = (*L)->next;
	while (p != NULL)
	{
		(*L)->next = p->next;
		free(p);
		p = (*L)->next;
	}
}
int C_read()
{
	Pnode L;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	char c;
	int i, j, k;
	printf("输入数的进制为：");
	scanf_s("%d", &i);
	printf("输入数，以#结尾：");
	c = getchar();
	k = 0;
	while (c != '#')
	{
		if (c != '\n')
			C_PUSH(&L, c);
		c = getchar();
	}
	Pnode p = L->next;
	for (j = 0; p != NULL; j++)
	{
		if (p->elem >= '0' && p->elem <= '9')
			k = k + (p->elem - '0') * pow(i, j);
		if (p->elem >= 'a' && p->elem <= 'z')
			k = k + (p->elem - 'a' + 10) * pow(i, j);
		p = p->next;
	}
	C_DelAll(&L);
	return k;
}
void C_tran(Pnode* L, int ini, int i)//i表示进制
{
	int a;
	printf("转换为%d进制为：", i);
	while (ini != 0)
	{
		a = ini % i;
		ini = ini / i;
		if (a < 10)
			C_PUSH(L, '0' + a);
		if (a >= 10)
			C_PUSH(L, 'a' + a - 10);
	}
	C_OUT(*L);
	C_DelAll(L);
}
int main()
{
	Pnode L = NULL;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	int ini = C_read();
	int i;
	for (i = 2; i <= 16; i++)
		C_tran(&L, ini, i);
	return 0;
}