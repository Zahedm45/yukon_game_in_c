//
// Created by MD. Zahed on 07/05/2022.
//

int contains_colon(char *str);
int contains_arrow(char *str);

int moves_commands(Game_board *board, char *commands){

    char move_from[3];
    char card_name[3];
    char move_to[3];


    if (contains_colon(commands) == 1 && contains_arrow(commands)){
        move_from[0] = commands[0];
        move_from[1] = commands[1];
        move_from[2] = '\0';

        card_name[0] = commands[3];
        card_name[1] = commands[4];
        card_name[2] = '\0';

        move_to[0] = commands[7];
        move_to[1] = commands[8];
        move_to[2] = '\0';

        //printf("from: %s\t, card: %s\t, to: %s\n", move_from, card_name, move_to);

        puts(move_from);
        puts(card_name);
        puts(move_to);

    }


    return 0;


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



/*
void split_command(char *str, char *from, char *card_name, char *to) {

*/
/*    int i = 0;



    while (str[i] != '\0') {
        if (str[i] == ':') {break;}
        from[i] = str[i];
        i++;
    }

    int k = 0;
    while (str[i] != '\0') {
        if (str[i] == '-' && str[i+1] == '>') {break;}
        card_name[k] = str[i];
        k++;
        i++;
    }*//*


}*/
