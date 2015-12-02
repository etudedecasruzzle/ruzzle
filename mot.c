#include <stdio.h>
#include <stdlib.h>
#include "mot.h"

int taille(mot* word){
    int i;
    while (word->word[i]){
        i++;
    }
    return i;
}

mot* create_mot(lettre** lettres, int tail){
    mot* word = malloc(sizeof(mot));
    word->word = lettres;
    word->score = 0;
    word->taille = taille(word);
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




char* retrouve_chaine_carac(mot* word){
    int i;
    char* chaine[word->taille];
    while (chaine[i]){
        chaine[i]=word->word[i]->letter;
        i++;
    }
    return *chaine;
}


