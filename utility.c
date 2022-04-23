//
// Created by MD. Zahed on 22/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "blocks.c"



Card *card_deck;
Card *last_added_card_deck;



void add_node(const char val[2], int hidden);
void add_card_to_block(Card **block, const char val[2], int hidden);
void free_mem(Card *mem);
void switch_block(int i, Blocks **board, Card *new_block_head);



Blocks * initialize_game_board(Card *cards){

    Card *temp = cards;
    Blocks *new_board = malloc(sizeof(Blocks));

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
            newC->face_up = 0;
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

    return new_board;
}


void switch_block(int i, Blocks **board, Card *new_block_head) {

    switch (i) {
        case 0:
            (*board)->block1 = new_block_head;
            break;

        case 1:
            (*board)->block2 = new_block_head;
            break;

        case 2:
            (*board)->block3 = new_block_head;
            break;

        case 3:
            (*board)->block4 = new_block_head;
            break;

        case 4:
            (*board)->block5 = new_block_head;
            break;

        case 5:
            (*board)->block6 = new_block_head;
            break;
        case 6:
            (*board)->block7 = new_block_head;
            break;

        default:
            printf("not found\n");
    }


}



void add_card_to_block(Card **block, const char val[2], int hidden){
    Card **temp = block;



    while ((*temp)->next!= NULL) {
        *temp = (*temp)->next;
    }

    Card *newC = malloc(sizeof(Card));
    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->face_up = hidden;
    newC->next = NULL;

    *temp = newC;

}



void helper_display_card_deck(Card *block, int block_num) {


    Card *temp = block;
    printf("Block: %d \t\t", block_num);
    while (temp != NULL) {
        printf("%s, %d\t", temp->suites_value, temp->face_up);
        temp = temp->next;
    }

    printf("\n");
}


void display_card_deck(Blocks *board){
    printf("C1\t\tC2\t\tC3\t\tC4\t\tC5\t\tC6\t\tC7\n");




    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");


    helper_display_card_deck(board->block1, 1);
    helper_display_card_deck(board->block2, 2);
    helper_display_card_deck(board->block3, 3);
    helper_display_card_deck(board->block4, 4);
    helper_display_card_deck(board->block5, 5);
    helper_display_card_deck(board->block6, 6);
    helper_display_card_deck(board->block7, 7);



}


void free_mem(Card *mem) {
    Card *temp;
    while (mem != NULL) {
        printf("heloooo");
        temp = mem;
        mem = mem->next;
        free(temp);
    }

}








void initialize_card_deck() {

    char values[13] = {'A' ,'2', '3', '4', '5', '6', '7', '8', '9',
                       'T', 'J', 'Q', 'K'};
    char suites[4] = {'C', 'D', 'H', 'S'};

    char val[2];

    for (int i = 0; i < sizeof(suites); ++i) {
        for (int j = 0; j < sizeof(values); ++j) {
            val[0] = suites[i];
            val[1] = values[j];
            add_node(val, 0);
        }

    }
}







void add_node(const char val[2], int hidden) {
    Card *newC = malloc(sizeof(Card));
    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->face_up = hidden;

    if (card_deck != NULL) {
        last_added_card_deck->next = newC;
        last_added_card_deck = last_added_card_deck->next;

    } else card_deck = last_added_card_deck = newC;

}











void print_out() {

    Card *temp = card_deck;
    while (temp != NULL) {
        printf("%s, %d\n", temp->suites_value, temp->face_up);
        temp = temp->next;
    }
}

