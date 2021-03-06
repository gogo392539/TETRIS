#pragma once

// 매크로 변수 및 구조체 등등
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAPBLOCK "■"
#define MAPEMPTY "·"
#define BLOCK 111
#define EMPTY 222

#define BLOCKSIZE 4

#define START 1
#define RANK 2
#define EXIT 3

#define MAPWIDTH 14
#define MAPHEIGHT 26
#define PREMAPSIZE 6

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

typedef struct S_Ranking {
	char sUserName[256];
	int nScore;
} S_Ranking;

void gotoxy(int x, int y);