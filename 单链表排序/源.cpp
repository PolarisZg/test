#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int elme;
	struct NODE* next;
}Node,*Pnode;
void Sort_in(Pnode* L)
{
	(*L) = NULL;
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	Pnode p = NULL;
	Pnode q = NULL;
	q = (*L);
	int size;
	scanf_s("%d", &size);
	scanf_s("%d", &(q->elme));//ɾȥ����Ϊ��ͷ���
	for (int i = 0; i < size-1; i++)//for (int i = 0; i < size; i++)��ͷ���
	{
		p = (Node*)malloc(sizeof(Node));
		scanf_s("%d", &(p->elme));
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
void Sort_out(Pnode L)
{
	for (Pnode p = L; p != NULL || printf("\n") && 0; p = p->next)//for(Pnode p=L->next;p!=NULL;p=p->next)��ͷ���
		printf("%d ", p->elme);
}
void Sort(Pnode* L, Pnode* S)
{
	(*S) = NULL;
	(*S) = (Node*)malloc(sizeof(Node));
	(*S)->next = NULL;
	Pnode q;
	for (Pnode p; (*L) != NULL;)//for (Pnode p; (*L)->next != NULL;)��ͷ���
	{
		q = (*S);
		p = (*L);//p = (*L)->next;��ͷ���
		(*L) = p->next;//(*L)->next = p->next;��ͷ���
		while (q->next!=NULL&&q->next->elme<=p->elme)
			q = q->next;
		p->next = q->next;
		q->next = p;
	}
	q = (*S);//ɾȥ����Ϊ��ͷ���
	(*S) = (*S)->next;//ɾȥ����Ϊ��ͷ���
	free(q);//ɾȥ����Ϊ��ͷ���
}
int main()
{
	Pnode L;
	Pnode S;
	Sort_in(&L);
	Sort_out(L);
	Sort(&L, &S);
	Sort_out(S);
}