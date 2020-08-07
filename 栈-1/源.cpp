#include<stdio.h>
#include<stdlib.h>
typedef struct ELEM
{

}Elemtype;
typedef struct STACK
{
	Elemtype* elem = NULL;
	int Maxsize;
	int top;
}SqStrack;
int STRACK_INI(SqStrack* S)
{
	printf("%d", &(S->Maxsize));
	S->elem = (Elemtype*)malloc(sizeof(Elemtype) * S->Maxsize);
	if (S->elem == NULL)
		return 0;//初始化失败
	S->top = -1;
	return 1;
}
int STRACK_EMPTY(SqStrack S)//空返回1
{
	if (S.top == -1)
		return 1;
	return 0;
}
int STRACK_FULL(SqStrack S)//满返回1
{
	if (S.top == S.Maxsize - 1)
		return 1;
	return 0;
}
int STRACK_PUSH(SqStrack* S, Elemtype e)
{
	if (STRACK_FULL(*S))
		return 0;//无法压栈
	S->elem[++S->top] = e;
	return 1;
}
int STRACK_POP(SqStrack* S, Elemtype* e)
{
	if (STRACK_EMPTY(*S))
		return 0;//无弹出元素
	e = &(S->elem[S->top--]);
	return 1;
}
