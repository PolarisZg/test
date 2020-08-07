#include<stdio.h>
#include<string.h>
typedef struct
{
	int no;
	char name[10];
	float score;
}student;
struct list
{
	student s[100];
	int len;
};
void In(struct list* L)
{
	int i;
	printf("input the number of student:");
	scanf_s("%d", &(*L).len);
	printf("input score and name:\n");
	for (i = 0; i < L->len; i++)
	{
		(L->s[i]).no = i + 1;
		scanf_s("%f", &((*L).s[i]).score);
		gets_s((L->s[i]).name);
	}
}
void Out(struct list L)
{
	int i;
	printf("output the list of students:\n");
	for (i = 0; i < L.len; i++)
		printf("%d %s %.2f\n", L.s[i].no, L.s[i].name, L.s[i].score);
}
void Find(struct list L)
{
	int i;
	char name[10];
	printf("input the name:");
	gets_s(name);
	for (i = 0; i < L.len; i++)
		if (strcmp(name, (L.s[i]).name) == 0)
			break;
	if (i < L.len)
		printf("FIND:%d %s %.2f\n", (L.s[i]).no, (L.s[i]).name, (L.s[i]).score);
	else("404");
}
void Del(struct list* L)
{
	int i;
	printf("输入要删除学生的序号:");
	scanf_s("%d", &i);
	for (; i < L->len; i++)
	{
		L->s[i - 1] = L->s[i];
		L->s[i - 1].no--;
	}
	L->len = L->len - 1;
	printf("OVER:\n");
}
void Insert(struct list* L)
{
	int i;
	student stu;
	printf("input score and name:");
	scanf_s("%f",&stu.score);
	gets_s(stu.name);
	stu.no = 1;
	L->len = L->len + 1;
	for (i = L->len; i > 0; i--)
	{
		L->s[i] = L->s[i - 1];
		L->s[i].no++;
	}
	L->s[0] = stu;
}
int main()
{
	struct list L;
	In(&L);
	Find(L);
	Del(&L);
	Out(L);
	Insert(&L);
	Out(L);
	return 0;
}