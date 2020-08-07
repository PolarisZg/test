#include<stdio.h>
int fun(long n)
{
	int a[100], i, j, k;
	for (i = 0; n != 0; i++)
	{
		a[i] = n % 10;
		n = n / 10;
	}
	i = i - 1;
	for (j = 0; j <= i; j++)
		if (a[j] != a[i - j])
			break;
	if (j - 1 == i)
		return 1;
	else
		return 0;
}
int main()

{
	long in;

	scanf_s("%ld", &in);

	if (fun(in))

		printf("YES\n");

	else

		printf("NO\n");

}