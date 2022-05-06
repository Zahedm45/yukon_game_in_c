//
// Created by MD. Zahed on 23/04/2022.
//
#include <stdio.h>
#include <string.h>


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
    fprintf(fpointer, "\n");
}



void save_game_board_on_pc(Game_board *board) {
    FILE *fpointer;
    fpointer = fopen("game_board.text", "w");



    Card *block = board->block1;
    save_game_board_helper(block, fpointer);

    block = board->block2;
    save_game_board_helper(block, fpointer);

    block = board->block3;
    save_game_board_helper(block, fpointer);

    block = board->block4;
    save_game_board_helper(block, fpointer);

    block = board->block5;
    save_game_board_helper(block, fpointer);


    block = board->block6;
    save_game_board_helper(block, fpointer);

    block = board->block7;
    save_game_board_helper(block, fpointer);




    fclose(fpointer);
}



void open_game_board_from_pc(char board_name[]) {


    FILE *file_pointer = fopen(board_name, "r");

    char line[200];
    while (!feof(file_pointer)) {
        fgets(line, 200, file_pointer);
        puts(line);
    }
    fclose(file_pointer);

}