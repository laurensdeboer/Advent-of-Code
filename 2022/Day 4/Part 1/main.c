#include <stdio.h>

#include "main.h"

int main()
{
    FILE *file = fopen("../data.txt", "r");
    if (file == NULL)
        return -1;

    int count = 0;

    while (!feof(file))
        contains_another(file, &count);
        
    printf("Answer = %d\n", count);

    return 0;
}

void contains_another(FILE *f, int *count)
{
    int elf1_1, elf1_2, elf2_1, elf2_2;
    fscanf(f, "%d-%d,%d-%d\n", &elf1_1, &elf1_2, &elf2_1, &elf2_2);
    if (elf1_1 <= elf2_1 && elf1_2 >= elf2_2 || elf1_1 >= elf2_1 && elf1_2 <= elf2_2)
        (*count)++;
}