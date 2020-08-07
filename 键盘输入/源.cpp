/*--------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

typedef struct NP
{
	int Palace[9][9];
}NP;

static NP NinePalaceQuestion;										// 全局变量，存九宫格问题
static NP NinePalaceAnswer;											// 全局变量，存九宫格答案

void iniNinePalace()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			NinePalaceAnswer.Palace[i][j] = NinePalaceQuestion.Palace[i][j] = 0;
}
/*--------------------------------------------------*/
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
	static HBRUSH hBrushBlue, hBrushYellow, hBrushGreen;
	static BOOL fState[9][9];
	static int xBlock, yBlock;
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
		hBrushGreen = CreateSolidBrush(RGB(28, 244, 28));
		iniNinePalace();
		xBlock = yBlock = 0;

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
		DeleteObject(hBrushGreen);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}