#include <stdio.h>
#include <stdlib.h>
#include "mot.h"

typedef struct{
    mot** liste;
    int nb_mot;
} liste_mot;

liste_mot* create_liste();
liste_mot* ajout_mot(liste_mot* liste_m,mot* word);
int meilleur_mot(mot* word, liste_mot* liste_t);
