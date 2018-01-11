#pragma once

// 매크로 변수 및 구조체 등등
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


#define LIGHTGRAY 7 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 

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

void gotoxy(int x, int y);