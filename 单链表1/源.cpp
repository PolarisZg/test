/*�½�
  ����
  ɾ��
  ����
  ����
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char c;
	int a;
}ElemType;//����������
typedef struct LNode
{
	ElemType data;//������
	struct LNode* next;//����
}Node,* Pnode;
/*int L_Creat(Pnode *p_list,int size)
  p_listָ��һ�������ָ�룬�˴������ͷ��ַ
  sizeҪ��������������Ĵ�С
  ���ܣ�����һ����СΪsize������
  �ɹ�����1��ʧ�ܷ���0
  */
int L_Creat(Pnode* p_list, int size)//Pnode* p_list�ɻ�ΪNode*��*p_list)
{
    Pnode p = NULL;
    int i;
    *p_list = (Node*)malloc(sizeof(Node));//Node*Ҳ���Ի���Pnode
    if (*p_list == NULL)
        return 0;
    (*p_list)->next = NULL;
    for (i = 0; i < size; i++)
    {
        p = (Pnode)malloc(sizeof(Node));
        if (p == NULL)
            return 0;
        p->next = (*p_list)->next;
        (*p_list)->next = p;
    }
    return 1;
}

/*int L_Insert(Pnode list,int position,ElemType elem)
  �ڱ�list��positionλ�ò�������elem
  listҪ�������ݵĵ�����
  position����Ԫ�ص�λ�ã���1����
  elemҪ���������
  �ɹ�����1��ʧ�ܷ���0
  */
int L_Insert(Pnode list, int position, ElemType elem)
{
    Pnode p, q;
    int i;
    p = list;
    for (i = 0; p != NULL && i < position - 1; i++)
        p = p->next;
    if (p == NULL || i > position - 1)
        return 0;

}