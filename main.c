#include <stdio.h>
#include <stdlib.h>
#include "utility.c"

Game_board *game_board;

int main() {

    starting_point();
    initialize_card_deck(1);
    game_board = initialize_game_board(card_deck);
    display_game_board(game_board);
    save_game_board(game_board);

    return 0;
}




