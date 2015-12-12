
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

<<<<<<< HEAD
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

=======
<<<<<<< HEAD
liste_mot* auto_grille(int i, int j,liste_mot* liste_fin,mot* temp,arbre dictio, grille* gr){
    char mot_fin[16]; //mot de maximum 16 lettres (16 cases dans une grille)
    char carac;
    carac = dictio->data;
    if ((carac == NULL) || (carac > dictio->data)) return NULL;
    if (carac == '\0') liste_fin = ajout_mot(liste_fin,temp);
    //on cherche une case avec le caractère
    //Si on trouve, on passe aux cases autour et l'arbre gauche
    //Sinon, arbre droite
    return liste_fin;
}

=======
/*mot** meilleur_score(grille* gr,arbre dictio){
    int nb_mot = 1600;  //On considère qu'il n'y a pas plus de 1600 mots possibes par grille (100 par case de départ
    int i=0;
    int j=0;
    mot** liste_meilleurs = (mot *) malloc(nb_mot*sizeof(mot*)); //max 1600 mots
    int c=0;
    for (c=0;c<nb_mot;c++){
        liste_meilleurs[c] = malloc(sizeof(mot));
    }
    int compt=0;
    lettre** lettres = (lettre *) malloc(20*sizeof(lettre*)); //20 lettres max sur un mot
    while (compt < nb_mot){
        for (i=0;i<4;i++){
            for (j=0;j<4;j++){
                liste_meilleurs=ranger_ens_mot(trouve_mot(i,j,gr,dictio,lettres,0),liste_meilleurs);
            }
        }
    }
    return liste_meilleurs;
}

mot** trouve_mot(int i,int j,grille* gr,arbre dictio,lettre** lettres,int num_lettre){
    mot** word=(mot*)malloc(100*sizeof(mot*));
    int nb_mot=0;
    mot* temp=malloc(sizeof(mot));
    int count;
    for (count=0;count<100;count++){
        word[count]=malloc(sizeof(mot));
    }
    if ((dictio==NULL)||(dictio->data > gr->jeu[i][j]->letter)) return NULL;
    if (gr->jeu[i][j]->letter == dictio->data){
        lettres[num_lettre]==create_lettre_with_2(dictio->data,gr->jeu[i][j]->multiplicateur_mot,gr->jeu[i][j]->multiplicateur_lettre);
        num_lettre++;
        temp=create_mot(lettres);
        if (est_dans_dico(retrouve_chaine_carac(temp),dictio)){
            word[nb_mot]=temp;
            nb_mot++;
        }
        if (i==0){
            if (j==0){
                word = ranger_ens_mot(trouve_mot(i,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j,gr,dictio->gauche,lettres,num_lettre),word);
            }
            else if (j==3){
                word = ranger_ens_mot(trouve_mot(i,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j,gr,dictio->gauche,lettres,num_lettre),word);
            }
            else {
                word = ranger_ens_mot(trouve_mot(i,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i+1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
            }
        }
        else if (i==3){
            if (j==0){
                word = ranger_ens_mot(trouve_mot(i,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j,gr,dictio->gauche,lettres,num_lettre),word);
            }
            else if (j==3){
                word = ranger_ens_mot(trouve_mot(i,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j,gr,dictio->gauche,lettres,num_lettre),word);
            }
            else {
                word = ranger_ens_mot(trouve_mot(i,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i,j-1,gr,dictio->gauche,lettres,num_lettre),word);
                word = ranger_ens_mot(trouve_mot(i-1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
            }
        }
        else {
            word = ranger_ens_mot(trouve_mot(i,j+1,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i-1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i-1,j,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i,j-1,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i-1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i+1,j+1,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i+1,j,gr,dictio->gauche,lettres,num_lettre),word);
            word = ranger_ens_mot(trouve_mot(i+1,j-1,gr,dictio->gauche,lettres,num_lettre),word);
        }
    }
    word = trouve_mot(i,j,gr,dictio->droite,lettres,num_lettre);
    return word;
}

mot** ranger_ens_mot(mot** source,mot** dest){
    int i=0;
    int j=0;
    while (dest[i] != NULL){
        i++;
    }
    i++;
    while (source[j]){
        dest[i]=source[j];
        j++;
        i++;
    }
    return dest;
}*/

>>>>>>> origin/master
>>>>>>> origin/master


