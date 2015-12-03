#include <stdio.h>
#include <stdlib.h>
#include "mot.h"

mot* create_mot(lettre** lettres, int tail){
    freopen("CON","w",stdout);
    mot* word = malloc(sizeof(mot));
    word->word = lettres;
    //int i=0;
    word->score = 0;
    //word->taille = tail;
    word->taille =tail;
    /*while (lettres[i] && lettres[i]!= '\0'){
        fprintf(stdout,"%c \n",get_char(lettres[i]));
        word->taille++;
        i++;
    }*/
    //fprintf(stdout,"%d\n",i);
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
    int i=0;
    char* chaine=(char*)malloc(word->taille*sizeof(char));
    while (chaine[i]){
        chaine[i]=get_char(word->word[i]);
        i++;
    }
    return chaine;
}


