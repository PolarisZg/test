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
		return 0;//��ʼ��ʧ��
	S->top = -1;
	return 1;
}
int STRACK_EMPTY(SqStrack S)//�շ���1
{
	if (S.top == -1)
		return 1;
	return 0;
}
int STRACK_FULL(SqStrack S)//������1
{
	if (S.top == S.Maxsize - 1)
		return 1;
	return 0;
}
int STRACK_PUSH(SqStrack* S, Elemtype e)
{
	if (STRACK_FULL(*S))
		return 0;//�޷�ѹջ
	S->elem[++S->top] = e;
	return 1;
}
int STRACK_POP(SqStrack* S, Elemtype* e)
{
	if (STRACK_EMPTY(*S))
		return 0;//�޵���Ԫ��
	e = &(S->elem[S->top--]);
	return 1;
}
