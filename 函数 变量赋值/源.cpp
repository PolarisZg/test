#include<stdio.h>
void in(int* a)
{
	scanf_s("%d", a);
}
int main()
{
	int y;
	in(&y);
	printf("%d", y);
	return 0;
}