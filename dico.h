#ifndef dico_h
#define dico_h
#include <stdio.h>
#include <string.h>
#include "mot.h"

typedef struct chararbre {
  char data;
  struct chararbre *gauche, *droite;
} *arbre;

arbre noeud(char data, arbre g, arbre d);
int est_dans_dico(char *mot, arbre dico);
arbre new_dico(char *mot);
arbre ajoute_dans_dico(char *mot, arbre dico);
int readline(FILE *stream, char *buffer);
arbre cree_dico(char *fichier);
void verifie_mots(arbre dico);
#endif // dico_h
