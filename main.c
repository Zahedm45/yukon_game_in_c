#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    char suites_value[2];
    int face_up;
    struct Card* next;

}Card;

Card *cards;
Card *last_added;

void add_node(char val[], int hidden);
void print_out();

int main() {

    char values[13] = {'A' ,'2', '3', '4', '5', '6', '7', '8', '9',
                        'T', 'J', 'Q', 'K'};

    char suites[4] = {'C', 'D', 'H', 'S'};


/*    add_node("HD", 1);
    add_node("H1", 1);
    add_node("H2", 1);*/

    char val[2];

/*
    for (int i = 0; i < sizeof(suites); ++i) {

        for (int j = 0; j < sizeof(values); ++j) {
            val[0] = suites[i];
            val[1] = values[j];
            //printf("%s", val[0], )
            add_node("hello", j);
        }

    }
*/

    add_node("hello", 1);
    add_node("hello", 2);
    add_node("hello", 3);




    print_out();

    return 0;
}


void add_node(char val[2], int hidden) {

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