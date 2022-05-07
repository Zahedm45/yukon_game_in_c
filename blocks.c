//
// Created by MD. Zahed on 22/04/2022.
//

int VISIBLE = 1;
int INVISIBLE = 0;


typedef struct Card {
    char suites_value[3];
    int face_up;
    struct Card* next;

}Card;



typedef struct Game_board{
    Card *block1;
    Card *block2;
    Card *block3;
    Card *block4;
    Card *block5;
    Card *block6;
    Card *block7;


    char foundation1[3];
    char foundation2[3];
    char foundation3[3];
    char foundation4[3];

}Game_board;




void switch_block(int i, Game_board **board, Card *new_block_head);
void foundation_display(Game_board *board, int foundation_num, char *f_name, char *f_card);

void switch_block(int i, Game_board **board, Card *new_block_head) {

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




void print_card_deck(Card *card_deck) {

    Card *temp = card_deck;
    while (temp != NULL) {
        printf("%s, %d\n", temp->suites_value, temp->face_up);
        temp = temp->next;
    }
}


/*void free_mem_block(Card *mem) {
    Card *temp;

    while (mem != NULL) {
        temp = mem;
        mem = mem->next;
        free(temp);
    }

}*/



void helper_func_display_card_deck(int face_up, char **val_b, char else_val[]){
    if (face_up == INVISIBLE) {
        *val_b = "[]";
    } else if (face_up == 1) {
        *val_b = else_val;

    } else {
        *val_b = " ";
    }
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


void foundation_display(Game_board *board, int foundation_num, char *f_name, char *f_card) {

    switch (foundation_num) {
        case 0:
            stpcpy(f_card, board->foundation1);
            break;

        case 1:
            f_name[1] = '2';
            stpcpy(f_card, board->foundation2);
            break;

        case 2:
            f_name[1] = '3';
            stpcpy(f_card, board->foundation3);
            break;
        case 3:
            f_name[1] = '4';
            stpcpy(f_card, board->foundation4);
            break;

        default:
            f_name[0] = ' ';
            f_name[1] = ' ';
            stpcpy(f_card, "");

    }

}


void display_game_board(Game_board *board){
    printf("B1\t\tB2\t\tB3\t\tB4\t\tB5\t\tB6\t\tB7\n\n");



    char *val_b1;
    char *val_b2;
    char *val_b3;
    char *val_b4;
    char *val_b5;
    char *val_b6;
    char *val_b7;

    Card *block1 = board->block1;
    Card *block2 = board->block2;
    Card *block3 = board->block3;
    Card *block4 = board->block4;
    Card *block5 = board->block5;
    Card *block6 = board->block6;
    Card *block7 = board->block7;


    Card *null_block = malloc(sizeof(Card));
    null_block->next = NULL;
    null_block->face_up = -1;


    int counter = 0;
    int continue_loop = 1;

    while (continue_loop == 1) {
        continue_loop = 0;

        int face_up_b1 = block1->face_up;
        helper_func_display_card_deck(face_up_b1, &val_b1, block1->suites_value);

        if (block1->next != NULL){
            block1 = block1->next;
            continue_loop = 1;
        } else block1 = null_block;



        int face_up_b2 = block2->face_up;
        helper_func_display_card_deck(face_up_b2, &val_b2, block2->suites_value);

        if (block2->next != NULL) {
            block2 = block2->next;
            continue_loop = 1;

        } else block2 = null_block;




        int face_up_b3 = block3->face_up;
        helper_func_display_card_deck(face_up_b3, &val_b3, block3->suites_value);
        if (block3->next != NULL) {
            block3 = block3->next;
            continue_loop = 1;

        } else block3 = null_block;



        int face_up_b4 = block4->face_up;
        helper_func_display_card_deck(face_up_b4, &val_b4, block4->suites_value);
        if (block4->next != NULL) {
            block4 = block4->next;
            continue_loop = 1;

        } else block4 = null_block;


        int face_up_b5 = block5->face_up;
        helper_func_display_card_deck(face_up_b5, &val_b5, block5->suites_value);
        if (block5->next != NULL) {
            block5 = block5->next;
            continue_loop = 1;

        } else block5 = null_block;


        int face_up_b6 = block6->face_up;
        helper_func_display_card_deck(face_up_b6, &val_b6, block6->suites_value);
        if (block6->next != NULL) {
            block6 = block6->next;
            continue_loop = 1;

        } else block6 = null_block;



        int face_up_b7 = block7->face_up;
        helper_func_display_card_deck(face_up_b7, &val_b7, block7->suites_value);
        if (block7->next != NULL) {
            block7 = block7->next;
            continue_loop = 1;

        } else block7 = null_block;


        char foundation_name[] = "F1";
        char foundation_card[3];



        foundation_display(board, counter, foundation_name, foundation_card);




        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%s\n", val_b1, val_b2, val_b3, val_b4, val_b5, val_b6, val_b7,foundation_card, foundation_name);

        counter++;
    }


    printf("\n");

}


void starting_point() {
    printf("B1\t\tB2\t\tB3\t\tB4\t\tB5\t\tB6\t\tB7\n\n");
    for (int i = 0; i < 4; ++i) {
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t[]\tF1\n\n");
    }

    printf("\n");

}