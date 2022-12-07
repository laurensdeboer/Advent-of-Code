#include <stdio.h>

#ifndef MAIN_H
#define MAIN_H

char get_array_index(char char_to_check);
char *loop_file(FILE *f);
char find_badge(char *ptr_elf_group);
char get_array_char(int to_char);

#define OFFSET_LC           97
#define OFFSET_UC           39
#define ELF_GROUP           3
#define CHARS               52 
#define BADGE_AMT           3     
#define LOWERCASE_BOUND     26

#endif