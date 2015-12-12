#ifndef lettre_h
#define lettre_h
#include <stdlib.h>

typedef struct{
    char letter;
    int score;
    int multiplicateur_lettre;
    int multiplicateur_mot;
} lettre;

lettre* create_lettre(char nom);
lettre* create_lettre_with_2(char nom, int multi_mot, int multi_let);
int calcul_score_lettre(lettre* word); //on calcule le score d'une lettre
int score_mot(lettre* a); //retourne le multiplicateur de mot d'une lettre
char get_char(lettre* a);


#endif // lettre_h


