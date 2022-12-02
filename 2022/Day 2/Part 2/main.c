#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    FILE *file = fopen("../data.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file...");
        return -1;
    }

    int answer = get_player_score(file);  
    printf("Answer = %d\n", answer);

    return 0;
}

/*
 *
 *  Function: get_player_score(FILE *file)
 *  -----------------------------------
 *  Finds the score of the player after the game of rock paper scissors ends
 * 
 *  Parameter
 *      file: File with input data
 * 
 *  Returns
 *      player_score: Final score of the player
 * 
 */
int get_player_score(FILE *file)
{
    char game_ending, opponent;

    int idx = 0, player_score = 0;
    int lut_player_loses[LUT_SIZE] = {2, 0, 1};
    int lut_player_wins[LUT_SIZE] = {1, 2, 0};
    
    // Loop over input data file
    while(fscanf(file, "%c %c\n", &opponent, &game_ending) != EOF)
    {
        int move_opp    = get_move(opponent);
        int end_of_game = get_move(game_ending); 
        int move_player;
 
        // Determine player move and score based on how the game should end
        switch (end_of_game)
        {
            case 0:
                move_player = lut_player_loses[move_opp];
                player_score += SCORE_LOST + (move_player + 1);
                break;
            
            case 1:
                move_player = move_opp;
                player_score += SCORE_DRAW + (move_player + 1);
                break;

            case 2:
                move_player = lut_player_wins[move_opp]; 
                player_score += SCORE_WIN + (move_player + 1);
                break;
        }

        idx++;
    }

    return player_score;
}

/*
 *
 *  Function: get_move(char c)
 *  -----------------------------------
 *  Converts move from characters to numbers
 * 
 *  Parameter
 *      c: Character to convert
 * 
 *  Returns
 *      0, 1 or 2 based on the character
 * 
 */
char get_move(char c)
{
    switch (c)
    {
        case 'A':
        case 'X':
            return 0;   // Rock & Player lose representation
        case 'B':
        case 'Y':
            return 1;   // Paper & Draw representation
        case 'C':
        case 'Z':
            return 2;   // Scissors & Player win representation
    }
}