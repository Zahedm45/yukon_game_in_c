#include <stdio.h>
#include <stdlib.h>
#include "utility.c"
#include <string.h>

Game_board *game_board;

void replace_char(char *string, char new);

int main() {

    char input[2];
    char message_output[20] = "";
    int length = 2;

    // Initialize game board
    starting_point();
    initialize_card_deck(1);
    game_board = initialize_game_board(card_deck);
    display_game_board(game_board);
    save_game_board(game_board);

    // Main game loop
    while(strcmp(input, "stop") != 0) {

        printf("LAST Command: \n");
        printf("Message: ");
        printf("%s \n", message_output);
        printf("INPUT > \t");
        scanf("%s", &input);
        printf("\n");

        if(strcmp(input, "LD") == 0) {
            strcpy(message_output, "OK");
            //printf("You entered %*.*s\n", length, length, input);
        } else {
            strcpy(message_output, "Unknown command");
        }

    }


}


