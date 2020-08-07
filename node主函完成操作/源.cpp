#include<stdio.h>
typedef struct node
{
	int num;//account number
	char name[10];//account name
	int* p;
}node;
void out(node a)
{
	printf("%d %s\n", a.num, a.name);
}
int main()
{
	node n1, n2;
	node* L;
	n1.p = n2.p;
	L->p = n1.p;
	out(n1);
	out(n2);
	return 0;
}