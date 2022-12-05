#include <stdio.h>

#ifndef MAIN_H
#define MAIN_H

#define STR_LEN_MAX     100
#define CHAR_AMT        52
#define SIZE_ALPHABET   26

#define LC_BOUND_LOWER  96
#define LC_BOUND_UPPER  123
#define UC_BOUND_LOWER  64
#define UC_BOUND_UPPER  91

int calculate_result(FILE *file);
void count_char_appearance(int *lc_arr, int *uc_arr, char *s);
void check_common_chars(int *c1, int *c2, int *score);

#endif