#include <stdio.h>
#include <string.h>

#include "main.h"

int main()
{
    FILE *file = fopen("../data.txt", "r");
    if (file == NULL)
        return -1;

    int priority_sum = 0;
    
    while (!feof(file))
    {
        char *arr = loop_file(file);
        char c = find_badge(arr);
        priority_sum += (get_array_index(c) + 1);
    }

    printf("Answer = %d\n", priority_sum);

    return 0;
}

char *loop_file(FILE *f)
{
    char elf_amt = 0;                   // To keep track of elves found
    static char items[CHARS] = {0};     // For storing which items (characters) are found

    // Loop until a three-elf group is found
    while(elf_amt != ELF_GROUP)
    {
        // Read a new character
        char current = fgetc(f);

        // If newline or end of file found, increase elves found
        if (current == '\n' || current == -1)
            elf_amt++;

        else
        {
            // Get array index needed for storing the character
            char current_idx = get_array_index(current);

            // Set a flag at the right array index to know which character occurred
            if (items[current_idx] == elf_amt)
                items[current_idx]++;
        }
    }        

    return items;
}

char find_badge(char *ptr_elf_group)
{
    int badge;

    // Find which item occured in each elves rucksack
    for (int i = 0; i < CHARS; i++)
        if (ptr_elf_group[i] == BADGE_AMT)
            badge = get_array_char(i);

    // Reset the array for the next three-elf group
    for (int i = 0; i < CHARS; i++)
        ptr_elf_group[i] = 0;

    return badge;
}

char get_array_char(int to_char)
{
    // Convert an index back to an alphabet character
    if (to_char < LOWERCASE_BOUND)
        return to_char + OFFSET_LC;
    else if (to_char >= LOWERCASE_BOUND)
        return to_char + OFFSET_UC;
}


char get_array_index(char char_to_check)
{
    // Return array index based on character being lowercase/uppercase
    if (char_to_check >= 'a')
        return (char_to_check - OFFSET_LC);
    else
        return (char_to_check - OFFSET_UC);
}