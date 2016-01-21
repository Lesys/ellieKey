#define MAX_NUM 16

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/fonctions.h"

//Fonction donnant un random modulo 36, donc entre 0 et 35
int GetRandom() {
    int randNum = 0; //Initialisation de la variable qui va prendre le random
    srand(time(NULL)); //Initialisation de rand
    randNum = rand()%MAX_NUM; //Affectation du random à la variable

    return randNum; //Retourne le random pour l'insérer dans le tableau pour la clé
}
