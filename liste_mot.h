#include "mot.h"

typedef struct{
    mot** liste;
    int nb_mot;
} liste_mot;

liste_mot* create_liste();
liste_mot* ajout_mot(liste_mot* liste_m,mot* word);
