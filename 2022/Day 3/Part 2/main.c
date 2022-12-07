#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    FILE *file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file...");
        return -1;
    }
    
    while (!feof(file))
    {
        char *arr = loop_file(file);
        char c = find_badge(arr);
        printf("Badge = %c\n", c);
    }

    return 0;
}

// Finds badge in elf group
char find_badge(char *ptr_elf_group)
{
    int badge;

    for (int i = 0; i < CHARS; i++)
    {
        printf("CHARR = %d\n", ptr_elf_group[i]);
        if (ptr_elf_group[i] == BADGE_AMT)
            badge = get_array_char(i);
    }

    for (int i = 0; i < CHARS; i++)
        ptr_elf_group[i] = 0;

    return badge;
}

char get_array_char(int to_char)
{
    if (to_char < LOWERCASE_BOUND)
        return to_char + OFFSET_LC;
    else if (to_char >= LOWERCASE_BOUND)
        return to_char + OFFSET_UC;
}

// Calculates in which array spot to place a 1 (indicating a character is found)
char get_array_index(char char_to_check)
{
    // Return array index based on character being lowercase/uppercase
    if (char_to_check >= 'a')
        return (char_to_check - OFFSET_LC);
    else
        return (char_to_check - OFFSET_UC);
}

char *loop_file(FILE *f)
{
    char str[50];
    char elve_amt = 0;
    static char items[CHARS] = {0};

    while(elve_amt != ELF_GROUP)
    {
        char c = fgetc(f);

        if (c == '\n' || c == -1)
        {
            elve_amt++;
            printf("Elf detected\n");
        }

        // Setting a flag at the right index to know which character occurred
        else
        {
            items[get_array_index(c)]++;
            printf("char = %c\n", c);
        }
    }        
    printf("\nElf group found\n");

    return items;
}
