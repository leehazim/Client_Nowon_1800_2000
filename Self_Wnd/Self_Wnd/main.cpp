#include "Player.h"
#include <Math.h>

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
	HBRUSH MyBrush, OldBrush;

	static Player *P;
	static int enemyX, enemyY;
	static double distance, total;
	int dx, dy;

	switch (msg) {
	case WM_CREATE:
		P = new Player;
		enemyX = enemyY = 100;
		SetTimer(hwnd, 1, 20, NULL);
		return 0;
		
	case WM_TIMER:
		total = pow((P->GetX() - enemyX), 2) + pow((P->GetY() - enemyY), 2);
		distance = sqrt(total);
		distance = 1.0;
		if (distance < 10.0 /*&& distance > 0*/) {
			if ((P->GetX() - enemyX) > 0)	dx = +1;
			else							dx = -1;

			if ((P->GetY() - enemyY) > 0)	dy = +1;
			else							dy = -1;

			enemyX += dx;
			enemyY += dy;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_KEYDOWN:
		P->Move(LOWORD(wParam));
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		//P->Draw(hwnd);
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, P->GetX(), P->GetY(), P->GetX() + 10, P->GetY() + 10);
		MyBrush = CreateSolidBrush(RGB(255, 0, 0));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

		Rectangle(hdc, enemyX, enemyY, enemyX + 10, enemyY + 10);
		DeleteObject(SelectObject(hdc, OldBrush));
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		delete P;
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}