#include<stdio.h>
int main()
{
	int a[10], max[2], min[2], i, k, n;
	scanf_s("%d", &n);
	k = 0;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		k = k + a[i];
	}
	max[0] = min[0] = a[0];
	max[1] = min[1] = 0;
	for (i = 0; i < n; i++)
	{
		if (max[0] < a[i])
		{
			max[0] = a[i];
			max[1] = i;
		}
		if (min[0] > a[i])
		{
			min[0] = a[i];
			min[1] = i;
		}
	}
	printf("���ֵ%d\n���ֵ�±�%d\n��Сֵ%d\n��Сֵ�±�%d\nƽ��ֵ%.2f", max[0], max[1], min[0], min[1], (k * 1.0) / (n * 1.0));
	return 0;
}