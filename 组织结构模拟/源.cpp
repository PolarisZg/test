#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct TREE
{
	char date[20];
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

void T_Inqueue(Queue* Q, Ptree t)
{
	Pnode p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->t = t;
	Q->tail->next = p;
	Q->tail = p;
}

void T_Outqueue(Queue* Q)
{
	Pnode p = Q->head->next;
	Q->head->next = p->next;
	free(p);
}

void T_Creat(Ptree* root)
{
	char fa[20], ch[20];
	gets_s(fa);
	gets_s(ch);
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
	strcpy_s(t->date, ch);
	t->Lchild = t->Rbrother = NULL;
	*root = t;
	T_Inqueue(&Q, t);
	while (1)
	{
		gets_s(fa);
		gets_s(ch);
		if (ch[0] == '#')
			break;
		s = (Tree*)malloc(sizeof(Tree));
		strcpy_s(s->date, ch);
		s->Lchild = s->Rbrother = NULL;
		T_Inqueue(&Q, s);
		while (strcmp(t->date, fa) != 0)
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

void T_out(Ptree t, int leval)
{
	if (t != NULL)
	{
		for (int i = 0; i < leval; i++)
			printf("  ");
		printf("%s\n", t->date);
		T_out(t->Lchild, leval + 1);
		T_out(t->Rbrother, leval);
	}
}
void T_leaf_out(Ptree t)
{
	if (t != NULL)
	{
		if (t->Lchild == NULL)
			printf("%s,", t->date);
		T_leaf_out(t->Lchild);
		T_leaf_out(t->Rbrother);
	}
}

int T_search(Ptree t,char* target,Ptree* r)
{
	if (t == NULL)
	{
		(*r) = NULL;
		return 0;
	}
	if (strcmp(t->date, target) == 0)
	{
		(*r) = t;
		return 1;
	}
	else
	{
		if (T_search(t->Lchild, target, r) == 0)
			return T_search(t->Rbrother, target, r);
	}
}

void T_nextfloor(Ptree t)
{
	if (t != NULL)
	{
		Ptree r = t->Lchild;
		while (r != NULL)
		{
			printf("%s,", r->date);
			r = r->Rbrother;
		}
		printf("\b \n");
	}
}

void T_nextflor_insert(Ptree* t)
{
	Ptree r = (*t)->Lchild;
	while (r->Rbrother != NULL)
		r = r->Rbrother;
	printf("��������:");
	Ptree s = NULL;
	s = (Tree*)malloc(sizeof(Tree));
	s->Lchild = s->Rbrother = NULL;
	gets_s(s->date);
	r->Rbrother = s;
}
void T_Del_all(Ptree* t)
{
	if ((*t) != NULL)
	{
		T_Del_all(&(*t)->Lchild);
		T_Del_all(&(*t)->Rbrother);
		free((*t));
	}
}
int main()
{
	Ptree root;
	printf("--------1)��ʼ������һ������n���������Ƶĺ����ֵ�����洢�ṹ--------\n");
	T_Creat(&root);
	printf("--------2)��������������״�ṹ--------\n");
	T_out(root, 0);
	int deepth = T_deepth(root);
	printf("--------3)����֯ͼ����ȣ����������--------\n");
	printf("deepth is %d\n", deepth);
	printf("--------4)������û���¼����ŵĲ��������--------\n");
	T_leaf_out(root);
	printf("\b \n");
	Ptree r;
	char target[20];
	printf("--------5)�����������в��գ�������ò��ŵ���һ�����в���--------\n");
	printf("����Ŀ��:");
	gets_s(target);
	T_search(root, target, &r);
	T_nextfloor(r);
	printf("--------6)�ڲ���������һ���в���һ���µĻ���--------\n");
	T_nextflor_insert(&r);
	T_out(root, 0);
	printf("--------7)ɾ��������֯����--------\n");
	T_Del_all(&root);
	return 0;
}