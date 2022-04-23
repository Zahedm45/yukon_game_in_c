#include <stdio.h>
#include <stdlib.h>
#include "utility.c"

Game_board *game_board;

int main() {

/*    initialize_card_deck();
    print_out();*/

    starting_point();
    initialize_card_deck();

    //print_out();
    game_board = initialize_game_board(card_deck);
    set_foundation(&game_board, 1, "H2");
    set_foundation(&game_board, 4, "H1");

    display_card_deck(game_board);

    //free_game_board(&game_board);
    //display_card_deck(game_board);
    return 0;
}




