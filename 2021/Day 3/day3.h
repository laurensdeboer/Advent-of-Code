#ifndef DAY3_H
#define DAY3_H

#define CHARS_PER_LINE      12
#define LINE_AMOUNT         1000
#define CHARS_IN_FILE       (CHARS_PER_LINE * LINE_AMOUNT)
#define MAX_POWER           2048

#include <stdio.h>

int part_one(FILE *file);
int calculate_result(int *gamma, int *epsilon);
void *mob_per_column(char *all_chars, int *g, int *e);
char *array_from_file(FILE *file);

#endif