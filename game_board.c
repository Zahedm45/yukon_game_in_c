//
// Created by MD. Zahed on 22/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blocks.c"
#include "save_and_open_game_board.c"



Card *card_deck;
//Card *last_added_card_deck;



void add_node(const char val[2], int hidden);
void add_card_to_block(Card *block, const char val[2], int hidden);
void initialize_card_deck();
Game_board * initialize_game_board(Card *cards);
void free_game_board(Game_board *board);
void set_foundation(Game_board **game_board, int foundation_num, char card[]);




Game_board * initialize_game_board(Card *cards){


    Card *temp = cards;
    Game_board *new_board = malloc(sizeof(Game_board));

    new_board->block1 = malloc(sizeof(Card));
    new_board->block2 = malloc(sizeof(Card));
    new_board->block3 = malloc(sizeof(Card));
    new_board->block4 = malloc(sizeof(Card));
    new_board->block5 = malloc(sizeof(Card));
    new_board->block6 = malloc(sizeof(Card));
    new_board->block7 = malloc(sizeof(Card));



    int i = 0;
    while (temp != NULL) {

        switch ( i % 7 ) {
            case 0:
                add_card_to_block(new_board->block1, temp->suites_value, temp->face_up);
                break;
            case 1:
                add_card_to_block(new_board->block2, temp->suites_value, temp->face_up);
                break;
            case 2:
                add_card_to_block( new_board->block3, temp->suites_value, temp->face_up);
                break;
            case 3:
                add_card_to_block( new_board->block4, temp->suites_value, temp->face_up);
                break;
            case 4:
                add_card_to_block( new_board->block5, temp->suites_value, temp->face_up);
                break;
            case 5:
                add_card_to_block( new_board->block6, temp->suites_value, temp->face_up);
                break;
            case 6:
                add_card_to_block( new_board->block7, temp->suites_value, temp->face_up);
                break;

            default:
                puts("something is wrong initialize()");
                ;
        }

        i++;
        temp = temp->next;
    }




    strcpy(new_board->foundation1, "[]");
    strcpy(new_board->foundation2, "[]");
    strcpy(new_board->foundation3, "[]");
    strcpy(new_board->foundation4, "[]");





    return new_board;
}






void add_card_to_block(Card *block, const char val[2], int hidden){


    if (strcmp(block->suites_value, "") == 0) {
        block->suites_value[0] = val[0];
        block->suites_value[1] = val[1];
        block->face_up = hidden;

    } else {
        Card *temp = block;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        Card *newC = malloc(sizeof(Card));
        newC->suites_value[0] = val[0];
        newC->suites_value[1] = val[1];
        newC->face_up = hidden;
        newC->next = NULL;

        temp->next = newC;
    }

}





void initialize_card_deck(int face_val) {

    char values[13] = {'A' ,'2', '3', '4', '5', '6', '7', '8', '9',
                       'T', 'J', 'Q', 'K'};
    char suites[4] = {'C', 'D', 'H', 'S'};

    char val[2];
    /**
     * TODO
     * The allocated memory has to be freed
     */

/*    if (card_deck != NULL) {
        free_mem_block(card_deck->next);
        free(card_deck);

    }*/



    card_deck = malloc(sizeof(Card));

    for (int i = 0; i < sizeof(suites); ++i) {
        for (int j = 0; j < sizeof(values); ++j) {
            val[0] = suites[i];
            val[1] = values[j];
            //add_node(val, hidden);
            add_card_to_block(card_deck, val, face_val);
        }

    }
}




/*void add_node(const char val[2], int hidden) {
    Card *newC = malloc(sizeof(Card));
    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->face_up = hidden;

    if (card_deck != NULL) {
        last_added_card_deck->next = newC;
        last_added_card_deck = last_added_card_deck->next;

    } else {

        card_deck = newC;
        last_added_card_deck = newC;
    }

}*/




void free_game_board(Game_board *board) {

    free_mem_block(board->block1);
    free_mem_block(board->block2);
    free_mem_block(board->block3);
    free_mem_block(board->block4);
    free_mem_block(board->block5);
    free_mem_block(board->block6);
    free_mem_block(board->block7);

}


void set_foundation(Game_board **game_board, int foundation_num, char card[]){
    switch (foundation_num) {
        case 1:
            (*game_board)->foundation1[0] = card[0];
            (*game_board)->foundation1[1] = card[1];
            break;

        case 2:
            (*game_board)->foundation2[0] = card[0];
            (*game_board)->foundation2[1] = card[1];
            break;

        case 3:
            (*game_board)->foundation3[0] = card[0];
            (*game_board)->foundation3[1] = card[1];
            break;

        case 4:
            (*game_board)->foundation4[0] = card[0];
            (*game_board)->foundation4[1] = card[1];
            break;

        default:
            ;
    }


}


 Card *sub_set_card_visible(Card *block) {

    Card *new_block = block;

    while (block != NULL) {

        block->face_up = 1;

        block = block->next;
    }
    return new_block;
}


void set_cards_visible(Game_board **game_board) {

    (*game_board)->block1 = sub_set_card_visible((*game_board)->block1);
    (*game_board)->block2 = sub_set_card_visible((*game_board)->block2);
    (*game_board)->block3 = sub_set_card_visible((*game_board)->block3);
    (*game_board)->block4 = sub_set_card_visible((*game_board)->block4);
    (*game_board)->block5 = sub_set_card_visible((*game_board)->block5);
    (*game_board)->block6 = sub_set_card_visible((*game_board)->block6);
    (*game_board)->block7 = sub_set_card_visible((*game_board)->block7);

    sub_set_card_visible(card_deck);

}




void shuffle_card_deck_SI(int split_num) {


    Card *part_1 = malloc(sizeof(Card));
    Card *temp = card_deck;

    int i = 0;
    while (temp != NULL && i < split_num){
        add_card_to_block(part_1, temp->suites_value, temp->face_up);
        temp = temp->next;
        i++;
    }


    Card *part_2 = malloc(sizeof(Card));
    while (temp != NULL) {

        add_card_to_block(part_2, temp->suites_value, temp->face_up);
        temp = temp->next;
    }


    /**
     * TODO
     * Variable card_deck has to be freed.
     */


    card_deck = malloc(sizeof(Card));

    for (int j = 0; j < 52; ++j) {

        if (part_1 != NULL) {
            add_card_to_block(card_deck, part_1->suites_value, part_1->face_up);
            part_1 = part_1->next;

        }

        if(part_2 != NULL) {
            add_card_to_block(card_deck, part_2->suites_value, part_2->face_up);
            part_2 = part_2->next;
        }
    }


    //print_card_deck(card_deck);

}











/*Game_board * initialize_game_board(Card *cards){

    Card *temp = cards;
    Game_board *new_board = malloc(sizeof(Game_board));

    int j = 0;
    for (int i = 0; i < 7; ++i) {

        Card *new_block_head = NULL;
        Card *new_block_last_added;

        j++;
        for (int k = 0; k <j; ++k) {
            if (temp == NULL) {
                printf("Something went wrong. From initialize_game_board() %d %d", i, k);
                exit(0);
            }




            Card *newC = malloc(sizeof(Card));
            newC->suites_value[0] = temp->suites_value[0];
            newC->suites_value[1] = temp->suites_value[1];
            newC->face_up = temp->face_up;
            newC->next = NULL;

            temp = temp->next;

            if (new_block_head == NULL) {
                new_block_head = new_block_last_added = newC;


            } else {
                new_block_last_added->next = newC;
                new_block_last_added = new_block_last_added->next;

            }

        }

        switch_block(i, &new_board, new_block_head);


        if (i == 0) {
            j = 5;
        }
    }



    strcpy(new_board->foundation1, "[]");
    strcpy(new_board->foundation2, "[]");
    strcpy(new_board->foundation3, "[]");
    strcpy(new_board->foundation4, "[]");





    return new_board;
}*/
