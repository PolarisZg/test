#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int elem;
    struct NODE* next;
}Node,*Pnode;
int P_creat(Pnode* L, int size)//成功返回1，失败返回0，创建链表并赋值
{
    *L = (Node*)malloc(sizeof(Node));
    if (*L == NULL)
        return 0;
    (*L)->next = NULL;
    Pnode p = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        if (p == NULL)
            return 0;
        printf("输入元素值:");
        scanf_s("%d", &(p->elem));
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return 1;
}
int P_out(Pnode L)//输出链表全体元素,不对链表进行改动, 成功返回1，失败返回0；
{
    if (L == NULL)
        return 0;
    Pnode p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n");
    return 1;
}
/*插入elem到链表L的position位置（以一开始计数）
  L后第一个间隔为1
  成功返回1，失败返回0*/
int P_insert(Pnode L, int position, int elem)
{
    if (L == NULL || position <= 0)
        return 0;
    Pnode p, q;
    p = L;
    q = NULL;
    int i;
    for (i = 0; i < position - 1 && p != NULL; i++)
        p = p->next;
    if (p == NULL && i < position - 1)
        return 0;
    q = (Node*)malloc(sizeof(Node));
    if (q == NULL)
        return 0;
    q->elem = elem;
    q->next = p->next;
    p->next = q;
    return 1;
}
int P_search(Pnode L, int elem)
{
    if (L == NULL)
        return 0;
    Node* p = L->next;
    while (p != NULL && elem != p->elem)
        p = p->next;
    if (p == NULL)
        return 0;
    return 1;
}
int P_delete(Pnode L, int elem)
{
    if (L == NULL)
        return 0;
    Node* p = L;
    while (p != NULL && elem != p->next->elem)
        p = p->next;
    if (elem == p->next->elem)
    {
        Node* q = p->next;
        p->next = q->next;
        free(q);
        return 1;
    }
    return 0;
}
void P_delALL(Pnode L)
{
    Node* p = L;
    Node* q;
    if (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}
void P_jiao(Pnode L, Pnode R)
{
    Pnode p;
    printf("\n交集：");
    for (p = L->next; p != NULL; p = p->next)
        if (P_search(R, p->elem))
            printf("%d ", p->elem);
}
void P_bing(Pnode L, Pnode R)
{
    Pnode p;
    printf("\n并集：");
    P_out(L);
    for (p = R->next; p != NULL; p = p->next)
        if (P_search(L, p->elem) == 0)
            printf("%d ", p->elem);
}
void P_cha(Pnode L, Pnode R)
{
    Pnode p;
    printf("\n差集：");
    for (p = L->next; p != NULL; p = p->next)
        if (P_search(R, p->elem) == 0)
            printf("%d ", p->elem);
    for (p = R->next; p != NULL; p = p->next)
        if (P_search(L, p->elem) == 0)
            printf("%d ", p->elem);
}
int main()
{
    Pnode R;
    int size;
    int position;
    int elem;
    scanf_s("%d", &size);
    P_creat(&R, size);
    P_out(R);
    Pnode L;
    scanf_s("%d", &size);
    P_creat(&L, size);
    P_out(L);
    P_bing(L, R);
    P_cha(L, R);
    P_jiao(L, R);
}