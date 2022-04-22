//
// Created by MD. Zahed on 22/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "blocks.c"



Card *card_deck;
Card *last_added_card_deck;

Blocks *game_board;

void add_node(const char val[2], int hidden);



Blocks * initialize_game_board(Card *cards){

    Card *temp = cards;
    Blocks *new_board = malloc(sizeof(Blocks));

    int j = 0;
    for (int i = 0; i < 7; ++i) {

        j++;
        for (int k = 0; k <j; ++k) {
            if (temp == NULL) {
                printf("Something went wrong. From initialize_game_board() %d %d", i, k);
                exit(0);
            }

            new_board->block1[i] = *temp;
            temp = temp->next;
        }

        if (i == 0) {
            j = 5;
        }
    }

    return new_board;
}




void display_card_deck(Blocks *game_board){
    printf("C1\t\tC2\t\tC3\t\tC4\t\tC5\t\tC6\t\tC7\n");




    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n");

    Card *temp;
    for (int i = 0; i < 7; ++i) {
        if (temp != NULL) {
            free(temp);
        }
        temp = &game_board->block1[i];


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




void add_card_to_block(Card *block, const char val[2], int hidden){
    Card *temp = block;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    Card *newC = malloc(sizeof(Card));
    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->face_up = hidden;



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

