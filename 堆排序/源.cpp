#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int indx = *a;
	*a = *b;
	*b = indx;
}
void heapInsert(int* arry, int in, int i)//创建大根堆
{
	int j = i;
	arry[j] = in;
	while (j > 0)
	{
		if (arry[(j - 1) / 2] < arry[j])
		{
			swap(&arry[(j - 1) / 2], &arry[j]);
			j = (j - 1) / 2;
		}
		else
			break;
	}
}
void heapify(int* arry, int i, int lenth)//数组，改变元素的位置以及数组元素个数
{
	int j = i;
	while (j < lenth)
	{
		if (j * 2 + 1 >= lenth)
			break;
		if (j * 2 + 2 >= lenth)
		{
			if (arry[j] > arry[j * 2 + 1])
				break;
			else
			{
				swap(&arry[j], &arry[j * 2 + 1]);
				j = j * 2 + 1;
				continue;
			}
		}
		else
		{
			if (arry[j] > arry[j * 2 + 1] && arry[j] > arry[2 * j + 2])
				break;
			else
			{
				if (arry[j * 2 + 1] > arry[j * 2 + 2])
				{
					swap(&arry[j], &arry[j * 2 + 1]);
					j = j * 2 + 1;
					continue;
				}
				else
				{
					swap(&arry[j], &arry[j * 2 + 2]);
					j = j * 2 + 2;
					continue;
				}
			}
		}
	}
}
int main()
{
	int arry[] = { 1,5,9,2,6,3,4,8,7,0 };
	int help[10];
	int i;
	for (i = 0; i < 10; i++)
		heapInsert(help, arry[i], i);
	for (i = 0; i < 10; i++)
	{
		arry[i] = help[0];
		swap(&help[0], &help[10 - i - 1]);
		heapify(help, 0, 10 - i );
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arry[i]);
}