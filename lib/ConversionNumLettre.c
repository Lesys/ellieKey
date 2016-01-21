#include <stdio.h>
#include <stdlib.h>

#include "../include/fonctions.h"

//Fonction permettant la convertion des numéros tirés au hasard en caractères (les numéros de 0 à 9 sont les mêmes)
char ConversionNumLettre(int numeroCle) {
	char numChar;

	switch(numeroCle) { //En fonction du numéro de "numeroCle", affecte un caractère différent à "numChar"
		case 0: numChar = '0';
			break;
        case 1: numChar = '1';
            break;
        case 2: numChar = '2';
            break;
        case 3: numChar = '3';
            break;
        case 4: numChar = '4';
            break;
        case 5: numChar = '5';
            break;
        case 6: numChar = '6';
            break;
        case 7: numChar = '7';
            break;
        case 8: numChar = '8';
            break;
        case 9: numChar = '9';
            break;
        case 10: numChar = 'A';
            break;
        case 11: numChar = 'B';
            break;
        case 12: numChar = 'C';
            break;
        case 13: numChar = 'D';
            break;
        case 14: numChar = 'E';
            break;
        case 15: numChar = 'F';
            break;
        default: numChar = '?';
            break;
	}
	return numChar; //Retourne le caractère correspondant au numéro selon la norme du switch
}