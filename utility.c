//
// Created by MD. Zahed on 22/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "blocks.c"



Card *card_deck;
Card *last_added_card_deck;



void add_node(const char val[2], int hidden);
Card * add_card_to_block(Card *block, const char val[2], int hidden);
void free_mem(Card *mem);



Blocks * initialize_game_board(Card *cards){

    Card *temp = cards;
    Blocks *new_board = malloc(sizeof(Blocks));

    int j = 0;
    for (int i = 0; i < 7; ++i) {

        Card *new_block = malloc(sizeof(Card));

        j++;
        for (int k = 0; k <j; ++k) {
            if (temp == NULL) {
                printf("Something went wrong. From initialize_game_board() %d %d", i, k);
                exit(0);
            }

            char value[2];
            value[0] =  temp->suites_value[0];
            value[1] =  temp->suites_value[1];

            //add_card_to_block(&new_block, value, temp->face_up);

            new_block = add_card_to_block(new_block, "hd", 1);

            temp = temp->next;


        }

        new_board->blocks[i] = *new_block;
//        free_mem(new_block);

        if (i == 0) {
            j = 5;
        }
    }

    return new_board;
}




Card* add_card_to_block(Card *block, const char val[2], int hidden){
    Card *head = block;



    while (block->next != NULL) {
        block = block->next;
    }

    Card *newC = malloc(sizeof(Card));
    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->face_up = hidden;

    return head;

}






void display_card_deck(Blocks *board){
    printf("C1\t\tC2\t\tC3\t\tC4\t\tC5\t\tC6\t\tC7\n");




    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");

    for (int i = 0; i < 7; ++i) {

        Card *temp = &board->blocks[i];
        printf("Block: %d ", i);
        while (temp != NULL) {
            printf("%s, %d\t", temp->suites_value, temp->face_up);
            temp = temp->next;
        }

        printf("\n");

    }


}


void free_mem(Card *mem) {

    while (mem != NULL) {
        Card *temp = mem;
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

