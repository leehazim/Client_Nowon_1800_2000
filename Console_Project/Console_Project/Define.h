#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <Time.h>

#define MAXENEMY 10
#define TRUE 1
#define FALSE 0

typedef struct tag_Player {
	int x, y;
	int dx, dy;
	char Shape;
}Player;

typedef struct tag_enemy {
	int exist;
	int x, y;
	int dx, dy;
	int nStay, nFrame, Range;
	char Shape;
}Enemy;

void SetCursorXY(int x, int y);