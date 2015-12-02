#ifndef mot_h
#define mot_h
#include "lettre.h"

typedef struct{
    lettre** word;
    int taille;
    int score;
} mot;

mot* create_mot(lettre** lettres, int taille); //créer un mot à partir d'un ensemble de lettres
int calcul_score(mot* word); //calcul le score total d'un mot
char* retrouve_chaine_carac(mot* word); // renvoie la chaine de caractères correspondante au mot
int taille(mot* word);


#endif // mot_h
