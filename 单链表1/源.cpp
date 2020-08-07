/*新建
  插入
  删除
  长度
  查找
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char c;
	int a;
}ElemType;//定义数据域
typedef struct LNode
{
	ElemType data;//数据域
	struct LNode* next;//链域
}Node,* Pnode;
/*int L_Creat(Pnode *p_list,int size)
  p_list指向一个链表的指针，此处传入表头地址
  size要创建链表数据域的大小
  功能：创建一个大小为size的链表
  成功返回1，失败返回0
  */
int L_Creat(Pnode* p_list, int size)//Pnode* p_list可换为Node*（*p_list)
{
    Pnode p = NULL;
    int i;
    *p_list = (Node*)malloc(sizeof(Node));//Node*也可以换成Pnode
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
  在表list的position位置插入数据elem
  list要插入数据的单链表
  position插入元素的位置，以1计数
  elem要插入的数据
  成功返回1，失败返回0
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