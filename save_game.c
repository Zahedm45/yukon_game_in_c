//
// Created by MD. Zahed on 23/04/2022.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>



void save_game_board_helper(Card *block, FILE *fpointer, char block_num[]) {
    fprintf(fpointer, block_num);
    fprintf(fpointer, "\n");

    while (block != NULL) {
        char arr[5];

        arr[0] = block->suites_value[0];
        arr[1] = block->suites_value[1];
        char face_up = block->face_up + '0';
        arr[2] = face_up;
        arr[3] = '\n';
        fprintf(fpointer, arr);

        block = block->next;
    }
    fprintf(fpointer, "end\n");
}



void save_game_board_on_pc(Game_board *board) {
    FILE *fpointer;
    fpointer = fopen("game_board.text", "w");



    Card *block = board->block1;
    save_game_board_helper(block, fpointer, "block1");

    block = board->block2;
    save_game_board_helper(block, fpointer, "block2");

    block = board->block3;
    save_game_board_helper(block, fpointer, "block3");

    block = board->block4;
    save_game_board_helper(block, fpointer, "block4");

    block = board->block5;
    save_game_board_helper(block, fpointer, "block5");


    block = board->block6;
    save_game_board_helper(block, fpointer, "block6");

    block = board->block7;
    save_game_board_helper(block, fpointer, "block7");


    fprintf(fpointer, "foundation\n");

    fprintf(fpointer, "%s\n", board->foundation1);
    fprintf(fpointer, "%s\n", board->foundation2);
    fprintf(fpointer, "%s\n", board->foundation3);
    fprintf(fpointer, "%s\n", board->foundation4);







    fclose(fpointer);
}




Card *single_line(FILE *fPointer){

    Card *block;
    Card *block_head = NULL;

    char singe_word[4];
    fgets(singe_word, 4, fPointer);

    while (strcmp(singe_word, "end") != 0) {
        fgets(singe_word, 4, fPointer);

        char i = singe_word[0];

        if (i != 'C' && i != 'H' && i != 'D' && i != 'S') {
            continue;
        }

        //printf("some %s\n", singe_word);
        Card *newCard = malloc(sizeof(Card));
        newCard->suites_value[0] = singe_word[0];
        newCard->suites_value[1] = singe_word[1];
        newCard->face_up = (int) singe_word[2];

        if (block_head == NULL) {
            //puts(newCard->suites_value);
            block_head = newCard;
            block = block_head;

/*            puts("ami");
            puts(newCard->suites_value);*/
        } else {
            block->next = newCard;
            block = block->next;
        }


        //puts(newCard->suites_value);

    }

    return block_head;
}

char * foundation_from_file(FILE *fPointer) {

    char *fv = malloc(sizeof(char));
    char i;

    while (!feof(fPointer)) {
        fgets(fv, 3, fPointer);
        i = fv[0];

        if (i == 'C' || i == 'H' || i == 'D' || i == 'S' || i == '[') {
            return fv;
        }
    }
    return NULL;
}

Game_board *open_game_board_from_pc(char board_name[]) {

    char with_format[70];
    stpcpy(with_format, board_name);
    strcat(with_format, ".text");
    FILE *file_pointer = fopen(with_format, "r");

    Game_board *gameBoard = malloc(sizeof(Game_board));
    char line[7];
    while (!feof(file_pointer)) {
        fgets(line, 7, file_pointer);

        //printf("here %s\n", line);


        if ( strcmp(line, "block1") == 0 ) {
            gameBoard->block1 = single_line(file_pointer);

        }

        else if (strcmp(line, "block2") == 0) {
            gameBoard->block2 = single_line(file_pointer);
        }


        else if (strcmp(line, "block3") == 0) {
            gameBoard->block3 = single_line(file_pointer);
        }

        else if (strcmp(line, "block4") == 0) {
            gameBoard->block4 = single_line(file_pointer);
        }

        else if (strcmp(line, "block5") == 0) {
            gameBoard->block5 = single_line(file_pointer);
        }

        else if (strcmp(line, "block6") == 0) {
            gameBoard->block6 = single_line(file_pointer);
        }

        else if (strcmp(line, "block7") == 0) {
            gameBoard->block7 = single_line(file_pointer);
        }

        else if (strcmp(line, "founda") == 0) {

            char *f1 = foundation_from_file(file_pointer);
            strcpy(gameBoard->foundation1, f1);

            char *f2 = foundation_from_file(file_pointer);
            strcpy(gameBoard->foundation2, f2);

            char *f3 = foundation_from_file(file_pointer);
            strcpy(gameBoard->foundation3, f3);


            char *f4 = foundation_from_file(file_pointer);
            strcpy(gameBoard->foundation4, f4);



            puts(gameBoard->foundation4);



/*            foundation_from_file(file_pointer, (char **) &(gameBoard->foundation2));
            foundation_from_file(file_pointer, (char **) &(gameBoard->foundation3));
            foundation_from_file(file_pointer, (char **) &(gameBoard->foundation4));*/
            break;
        }

    }
    fclose(file_pointer);

    printf("hello %s\n", gameBoard->block2->next->suites_value);

    return gameBoard;

}