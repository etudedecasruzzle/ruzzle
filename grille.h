#ifndef grille_h
#define grille_h
#include <stdlib.h>
#include <stdio.h>
#include "lettre.h"

typedef struct{
    lettre* jeu[4][4];
} grille;

grille* create_grille(char* fichier);
void affichage_grille(grille* gr);

#endif // grille_h
