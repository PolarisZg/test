#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int indx = *a;
	*a = *b;
	*b = indx;
}
void heapInsert(int* Help, int k, int j)
{
	int i = j;
	Help[i] = k;
	while (i >= 0&&(Help[(i - 1) / 2] < Help[i]))
	{
		swap(&Help[(i - 1) / 2], &Help[i]);
		i = (i - 1) / 2;
	}
}
void heap(int* arry, int length)
{
	if (length > 0)
	{
		int* help = NULL;
		help = (int*)malloc(sizeof(int) * length);
		int i = 0;
		for (i = 0; i < length; i++)
			heapInsert(help, arry[i], i);
		for (i = 0; i < 10; i++)
			arry[i] = help[i];
		free(help);
	}
}
int main()
{
	int i;
	int arry[] = { 1,5,2,9,6,3,4,7,8,0 };
	heap(arry, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", arry[i]);
	return 0;
}