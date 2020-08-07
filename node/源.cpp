#include<stdio.h>
typedef struct node
{
	char name[10];
	int ID;
	struct node* p;
}node;
int main()
{
	node n1, n2;
	node* L;
	n1.p = &n2;
	L = &n1;
	n2.p = NULL;
}