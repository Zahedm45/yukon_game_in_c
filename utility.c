//
// Created by MD. Zahed on 22/04/2022.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Card {
    char suites_value[2];
    int face_up;
    struct Card* next;

}Card;

Card *cards;
Card *last_added;
void add_node(const char val[2], int hidden);

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

    if (cards != NULL) {
        last_added->next = newC;
        last_added = last_added->next;

    } else cards = last_added = newC;

}





void print_out() {

    Card *temp = cards;
    while (temp != NULL) {
        printf("%s, %d\n", temp->suites_value, temp->face_up);
        temp = temp->next;
    }
}

