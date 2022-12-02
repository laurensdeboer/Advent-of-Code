#include <stdio.h>

#ifndef MAIN_H
#define MAIN_H

int get_player_score(FILE *file);
char get_move(char c);

#define VALUE_ROCK      1
#define VALUE_PAPER     2
#define VALUE_SCISSORS  3

#define SCORE_LOST      0
#define SCORE_DRAW      3
#define SCORE_WIN       6

#define LUT_SIZE        3

#endif