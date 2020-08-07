#include<stdio.h>
void swap(int* arry, int a, int b)
{
	int indx;
	indx = arry[a];
	arry[a] = arry[b];
	arry[b] = indx;
}
void QuickMerge(int* arry, int Left, int Right, int* a)
{
	int num = arry[Right];
	int i = Left;
	int less = Left - 1;
	int more = Right + 1;
	while (i < more)
	{
		if (arry[i] > num)
		{
			swap(arry, i, more - 1);
			more--;
		}
		else if (arry[i] < num)
		{
			swap(arry, i, less + 1);
			less++;
			i++;
		}
		else
			i++;
	}
	a[0] = less;
	a[1] = more;
}
void QuickSort(int* arry, int Left, int Right)
{
	if (Left < Right)
	{
		int a[2];//分割数组成为两个部分
		QuickMerge(arry, Left, Right, a);
		QuickSort(arry, Left, a[0]);
		QuickSort(arry, a[1], Right);
	}
}
int main()
{
	int arry[] = { 1,2,3,4,5,6,7,8,9,0,3,2,1,6,5,4,9,8,7,0 };
	int i = 0;
	QuickSort(arry, 0, 19);
	for (i = 0; i < 20; i++)
		printf("%d ", arry[i]);
	return 0;
}