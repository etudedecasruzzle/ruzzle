#include "dico.h"
dico* create_dico_from_file(FILE* fichier){
    dico* dictionnaire = malloc(sizeof(dico));
    //On va regarder le nombre de ligne du fichier pour savoir combien de case il faut allouer à notre dictionnaire
    //pour pouvoir ensuite construire une table de hashage
    int c;
    int nLignes = 0;
    while((c=fgetc(fichier)) != EOF)
    {
        if(c=='\n')
            nLignes++;
    }
    freopen("CON","w",stdout);
    fprintf(stdout,"%d\n",nLignes);
    dictionnaire->dictionnaire = malloc(nLignes*sizeof(mot));
    char* line[128];
    int hache = 0;
    mot* mot_temp = malloc(sizeof(mot));
    /*while (fgets(line,sizeof(line),fichier) != NULL) {
        hache = hashage(line,nLignes);

        dictionnaire->dictionnaire*[hache]->word = line;
    }*/
    return dictionnaire;
}

int hashage(char* chaine, int nbMot){
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= nbMot;

    return nombreHache;
}
