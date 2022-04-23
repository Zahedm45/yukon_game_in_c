//
// Created by MD. Zahed on 23/04/2022.
//
#include "blocks.c"

void save_game_board_helper(Card *block, FILE *fpointer) {
    while (block != NULL) {

        char arr[5];

        arr[0] = block->suites_value[0];
        arr[1] = block->suites_value[1];
        char face_up = block->face_up + '0';
        arr[2] = face_up;
        arr[3] = ' ';
        fprintf(fpointer, arr);

        block = block->next;
    }
}



void save_game_board(Game_board *board) {
    FILE *fpointer;
    fpointer = fopen("game_board.text", "w");



    Card *block = board->block1;






    fclose(fpointer);
}



