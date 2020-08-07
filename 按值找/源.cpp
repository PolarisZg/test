#include<stdio.h>
int main()
{
	int i, k;
	int a[5];
	for (i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d",&k);
	for (i = 0; i < 5; i++)
		if (k == a[i])
			break;
	printf("%d", i);
	return 0;
}