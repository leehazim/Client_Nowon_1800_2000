#include "Bullet.h"

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
 Player P;
 Bullet* B[10];
 Enemy* E[MAXENEMY];

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;
	HWND MenuWnd;
	int i;
	int key;

	switch (msg) {
	case WM_CREATE:
		/* ���� ���۽� �����߻��� ����*/
		srand(time(NULL)); 

		/* ���� ���۰� ���ÿ� ���� ������� �޸� Ȯ��*/
		for (i = 0; i < MAXENEMY; i++) 	E[i] = new Enemy(&P);

		/* �Ѿ˵� ������� �ڸ� Ȯ��*/
		for (i = 0; i < 10; i++)	B[i] = new Bullet(P);

		SetTimer(hwnd, 1, 20, NULL);
		return 0;

	case WM_TIMER:
		/* 1000���� 1 Ȯ���� ���� ����*/
		for (i = 0; i < MAXENEMY; i++) if (!(rand() % 1000)) E[i]->SetExist(true);
		/* ���� ������ ��ȣ*/
		for (i = 0; i < MAXENEMY; i++) {
			if (!E[i]->GetExist()) continue;
			E[i]->Move();
		}

		for (i = 0; i < 10; i++) {
			if (!B[i]->getExist()) continue;
			B[i]->Move(P);
		}
		/* �÷��̾�� ���� �浹����*/
		for (i = 0; i < MAXENEMY; i++) if (E[i]->IsCrash(&P)) SendMessage(hwnd, WM_DESTROY, 0, 0); 
		
		/* �Ѿ˰� ���� �浹����*/
		for (i = 0; i < MAXENEMY; i++) 
			for (int j = 0; j < 10; j++) B[j]->IsCrash(E[i]);
			
		
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_KEYDOWN:
		/* Ű �Է����� �÷��̾� �̵��� �Ѿ� ���� ����*/
		key = LOWORD(wParam);
		P.Move(key);
		for (i = 0; i < 10; i++) {
			if (B[i]->getExist() == false) { B[i]->Make(key, key, P); break; }
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		/* Ű �Է½ø��� ��ǥ �ٽ� �˻��ؼ� �÷��̾� �׸���*/
		P.Draw(hdc);
		
		/* wm_timer �߻��ø��� �������� ��ǥ���� �ٽ� �޾Ƽ� �ٽ� �׸�*/
		for (i = 0; i < MAXENEMY; i++) {
			if (!E[i]->GetExist()) continue;
			E[i]->Draw(hdc);
		}
		/* WM_TIMER �߻��ø��� �Ѿ˵��� ��ǥ�� �ٽ� �޾Ƽ� �ٽ� �׸�*/
		for (i = 0; i < 10; i++) {
			if (!B[i]->getExist()) continue;
			B[i]->Draw(hdc);	
		}
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		/* Ȯ���� �ξ��� ���� �Ѿ˵��� �޸� ����*/
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