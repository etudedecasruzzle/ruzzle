#include "lettre.h"

lettre* create_lettre(char nom, int score, int multiplicateur_lettre, int multiplicateur_mot){
    lettre* a = malloc(sizeof(lettre));
    a->letter = nom;
    a->score = score;
    if (multiplicateur_lettre != 1){
        a->multiplicateur_lettre = multiplicateur_lettre;
        a->multiplicateur_mot =1;
    }
    else {
        a->multiplicateur_mot = multiplicateur_mot;
        a->multiplicateur_lettre = 1;
    }
    return a;
}

int calcul_score_lettre(lettre* word){
    int score=word->score*word->multiplicateur_lettre;
}

int score_mot(lettre* a){
    return a->multiplicateur_mot;
}
