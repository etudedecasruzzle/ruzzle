#ifndef dico_h
#define dico_h
#include <stdio.h>
#include "mot.h"

typedef struct{
    mot** dictionnaire;
} dico;

dico* create_dico_from_file(FILE* fichier);

#endif // dico_h
