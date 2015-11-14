#ifndef lettre_h
#define lettre_h

typedef struct{
    char letter;
    int score;
    int multiplicateur_lettre;
    int multiplicateur_mot;
} lettre;

lettre* create_lettre(char nom, int score, int multiplicateur_lettre, int multiplicateur_mot); //cr�er une lettre, on ne peut avoir qu'un seul multiplicateur, ainsi si le multiplicateur de lettre est sup�rieur � 1, le multiplicateur de mot sera �gal � 1;
int calcul_score_lettre(lettre* word); //on calcule le score d'une lettre
int score_mot(lettre* a); //retourne le multiplicateur de mot d'une lettre


#endif // lettre_h


