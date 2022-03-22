#include "Player.h"

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
	static Player *P;

	switch (msg) {
	case WM_CREATE:
		P = new Player;
		return 0;

	case WM_KEYDOWN:
		P->Move(LOWORD(wParam));
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		P->Draw(hwnd);
		return 0;

	case WM_DESTROY:
		delete P;
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}