#include "grille.h"
#include "lettre.h"

grille* create_grille(char* fichier){
    freopen("CON","w",stdout);
    grille* gr = malloc(sizeof(grille));
    FILE* grille_txt = fopen(fichier,"r");
    if (fichier != NULL){
        lettre* temp;
        int charac = 0;
        int i=0;
        int j=0;
        do {
            i=0;
            do {
                charac = fgetc(grille_txt);
                char c = (char) charac;
                if (c != '\n'){
                    switch (j){
                        case 0:
                            switch (i){
                                case 1:temp = create_lettre_with_2(c,2,1);break;
                                case 2:temp = create_lettre_with_2(c,1,3);break;
                                case 3:temp = create_lettre_with_2(c,2,1);break;
                                default:temp=create_lettre(c);break;
                            }
                            break;
                        case 2:
                            switch (j){
                                case 2:temp = create_lettre_with_2(c,1,3);break;
                                default:temp=create_lettre(c);break;
                            }
                            break;
                        case 3:
                            switch (j){
                                case 1:temp = create_lettre_with_2(c,1,2);break;
                                case 2:temp = create_lettre_with_2(c,3,1);break;
                                default:temp=create_lettre(c);break;
                            }
                            break;
                        default:temp=create_lettre(c);break;
                    }
                    gr->jeu[j][i] = temp;
                    i++;
                }
            } while (i<4);
            j++;
        } while (j<4);
    }
    else {
        fprintf(stdout,"Probl�me de fichier");
    }
    return gr;
}

void affichage_grille(grille* gr){
    int i=0;
    int j=0;
    freopen("CON","w",stdout);
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            fprintf(stdout,"%c ",get_char(gr->jeu[i][j]));
        }
        fprintf(stdout,"\n");
    }
}

mot** meilleur_score(grille* gr){

}

