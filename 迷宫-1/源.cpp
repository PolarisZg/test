#include<stdio.h>
#include<stdlib.h>
/*end出口，1东，2西，3南，4北，x轴locationA，y轴locationB，上北下南，a记录路线，b地图*/
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
/*void MAZE_IN(int** b, int* i,int* j)//i迷宫长，j迷宫宽
{
	int y, x;
	printf("迷宫长，迷宫宽：");
	scanf_s("%d%d", &(*i), &(*j));
	b = (int**)malloc(sizeof(int) * *j);
	for (y = 0; y < *j; y++)
		b[y] = (int*)malloc(sizeof(int) * *i);
	for (y = 0; y < *j; y++)
	{
		printf("第%d行：", y);
		for (x = 0; x < *i; x++)
			scanf_s("%d", &b[y][x]);
	}
}*/
int main()
{
	int i, j, k, x, y;
	int** b = NULL;
	printf("迷宫长，迷宫宽：");
	scanf_s("%d%d", &i, &j);
	b = (int**)malloc(sizeof(int) * j);
	for (y = 0; y < j; y++)
		b[y] = (int*)malloc(sizeof(int) * i);
	for (y = 0; y < j; y++)
	{
		printf("第%d行：", y);
		for (x = 0; x < i; x++)
			scanf_s("%d", &b[y][x]);
	}
	int start[2];
	printf("起点坐标：");
	scanf_s("%d%d", &start[0], &start[1]);
	int end[2];
	printf("终点坐标：");
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