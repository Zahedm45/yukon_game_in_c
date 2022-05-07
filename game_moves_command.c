//
// Created by MD. Zahed on 07/05/2022.
//

int contains_colon(char *str);
int contains_arrow(char *str);
void init_commands(char *source, char *dist, int first_n, int sec_n);
int move_card_to_another_block(Card *dist, Card *source, char card_name[], char *msg);
Card *find_block_name(Game_board *board, char *str);
int convert_char_to_int(char str);
char *find_foundation_name(Game_board *board, char *str);
int move_card_to_foundation(Game_board *board, Card *block_from, char *move_to, char *msg);






int moves_commands(Game_board *board, char *commands, char *msg){

    char move_from[3];
    char move_to[3];


    if (contains_colon(commands) == 1 && contains_arrow(commands) == 1){

        char card_name[3];
        init_commands(commands, move_from, 0, 1);
        init_commands(commands, card_name, 3, 4);
        init_commands(commands, move_to, 7, 8);

        Card *block_from = find_block_name(board, move_from);
        Card *block_to = find_block_name(board, move_to);



        return move_card_to_another_block(block_to, block_from, card_name, msg);



    } else if (contains_arrow(commands) == 1) {
        init_commands(commands, move_from, 0, 1);
        init_commands(commands, move_to, 4, 5);
        Card *block_from = find_block_name(board, move_from);



        if (move_to[0] == 'F') {
            return move_card_to_foundation(board, block_from, move_to, msg);

        } else {

            Card *block_to = find_block_name(board, move_to);
            return move_card_to_another_block(block_to, block_from, NULL, msg);
        }



    }


    return 0;


}

int move_card_to_foundation(Game_board *board, Card *block_from, char *move_to, char *msg){

    char *foundation = find_foundation_name(board, move_to);

    Card *temp = block_from;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    if (foundation[0] == temp->next->suites_value[0]) {
        int int_foundation_card_val = convert_char_to_int(foundation[1]);
        int int_block_card_val = convert_char_to_int(temp->next->suites_value[1]);


        if (int_block_card_val-1 == int_foundation_card_val) {
            foundation[0] = temp->next->suites_value[0];
            foundation[1] = temp->next->suites_value[1];
            temp->next = NULL;
            return 1;
        } else {
            strcpy(msg, "Move is not possible");
            return 1;
        }

    } else {
        strcpy(msg, "Move is not possible");
        return 1;
    }


}



int move_card_to_another_block(Card *dist, Card *source, char card_name[], char *msg){

    Card *temp_s = source;


    if (card_name != NULL) {
        while (temp_s->next != NULL) {
            if (temp_s->next->face_up == VISIBLE) {

                if (strncmp(temp_s->next->suites_value, card_name, 2) == 0) {
                    break;
                }
            }

            temp_s = temp_s->next;
        }

        strcpy(msg, "Card x does not exist in the block");
        return 1;

    } else {

        while (temp_s->next->next != NULL) {
            temp_s = temp_s->next;
        }
    }





    Card *temp_d = dist;
    while (temp_d->next != NULL) {
        temp_d = temp_d->next;
    }


    if (temp_s->next->suites_value[0] == temp_d->suites_value[0]) {
        strcpy(msg, "Move is not possible(same suit)!");
        return 1;
    }



    int card_to_move_val = convert_char_to_int(temp_s->next->suites_value[1]);
    int card_dist_val = convert_char_to_int(temp_d->suites_value[1]);

    if (card_to_move_val == (card_dist_val-1)) {

        temp_d->next = temp_s->next;
        temp_s->next = NULL;
        return 1;
    }




    return 0;

}




int convert_char_to_int(char str){
    int int_val = atoi(&str);

    if (int_val == 0) {

        if (str == 'A') return 1;
        else if (str == 'T') return 10;
        else if (str == 'J') return 11;
        else if (str == 'Q') return 12;
        else if (str == 'K') return 13;

    }
    return int_val;

}


char *find_foundation_name(Game_board *board, char *str){

    if (strncmp(str, "F1", 2) == 0) {return board->foundation1;}
    else if (strncmp(str, "F2", 2) == 0) {return board->foundation2;}
    else if (strncmp(str, "F3", 2) == 0) {return board->foundation3;}
    else if (strncmp(str, "F4", 2) == 0) {return board->foundation4;}
    else return NULL;

}




Card *find_block_name(Game_board *board, char *str){

    if (strncmp(str, "B1", 2) == 0) return board->block1;
    else if (strncmp(str, "B2", 2) == 0) return board->block2;
    else if (strncmp(str, "B3", 2) == 0) return board->block3;
    else if (strncmp(str, "B4", 2) == 0) return board->block4;
    else if (strncmp(str, "B5", 2) == 0) return board->block5;
    else if (strncmp(str, "B6", 2) == 0) return board->block6;
    else if (strncmp(str, "B7", 2) == 0) return board->block7;
    else return NULL;
}







int contains_colon(char *str) {

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ':') {
            return 1;
        }
        i++;
    }

    return 0;
}



int contains_arrow(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '-' && str[i+1] == '>') {
            return 1;
        }
        i++;
    }

    return 0;
}

void init_commands(char *source, char *dist, int first_n, int sec_n) {
    dist[0] = source[first_n];
    dist[1] = source[sec_n];
    dist[2] = '\0';
}