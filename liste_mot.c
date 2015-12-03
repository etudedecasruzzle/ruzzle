#include "liste_mot.h"

liste_mot* create_liste(){
    liste_mot* new_list = malloc(sizeof(liste_mot));
    new_list->nb_mot = 0;
    return new_list;
}

liste_mot* ajout_mot(liste_mot* liste_m,mot* word){
    liste_m->nb_mot++;
    liste_mot* new_list = malloc(sizeof(liste_mot));
    new_list->liste = (mot*) malloc(liste_m->nb_mot*sizeof(mot*));
    int i;
    for (i=0;i<liste_m->nb_mot-1;i++){
        new_list->liste[i] = liste_m->liste[i];
    }
    new_list->liste[liste_m->nb_mot - 1] = word;
    new_list->nb_mot = liste_m->nb_mot;
    return new_list;
}
