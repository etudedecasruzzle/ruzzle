
#include "grille.h"

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
        fprintf(stdout,"Problème de fichier");
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

liste_mot* auto_grille(int i, int j,liste_mot* liste_fin,mot* temp,arbre dictio, grille* gr){
    mot* stock = temp;
    arbre dico = dictio;
    char carac;
    carac = dictio->data;
    freopen("CON","w",stdout);
    if (carac == '\0'){
        fprintf(stdout,"%s\n",retrouve_chaine_carac(temp));
        liste_fin = ajout_mot(liste_fin,temp);
        fprintf(stdout,"OK\n");
        if (dictio->droite != NULL){
            liste_fin=auto_grille(i,j,liste_fin,temp,dictio->droite,gr);
        }
        else {
            return liste_fin;
        }
    }

    int l,col;
    for (l=0;l<4;l++){
        for (col=0;col<4;col++){
            if (gr->jeu[l][col]->letter == dictio->data){
                if (i != 0 && j != 0 && i != 3 && j != 3 && i != -1 && i != -1){
                    if (l<=i+1 && l>=i-1 && col>=j-1 && col<=j+1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (i==0 && j==0){
                    if (l<=i+1 && col<=j+1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (i==0 && j<3){
                    if (l<=i+1 && col>=j-1 && col<=j+1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j==0 && i<3){
                    if (l<=i+1 && l>=i-1 && col<=j+1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j==3 && i==0){
                    if (l<=i+1 && col>=j-1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j==3 && i<3){
                    if (l<=i+1 && l>=i-1 && col>=j-1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j==3 && i==3){
                    if (l>=i-1 && col>=j-1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j<3 && i==3){
                    if (l>=i-1 && col>=j-1 && col<=j+1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else if (j==0 && i==3){
                    if (l>=i-1 && col<=j+1 && i != -1 && i != -1){
                        if (!contient_lettre(temp,gr->jeu[l][col])){
                            temp = ajout_lettre(temp,gr->jeu[l][col]);
                            liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                            temp = stock;
                            carac = dico->data;
                        }
                    }
                }
                else {
                    if (!contient_lettre(temp,gr->jeu[l][col])){
                        temp = ajout_lettre(temp,gr->jeu[l][col]);
                        liste_fin = auto_grille(l,col,liste_fin,temp,dictio->gauche,gr);
                        temp = stock;
                        carac = dico->data;
                    }

                }
            }
        }
    }
    if (dictio->droite){
        liste_fin = auto_grille(i,j,liste_fin,temp,dictio->droite,gr);
    }
    else {
        return liste_fin;
    }
    return liste_fin;
    //Sinon, arbre droite
}



