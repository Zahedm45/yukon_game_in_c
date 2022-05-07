#include <stdio.h>
#include <stdlib.h>
#include "game_board.c"
#include <string.h>
#include "utils.c"
#define MAX_BUFFER 60

Game_board *game_board;

void SI_command();
void SD_command();
void SW_command();
void LD_command();

char input[MAX_BUFFER];
char *command = "";
char *optional_command;
char last_command[MAX_BUFFER] = "";
char message_output[70] = "";
char input_copy[MAX_BUFFER];

char msg1[] = "Initialize a game board by typing LD";


int main() {




    // Initialize game board
    starting_point();




    // Main game loop
    while(strcmp(command, "stop") != 0) {

        printf("LAST Command: ");
        printf("%s \n", last_command);
        printf("Message: ");
        printf("%s \n", message_output);
        printf("INPUT > \t");
        fgets(input, MAX_BUFFER, stdin);
        printf("\n");

        strcpy(input_copy, input);
        command = strtok(input_copy, " ");
        optional_command = strtok(NULL, " ");




        if(strncmp(command, "LD", 2) == 0) {
            LD_command();

        } else if(strncmp(command, "SW", 2) == 0) {
            SW_command();

        } else if  (strncmp(command, "SD", 2) == 0) {
            SD_command();

        } else if (strncmp(command, "SI", 2) == 0) {
            SI_command();
        }

        else {
            strcpy(message_output, "Unknown command");
            strcpy(last_command, "INVALID COMMAND EXECUTED");
        }

    }


}




void LD_command() {

    if (optional_command != NULL) {
        game_board = load_game_board_from_pc(optional_command);

    } else {

/*        if (card_deck == NULL) {
            initialize_card_deck(-1);

        }*/

        initialize_card_deck(-1);
        game_board = initialize_game_board(card_deck);
    }



    display_game_board(game_board);
    strcpy(last_command, input);
    strcpy(message_output, "OK");
}



void SW_command() {
    if (game_board == NULL){
        strcpy(message_output, msg1);

    } else {
        strcpy(last_command, input);
        strcpy(message_output, "OK");
        set_cards_visible(&game_board);
        display_game_board(game_board);
    }

}




void SD_command() {

    if (game_board == NULL) {
        strcpy(message_output, msg1);

    } else {
        if (optional_command == NULL) {
            strcpy(message_output, "Board name");

        } else {
            save_game_board_on_pc( game_board, optional_command);
            strcpy(last_command, input);
            strcpy(message_output, "OK");
        }
    }
}



void SI_command() {

    if (card_deck != NULL) {

        if (optional_command != NULL) {
            int split_num = atoi(optional_command);
            if (split_num < 52) {

                shuffle_card_deck_SI(split_num);
                game_board = initialize_game_board(card_deck);
                display_game_board(game_board);

                strcpy(last_command, input);
                strcpy(message_output, "OK");

            } else strcpy(message_output, "The digit is too large");

        } else {


        }


    } else strcpy(message_output, msg1);


}