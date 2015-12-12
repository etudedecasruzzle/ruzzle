
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

int meilleur_mot(mot* word,liste_mot* liste_t){
    int i;
    for (i=0;i<liste_t->nb_mot;i++){
        if (retrouve_chaine_carac(word)==retrouve_chaine_carac(liste_t->liste[i])){
            if (calcul_score(word) > calcul_score(liste_t->liste[i])){
                liste_t->liste[i]->score = calcul_score(word);
                return 1;
            }
        }
    }
    liste_t = ajout_mot(liste_t,word);
    return 1;
}

void affichage_liste(liste_mot* liste_t){
    int i;
    freopen("CON","w",stdout);
    for (i=0;i<liste_t->nb_mot;i++){
        fprintf(stdout,"%c : %i\n",retrouve_chaine_carac(liste_t->liste[i]),calcul_score(liste_t->liste[i]));
    }
}
