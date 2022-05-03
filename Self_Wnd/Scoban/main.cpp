#include <Windows.h>
#include "resource.h"
/* 위도우용 변수들*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszClass = TEXT("Scoban");
HINSTANCE g_hInst;
HWND g_hWnd;

/* 게임 로직용 변수들*/
enum tag_tile{ WALL, BOX, MAN, GOAL, WAY };
HBITMAP hBitObject[5];
const int stage = 3;
int px = -1, py = -1;

/* 맵 플레이용 배열*/
int MemMap[MAX_HEIGHT][MAX_WIDTH];
/* 맵 저장용 배열*/
 tag_tile Map[stage][MAX_HEIGHT][MAX_WIDTH] = {
	{
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WAY,WAY,GOAL,WAY,WAY,WALL,WALL,WALL},
	{WALL,WALL,WAY,WAY,BOX,WAY,WAY,WALL,WALL,WALL},
	{WALL,WALL,WAY,WAY,WAY,WAY,WAY,WALL,WALL,WALL},
	{WALL,WALL,WAY,WAY,MAN,WAY,WAY,WALL,WALL,WALL},
	{WALL,WALL,WAY,WAY,WAY,WAY,WAY,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	}
};

 void InitWindow();

/* 비트맵 관련 함수*/
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);
void InitBitmap();
void DestroyBitmap();
void Render(HDC hdc);


void ResetGame();
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
		InitWindow();
		return 0;

	case MESSAGE_START:
		ResetGame();
		return 0;

	case WM_KEYDOWN:
		switch (wParam) {
		case 'S': SendMessage(hwnd, MESSAGE_START, 0, 0); break;		  
		}
		Move(wParam);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Render(hdc);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		DestroyBitmap();
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}

void InitWindow() {
	int x, y;
	BITMAP bit;

	GetObject(hBitObject[0], sizeof(BITMAP), &bit);
	x = bit.bmWidth;
	y = bit.bmHeight;
	SetWindowPos(g_hWnd, NULL, 0, 0, x * MAX_WIDTH * 2, (y + 3) * MAX_HEIGHT, SWP_NOMOVE);
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
	hBitObject[GOAL] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_GOAL));
	hBitObject[WAY] = NULL;
}

void DestroyBitmap() {
	for (int i = 0; i < 4; i++)  DeleteObject(hBitObject[i]);
}
void Render(HDC hdc) {
	for (int i = 0; i < MAX_WIDTH; i++) {
		for (int j = 0; j < MAX_HEIGHT; j++) {
			DrawBitmap(hdc, i * 32, j * 32, hBitObject[MemMap[j][i]]);
		}
	}
}

void ResetGame() {
	for (int i = 0; i < MAX_WIDTH; i++) {
		for (int j = 0; j < MAX_HEIGHT; j++) {
			if (Map[0][j][i] == 2) {
				px = i;
				py = j;
			}
			MemMap[j][i] = Map[0][j][i];
		}
	}
}

void Move(int key) {
	if (px == -1 || py == -1)return;
	int dx = 0, dy = 0;
	switch (key) {
	case VK_LEFT: dx = -1;	break;
	case VK_RIGHT:dx = +1;	break;
	case VK_UP:	dy = -1;	break;
	case VK_DOWN: dy = +1;	break;
	}
	/*MemMap[py][px] = MAN;*/

	if (MemMap[py + dy][px + dx] != WALL) {
		if (MemMap[py + dy][px + dx] == WAY) {
			if (Map[0][py][px] == GOAL) {
				MemMap[py][px] = GOAL;
				MemMap[py + dy][px + dx] = MAN;
			}
			else {
				MemMap[py][px] = WAY;
				MemMap[py + dy][px + dx] = MAN;
			}
		}
		else if(MemMap[py + dy][px + dx] == GOAL) {
			if (Map[0][py][px] == GOAL) {
				MemMap[py][px] = GOAL;
				MemMap[py + dy][px + dx] = MAN;
			}
			else {
				MemMap[py][px] = WAY;
				MemMap[py + dy][px + dx] = MAN;
			}
		}
	}
	else {
		dx = dy = 0;
	}
	py += dy;
	px += dx;
	InvalidateRect(g_hWnd, NULL, TRUE);
}