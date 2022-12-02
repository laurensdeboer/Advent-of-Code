#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    FILE *file;
    file = fopen("../data.txt", "r");

    if (file == NULL)
        printf("Failed to open file...");

    int mc = most_calories(file);
    printf("Answer = %d\n", mc);

    return 0;
}

/*
 *
 *  Function: most_calories(FILE *file)
 *  -----------------------------------
 *  Finds the elf carrying the most calories of food and returns this amount
 * 
 *  Parameter
 *      file:   File with input data
 * 
 *  Returns
 *      most_calories: Most calories that an elf was carrying
 * 
 */
int most_calories(FILE *file)
{
    // Because the amount of elves is unknown, we'll just assume it's 1000 max
    int arr[ARRAY_SIZE];

    // Filling the array with -1 makes it easy to find where the real calorie data ends later on
    for (int i = 0; i < ARRAY_SIZE; i++)    arr[i] = -1;

    int calories = 0, idx = 0;
    char line[MAX_LINE_LEN];

    // Loops over each line in file, puts every elves calories in new array spot
    while(fgets(line, MAX_LINE_LEN, file) != NULL)
    {
        int to_int = atoi(line);
        if (to_int != 0)
        {
            calories += to_int;
        }

        else if (to_int == 0)
        {
            arr[idx] = calories;
            calories = 0;
            idx++;
        }
    }

    // Fills the last array spot manually, because end of file is not a blank line
    arr[idx] = calories; 

    int most_calories = 0;

    // Loops over the calorie amounts, saves the largest calorie amount
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i] == -1)
            break;
        else
        {
            if (arr[i] >= most_calories)
                most_calories = arr[i];
        }
    }
        
    return most_calories;
}