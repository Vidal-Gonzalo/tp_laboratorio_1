/*
 * general.c
 *
 *  Created on: 11 may 2022
 *      Author: gonza
 */

#include "general.h"

int utn_getNumero(char message[], char messageError[], int min, int retries,
		int *number1) {
	int r = -1;
	int auxInt;

	if (message != NULL && min >= 0 && messageError != NULL && number1 != NULL
			&& retries > 0) {
		printf("%s", message);
		do {
			if (getInt(&auxInt) == 0 && auxInt >= min) {
				*number1 = auxInt;
				r = 0;
				break;
			}
			retries--;
			printf("%s", messageError);
		} while (retries > 0);
	}
	return r;
}

int utn_getNumeroFlotante(char message[], char messageError[], int min,
		int retries, float *number1) {
	int r = -1;
	float auxFloat;

	if (message != NULL && min >= 0 && messageError != NULL && number1 != NULL
			&& retries > 0) {
		printf("%s", message);
		do {
			if (getFloat(&auxFloat) == 0 && auxFloat >= min) {
				*number1 = auxFloat;
				r = 0;
				break;
			}
			retries--;
			printf("%s", messageError);
		} while (retries > 0);
	}

	return r;
}

int getString(char *cadena, int longitud, char message[], char messageError[]) {
	int r = -1;
	char aux[4096];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		printf("%s", message);
		if (myGets(aux, 4096) == 0) {
			strncpy(cadena, aux, longitud);
			r = 0;
		} else {
			printf("%s", messageError);
		}
	}
	return r;
}

int getInt(int *number1) {
	int r = -1;
	char numAux[200];
	if (myGets(numAux, sizeof(numAux)) == 0 && esNumerica(numAux) == 0) {
		*number1 = atoi(numAux);
		r = 0;
	}
	return r;
}

int esNumerica(char arrayNum[]) {
	int r = -1;
	int i;

	if (arrayNum != NULL) {
		i = 0;
		if (arrayNum[0] == '-') {
			i = 1;
		}
		for (i = 0; arrayNum[i] != '\0'; i++) {
			if (arrayNum[i] < '0' || arrayNum[i] > '9') {
				r = -1;
				break;
			}
		}
		r = 0;
	}
	return r;
}

int myGets(char cadena[], int longitud) { //Hacer el getFloat
	int r = -1;
	char aux[4096]; //esto es un buffer
	aux[strlen(aux) - 1] = '\0';
	if (cadena != NULL && longitud > 0
			&& fgets(aux, sizeof(aux), stdin) == aux) {
		r = 0;
		strncpy(cadena, aux, longitud);
	}
	return r;
}

int getFloat(float *number1) {
	int r = -1;
	char aux[64];

	if (number1 != NULL) {
		if (myGets(aux, sizeof(aux)) == 0 && isFloat(aux) == 0) {
			*number1 = atof(aux);
			r = 0;
		}
	}
	return r;
}

int isFloat(char cadena[]) {
	int i = 0;
	int r = -1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if ((i == 0 && cadena[i] == '-') || cadena[i] == '+') {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
					r = 0;
					break;
				}
			}
		}
	}
	return r;
}

int printMessage(char *message, int type) {
	//type = 1 ---> underlined
	//type = 2 ---> alert

	int r = -1;
	int length;
	char asterisks[4096];
	if (message != NULL) {
		fflush(stdin);
		length = strlen(message);
		produceAsterisks(asterisks, length);
		if (type == 2) {
			r = 0;
			printf("\n%s*****", asterisks);
			puts("");
			printf("\n*  %s  *\n", message);
			puts("");
			printf("%s*****\n\n", asterisks);
		} else {
			if (type == 1) {
				printf("\n%s\n", message);
				printf("%s", asterisks);
				puts("");
			}
		}

	}
	return r;
}

int produceAsterisks(char asterisks[], int size) {
	int r = -1;
	char newAsterisks[4096];
	char asterisk[1] = { "*" };
	fflush(stdin);
	if (asterisks != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			newAsterisks[i] = asterisk[0];
		}
		strcpy(asterisks, newAsterisks);
		r = 0;
	}
	return r;
}

int confirmation(char message[], char messageError[]) {
	int r = -1;
	int aux = 0;
	if (utn_getNumero(message, messageError, 0, 3, &aux) == 0) {
		if (aux == 1) {
			r = 1;
		} else {
			r = 0;
		}
	} else {
		printMessage(messageError, 1);
	}

	return r;
}
