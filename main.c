#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    char suites_value[2];
    int hidden;
    struct Card* next;

}Card;

Card *cards;
Card *last_added;

void add_node(char val[], int hidden);

int main() {

    char values[13] = {'A' ,'2', '3', '4', '5', '6', '7', '8', '9',
                        'T', 'J', 'Q', 'K'};

    char suites[4] = {'C', 'D', 'H', 'S'};


    add_node("HD", 1);
    add_node("H1", 1);
    add_node("H2", 1);

    Card *temp = cards;

    while (temp != NULL) {

        printf("hello %s, %d\n", temp->suites_value, temp->hidden);

        temp = temp->next;
    }



/*    for (int i = 0; i < sizeof(suites); ++i) {

        for (int j = 0; j < sizeof(values); ++j) {


        }
    }*/



    return 0;
}


void add_node(char val[], int hidden) {

    Card *newC = malloc(sizeof(Card));

    newC->suites_value[0] = val[0];
    newC->suites_value[1] = val[1];
    newC->hidden = hidden;


    if (cards != NULL) {
        last_added->next = newC;
        last_added = newC;

    } else cards = last_added = newC;


}