#include<stdio.h>
#include<stdlib.h>
typedef struct ELEM
{
	int date = 0;
	int fa = -1;
	int Lchild = -1;
	int Rchild = -1;
}Elem;
typedef struct HFTREE
{
	Elem* E;
	int size;
	int length = 0;
}HFtree;
typedef struct TREE
{
	int data;
	struct TREE* Lchild;
	struct TREE* Rchild;
}Tree, * Ptree;
int HF_min(HFtree t)
{	
	int location_min = 9999999;
	int data = 9999999;
	for (int i = 0; i < t.length; i++)
		if (data >= t.E[i].date)
			if (t.E[i].fa == -1)
			{
				location_min = i;
				data = t.E[location_min].date;
			}
	return location_min;
}
void HF_out(HFtree t)
{
	for (int i = 0; i < t.length; i++)
		printf("%5d%5d%5d%5d%5d\n", i, t.E[i].date, t.E[i].fa, t.E[i].Lchild, t.E[i].Rchild);
}
void HF_in(HFtree* t)
{
	printf("输入权值个数:");
	scanf_s("%d", &t->length);
	t->size = t->length * 2;
	t->E = NULL;
	t->E = (Elem*)malloc(sizeof(Elem) * t->size);
	{
		for (int i = 0; i < t->size; i++)
		{
			t->E[i].date = 0;
			t->E[i].fa = -1;
			t->E[i].Lchild = -1;
			t->E[i].Rchild = -1;
		}
	}
	printf("输入权值:");
	for (int i = 0; i < t->length; i++)
		scanf_s("%d", &t->E[i].date);
	printf("------------------\n初始化存储空间状态\n");
	HF_out(*t);
	for (int i = t->length - 1; i > 0; i--)
	{
		t->E[t->length].Lchild = HF_min(*t);
		t->E[t->E[t->length].Lchild].fa = t->length;
		t->E[t->length].Rchild = HF_min(*t);
		t->E[t->E[t->length].Rchild].fa = t->length;
		t->E[t->length].date = t->E[t->E[t->length].Lchild].date + t->E[t->E[t->length].Rchild].date;
		t->length++;
	}
	printf("------------------\n构建好后存储空间状态\n");
	HF_out(*t);
}
Ptree HF_tree(HFtree h, int location)
{
	if (location == -1)
		return NULL;
	else
	{
		Ptree tree = NULL;
		tree = (Tree*)malloc(sizeof(Tree));
		tree->data = h.E[location].date;
		tree->Lchild = HF_tree(h, h.E[location].Lchild);
		tree->Rchild = HF_tree(h, h.E[location].Rchild);
		return tree;
	}
}
void HF_tree_out(Ptree tree,int deepth)
{
	if (tree != NULL)
	{
		for (int i = 0; i < deepth; i++)
			printf("	");
		printf("%d", tree->data);
		printf("\n");
		HF_tree_out(tree->Lchild, deepth + 1);
		HF_tree_out(tree->Rchild, deepth + 1);
	}
}
int main()
{
	HFtree t;
	Ptree tree;
	HF_in(&t);
	tree = HF_tree(t, t.length - 1);
	printf("----------------\n构建好的哈夫曼树\n凹入表法输出树\n");
	HF_tree_out(tree, 0);
}