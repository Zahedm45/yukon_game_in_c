#include <stdio.h>
#include <stdlib.h>
#include "utility.c"

Blocks *game_board;

int main() {

/*    initialize_card_deck();
    print_out();*/


    initialize_card_deck();

    //print_out();
    game_board = initialize_game_board(card_deck);
    print_card_deck(card_deck);

    display_card_deck(game_board);

    free_game_board(&game_board);
    display_card_deck(game_board);
    return 0;
}




