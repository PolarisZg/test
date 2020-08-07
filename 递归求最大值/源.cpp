#include<stdio.h>
int getMax(int* arry, int L, int R)
{
	if (L == R)
		return arry[L];
	else
	{
		int mid = (L + R) / 2;
		int maxLeft = getMax(arry, L, mid);
		int maxRight = getMax(arry, mid + 1, R);
		return (maxLeft > maxRight ? maxLeft : maxRight);
	}
}
int main()
{
	int arry[] = { 1,2,3,4,5 };
	int L = 0;
	int R = 4;
	printf("%d", getMax(arry, L, R));
	return 0;
}