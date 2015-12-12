#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "dico.h"
#include "grille.h"



int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1){
        freopen("CON","w",stdout);
        fprintf(stdout,"Erreur");
        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640,480,16,SDL_HWSURFACE);
        SDL_Delay(10000);
    }
    else {
        freopen("CON","w",stdout);
        grille* gr = create_grille("grille.txt");
        affichage_grille(gr);
        arbre dico;
        printf("création du dictionnaire...\n");


        //Test création lettre, mot, taille des mots, score des mots
        lettre* a = create_lettre('a');
        lettre* b = create_lettre('b');
        lettre* a2 = create_lettre('a');
        lettre* i = create_lettre('i');
        lettre* s = create_lettre('s');
        lettre* s2 = create_lettre('s');
        lettre* e = create_lettre('e');
        lettre* m = create_lettre('m');
        lettre* e2 = create_lettre('e');
        lettre* n = create_lettre('n');
        lettre* t = create_lettre('t');

        /*lettre** abaissement = (lettre *) malloc(11*sizeof(lettre*));
        int ind=0;
        for (ind=0;ind<11;ind++){
            abaissement[ind]=malloc(sizeof(lettre));
        }
        abaissement[0] = a;
        abaissement[1] = b;
        abaissement[2] = a2;
        abaissement[3] = i;
        abaissement[4] = s;
        abaissement[5] = s2;
        abaissement[6] = e;
        abaissement[7] = m;
        abaissement[8] = e2;
        abaissement[9] = n;
        abaissement[10] = t;
        mot* word = create_mot(abaissement,11);
        fprintf(stdout, "taille de word :%d\n",word->taille);
<<<<<<< HEAD
        fprintf(stdout,"score d'%s :", retrouve_chaine_carac(word));
        fprintf(stdout,"%d\n",calcul_score(word));*/

        //Test création de mot avec mot vide
        mot* word = create_mot_sans_tail();
        word = ajout_lettre(word,a);
        word = ajout_lettre(word,b);
        word = ajout_lettre(word,a2);
        word = ajout_lettre(word,i);
        word = ajout_lettre(word,s);
        word = ajout_lettre(word,s2);
        word = ajout_lettre(word,e);
        word = ajout_lettre(word,m);
        word = ajout_lettre(word,e2);
        word = ajout_lettre(word,n);
        word = ajout_lettre(word,t);
        fprintf(stdout,"taille de word : %d\n",word->taille);
        fprintf(stdout,"score d'%s : %d\n",retrouve_chaine_carac(word),calcul_score(word));
=======
        fprintf(stdout,"score d'%s : %d\n", retrouve_chaine_carac(word),calcul_score(word));
>>>>>>> origin/master

        //Création dictionnaire
        dico = cree_dico("dico.txt");
        /*mot** meilleur = meilleur_score(gr,dico);
        int score_mot=0;
        int compt=0;
        int score_tot = 0;
        while(meilleur[compt]){
            score_mot = calcul_score(meilleur[compt]);
            score_tot += score_mot;
            fprintf(stdout,"%s : %d\n",retrouve_chaine_carac(meilleur[compt]),score_mot);
            compt++;
        }
        fprintf(stdout,"score total : %d",score_tot);*/
        //dico = cree_dico("mots");

        //Parcours automatique de la grille
        liste_mot* liste_fin = create_liste();
        mot* temp = create_mot_sans_tail();
        liste_fin = auto_grille(-1,-1,liste_fin,temp,dico,gr);
        affichage_liste(liste_fin);


        fprintf(stdout,"OK\n");


        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640,480,16,SDL_HWSURFACE);
        SDL_Delay(10000);
    }

    printf("Hello World\n");

    system("PAUSE");
    SDL_Quit();
    return EXIT_SUCCESS;
}
