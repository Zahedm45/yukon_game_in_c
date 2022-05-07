//
// Created by MD. Zahed on 06/05/2022.
//


void spilt_input(char input[], char first_input[], char second_input[]) {


    char elem;

    int is_first_input = 1;

    int k = 0;

    for (int i = 0; i < 50; ++i) {
        elem = input[i];

        if(elem == '0') {
            return;
        }

        if (elem == ' ') {is_first_input = 0;}

        else if (is_first_input == 1) {first_input[i] = elem;}

        else if (is_first_input == 0) {second_input[k] = elem;
            k++;
        }

    }

}


void str_copy(char *dist, char *source) {
    for (int i = 0; source[i] != '\n'; ++i) {
        dist[i] = source[i];
    }
}


/*
void str_copy(char *source) {
    for (int i = 0; source[i] != '\n'; ++i) {
        dist[i] = source[i];
    }
}*/
