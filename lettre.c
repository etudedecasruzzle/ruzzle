#include "lettre.h"

lettre* create_lettre_with_2(char nom, int multi_mot, int multi_let){
    lettre* a = malloc(sizeof(lettre));
    a->letter = nom;
    a->multiplicateur_lettre = multi_let;
    a->multiplicateur_mot = multi_mot;
    switch (nom){
        case 'a':a->score=1;break;
        case 'b':a->score=3;break;
        case 'c':a->score=3;break;
        case 'd':a->score=2;break;
        case 'e':a->score=1;break;
        case 'f':a->score=4;break;
        case 'g':a->score=2;break;
        case 'h':a->score=4;break;
        case 'i':a->score=1;break;
        case 'j':a->score=8;break;
        case 'k':a->score=10;break;
        case 'l':a->score=1;break;
        case 'm':a->score=2;break;
        case 'n':a->score=1;break;
        case 'o':a->score=1;break;
        case 'p':a->score=3;break;
        case 'q':a->score=8;break;
        case 'r':a->score=1;break;
        case 's':a->score=1;break;
        case 't':a->score=1;break;
        case 'u':a->score=1;break;
        case 'v':a->score=4;break;
        case 'w':a->score=10;break;
        case 'x':a->score=10;break;
        case 'y':a->score=10;break;
        case 'z':a->score=10;break;
    }
    return a;
}


lettre* create_lettre(char nom){
    lettre* a = malloc(sizeof(lettre));
    a->letter = nom;
    a->multiplicateur_lettre = 1;
    a->multiplicateur_mot = 1;
    switch (nom){
        case 'a':a->score=1;break;
        case 'b':a->score=3;break;
        case 'c':a->score=3;break;
        case 'd':a->score=2;break;
        case 'e':a->score=1;break;
        case 'f':a->score=4;break;
        case 'g':a->score=2;break;
        case 'h':a->score=4;break;
        case 'i':a->score=1;break;
        case 'j':a->score=8;break;
        case 'k':a->score=10;break;
        case 'l':a->score=1;break;
        case 'm':a->score=2;break;
        case 'n':a->score=1;break;
        case 'o':a->score=1;break;
        case 'p':a->score=3;break;
        case 'q':a->score=8;break;
        case 'r':a->score=1;break;
        case 's':a->score=1;break;
        case 't':a->score=1;break;
        case 'u':a->score=1;break;
        case 'v':a->score=4;break;
        case 'w':a->score=10;break;
        case 'x':a->score=10;break;
        case 'y':a->score=10;break;
        case 'z':a->score=10;break;
    }
    return a;
}

int calcul_score_lettre(lettre* word){
    int score=word->score*word->multiplicateur_lettre;
}

int score_mot(lettre* a){
    return a->multiplicateur_mot;
}

char get_char(lettre* a){
    return a->letter;
}
