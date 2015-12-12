#ifndef mot_h
#define mot_h
#include "lettre.h"

typedef struct{
    lettre** word;
    int taille;
    int score;
} mot;

mot* create_mot(lettre** lettres, int tail); //créer un mot à partir d'un ensemble de lettres
<<<<<<< HEAD
mot* create_mot_sans_tail();
int calcul_score(mot* word); //calcul le score total d'un mot
char* retrouve_chaine_carac(mot* word); // renvoie la chaine de caractères correspondante au mot
mot* ajout_lettre(mot* word,lettre* let);
int contient_lettre(mot* word, lettre* let);
=======
<<<<<<< HEAD
mot* create_mot_sans_tail();
int calcul_score(mot* word); //calcul le score total d'un mot
char* retrouve_chaine_carac(mot* word); // renvoie la chaine de caractères correspondante au mot
mot* ajout_lettre(mot* word,lettre* let);
int contient_lettre(mot* word, lettre* let);
=======
<<<<<<< HEAD
mot* create_mot_sans_tail();
int calcul_score(mot* word); //calcul le score total d'un mot
char* retrouve_chaine_carac(mot* word); // renvoie la chaine de caractères correspondante au mot
mot* ajout_lettre(mot* word,lettre* let);
=======
int calcul_score(mot* word); //calcul le score total d'un mot
char* retrouve_chaine_carac(mot* word); // renvoie la chaine de caractères correspondante au mot

>>>>>>> origin/master
>>>>>>> origin/master
>>>>>>> origin/master

#endif // mot_h
