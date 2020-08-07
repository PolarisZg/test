#include<stdio.h>
int findInArray(int* array, int element, int size)
{
	for (int i = 0; i < size; i++)
		if (array[i] == element)
			return i;
	return -1;
}
int main()
{
	int n = 0;
	int array[1000];
	int m = 0;
	int search_target[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &array[i]);
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++)
		scanf_s("%d", &search_target[i]);
	for (int i = 0; i < m; i++)
	{
		int location = findInArray(array, search_target[i], n);
		if (location == 0)
			printf("%d\n", array[1]);
		else if (location == n - 1)
			printf("%d\n", array[n - 2]);
		else if (location == -1)
			printf("NULL\n");
		else
			printf("%d %d\n", array[location - 1], array[location + 1]);
	}
	return 0;
}