#include<stdio.h>
#include<stdlib.h>

typedef struct NP
{
	int Palace[9][9];
}NP;

static NP NinePalaceQuestion;										// 全局变量，存九宫格问题
static NP NinePalaceAnswer;											// 全局变量，存九宫格答案

void NinePalaceGame();												// 九宫格主程序
void NinePalace_Build(NP* NinePalace);								// 创建九宫格问题
int NinePalace_Answer(NP NinePalace);								// 解答九宫格问题
void NinePalace_In(NP* NinePalace);									// 输入九宫格问题
void NinePalace_Out(NP NinePalace);									// 输出九宫格问题至全局变量
void NinePalace_OutScreen(NP NinePalace);							// 输出九宫格至屏幕
void NinePalace_SearchZero(NP NinePalace, int* x, int* y);			// 检索九宫格中的没填写的空格并返回空格位置
int NinePalace_MatchNum(NP NinePalace, int x, int y, int num);		// 检查九宫格中新填写的数是否合法


void NinePalace_Build(NP* NinePalace)
{

	/*---------------用随机数给九宫格中填写15个数据---------------*/
	for (int i = 0; i < 15; i++)
	{
		int x = (rand() % 9);
		int y = (rand() % 9);
		int num = (rand() % 9) + 1;
		if (NinePalace->Palace[x][y] != 0)
			i--;
		else if (NinePalace_MatchNum(*NinePalace, x, y, num))
			NinePalace->Palace[x][y] = num;
		else
			i--;
	}
	/*------------------------------------------------------------*/

	/*---------------使用破解工具把九宫格填满，再取出40个来组成问题---------------*/
	NinePalace_Answer(*NinePalace);
	for (int i = 0; i < 40; i++)
	{
		int x = (rand() % 9);
		int y = (rand() % 9);
		if (NinePalace->Palace[x][y] != 0)
			i--;
		else
			NinePalace->Palace[x][y] = NinePalaceAnswer.Palace[x][y];
	}
	/*---------------------------------------------------------------------------*/

}

void NinePalace_In(NP* NinePalace)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			scanf_s("%d", &NinePalace->Palace[i][j]);
		}
}

void NinePalace_Out(NP NinePalace)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			NinePalaceAnswer.Palace[i][j] = NinePalace.Palace[i][j];
}

void NinePalace_SearchZero(NP NinePalace, int* x, int* y)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (NinePalace.Palace[i][j] == 0)
			{
				(*x) = i;
				(*y) = j;
			}
}

int NinePalace_MatchNum(NP NinePalace, int x, int y, int num)
{
	for (int i = 0; i < 9; i++)
		if (NinePalace.Palace[x][i] == num)
			return 0;
	for (int i = 0; i < 9; i++)
		if (NinePalace.Palace[i][y] == num)
			return 0;
	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
			if (NinePalace.Palace[i][j] == num)
				return 0;
	return 1;
}

int NinePalace_Answer(NP NinePalace)
{
	int x = -1;
	int y = -1;
	NinePalace_SearchZero(NinePalace, &x, &y);
	if (x == -1 && y == -1)
	{
		NinePalace_Out(NinePalace);
		return 1;
	}
	else
	{
		int i;
		for (i = 1; i <= 9; i++)
			if (NinePalace_MatchNum(NinePalace, x, y, i))
			{
				NinePalace.Palace[x][y] = i;
				if (NinePalace_Answer(NinePalace) == 0)
					NinePalace.Palace[x][y] = 0;
				else
					return 1;
			}
		if (i == 10)
			return 0;
	}
}

void NinePalace_OutScreen(NP NinePalace)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%3d", NinePalace.Palace[i][j]);
		printf("\n");
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			NinePalaceAnswer.Palace[i][j] = NinePalaceQuestion.Palace[i][j] = 0;
	NinePalace_Build(&NinePalaceQuestion);
		printf("输入 1 生成九宫格问题 ;\n输入 2 进行九宫格破解 ;\n输入其他数字结束程序 ;\n");
		int a;
		scanf_s("%d", &a);
		if (a == 1)
		{
			NinePalace_Build(&NinePalaceQuestion);
			NinePalace_OutScreen(NinePalaceQuestion);
		}
		else if (a == 2)
		{
			NinePalace_In(&NinePalaceQuestion);
			if (NinePalace_Answer(NinePalaceQuestion) == 0)
				printf("error");
			printf("---------------------------\n");
			NinePalace_OutScreen(NinePalaceAnswer);
		}
		printf("输入 1 生成九宫格问题 ;\n输入 2 进行九宫格破解 ;\n输入其他数字结束程序 ;\n");
		scanf_s("%d", &a);
	
}