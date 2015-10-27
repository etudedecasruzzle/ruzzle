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
        FILE* fichier = fopen("dico.txt","r");
        dico* dictionnaire = create_dico_from_file(fichier);
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
