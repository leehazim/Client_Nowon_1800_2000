#include "define.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND g_hWnd;
LPCTSTR lpszClass = TEXT("Follow Rect");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdParam, int nCmdShow) {

	HWND hWnd;
	WNDCLASS WndClass;
	MSG Msg;
	g_hInst = hInstance;

	WndClass.style = CS_VREDRAW | CS_HREDRAW;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 640,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Msg, NULL, 0, 0)){
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {


	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y;

	switch (msg) {
	case WM_CREATE:
		x = y = 10;
		return 0;

	case WM_KEYDOWN:
		switch (LOWORD(wParam)) {
		case VK_RIGHT:
			x = min(x+10, 700);
			break;
		case VK_LEFT:
			x = max(x- 10, 10);
			break;
		case VK_UP:
			y = max(y-10, 10);
			break;
		case VK_DOWN:
			y = min(y+10, 530);
			break;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, x, y, x + 10, y + 10);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}