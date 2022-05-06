#include <stdio.h>
#include <stdlib.h>
#include "utility.c"
#include <string.h>

Game_board *game_board;

int main(void) {


    char input[2];
    int length = 2;

    // Initialize game board
    starting_point();
    initialize_card_deck(1);
    game_board = initialize_game_board(card_deck);

    display_game_board(game_board);


    set_foundation(&game_board, 1, "C2");
    save_game_board_on_pc(game_board);


    game_board = open_game_board_from_pc("game_board");
    display_game_board(game_board);




    //game_board = open_game_board_from_pc("game_board");
    //display_game_board(game_board);


    // Main game loop
    while(strcmp(input, "stop") != 0) {


        printf("LAST Command: \n");
        printf("Message: \n");
        printf("INPUT > \t");
        scanf("%s", &input);

        printf("You entered %*.*s\n", length, length, input);
    }



    return 0;
}




