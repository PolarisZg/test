#include<stdio.h>
#include<stdlib.h>
void merge(int* arry, int L, int mid, int R)
{
	int* help = NULL;
	help = (int*)malloc(sizeof(int) * (R - L + 1));
	int i = L;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= R)
	{
		if (arry[i] < arry[j])
		{
			help[k] = arry[i];
			i = i + 1;
		}
		else
		{
			help[k] = arry[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i > mid&& j <= R)
	{
		help[k] = arry[j];
		k = k + 1;
		j = j + 1;
	}
	while (i <= mid && j > R)
	{
		help[k] = arry[i];
		k = k + 1;
		i = i + 1;
	}
	for (i = 0; i < (R - L + 1); i++)
		arry[i] = help[i];
	free(help);
}
int main()
{
	int i = 0;
	int arry[] = { 1,2,3,5,6,4,7,8,9 };
	merge(arry, 0, 4, 8);
	for (i = 0; i < 9; i++)
		printf("%d ", arry[i]);
	return 0;
}