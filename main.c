#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "dico.h"



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
        arbre dico;
        printf("création du dictionnaire...\n");
        lettre* a = create_lettre('a',1,1,1);
        lettre* b = create_lettre('b',1,1,2);
        lettre* a2 = create_lettre('a',1,2,1);
        lettre* i = create_lettre('i',1,3,1);
        lettre* s = create_lettre('s',1,1,1);
        lettre* s2 = create_lettre('s',1,1,1);
        lettre* e = create_lettre('e',1,1,3);
        lettre* m = create_lettre('m',1,1,1);
        lettre* e2 = create_lettre('e',1,1,1);
        lettre* n = create_lettre('n',1,2,1);
        lettre* t = create_lettre('t',1,2,3);
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
        fprintf(stdout,"score d'abaissement : %d\n", calcul_score(word));
        dico = cree_dico("dico.txt");
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
