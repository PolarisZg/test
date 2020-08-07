#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	char c;
	struct NODE* right;
	struct NODE* left;
}Node,* Pnode;
void Tree_in(Pnode* p)
{
	char c = getchar();
	getchar();//回收回车
	if (c == '#')
	{
		*p = NULL;
		return;
	}
	else
	{
		(*p) = (Node*)malloc(sizeof(Node));
		(*p)->c = c;
		(*p)->left = (*p)->right = NULL;
		printf("left child of %c:", c);
		Tree_in(&(*p)->left);
		printf("right child of %c:", c);
		Tree_in(&(*p)->right);
	}
}
void Tree_out_left(Pnode p)
{
	if (p != NULL)
	{
		printf("%c", p->c);
		Tree_out_left(p->left);
		Tree_out_left(p->right);
	}
}
void Tree_out_mid(Pnode p)
{
	if (p != NULL)
	{
		Tree_out_mid(p->left);
		printf("%c", p->c);
		Tree_out_mid(p->right);
	}
}
void Tree_out_last(Pnode p)
{
	if (p != NULL)
	{
		Tree_out_last(p->left);
		Tree_out_last(p->right);
		printf("%c", p->c);
	}
}
int main()
{
	Pnode p = NULL;
	printf("root:");
	Tree_in(&p);
	Tree_out_left(p);
	printf("\n");
	Tree_out_mid(p);
	printf("\n");
	Tree_out_last(p);
}
/*#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int c;
	struct NODE* right;
	struct NODE* left;
}Node, * Pnode;
void Tree_in(Pnode* p)
{
	int c ;
	scanf_s("%d", &c);
	if (c == -999)
	{
		*p = NULL;
		return;
	}
	else
	{
		(*p) = (Node*)malloc(sizeof(Node));
		(*p)->c = c;
		(*p)->left = (*p)->right = NULL;
		printf("left child of %d:", c);
		Tree_in(&(*p)->left);
		printf("right child of %d:", c);
		Tree_in(&(*p)->right);
	}
}
void Tree_out_left(Pnode p)
{
	if (p != NULL)
	{
		printf("%d ", p->c);
		Tree_out_left(p->left);
		Tree_out_left(p->right);
	}
}
void Tree_out_mid(Pnode p)
{
	if (p != NULL)
	{
		Tree_out_mid(p->left);
		printf("%d ", p->c);
		Tree_out_mid(p->right);
	}
}
void Tree_out_last(Pnode p)
{
	if (p != NULL)
	{
		Tree_out_last(p->left);
		Tree_out_last(p->right);
		printf("%d ", p->c);
	}
}
int main()
{
	Pnode p = NULL;
	printf("以-999表示该位置无数据\n");
	printf("root:");
	Tree_in(&p);
	printf("DLR:");
	Tree_out_left(p);
	printf("\nLDR:");
	Tree_out_mid(p);
	printf("\nLRD:");
	Tree_out_last(p);
}*/