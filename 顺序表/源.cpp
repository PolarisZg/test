#include<stdio.h>
#include<stdlib.h>
typedef struct Sqlist
{
	int* elem = NULL;
	int length;
	int size;
}list;
void S_creat(list* L)
{
	L->size = 10;
	L->elem = (int*)malloc(sizeof(L->size));
	L->length = 3;
	int i;
	for (i = 0; i < L->length; i++)
		L->elem[i] = i + 1;
}
void S_out(list L)
{
	int i;
	for (i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n");
}
void S_insert(list* L)
{
	L->length++;
	L->elem[L->length - 1] = 666;
}
void S_del(list* L)
{
	L->length--;
}
int main()
{
	list L;
	S_creat(&L);
	S_out(L);
	S_insert(&L);
	S_out(L);
	S_del(&L);
	S_out(L);
}