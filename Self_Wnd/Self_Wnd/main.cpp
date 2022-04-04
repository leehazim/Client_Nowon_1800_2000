#include "Enemy.h"

#define MAXENEMY 20

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK MenuProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND g_hWnd;
LPCTSTR lpszClass = TEXT("Follow Rect");
LPCTSTR MenuClass = TEXT("Menu");

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

	WndClass.lpfnWndProc = MenuProc;
	WndClass.lpszClassName = MenuClass;
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
	HWND MenuWnd;
	int i;

	static Player* P;
	static Bullet* B[10];
	static Enemy* E[MAXENEMY];
	static int key;

	switch (msg) {
	case WM_CREATE:
		P = new Player;
		for (i = 0; i < MAXENEMY; i++) {
			E[i] = new Enemy(P);
			B[i] = new Bullet(P);
		}
		SetTimer(hwnd, 1, 20, NULL);
		return 0;

	/*case WM_LBUTTONDOWN:
		MenuWnd = CreateWindow(MenuClass, MenuClass, WS_POPUP | WS_VISIBLE | WS_CAPTION,
							   CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, hwnd, (HMENU)NULL,
							   g_hInst, NULL);
		return 0;*/

	case WM_TIMER:
		for (i = 0; i < MAXENEMY; i++) if (!(rand() % 1000)) E[i]->SetExist(true);
		for (i = 0; i < MAXENEMY; i++) {
			if (!E[i]->GetExist()) continue;
			E[i]->Move();
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_KEYDOWN:
		key = LOWORD(wParam);
		P->Move(key);
		for (i = 0; i < 10; i++) 
			if (B[i]->getExist() == false) {
				B[i]->Make(key, key);
			break;
		}
		
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		//P->Draw(hwnd);
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, P->GetX(), P->GetY(), P->GetX() + 10, P->GetY() + 10);
		MyBrush = CreateSolidBrush(RGB(255, 0, 0));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
		for (i = 0; i < MAXENEMY; i++) {
			if (!E[i]->GetExist()) continue;
			Rectangle(hdc, E[i]->GetX(), E[i]->GetY(), E[i]->GetX() + 10, E[i]->GetY() + 10);
		}
		DeleteObject(SelectObject(hdc, OldBrush));
		MyBrush = CreateSolidBrush(RGB(0, 0, 255));
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
		for (i = 0; i < 10; i++) {
			if (!B[i]->getExist()) continue;
			B[i]->Move();
			Rectangle(hdc, B[i]->GetX(), B[i]->GetY(), B[i]->GetX() + 10, B[i]->GetY() + 10);
		}
		DeleteObject(SelectObject(hdc, OldBrush));
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		delete P;
		for (i = 0; i < 10; i++) delete E[i];
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK MenuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {
	case WM_CREATE:
		CreateWindow(TEXT("button"), TEXT("Close"), WS_CHILD | WS_VISIBLE  | BS_PUSHBUTTON,
					 200, 100, 50, 20, hwnd, (HMENU)1, g_hInst, NULL);
		return 0;

	case WM_COMMAND:
		switch (wParam) {
		case 1: 
			SendMessage(hwnd, WM_DESTROY, 0, 0);
			break;
		}
		return 0;

	case WM_DESTROY:
		DestroyWindow(hwnd);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}