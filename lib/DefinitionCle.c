//AFFICHAGE GRAPHIQUE BY KNONN
//GRAPHIC INTERFACE BY KNONN

#define TAILLE_CLE 27
#define TAILLE_CHAR 26
#define TAILLE_INT 25

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "../include/fonctions.h"

//Fonction de fabrication de la clé Ellie et insérant cette dernière dans le fichier "lesCles"
void DefinitionCle() {
	int liste[TAILLE_INT] = {0}; //Initialisation du tableau d'entier liste qui contiendra la liste des caractère les uns après les autres
	char listeChar[TAILLE_CHAR]; //Initialisation du tableau de caractère qui sera enregistré dans le fichier "lesCles"
	FILE* fichierCles = NULL; //Declaration du fichier fichierCles qui prendra comme valeur le fichier lesCles voir ligne en dessous)
	fichierCles = fopen("keys.txt", "a+"); //Ouverture du fichier lesCles et implémentation dans la variable fichier fichierCles
	_Bool doubleDeCles; //Booléen qui permet de refaire la boucle ou non (en fonction de si la clé est identique a une autre dans le fichier)

	do {
		doubleDeCles = true; //Initialisation a "true" car si le fichierCles n'est pas trouvé ou s'il n'existe pas, le programme ne tournera pas en boucle / dans le vide
		int r2 = 0; //r2 est la variable qui prendra le caractère random pour le mettre dans la liste.
		int rep = 0; //rep est la variable qui, quand un caractère (r2) a été répété trop de fois (plus de 3 fois dans la liste dejaVu) il est supprimé et on reprend un autre random
		int comparaisonListe = 0; //Permet de faire la comparaison avec les autres clés qui sont dans le fichier lesCles et de voir si cette clé existe déjà (exactement la même clé)
		bool ok; //Booléen qui permet de savoir si on ajoute
		int num = 0; //Numéro pour parcourir les listes "liste" et "dejaVu" pour completer la liste
		int j = 0; //Nombre pour faire la boucle d'ajout des numéros (de 0 à 24)
		int i = 0; //Nombre pour faire tout les "while"
		double a = 0; //Nombre pour le compteur de génération
		char cleDouble[TAILLE_CHAR]; //Déclaration d'une chaine de caractère vide de taille TAILLE_CLE
		printf("Generating..."); //Affiche le début de la génération de la clé


		if (fichierCles != NULL) {//Si l'ouverture et l'implémentation dans le fichier fichierCles a bien été faite et qu'il n'est pas NULL (donc a gardé la valeur de déclaration)
			while (i < TAILLE_INT) { //Donne les nombres x 25
				r2 = GetRandom(); //On donne une valeur random a la variable r2
	   			printf("%f%%\n", (a/TAILLE_INT)*100); //Affiche le pourcentage d'avancement
				//printf("r2 != %d, test r2 != num avec num == %d n° %d\n", r2, num, j); //Pour les tests: Affiche les valeurs
	   			sleep(1); //Fait une pause de 1 seconde
				rep = 0; //On remet la valeur de rep a 0 pour pouvoir la réutiliser dans le while suivant
				j = 0; //Compteur pour les tests

		   		do{ //Boucle pour faire la liste de 25 arguments
					num = liste[j]; //Prend le numéro de la liste a l'emplacement j (pour comparer le nouveau avec les anciens)

		   	     	if (r2 == num) { //On regarde si le numéro est déjà présent. Si oui, on incrémente rep de 1 pour signaler une répétition de nombre
						rep++;  //Ajoute 1 dans le compteur de répétition du caractère
						//printf("r2 == %d, test r2 == num avec num == %d n° %d\n", r2, num, j); //Pour les tests: Affiche les valeurs
					}
					else {
						//printf("r2 == %d, test r2 != num avec num == %d n° %d\n", r2, num, j); //Pour les tests: Affiche les valeurs
					}

					if (rep == 3) { //Si il est 3 fois dedans, on break et on recommence avec un autre
			   		    i--; //Enlève 1 au compteur du nombre de caractères fait car trop de fois présent dans la clé
			   		    a--; //Réduit le compteur de génération de 1
						//printf("r2 == %d, test r2 == 3 avec num == %d n° %d\n", r2, num, j); //Pour les tests: Affiche les valeurs
		   			    break; //Casse le "while" pour refaire le numéro (car trop présent dans la nouvelle clé)
					}

					j++; //Compteur pour comparer les numéros déjà présents dans la nouvelle clé
					if (i == j || i == 0) { //Si le numéro n'est pas déjà présent 3 fois (après vérification de tout les autres numéros)
						liste[i] = r2; //On ajoute le numéro a la fin de la clé
						//printf("i==%d\n", i); //Pour les tests: Affiche l'index du numéro
					}

				} while (j < i); //Tant que le nombre de nuémros déjà inscrit nest pas atteind

				i++; //Incrémente le compteur du while de 1
				a++; //Incrémente le compteur de la génération de 1
			}

			while (fgets(cleDouble, TAILLE_CLE, fichierCles)) { //On regarde si la suite de chiffre existe déjà (oui, c'est peu probable mais quand même :/)
				comparaisonListe = 0; //Réinitialisation du compteur de comparaison des clés
				i = 0; //Réinitialisation du compteur poru le while

				while (i < TAILLE_INT) { //Pour tout les caractères dans la clé
					if (cleDouble[i] == ConversionNumLettre(liste[i])) { //Si le caractère de la nouvelle clé est le même que celui de la clé vérifiée
						comparaisonListe++; //On ajoute 1 dans la variable
					}
					//printf("cleDouble: %c liste: %c\n", cleDouble[i], ConversionNumLettre(liste[i])); //Affichage du caractère actuel des 2 clés
					i++; //Ajoute 1 au compteur pour le while
				}
				if (comparaisonListe == TAILLE_INT) { //Si la clé est exactement la même qu'une déjà dans le fichier
					doubleDeCles = false; //On passe le booléen en false pour devoir refaire la clé en entière
					break; //On quitte le while actuel
				}
			}
		}
		else { //Si le fichier n'a pas pu être ouvert
			printf("Problème: le fichier n'a pas été trouvé. Essayez de voir si le chemin est correct."); //Affiche un message d'erreur
			exit(1); //Quitte le programme avec le code d'erreur 1
		}
	}
	while (doubleDeCles == false); //Tant que la clé générée est la même qu'une autre clé dans le fichier

	int i = 0; //Entier pour faire la boucle
	while (i < TAILLE_INT) { //Tant que 'i' n'atteind pas le dernier entier du tableau
		listeChar[i] = ConversionNumLettre(liste[i]); //Affecte le numéro converti en char dans le tableau "listeChar" a l'index 'i'
		//printf("%c", listeChar[i]); //Test pour voir les caractères de la nouvelle clé
		i++; //Incrémente pour la boucle
	}
	listeChar[i] = '\0'; //Affecte la fin de chaine de caractère pour le tableau
	fputs(listeChar, fichierCles); //Écrit la chaine de caractère dans le fichier contenant les clés
	fputs("\n", fichierCles); //Fait un saut de ligne pour écrire une clé prochainement

	fclose(fichierCles); //Ferme le fichier correctement
}
