#include<stdio.h>
typedef struct BankAccount
{
	int num;//account number
	char name[10];//account name
}BankAccount;
void read(BankAccount* a)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf_s("%d", &a[i].num);
		gets_s(a[i].name);
	}
}
void out(BankAccount* a)
{
	int i;
	for(i=0;i<3;i++)
		printf("%d %s\n", a[i].num, a[i].name);
}
int main()
{
	BankAccount* ac;
	BankAccount a[3];
	read(a);
	out(a);
	return 0;
}