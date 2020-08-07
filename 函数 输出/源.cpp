#include<stdio.h>
void out(int a)
{
	printf("%d", a);
}
int main()
{
	int a;
	scanf_s("%d", &a);
	out(a);
	return 0;
}