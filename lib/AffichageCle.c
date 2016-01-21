#define TAILLE_CLE 27
#define TAILLE_ESPACE 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/fonctions.h"

//Fonction permettant d'afficher la dernière clé qui vient d'être créée pour que l'utilisateur l'enregistre
void AffichageCle() {
	FILE* fichierCles = NULL; //Declaration du fichier fichierCles qui prendra comme valeur le fichier lesCles voir ligne en dessous)
	fichierCles = fopen("keys.txt", "r"); //Ouvre le fichier en lecture seule
	char laCle[TAILLE_CLE]; //Initialisation d'un tableau de caractère qui prendra la valeur de la dernière clé enregistrée pour l'afficher
	int i = 0; //Entier pour permettre l'affichage de la clé
	rewind(fichierCles); //Nous place au début du fichier

	while (fgets(laCle, TAILLE_CLE, fichierCles)) { //Parcours toutes les clés pour prendre la dernière
	}

	while (i < TAILLE_CLE - 1) { //Affiche la clé caractère par caractère
		if (i % TAILLE_ESPACE == 0 && i != 0) { //Tout les 5 caractères, il espace s'affiche (pour la lisibilité)
			printf(" "); //Affiche l'espace
		}

		printf("%c", laCle[i]); //Affiche le caractère à la position 'i'
		i++; //Incrémente 'i' de 1 pour le prochain caractère
	}
}