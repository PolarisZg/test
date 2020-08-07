#include<stdio.h>
#include<string.h>
int i=10;//记录找出的元素
typedef struct student
{
	char name[10];
	int IDnum;
	int age;
	char sex[4];
	char bir[9];
}STU;
void Init(STU stu[])
{
	int j;
	for (j = 0; j < 10; j++)
	{
		gets_s(stu[j].name);
		scanf_s("%d%d", stu[j].IDnum, stu[j].age);
		gets_s(stu[j].sex);
		gets_s(stu[j].bir);
	}
}
void Find(STU stu[])
{
	int j;
	char name[10];
	for (j = 0; j < 10; j++)
		if (strcmp(stu[j].name, name) == 0)
			break;
	i = j;
	if (i != 10)
		printf("find : %s %d %d %s %s", stu[i].name, stu[i].IDnum, stu[i].age, stu[i].sex, stu[i].bir);
	else
		printf("404");
}
void Insert(STU stu[])
{

}
void Delelte(STU stu[])
{
	int j;
	printf("delete what it had found\n");
	
}
void Output(STU stu[])
{

}
int main()
{
	STU stu[10];
	Init(stu);
	Find(stu);	
	Delelte(stu);
	Insert(stu);
	Output(stu);
}