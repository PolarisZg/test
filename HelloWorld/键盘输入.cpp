#include<stdio.h>
#include<stdlib.h>

typedef struct NP
{
	int Palace[9][9];
}NP;

#define DIVISIONS 9
static int ninePalace[DIVISIONS][DIVISIONS];
static NP NinePalaceQuestion;										// 全局变量，存九宫格问题
void NinePalaceGame();												// 九宫格主程序
int NinePalace_Answer(NP NinePalace);								// 解答九宫格问题
void NinePalace_Out(NP NinePalace);									// 输出九宫格问题至全局变量
void NinePalace_SearchZero(NP NinePalace, int* x, int* y);			// 检索九宫格中的没填写的空格并返回空格位置
int NinePalace_MatchNum(NP NinePalace, int x, int y, int num);		// 检查九宫格中新填写的数是否合法
static int END = 0;													// 检测程序是否结束

void NinePalace_Out(NP NinePalace)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			ninePalace[i][j] = NinePalace.Palace[i][j];
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

void NinePalaceGame()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			NinePalaceQuestion.Palace[i][j] = ninePalace[i][j];
		}
	if (NinePalace_Answer(NinePalaceQuestion) == 0)
		END=2;
}

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
	static BOOL fState[DIVISIONS][DIVISIONS];
	static int cxBlock, cyBlock;
	static int cxChar, cyChar, cxCaps;
	TEXTMETRIC tm;
	HDC hdc;
	static int x, y;
	PAINTSTRUCT ps;
	RECT rect;
	static HPEN hPenRed, hPenBlack;
	static HBRUSH hBrushBlue, hBrushYellow, hBrushRed;
	TCHAR szBuffer[10];

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
		hBrushRed = CreateSolidBrush(RGB(255, 0, 0));
		for (int i = 0; i < DIVISIONS; i++)
			for (int j = 0; j < DIVISIONS; j++)
				ninePalace[i][j] = 0;

		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_SIZE:
		cxBlock = LOWORD(lParam) / DIVISIONS;
		cyBlock = HIWORD(lParam) / DIVISIONS;
		return 0;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam) / cxBlock;
		y = HIWORD(lParam) / cyBlock;

		if (x < DIVISIONS && y < DIVISIONS)
		{
			fState[x][y] ^= 1;

			rect.left = x * cxBlock;
			rect.top = y * cyBlock;
			rect.right = (x + 1) * cxBlock;
			rect.bottom = (y + 1) * cyBlock;

			InvalidateRect(hwnd, &rect, FALSE);
		}
		else
			MessageBeep(0);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_END)
		{
			NinePalaceGame();
			END = 1;
		}
		InvalidateRect(hwnd, NULL, FALSE);
		return 0;
	case WM_CHAR:
		if (wParam >= '0' && wParam <= '9' && fState[x][y] == 1)
			ninePalace[x][y] = wParam - '0';
		InvalidateRect(hwnd, NULL, FALSE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (END != 2)
		{
			for (int i = 0; i < DIVISIONS; i++)
				for (int j = 0; j < DIVISIONS; j++)
				{
					SelectObject(hdc, hBrushBlue);
					Rectangle(hdc, i * cxBlock, j * cyBlock, (i + 1) * cxBlock, (j + 1) * cyBlock);

					if (fState[i][j])
					{
						SelectObject(hdc, hBrushYellow);
						Rectangle(hdc, i * cxBlock, j * cyBlock, (i + 1) * cxBlock, (j + 1) * cyBlock);
					}

					if (ninePalace[i][j] != 0)
					{
						RECT rect;
						rect.left = i * cxBlock;
						rect.top = j * cyBlock;
						rect.right = (i + 1) * cxBlock;
						rect.bottom = (j + 1) * cyBlock;
						DrawText(hdc, szBuffer, wsprintf(szBuffer, TEXT("%d"), ninePalace[i][j]), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
					}
				}
			SelectObject(hdc, hPenRed);
			MoveToEx(hdc, 0, cyBlock * 3, NULL);
			LineTo(hdc, cxBlock * 9, cyBlock * 3);
			MoveToEx(hdc, 0, cyBlock * 6, NULL);
			LineTo(hdc, cxBlock * 9, cyBlock * 6);
			MoveToEx(hdc, cxBlock * 3, 0, NULL);
			LineTo(hdc, cxBlock * 3, cyBlock * 9);
			MoveToEx(hdc, cxBlock * 6, 0, NULL);
			LineTo(hdc, cxBlock * 6, cyBlock * 9);
		}
		else
		{
			RECT rect;
			GetClientRect(hwnd, &rect);
			SelectObject(hdc, hBrushRed);
			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
			DrawText(hdc, TEXT("输入数据错误"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		DeleteObject(hPenRed);
		DeleteObject(hPenBlack);
		DeleteObject(hBrushBlue);
		DeleteObject(hBrushYellow);
		DeleteObject(hBrushRed);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}