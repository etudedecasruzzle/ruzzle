#ifndef grille_h
#define grille_h
#include <stdlib.h>
#include <stdio.h>
#include "lettre.h"
#include "mot.h"
#include "dico.h"
#include "liste_mot.h"

typedef struct{
    lettre* jeu[4][4];
} grille;

grille* create_grille(char* fichier);
void affichage_grille(grille* gr);
liste_mot* auto_grille(int i, int j,liste_mot* liste_fin,mot* temp,arbre dictio, grille* gr);
/*mot** trouve_mot(int i,int j,grille* gr,arbre dictio,lettre** lettres,int num_lettre);
mot** ranger_ens_mot(mot** source,mot** dest);
mot** meilleur_score(grille* gr,arbre dictio);
*/
#endif // grille_h
