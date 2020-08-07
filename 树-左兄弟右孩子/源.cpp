#include<stdio.h>
#include<stdlib.h>

//必需的各种结构体
typedef struct TREE
{
	int date;
	struct TREE* Lchild = NULL;
	struct TREE* Rbrother = NULL;
}Tree, * Ptree;
typedef struct NODE
{
	Ptree t;
	struct NODE* next = NULL;
}Node, * Pnode;
typedef struct QUEUE
{
	Pnode head = NULL;
	Pnode tail = NULL;
}Queue;

//入队
void T_Inqueue(Queue* Q, Ptree t)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->t = t;
	Q->tail->next = p;
	Q->tail = p;
}

//出队
void T_Outqueue(Queue* Q)
{
	Pnode p = Q->head->next;
	Q->head->next = p->next;
	free(p);
}

//基于读边法创造树
void T_Creat(Ptree* root)
{
	int fa, ch;
	printf("父 子，以子为-1结束输入:\n");
	scanf_s("%d%d", &fa, &ch);
	Ptree t = NULL;
	Ptree s = NULL;
	Ptree r = NULL;
	Queue Q;
	{
		Q.head = (Node*)malloc(sizeof(Node));
		Q.head->next = NULL;
		Q.tail = Q.head;
	}
	t = (Tree*)malloc(sizeof(Tree));
	t->date = ch;
	t->Lchild = t->Rbrother = NULL;
	*root = t;
	T_Inqueue(&Q, t);
	while (1)
	{
		scanf_s("%d%d", &fa, &ch);
		if (ch == -1)
			break;
		s = (Tree*)malloc(sizeof(Tree));
		s->date = ch;
		s->Lchild = s->Rbrother = NULL;
		T_Inqueue(&Q, s);
		while (t->date != fa)
		{
			T_Outqueue(&Q);
			t = Q.head->next->t;
		}
		if (t->Lchild == NULL)
			t->Lchild = s;
		else
		{
			r = t->Lchild;
			while (r->Rbrother != NULL)
				r = r->Rbrother;
			r->Rbrother = s;
		}
	}
}

//叶子个数
int T_leavesNum(Ptree t)
{
	if (t == NULL)
		return 0;
	if (t->Lchild == NULL)
		return 1 + T_leavesNum(t->Rbrother);
	else
		return T_leavesNum(t->Lchild) + T_leavesNum(t->Rbrother);
}

//结点度数
int T_NumNode(Ptree t)
{
	if (t == NULL || t->Lchild == NULL)
		return 1;
	else
	{
		int NumNode = 0;
		Ptree r = t->Lchild;
		while (r != NULL)
		{
			NumNode = NumNode + 1;
			r = r->Rbrother;
		}
		return NumNode;
	}
}

//最大度的结点
Ptree T_MaxNode(Ptree t)
{
	if (t == NULL)
		return NULL;
	if (t->Lchild == NULL)
		return T_MaxNode(t->Rbrother);
	else
	{
		int Num_t = T_NumNode(t);
		int Num_t_Lc = T_NumNode(T_MaxNode(t->Lchild));
		int Num_t_Rb = T_NumNode(T_MaxNode(t->Rbrother));
		if (Num_t >= Num_t_Lc && Num_t >= Num_t_Rb)
			return t;
		else if (Num_t >= Num_t_Rb)
			return T_MaxNode(t->Lchild);
		else
			return T_MaxNode(t->Rbrother);
	}
}

//树的深度
int T_deepth(Ptree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int deepthLc = T_deepth(t->Lchild) + 1;
		int deepthRb = T_deepth(t->Rbrother);
		int deepth = (deepthLc > deepthRb) ? deepthLc : deepthRb;
	}
}

//凹入表法输出树,和DLR差不多嘛
void T_out(Ptree t, int leval)
{
	if (t != NULL)
	{
		for (int i = 0; i < leval; i++)
			printf("  ");
		printf("%d\n", t->date);
		T_out(t->Lchild, leval + 1);
		T_out(t->Rbrother, leval);
	}
}

//求根到叶子的路径。难道是迷宫求解？感觉差不多
//t树,target要找的结点,i第几步,a记录路径
int T_search(Ptree t, int target, int i, int* a)
{
	if (t == NULL)
		return 0;
	if (t->date == target)
		return 1;
	else if (t->date != target)
	{
		a[i] = t->date;
		if (T_search(t->Lchild, target, i + 1, a) == 0)
			return T_search(t->Rbrother, target, i, a);
	}
}

int main()
{
	Ptree root;
	T_Creat(&root);
	int leavesNum = T_leavesNum(root);
	Ptree MaxNode = T_MaxNode(root);
	int deepth = T_deepth(root);
	printf("Num of leaves is %d\n", leavesNum);
	printf("Max num of node is %d\n", MaxNode->date);
	printf("deepth of tree is %d\n", deepth);
	T_out(root, 0);
	int target;
	printf("target:");
	scanf_s("%d", &target);
	int* a = NULL;
	a = (int*)malloc(sizeof(int) * deepth);
	{
		for (int i = 0; i < deepth; i++)
			a[i] = -999999999;
	}//初始化路径
	T_search(root, target, 0, a);
	for (int i = 0; a[i] != -999999999; i++)
		printf("%d--->", a[i]);
	printf("%d", target);
	return 0;
}