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
        lettre** abaissement = (lettre *) malloc(11*sizeof(lettre*));
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
        fprintf(stdout,"score d'%s : %d\n", retrouve_chaine_carac(word),calcul_score(word));

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
        verifie_mots(dico);
        //fprintf(stdout,"OK\n");


        SDL_Surface *screen;
        screen = SDL_SetVideoMode(640,480,16,SDL_HWSURFACE);
        SDL_Delay(10000);
    }

    printf("Hello World\n");

    system("PAUSE");
    SDL_Quit();
    return EXIT_SUCCESS;
}
