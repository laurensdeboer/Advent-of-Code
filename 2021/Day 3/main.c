#include <stdio.h>
#include <stdint.h>

#include "day3.h"

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL)
        printf("Failed to open file...");

    // Initialize final arrays
    int gamma[CHARS_PER_LINE], epsilon[CHARS_PER_LINE];
    
    // Get character array from original file
    char *char_array = array_from_file(fp);
    
    // Find most occuring bit per column from original file
    mob_per_column(char_array, gamma, epsilon);
    
    // Calculate final answer
    int result = calculate_result(gamma, epsilon);

    // Answer!
    printf("Answer = %d", result);

    return 0;
}

/*
 *  Function: array_from_file
 *  -------------------------
 *  Takes the file with binary data as input, and puts each character in an array
 * 
 *  Parameter(s)
 *      file: The input file to read from
 * 
 *  Returns
 *      all_chars: The array filled with the file contents
 */
char *array_from_file(FILE *file)
{
    static char all_chars[CHARS_IN_FILE];
    int i = 0;

    while(!feof(file))
    {
        char c = fgetc(file);
        if (c != '\n' && c != -1)
        {
            all_chars[i] = c;
            i++;
        }
    }

    fclose(file);
    return all_chars;
}

/*
 *  Function: mob_per_column (mob = most occurring bit)
 *  -------------------------
 *  Finds the most and least occuring bit per column of the original file and puts it in gamma and epsilon arrays
 * 
 *  Parameter(s)
 *      all_chars   : The array that contains the characters from the original file
 *      g           : Array to store the gamma values
 *      e           : Array to store the epsilon values
 *  
 */
void *mob_per_column(char *all_chars, int *g, int *e)
{
    int zero_count = 0, one_count = 0;
    int current_bit = 0;

    while (current_bit < CHARS_PER_LINE)
    {
        for (int i = current_bit; i < CHARS_IN_FILE; i += CHARS_PER_LINE)
        {
            if (all_chars[i] == '0')
                zero_count++;     
            else
                one_count++;
        }

        if (one_count >= zero_count)
        {
            g[current_bit] = 1;
            e[current_bit] = 0;   
        }    
        else
        {
            g[current_bit] = 0;
            e[current_bit] = 1;   
        }

        zero_count = 0, one_count = 0;
        current_bit++;
    }
}

/*
 *  Function: calculate_result
 *  -------------------------
 *  Converts binary gamma and epsilon data to decimal numbers, then multiplies them for the final answer
 * 
 *  Parameter(s)
 *      gamma   : Array with the gamma values in binary
 *      epsilon : Array with the epsilon values in binary
 * 
 *  Returns
 *      result  : Gamma and epsilon decimal values multiplied - final answer
 *  
 */
int calculate_result(int *gamma, int *epsilon)
{
    int idx = 0;
    for (int j = MAX_POWER; j != 1; j /= 2)
    {
        if (idx < 12)
        {
            if (gamma[idx] == 1)
            {
                gamma[idx] = j;
                epsilon[idx] = 0;
            }
                
            else
            {
                epsilon[idx] = j;
                gamma[idx] = 0;
            }  
            idx++;
        }       
    }

    int sum_gamma = 0, sum_epsilon = 0;
    for (int i = 0; i < CHARS_PER_LINE; i++)
    {
        sum_gamma += gamma[i];
        sum_epsilon += epsilon[i];
    }

    int result = (sum_gamma * sum_epsilon);
    return result;
}
