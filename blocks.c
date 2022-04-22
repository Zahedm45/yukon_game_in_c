//
// Created by MD. Zahed on 22/04/2022.
//




typedef struct Card {
    char suites_value[2];
    int face_up;
    struct Card* next;

}Card;



typedef struct Block{
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

}Block;





