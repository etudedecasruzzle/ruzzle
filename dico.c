#include <stdlib.h>
#include <stdio.h>
#include "dico.h"

#define BUFFER_SIZE 100 //plus grand que le plus grand mot possible
#define HAUTEUR_MAX BUFFER_SIZE + 40

arbre noeud(char data, arbre g, arbre d){
  arbre res;
  res = (arbre) malloc(sizeof(struct chararbre));
  res->data = data;
  res->gauche = g;
  res->droite = d;
  return res;
}

//-----------------------------------------------------------------------

/* Manipulation du dictionnaire */
int est_dans_dico(char *mot, arbre dico){
  if((dico == NULL)||(dico->data > mot[0])) return 0;
  if(mot[0] == dico->data){
    if(mot[0] == '\0') return 1;
    return est_dans_dico(mot+1, dico->gauche);
  }
  return est_dans_dico(mot, dico->droite);
}

arbre new_dico(char *mot){
  if(mot[0] == '\0') return noeud('\0',NULL,NULL);
  return noeud(mot[0],new_dico(mot+1),NULL);
}

arbre ajoute_dans_dico(char *mot, arbre dico){
  if(dico == NULL) return new_dico(mot);
  if(mot[0] == '\0') return (dico->data == '\0')?dico:noeud('\0',NULL,dico);
  /* Car '\0' est le plus petit char possible */
  if(mot[0] < dico->data) return noeud(mot[0], new_dico(mot+1), dico);
  if(mot[0] == dico->data){
    dico->gauche = ajoute_dans_dico(mot+1, dico->gauche);
    return dico;
  }
  dico->droite = ajoute_dans_dico(mot, dico->droite);
  return dico;
}

/* Création du dictionnaire */
int readline(FILE *stream, char *buffer){//buffer de taille BUFFER_SIZE
  int c,count;
  for(count=0;(c=fgetc(stream))!=EOF && count<BUFFER_SIZE; count++){
    if(c=='\n') {
      buffer[count]='\0';
      return 1;
    }
    else if (c=='\r') count--;
    else buffer[count]=c;
  }
  if(count<BUFFER_SIZE){//une ligne finale, non terminée par \n
    buffer[count]='\0';
    return 0;
  }
  buffer[BUFFER_SIZE-1]='\0';
  fprintf(stderr,"Le mot commençant par %s est trop long\n",buffer);
  return 1;
}

arbre cree_dico(char *fichier){
  arbre dico=NULL;
  FILE *file;
  char buffer[BUFFER_SIZE];
  file = fopen(fichier,"r");
  while(readline(file, buffer)) dico = ajoute_dans_dico(buffer,dico);
  if(buffer[0]!='\0') dico = ajoute_dans_dico(buffer,dico);
  fclose(file);
  return dico;
}

void verifie_mots(arbre dico){
  char buffer[BUFFER_SIZE];
  printf("Entrez les mots à vérifier. Terminez par une ligne vide (ctrl D ou .)\n");
  while(readline(stdin, buffer)){
    if((buffer[0]=='.')&&(buffer[1]=='\0')) break;
    printf("%s",buffer);
    if(est_dans_dico(buffer, dico)) printf(" est correct\n");
    else printf(" n'est pas dans le dictionnaire\n");
  }
}




