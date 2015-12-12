#include <stdio.h>
#include <stdlib.h>
#include "mot.h"

#define MAX_SIZE 17 //il ne peut y avoir que 16 lettres par mot + caractère de fin de chaine

mot* create_mot(lettre** lettres, int tail){
    freopen("CON","w",stdout);
    mot* word = malloc(sizeof(mot));
    word->word = lettres;
    word->taille =tail;
    word->score = 0;
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
    freopen("CON","w",stdout);
    int i=0;
    char* chaine = (char*) malloc((word->taille+1)*sizeof(char*));
    for (i=0;i<word->taille;i++){
        chaine[i]=malloc(sizeof(char));
        chaine[i]='\0';
    }
    i=0;
    while (i<word->taille && word->word[i]->letter != 'A' ){
        fprintf(stdout,"%c ",word->word[i]->letter);
        chaine[i]=word->word[i]->letter;
        i++;
    }
    chaine[i]='\0';

    fprintf(stdout,"fin\n");
    return chaine;
}

mot* create_mot_sans_tail(){
    mot* new_mot = malloc(sizeof(mot));
    new_mot->word = (lettre*) malloc(MAX_SIZE*sizeof(lettre*));
    int i;
    for (i=0;i<MAX_SIZE;i++){
        new_mot->word[i]=create_lettre('A');
    }
    new_mot->taille = 0;
    new_mot->score = 0;
    return new_mot;
}

mot* ajout_lettre(mot* word,lettre* let){
    mot* new_mot = create_mot_sans_tail();
    word->taille++;
    int i;
    for (i=0;i<word->taille-1;i++){
        new_mot->word[i] = word->word[i];
    }
    new_mot->word[word->taille-1]=let;
    new_mot->taille = word->taille;
    return new_mot;
}

int contient_lettre(mot* word, lettre* let){
    int i=0;
    while (i < word->taille){
        if (word->word[i] == let){
            return 1;
        }
        i++;
    }
    return 0;
}


