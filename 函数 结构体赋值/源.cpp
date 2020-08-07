#include<stdio.h>
struct student
{
	char num[5];
	char name[10];
};
void in(struct student* st)
{
	gets_s(st->num);
	gets_s(st->name);
}
void out(struct student st)
{
	printf("%s\n%s", st.num, st.name);
}
int main()
{
	struct student s;
	in(&s);
	out(s);
	return 0;
}