#pragma once

#include "main.h"

extern S_Ranking sRanking[10];

int PrintingMainMenu();

void sortGameRanking(char* sUserName, int nInput, int nRankingIdx);
void showRanking();
void gameOver(int nScore);
void saveRanking(int nScore);

void readFileRanking();
void writeFileranking();

BOOL finishGame();