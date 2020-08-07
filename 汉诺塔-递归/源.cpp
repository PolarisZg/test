#include<stdio.h>
void Han(int n, char A, char B, char C)
{
	if (n > 1)
	{
		Han(n - 1, A, C, B);
		printf("%d,%c-->%c\n", n, A, C);
		Han(n - 1, B, A, C);
	}
	else
		printf("%d,%c-->%c\n", n, A, C);
}
int main()
{
	Han(4, 'A', 'B', 'C');
	return 0;
}