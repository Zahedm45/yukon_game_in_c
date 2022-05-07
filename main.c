#include <stdio.h>
#include <stdlib.h>
#include "game_board.c"
#include <string.h>
#include "utils.c"
#define MAX_BUFFER 60
Game_board *game_board;


int main() {

    char input[MAX_BUFFER];
    char *command = "";
    char *optional_command;
    char last_command[60] = "";
    char message_output[70] = "";


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

        command = strtok(input, " ");
        optional_command = strtok(NULL, " ");




        if(strncmp(command, "LD", 2) == 0) {

            if (optional_command != NULL) {
                game_board = load_game_board_from_pc(optional_command);

            } else {

                if (card_deck == NULL) {
                    initialize_card_deck(-1);

                }
                game_board = initialize_game_board(card_deck);
            }



            display_game_board(game_board);
            strcpy(last_command, input);
            strcpy(message_output, "OK");


        } else if(strncmp(command, "SW", 2) == 0) {

            if (game_board == NULL){
                strcpy(message_output, "Initialize a game board by typing LD");

            } else {
                strcpy(last_command, input);
                strcpy(message_output, "OK");
                set_cards_visible(&game_board);
                display_game_board(game_board);
            }

        } else if  (strncmp(command, "SD", 2) == 0) {

            if (game_board == NULL) {
                strcpy(message_output, "Initialize a game board by typing LD");

            } else {
                if (optional_command == NULL) {
                    strcpy(message_output, "Board name");

                } else {
                    save_game_board_on_pc( game_board, optional_command);
                    strcpy(last_command, input);
                    strcpy(message_output, "OK");
                }
            }

        } else if (strncmp(command, "SI", 2) == 0) {

            shuffle_card_deck_SI(5);
            game_board = initialize_game_board(card_deck);

            display_game_board(game_board);
            if (optional_command != NULL) {



/*                int split_num = atoi(optional_command);
                if (split_num < 52) {
                    shuffle_card_deck_SI(5);
                    initialize_game_board(card_deck);
                    puts("heeheheeh");
                }*/
            }


        }

        else {
            strcpy(message_output, "Unknown command");
            strcpy(last_command, "INVALID COMMAND EXECUTED");
        }

    }


}


