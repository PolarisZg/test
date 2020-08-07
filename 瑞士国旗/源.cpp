#include<stdio.h>
void swap(int* arry, int a, int b)
{
	int indx;
	indx = arry[a];
	arry[a] = arry[b];
	arry[b] = indx;
}
void SwisFlag(int* arry, int num, int Left, int Right)
{
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
}
int main()
{
	int arry[] = { 0,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	SwisFlag(arry, 5,0,18);
	for (i = 0; i < 19; i++)
		printf("%d ", arry[i]);
	return 0;
}