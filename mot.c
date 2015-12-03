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
    return word->score+5*(word->taille - 4);

}

char* retrouve_chaine_carac(mot* word){
    int i=0;
    char* chaine=(char*)malloc(word->taille*sizeof(char));
    while (i<word->taille){
        chaine[i]=get_char(word->word[i]);
        i++;
    }
    return chaine;
}

mot* create_mot_sans_tail(){
    mot* new_mot = malloc(sizeof(mot));
    new_mot->taille = 0;
    return new_mot;
}

mot* ajout_lettre(mot* word,lettre* let){
    mot* new_mot = malloc(sizeof(mot));
    word->taille++;
    new_mot->word = (lettre*) malloc(word->taille*sizeof(lettre*));
    int i;
    for (i=0;i<word->taille-1;i++){
        new_mot->word[i] = word->word[i];
    }
    new_mot->word[word->taille-1]=let;
    new_mot->taille = word->taille;
    return new_mot;
}


