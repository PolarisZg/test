#include<stdio.h>
int main()
{
	char a;
	int  j;
	j = 0;
	while (1)
	{
		a = getchar();
		if (a >= '0' && a <= '9')
			j = j + 1;
		if (a == '\n')
			break;
	}
	printf("%d", j);
	return 0;
}
