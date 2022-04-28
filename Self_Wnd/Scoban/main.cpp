#include <Windows.h>
#include "resource.h"
/* 위도우용 변수들*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszClass = TEXT("Scoban");
HINSTANCE g_hInst;
HWND g_hWnd;

/* 게임 로직용 변수들*/
int MemMap[MAX_HEIGHT][MAX_WIDTH];
HBITMAP hBitWall, hBitBox, hBitMan;
HBITMAP hBitObject[4];
enum { WALL, BOX, MAN, WAY };
const int stage = 3;

int px, py;

int Map[stage][MAX_HEIGHT][MAX_WIDTH] = {
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
	}
};

/* 비트맵 관련 함수*/
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);
void InitBitmap();
void DestroyBitmap();

void CheckPlayerPos();
void Move(int key);


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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {

	int x, y;
	BITMAP bit;
	HDC hdc; PAINTSTRUCT ps;

	switch (iMessage) {	
	case WM_CREATE:
		g_hWnd = hwnd;
		InitBitmap();
		GetObject(hBitObject[0], sizeof(BITMAP), &bit);
		x = bit.bmWidth;
		y = bit.bmHeight;
		SetWindowPos(hwnd, NULL, 0, 0, x * MAX_WIDTH * 2, (y+3) * MAX_HEIGHT, SWP_NOMOVE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < MAX_WIDTH; i++) {
			for (int j = 0; j < MAX_HEIGHT; j++) {
				DrawBitmap(hdc, i*32, j *32, hBitObject[Map[0][j][i]]);
			}
		}
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		DestroyBitmap();
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit) {
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;
	int bx, by;
	
	if (hBit == NULL) return;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);
	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;
	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);
	
	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void InitBitmap() {
	hBitObject[WALL] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_WALL));
	hBitObject[BOX] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BOX));
	hBitObject[MAN] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MAN));
	hBitObject[WAY] = NULL;
}

void DestroyBitmap() {
	DeleteObject(hBitObject[WALL]);
	DeleteObject(hBitObject[BOX]);
	DeleteObject(hBitObject[MAN]);
}

void CheckPlayerPos() {
	for (int i = 0; i < MAX_WIDTH; i++) {
		for (int j = 0; j < MAX_HEIGHT; j++) {
			if (Map[0][j][i] == 2) {
				px = i;
				py = j;
			}
		}
	 }
}

void Move(int key) {
	switch (key) {
	case VK_LEFT:
		
	}
}