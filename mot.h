#ifndef mot_h
#define mot_h
#include "lettre.h"

typedef struct{
    lettre** word;
    int score;
    int multiplicateur;
} mot;

#endif // mot_h
