#include<stdio.h>
void in(int a[])
{
	int i;
	for (i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);
}
void out(int a[])
{
	int i;
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]);
}
int main()
{
	int arr[10];
	in(arr);
	out(arr);
	return 0;
}