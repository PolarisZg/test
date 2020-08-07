#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}*List, Node;
void CreatList(List& L, int n)
{
 //   int a;
    if (n == 0)
    {
        L = NULL;
    }
    else
    {
//        scanf("%d", &a);
        L = (List)malloc(sizeof(Node));
        L->data = n;
        CreatList(L->next, --n);
    }
}
void Out(List& L)
{
    if (L)
    {
        printf("%d ", L->data);
        Out(L->next);
    }
}
void DestoryList(List& L)
{
    if (L)
    {
        DestoryList(L->next);
        free(L);
        L = NULL;
    }
}
int listLength(List& L)
{
    if (L->next != NULL)
    {
        L = L->next;
        return listLength(L) + 1;
    }
    return 1;
}
void sum(List L, int sum1)
{
    if (L == NULL)
    {
        printf("%d", sum1);
    }
    sum1 += L->data;
    sum(L->next, sum1);

}
int main()
{
    int sum1 = 0, n;
    List L;
 //   printf("请输入数据长度以及数据\n");
 //   scanf("%d", &n);
    CreatList(L, 5);
    Out(L);
    printf("\n");
    printf("%d", listLength(L));
    printf("\n");
    sum(L->next, sum1);
    DestoryList(L);
}