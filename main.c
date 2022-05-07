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
void P_command();

char input[MAX_BUFFER];
char *command = "";
char *optional_command;
char last_command[MAX_BUFFER] = "";
char message_output[100] = "";
char input_copy[MAX_BUFFER];
int in_play_mode = -1;

char msg1[] = "Initialize a game board by typing LD";
char pm_msg[] = "The game is in play mode!. Type Q to exit.";
char file_saved_msg[] = "The game board has been saved on your pc.";


int main() {




    // Initialize game board
    starting_point();



    // Main game loop
    while(1) {

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
        remove_last_line(input);


        if (in_play_mode == 1) {
            if (strncmp(command, "Q", 1) == 0) {
                in_play_mode = -1;
                strcpy(message_output, "OK");

            } else {
                strcpy(message_output, pm_msg);

            }

            strcpy(last_command, input);


        }else if (strncmp(command, "LD", 2) == 0) {
            LD_command();


        } else if (strncmp(command, "SW", 2) == 0) {
            SW_command();

        } else if (strncmp(command, "SD", 2) == 0) {
            SD_command();

        } else if (strncmp(command, "SI", 2) == 0) {
            SI_command();
        } else if (strncmp(command, "QQ", 2) == 0) {
            exit(0);

        } else if (strncmp(command, "P", 1) == 0) {
            P_command();
        } else {
            strcpy(message_output, "Unknown command");
            strcpy(last_command, "INVALID COMMAND EXECUTED");
        }

    }


}




void LD_command() {

    if (optional_command != NULL) {
        game_board = load_game_board_from_pc(optional_command);

    } else {

        initialize_card_deck(INVISIBLE);
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
            strcpy(message_output, file_saved_msg);
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

            int random_num = rand() % 52;

            printf("rand %d\n", random_num);
            shuffle_card_deck_SI(random_num);
            game_board = initialize_game_board(card_deck);
            display_game_board(game_board);

            strcpy(last_command, input);
            strcpy(message_output, "OK");

        }


    } else strcpy(message_output, msg1);

}


void P_command() {

    card_deck = load_from_board_to_card_deck(game_board);
    game_board = set_play_board(card_deck, "[]", "[]", "[]", "[]");
    set_half_of_the_cards_invisible(game_board);
    display_game_board(game_board);
    in_play_mode = 1;

}