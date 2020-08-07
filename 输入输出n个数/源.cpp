#include<stdio.h>
struct intlist
{
	int a[100];
	int len;
};
typedef struct intlist List;
void In(List* L)
{
	int i;
	printf("intput the lenth:");
	scanf_s("%d", &(*L).len);
	printf("input every element:");
	for (i = 0; i < L->len; i++)
		scanf_s("%d", &(*L).a[i]);
}
void Out(List L)
{
	int i;
	printf("output every element:");
	for (i = 0; i < L.len; i++)
		printf("%d ", L.a[i]);
}
int main()
{
	List L;
	In(&L);
	Out(L);
	return 0;
}