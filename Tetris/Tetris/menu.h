#pragma once

#include "main.h"

//extern char* arGameScore[10];
extern int arGameScore[10];

int PrintingMainMenu();

void setGameScore(int nInput);
void showRanking();

void rankingFileInput();
void rankingFileOutput();

BOOL finishGame();