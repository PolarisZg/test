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
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			NinePalaceAnswer.Palace[i][j] = 0;

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

void NinePalaceGame()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			NinePalaceAnswer.Palace[i][j] = NinePalaceQuestion.Palace[i][j] = 0;
	NinePalace_Build(&NinePalaceQuestion);
	/*	printf("输入 1 生成九宫格问题 ;\n输入 2 进行九宫格破解 ;\n输入其他数字结束程序 ;\n");
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
	*/
}

/*----------------------------------------------------------------------------------------------------*/

#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("NinePalace");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("this program require Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName,					//window class name
		TEXT("九宫格 by zgbcq"),	//window caption
		WS_OVERLAPPEDWINDOW,		//window style 
		CW_USEDEFAULT,				//initial x position
		CW_USEDEFAULT,				//initial y position
		CW_USEDEFAULT,				//initial x size
		CW_USEDEFAULT,				//initial y size
		NULL,						//parent window handle
		NULL,						//window menu handle
		hInstance,					//program instance handle
		NULL						//creation parameters
	);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int cxChar, cyChar, cxCaps;
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR szBuffer[10];
	TEXTMETRIC tm;
	RECT rect;
	static HPEN hPenRed, hPenBlack;
	static HBRUSH hBrushBlue, hBrushYellow;
	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);

		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		hPenRed = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		hPenBlack = CreatePen(PS_SOLID, 2, 0);
		hBrushBlue = CreateSolidBrush(RGB(64, 141, 236));
		hBrushYellow = CreateSolidBrush(RGB(244, 244, 26));
		NinePalaceGame();

		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		SelectObject(hdc, hPenBlack);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int xLeft = cxChar + cyChar + j * (cxChar + cyChar);
				int yTop = cxChar + cyChar + i * (cxChar + cyChar);
				int xRight = cxChar + cyChar + (j + 1) * (cxChar + cyChar);
				int yBottom = cxChar + cyChar + (i + 1) * (cxChar + cyChar);
				if (NinePalaceQuestion.Palace[i][j] != 0)
				{

					SelectObject(hdc, hBrushYellow);
					Rectangle(hdc, xLeft, yTop, xRight, yBottom);
					TextOut(hdc, (xLeft + xRight - cxChar) / 2, (yTop + yBottom - cyChar) / 2, szBuffer, wsprintf(szBuffer, TEXT("%d"), NinePalaceQuestion.Palace[i][j]));
				}
				else
				{

					SelectObject(hdc, hBrushBlue);
					Rectangle(hdc, xLeft, yTop, xRight, yBottom);
				}

			}
		}
		SelectObject(hdc, hPenRed);
		MoveToEx(hdc, (cxChar + cyChar) * 1, (cxChar + cyChar) * 4, NULL);
		LineTo(hdc, (cxChar + cyChar) * 10, (cxChar + cyChar) * 4);
		MoveToEx(hdc, (cxChar + cyChar) * 1, (cxChar + cyChar) * 7, NULL);
		LineTo(hdc, (cxChar + cyChar) * 10, (cxChar + cyChar) * 7);
		MoveToEx(hdc, (cxChar + cyChar) * 4, (cxChar + cyChar) * 1, NULL);
		LineTo(hdc, (cxChar + cyChar) * 4, (cxChar + cyChar) * 10);
		MoveToEx(hdc, (cxChar + cyChar) * 7, (cxChar + cyChar) * 1, NULL);
		LineTo(hdc, (cxChar + cyChar) * 7, (cxChar + cyChar) * 10);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		DeleteObject(hPenRed);
		DeleteObject(hPenBlack);
		DeleteObject(hBrushBlue);
		DeleteObject(hBrushYellow);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}