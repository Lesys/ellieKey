//AFFICHAGE GRAPHIQUE BY KNONN
//GRAPHIC INTERFACE BY KNONN

#include <stdio.h>
#include <stdlib.h>

#include "../include/fonctions.h"

int main() {
	DefinitionCle(); //Appelle la fonction qui permet de créer la clé
	printf("Your Ellie key is: "); //Indication
	AffichageCle(); //Affiche la dernière clé insérée dans le fichier des clés
	return 0;
}