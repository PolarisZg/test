/*
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("WNDCLASS NAME");
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

    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, TEXT("窗口创建失败！需要Windows NT！(传递消息为UNICODE)"), szAppName, MB_ICONERROR);

        return 0;
    }

    hwnd = CreateWindow(
        szAppName,
        TEXT("Hk_Mayfly"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,//宽度
        800,//高度
        NULL,
        NULL,
        hInstance,
        NULL
    );
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static int cxClient, cyClient;
    HDC hdc;
    PAINTSTRUCT ps;
    static HPEN hPen1, hPen2;

    switch (message) {
    case WM_CREATE:
        hPen1 = CreatePen(PS_DOT, 0, 0);
        hPen2 = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
    case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        SelectObject(hdc, hPen1);
        Ellipse(hdc, 200, 200, 600, 600);
        Ellipse(hdc, 388, 288, 412, 312);//小圆圈
        SelectObject(hdc, hPen2);
        Arc(hdc, 300, 200, 500, 400, 400, 200, 400, 400);//弧，逆时针绘制
        SelectObject(hdc, CreatePen(PS_DASH, 1, RGB(50, 50, 50)));
        Arc(hdc, 300, 400, 500, 600, 400, 600, 400, 400);
        Ellipse(hdc, 388, 488, 412, 512);
        DeleteObject(SelectObject(hdc, CreatePen(PS_DASH, 1, RGB(50, 50, 50))));
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        DeleteObject(hPen1);
        DeleteObject(hPen2);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
*/