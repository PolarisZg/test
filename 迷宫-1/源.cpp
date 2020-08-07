#include<stdio.h>
#include<stdlib.h>
/*end���ڣ�1����2����3�ϣ�4����x��locationA��y��locationB���ϱ����ϣ�a��¼·�ߣ�b��ͼ*/
void MAZE(int *end, int locationA, int locationB, int stepNUM, int direction, int** a, int** b)
{
	if (locationA != end[0] || locationB != end[1])
	{
		stepNUM++;
		a[stepNUM][0] = locationA;
		a[stepNUM][1] = locationB;
		if (b[locationA + 1][locationB] == 1 && direction != 2)
			MAZE(end, ++locationA, locationB, stepNUM, 1, a, b);
		if (b[locationA][locationB + 1] == 1 && direction != 3)
			MAZE(end, locationA, ++locationB, stepNUM, 4, a, b);
		if (b[locationA - 1][locationB] == 1 && direction != 1)
			MAZE(end, --locationA, locationB, stepNUM, 2, a, b);
		if (b[locationA][locationB - 1] == 1 && direction != 4)
			MAZE(end, locationA, --locationB, stepNUM, 3, a, b);
	}
}
/*void MAZE_IN(int** b, int* i,int* j)//i�Թ�����j�Թ���
{
	int y, x;
	printf("�Թ������Թ���");
	scanf_s("%d%d", &(*i), &(*j));
	b = (int**)malloc(sizeof(int) * *j);
	for (y = 0; y < *j; y++)
		b[y] = (int*)malloc(sizeof(int) * *i);
	for (y = 0; y < *j; y++)
	{
		printf("��%d�У�", y);
		for (x = 0; x < *i; x++)
			scanf_s("%d", &b[y][x]);
	}
}*/
int main()
{
	int i, j, k, x, y;
	int** b = NULL;
	printf("�Թ������Թ���");
	scanf_s("%d%d", &i, &j);
	b = (int**)malloc(sizeof(int) * j);
	for (y = 0; y < j; y++)
		b[y] = (int*)malloc(sizeof(int) * i);
	for (y = 0; y < j; y++)
	{
		printf("��%d�У�", y);
		for (x = 0; x < i; x++)
			scanf_s("%d", &b[y][x]);
	}
	int start[2];
	printf("������꣺");
	scanf_s("%d%d", &start[0], &start[1]);
	int end[2];
	printf("�յ����꣺");
	scanf_s("%d%d", &end[0], &end[1]);
	int** a = NULL;
	a = (int**)malloc(sizeof(int) * (i * j));
	for (k = 0; k < (i * j); k++)
	{
		a[k]= (int*)malloc(sizeof(int) * 2);
		a[k][0] = a[k][1] = 0;
	}
	MAZE(end, start[0], start[1], 0, 0, a, b);
	for (k = 1; a[k][0] != 0 && a[k][1] != 0; k++)
		printf("(%d,%d)\n", a[k][0], a[k][1]);
}