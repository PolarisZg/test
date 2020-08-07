#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	char c;
	struct NODE* next = NULL;
}Node,* Pnode;
typedef struct queue
{
	Pnode head = NULL;
	Pnode tail = NULL;
}Queue;
void H_stack_PUSH(Pnode* L, char c)//ѹջ
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->c = c;
	p->next = (*L)->next;
	(*L)->next = p;
}
char H_stack_POP(Pnode* L)//����
{
	Pnode p = (*L)->next;
	char c;
	c = p->c;
	(*L)->next = p->next;
	free(p);
	return c;
}
void H_queue_IN(Queue* Q, char c)//���
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->c = c;
	p->next = NULL;
	Q->tail->next = p;
	Q->tail = p;
}
char H_queue_OUT(Queue* Q)//����
{
	Pnode p = Q->head->next;
	Q->head->next = p->next;
	char c;
	c = p->c;
	free(p);
	return c;
}
void H_creat(Pnode* L, Queue* Q)
{
	(*L) = NULL;
	(*L) = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;
	Q->head = (Node*)malloc(sizeof(Node));
	Q->tail = Q->head;
	Q->head->next = NULL;
	for (char c = getchar(); c != '\n'; c = getchar())
	{
		H_queue_IN(Q, c);
		H_stack_PUSH(L, c);
	}
}
void H_out(Pnode* L, Queue* Q)
{
	char c;
	{
		while (Q->head->next != NULL)
		{
			c = H_queue_OUT(Q);
			printf("%c", c);
		}
	}//��ӡ����
	printf("||||||������ջ�ָ���||||||");
	{
		while ((*L)->next != NULL)
		{
			c = H_stack_POP(L);
			printf("%c", c);
		}
	}
}
int main()
{
	Pnode L;
	Queue Q;
	H_creat(&L, &Q);
	H_out(&L, &Q);
}