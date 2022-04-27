#include <Windows.h>
#include "resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszClass = TEXT("Scoban");
HINSTANCE g_hInst;
HWND g_hWnd;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hRrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hWnd;
	WNDCLASS ws;
	MSG Message;
	g_hInst = hInstance;

	ws.style = CS_HREDRAW | CS_VREDRAW;
	ws.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	ws.hInstance = hInstance;
	ws.lpfnWndProc = WndProc;
	ws.cbClsExtra = 0;
	ws.cbWndExtra = 0;
	ws.hCursor = LoadCursor(NULL, IDC_ARROW);
	ws.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	ws.lpszClassName = lpszClass;
	ws.lpszMenuName = NULL;
	RegisterClass(&ws);

	DWORD style = WS_OVERLAPPEDWINDOW;
	style &= ~WS_THICKFRAME;
	hWnd = CreateWindow(lpszClass, lpszClass, style,
						CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}
int Map[MAX_WIDTH][MAX_HEIGHT];
HBITMAP hBitWall, hBitBox, hBitMan;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {

	int x, y;
	BITMAP bit;
	switch (iMessage) {	
	case WM_CREATE:
		g_hWnd = hwnd;
		hBitWall = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_WALL));
		hBitBox = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BOX));
		hBitMan = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MAN));
		GetObject(hBitWall, sizeof(BITMAP), &bit);
		x = bit.bmWidth;
		y = bit.bmHeight;
		SetWindowPos(hwnd, NULL, 0, 0, x * MAX_WIDTH * 2, y * MAX_HEIGHT, SWP_NOMOVE);
		return 0;

	case WM_DESTROY:
		DeleteObject(hBitWall);
		DeleteObject(hBitBox);
		DeleteObject(hBitMan);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}