#include<stdio.h>
#include<stdlib.h>

typedef struct NP
{
	int Palace[9][9];
}NP;

static NP NinePalaceQuestion;										// ȫ�ֱ�������Ź�������
static NP NinePalaceAnswer;											// ȫ�ֱ�������Ź����

void NinePalaceGame();												// �Ź���������
void NinePalace_Build(NP* NinePalace);								// �����Ź�������
int NinePalace_Answer(NP NinePalace);								// ���Ź�������
void NinePalace_In(NP* NinePalace);									// ����Ź�������
void NinePalace_Out(NP NinePalace);									// ����Ź���������ȫ�ֱ���
void NinePalace_OutScreen(NP NinePalace);							// ����Ź�������Ļ
void NinePalace_SearchZero(NP NinePalace, int* x, int* y);			// �����Ź����е�û��д�Ŀո񲢷��ؿո�λ��
int NinePalace_MatchNum(NP NinePalace, int x, int y, int num);		// ���Ź���������д�����Ƿ�Ϸ�


void NinePalace_Build(NP* NinePalace)
{

	/*---------------����������Ź�������д15������---------------*/
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

	/*---------------ʹ���ƽ⹤�߰ѾŹ�����������ȡ��40�����������---------------*/
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
		printf("���� 1 ���ɾŹ������� ;\n���� 2 ���оŹ����ƽ� ;\n�����������ֽ������� ;\n");
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
		printf("���� 1 ���ɾŹ������� ;\n���� 2 ���оŹ����ƽ� ;\n�����������ֽ������� ;\n");
		scanf_s("%d", &a);
	
}