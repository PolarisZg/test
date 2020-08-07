#include<stdio.h>
int main()
{
	float r, n, p;
	p = 1.0;
	printf("please give 2 float\n");
	scanf_s("%f %f", &r, &n);
	while (n > 1.0)
	{
		p = p * (1 + r);
		n = n - 1.0;
	}

	printf("%f", p);

	return 0;
}