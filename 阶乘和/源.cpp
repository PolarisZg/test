#include<stdio.h>
int main()
{
	int n;
	int i, k, s;
	s = 1;
	k = 1;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		k = k * i;
		s = s * k;
	}
	printf("%d", s);
}