#include<stdio.h>
int main()
{
	char a[100];
	int i, j, k, t;
	for (i = 0; 1; i++)
	{
		a[i] = getchar();
		if (a[i] == '\n')
			break;
	}
	k = i;
	for (i = 0; i < k; i++)
		for (j = i; j < k; j++)
			if (a[i] < a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for (i = 0; i < k; i++)
		printf("%c", a[i]);
	return 0;
}