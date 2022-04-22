#include <stdio.h>
#include <stdlib.h>
#include "utility.c"



int main() {

/*    initialize_card_deck();
    print_out();*/


    initialize_card_deck();

    print_out();
    initialize_game_board(card_deck);
    return 0;
}




