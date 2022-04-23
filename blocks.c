//
// Created by MD. Zahed on 22/04/2022.
//




typedef struct Card {
    char suites_value[2];
    int face_up;
    struct Card* next;

}Card;



typedef struct Blocks{
    Card *block1;
    Card *block2;
    Card *block3;
    Card *block4;
    Card *block5;
    Card *block6;
    Card *block7;


    char foundation1[2];
    char foundation2[2];
    char foundation3[2];
    char foundation4[2];

}Blocks;



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




void print_out(Card *card_deck) {

    Card *temp = card_deck;
    while (temp != NULL) {
        printf("%s, %d\n", temp->suites_value, temp->face_up);
        temp = temp->next;
    }
}


void free_mem_block(Card **mem) {
    Card *temp;


    while (*mem != NULL) {
        temp = *mem;
        *mem = (*mem)->next;
        free(temp);
    }

}






