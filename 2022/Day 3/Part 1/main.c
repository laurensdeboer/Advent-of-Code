#include <stdio.h>
#include <string.h>

#include "main.h"

int main()
{
    FILE *file = fopen("../data.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file...");
        return -1;
    }

    int answer = calculate_result(file);
    printf("Answer = %d\n", answer);
    
    return 0;
}

/*
    Function: calculate_result
    --------------------------
    Calculates the final score

    Parameters:
        f --> The file to read data from

    Returns:
        score --> The answer of the puzzle
*/
int calculate_result(FILE *f)
{
    int compartment_one[CHAR_AMT] = {0}, compartment_two[CHAR_AMT] = {0};
    int score = 0;
    char str[STR_LEN_MAX];
    
    while(fgets(str, STR_LEN_MAX, f) != NULL)
    {
        count_char_appearance(compartment_one, compartment_two, str);
        check_common_chars(compartment_one, compartment_two, &score);
    }

    return score;
}

/*
    Function: count_char_appearance
    -------------------------------
    Finds the amount of each character that is in the input file

    Parameters:
        f       --> The file to read data from
        c1      --> Pointer to array for compartment one
        c2      --> Pointer to array for compartment two
        s       --> Pointer to string to read characters from
*/
void count_char_appearance(int *c1, int *c2, char *s)
{
    int item_amt = strlen(s);
    int compartment_len = item_amt / 2;
    int val_of_a = 'a', val_of_A = 'A', ascii_val;

    for (int i = 0; i < item_amt; i++)
    {
        ascii_val = (int)s[i];

        if (i < compartment_len)
        {
            if (ascii_val < UC_BOUND_UPPER && ascii_val > UC_BOUND_LOWER)
                c1[ascii_val - val_of_A + SIZE_ALPHABET]++;
            else if (ascii_val > LC_BOUND_LOWER && ascii_val < LC_BOUND_UPPER)                                 
                c1[ascii_val - val_of_a]++;
        }
        
        else
        {
            if (ascii_val < UC_BOUND_UPPER && ascii_val > UC_BOUND_LOWER)
                c2[ascii_val - val_of_A + SIZE_ALPHABET]++;
            else if (ascii_val > LC_BOUND_LOWER && ascii_val < LC_BOUND_UPPER)                                    
                c2[ascii_val - val_of_a]++;
        } 
    }
}

/*
    Function: check_common_chars
    ----------------------------
    Checks which characters appear in both the lower and upper compartment of the rucksack

    Parameters:
        c1      --> Pointer to array for compartment one
        c2      --> Pointer to array for compartment two
        score   --> To keep track of the character score
*/
void check_common_chars(int *c1, int *c2, int *score)
{
    for (int i = 0; i < CHAR_AMT; i++)
        if (c1[i] > 0 && c2[i] > 0)
            *score += (i + 1); 

    for (int i = 0; i < CHAR_AMT; i++)
    {
        c1[i] = 0;
        c2[i] = 0;
    }
}

