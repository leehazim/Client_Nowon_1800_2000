#include "Bullet.h"

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
const int MAXENEMY = 20;
Player P;
Bullet* B[10];
Enemy* E[MAXENEMY];
AutoMove* A[30];

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;
	HWND MenuWnd;
	int i;
	int key;

	switch (msg) {
	case WM_CREATE:
		/* 게임 시작시 난수발생기 생성*/
		srand(time(NULL)); 
		/* 게임 시작과 동시에 적군 만들어질 메모리 확보*/
		for (i = 0; i < 30; i++) {
			if (i < 10) A[i] = new Bullet(P);
			else A[i] = new Enemy(&P);
		}
		/*for (i = 0; i < MAXENEMY; i++) {
			E[i] = new Enemy(&P);
			if (i < 10) B[i] = new Bullet(P);
		}*/
		SetTimer(hwnd, 1, 20, NULL);
		return 0;

	case WM_TIMER:
		/* 1000분의 1 확률로 적군 생성*/
		for (i = 0; i < MAXENEMY; i++) if (!(rand() % 1000)) E[i]->SetExist(true);
		/* 적군 움직임 신호*/
		for (i = 0; i < MAXENEMY; i++) {
			if (!A[i]->GetExist()) continue;
			A[i]->Move();
		/*	if (!E[i]->GetExist()) continue;
			E[i]->Move();
			if (i < 10) {
				if (!B[i]->getExist()) continue;
				B[i]->Move();
			}*/
		}
		/*for (i = 0; i < 10; i++) {
			if (!B[i]->getExist()) continue;
			B[i]->Move();
		}*/

		/* 플레이어와 적군 충돌감지*/
		for (i = 0; i < MAXENEMY; i++) {
			if (E[i]->IsCrash(&P)) SendMessage(hwnd, WM_DESTROY, 0, 0);
			for (int j = 0; j < 10; j++) B[j]->IsCrash(E[i]);
		}
		
		/* 총알과 적군 충돌감지*/
		/*for (i = 0; i < MAXENEMY; i++) 
			for (int j = 0; j < 10; j++) B[j]->IsCrash(E[i]);*/
			
		
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_KEYDOWN:
		/* 키 입력으로 플레이어 이동및 총알 방향 설정*/
		key = LOWORD(wParam);
		P.Move(key);
		for (i = 0; i < 10; i++) {
			if (B[i]->GetExist() == false) { B[i]->Make(key, key, P); break; }
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		/* 키 입력시마다 좌표 다시 검사해서 플레이어 그리기*/
		P.Draw(hdc);
		
		/* wm_timer 발생시마다 적군들의 좌표들을 다시 받아서 다시 그림*/
		for (i = 10; i < MAXENEMY+10; i++) {
			if (!E[i]->GetExist()) continue;
			E[i]->Draw(hdc);
		}
		/* WM_TIMER 발생시마다 총알들의 좌표를 다시 받아서 다시 그림*/
		for (i = 0; i < 10; i++) {
			if (!B[i]->GetExist()) continue;
			B[i]->Draw(hdc);	
		}
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		/* 확보해 두었던 적군 총알들을 메모리 해제*/
		for (i = 0; i < MAXENEMY; i++) delete E[i];
		for (i = 0; i < 10; i++)	delete B[i];
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