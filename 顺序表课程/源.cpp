//����˳���洢�ṹ��д��ʼ�������룻ɾ������������� ����������ʵ�ֹ���
#include<stdio.h>
#include<stdlib.h>
typedef struct
{

}Element;
typedef struct
{
	Element* E = NULL;
	int length;
	int listsize;
}SqList;
int Apply(SqList* L)
{
	int i;
	printf("input the space of list:");
	scanf_s("%d", &i);
	L->E = (Element*)malloc(sizeof(Element) * i);
	if (L->E == NULL)
		return 0;
	L->length = 0;
	L->listsize = i;
	return 1;
}
void Out(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		outputE(L.E[i]);
}
void outputE(Element e)
{
	printf("    ");
}
void Search(SqList* L)
{

}