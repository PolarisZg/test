#include<stdio.h>
int main()
{
	int n, x;
	printf("Input n:");
	scanf_s("%d", &n);
	int a, i, j, k;
	j  = 1;
	x = 0;
	do
	{
		i = 1;
		a = 1;
		while (j % 2 == 1 && i <= j)
			a = a * i;
		x = x + a;
		j = j + 1;
	} while (j < 2 * n - 1);
	printf("%d", x);
}