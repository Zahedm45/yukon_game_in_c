//
// Created by MD. Zahed on 07/05/2022.
//

int contains_colon(char *str);
int contains_arrow(char *str);
void init_commands(char *source, char *dist, int first_n, int sec_n);
int move_card(Card *dist, Card *source, char card_name[]);
Card *find_block_name(Game_board *board, char *str);
int convert_char_to_int(char str);

int moves_commands(Game_board *board, char *commands){

    char move_from[3];
    char move_to[3];


    if (contains_colon(commands) == 1 && contains_arrow(commands) == 1){

        char card_name[3];
        init_commands(commands, move_from, 0, 1);
        init_commands(commands, card_name, 3, 4);
        init_commands(commands, move_to, 7, 8);

        Card *block_from = find_block_name(board, move_from);
        Card *block_to = find_block_name(board, move_to);



        int i = move_card(block_to, block_from, card_name);


        return 1;


    } else if (contains_arrow(commands) == 1) {
        init_commands(commands, move_from, 0, 1);
        init_commands(commands, move_to, 4, 5);



        return 1;
    }


    return 0;


}


int move_card(Card *dist, Card *source, char card_name[]){

    Card *temp = source;

    while (temp->next != NULL) {
        if (temp->next->face_up == VISIBLE) {




            if (strncmp(temp->next->suites_value, card_name, 2) == 0) {


                Card *temp_d = dist;

                while (temp_d->next != NULL) {
                    temp_d = temp_d->next;
                }



                int card_to_move_val = convert_char_to_int(temp->next->suites_value[1]);
                int card_dist_val = convert_char_to_int(temp_d->suites_value[1]);

                if (card_to_move_val == (card_dist_val-1)) {

                    temp_d->next = temp->next;
                    temp->next = NULL;
                }

            }
        }



        temp = temp->next;
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



Card *find_block_name(Game_board *board, char *str){

    if (strncmp(str, "C1", 2) == 0) return board->block1;
    else if (strncmp(str, "C2", 2) == 0) return board->block2;
    else if (strncmp(str, "C3", 2) == 0) return board->block3;
    else if (strncmp(str, "C4", 2) == 0) return board->block4;
    else if (strncmp(str, "C5", 2) == 0) return board->block5;
    else if (strncmp(str, "C6", 2) == 0) return board->block6;
    else if (strncmp(str, "C7", 2) == 0) return board->block7;
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