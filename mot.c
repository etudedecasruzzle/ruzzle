#include <stdio.h>
#include <stdlib.h>
#include "mot.h"

mot* create_mot(lettre** lettres, int taille){
    mot* word = malloc(sizeof(mot));
    word->word = lettres;
    word->score = 0;
    word->taille = taille;
    return word;
}

int calcul_score(mot* word){
    int i=0;
    int multiplicateur_mot=1;
    while (i<word->taille){
        word->score+=calcul_score_lettre(word->word[i]);
        multiplicateur_mot=multiplicateur_mot*score_mot(word->word[i]);
        i++;
    }
    word->score=word->score*multiplicateur_mot;
    return word->score;
}

/*int taille(mot* word){
    int i;
    while (word->word[i] != NULL){
        i++;
    }
    return i;
}*/

char* retrouve_chaine_carac(mot* word){
    int i;
    char* chaine[word->taille];
    for (i=0;i<sizeof(chaine);i++){
        *chaine[i] = word->word[i]->letter;
    }
    return *chaine;
}


