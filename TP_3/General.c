/*
 * General.c
 *
 *  Created on: 14 may 2022
 *      Author: gonza
 */

#include "general.h"

//Numbers
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

int utn_getShortInt(char message[], char messageError[], int min, int max,
		int retries, short int *number1) {
	int r = -1;
	short int auxInt;

	if (message != NULL && min >= 0 && max > 0 && messageError != NULL
			&& number1 != NULL && retries > 0) {
		printf("%s", message);
		do {
			if (getShortInt(&auxInt) == 0 && auxInt >= min && auxInt <= max) {
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

int utn_getNumeroWithMax(char message[], char messageError[], int min, int max,
		int retries, int *number1) {
	int r = -1;
	int auxInt;

	if (message != NULL && min >= 0 && max >= 1 && messageError != NULL
			&& number1 != NULL && retries > 0) {
		printf("%s", message);
		do {
			if (getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max) {
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

int utn_getNumeroFlotante(char message[], char messageError[], float min,
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

int getFloat(float *number1) {
	int r = -1;
	char aux[200];

	if (myGets(aux, sizeof(aux)) == 0) {
		if (isNumber(aux) == 0) {
			*number1 = atof(aux);
			r = 0;
		}

	}
	return r;
}

int getInt(int *number1) {
	int r = -1;
	char numAux[200];
	if (myGets(numAux, sizeof(numAux)) == 0 && isNumber(numAux) == 0) {
		*number1 = atoi(numAux);
		r = 0;
	}
	return r;
}

int getShortInt(short int *number1) {
	int r = -1;
	char numAux[200];
	if (myGets(numAux, sizeof(numAux)) == 0 && isNumber(numAux) == 0) {
		*number1 = atoi(numAux);
		r = 0;
	}
	return r;
}

int isNumber(char arrayNum[]) {
	int r = -1;
	int i;

	if (arrayNum != NULL) {
		i = 0;
		if (arrayNum[0] == '-') {
			i = 1;
		}
		for (i = 0; arrayNum[i] != '\0'; i++) {
			if (arrayNum[i] < '9' || arrayNum[i] > '0') {
				r = 0;
				break;
			}
		}
	}
	return r;
}

int isFloat(char cadena[]) {
	int r = -1;
	int i = 0;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] > '0' || cadena[i] < '9') {
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

int myGets(char cadena[], int longitud) {
	int r = -1;
	char aux[4096];
	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(aux, sizeof(aux), stdin) != NULL) {
			if (aux[strnlen(aux, sizeof(aux)) - 1] == '\n') {
				aux[strnlen(aux, sizeof(aux)) - 1] = '\0';
			}
		}
		if (strnlen(aux, sizeof(aux)) <= longitud) {
			strncpy(cadena, aux, longitud);
			r = 0;
		}
	}
	return r;
}

//Strings
int getString(char *newArray, int size) {
	int r = -1;
	char bufferString[4096];

	if (newArray != NULL && size > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= size) {
				strncpy(newArray, bufferString, size);
				r = 0;
			}
		}
	}
	return r;
}

int getName(char *newArray, int size) {
	int r = -1;
	char buffer[4096];

	if (newArray != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& isName(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < size) {
			strncpy(newArray, buffer, size);
			r = 0;
		}
	}
	return r;
}

int isName(char newArray[], int size) {
	int i = 0;
	int r = 1;

	if (newArray != NULL && size > 0) {
		for (i = 0; newArray[i] != '\0' && i < size; i++) {
			if ((newArray[i] < 'A' || newArray[i] > 'Z')
					&& (newArray[i] < 'a' || newArray[i] > 'z')) {
				r = 0;
				break;
			}
		}
	}
	return r;
}

int utn_getString(char newArray[], int size, char message[],
		char messageError[], int retries) {
	char bufferString[4096];
	int r = -1;
	if (newArray != NULL && size > 0 && message != NULL && messageError != NULL
			&& retries > 0) {
		while (retries >= 0) {
			retries--;
			printf("%s", message);
			if (getName(bufferString, sizeof(bufferString)) == 0
					&& strnlen(bufferString, sizeof(bufferString)) < size) {
				strncpy(newArray, bufferString, size);
				r = 0;
				break;
			}
			printf("%s", messageError);
		}
	}

	return r;
}

int utn_getStringWithMin(char newArray[], int size, int min, char message[],
		char messageError[], int retries) {
	char bufferString[4096];
	int r = -1;
	if (newArray != NULL && size > 0 && message != NULL && messageError != NULL
			&& retries > 0) {
		while (retries >= 0) {
			retries--;
			printf("%s", message);
			if (getName(bufferString, sizeof(bufferString)) == 0
					&& strnlen(bufferString, sizeof(bufferString)) < size) {
				if (strnlen((bufferString), sizeof(bufferString)) >= min) {
					strncpy(newArray, bufferString, size);
					r = 0;
					break;
				} else {
					printf("Minimo 4 caracteres.\n");
				}
			}
			printf("%s", messageError);
		}
	}

	return r;
}

int general_getEmail(char newArray[], int size, char message[],
		char messageError[], int retries) {
	int r = -1;
	char bufferString[4096];
	if (newArray != NULL && size > 0 && message != NULL && messageError != NULL
			&& retries > 0) {
		while (retries >= 0) {
			retries--;
			printf("%s", message);
			if (getEmail(bufferString, sizeof(bufferString)) == 0
					&& strnlen(bufferString, sizeof(bufferString)) < size) {
				strncpy(newArray, bufferString, size);
				r = 0;
				break;
			}
			printf("%s", messageError);
		}
	}
	return r;
}

int getEmail(char newArray[], int size) {
	int r = -1;
	char buffer[4096];
	if (newArray != NULL && size > 0) {
		if (getString(buffer, sizeof(buffer)) == 0) {
			if (verifyAt(buffer, sizeof(buffer)) == 0) {
				strncpy(newArray, buffer, size);
				r = 0;
			}
		}
	}
	return r;
}

int verifyAt(char email[], int size) {
	int r = -1;
	int at = 0;
	int dot = 0;

	if (email != NULL && size > 0) {
		for (int i = 0; email[i] != '\0' && i < size; i++) {
			if (email[i] == '@') {
				at = 1;
			}
			if (email[i] == '.') {
				dot = 1;
			}
		}
		if (at == 1 && dot == 1) {
			r = 0;
		}
	}
	return r;
}

int general_getAlphanumeric(char newArray[], int size, char message[],
		char messageError[], int retries) {
	int r = -1;
	char bufferString[4096];
	if (newArray != NULL && size > 0 && message != NULL && messageError != NULL
			&& retries > 0) {
		while (retries >= 0) {
			retries--;
			printf("%s", message);
			if (getAlphanumeric(bufferString, sizeof(bufferString)) == 0
					&& strnlen(bufferString, sizeof(bufferString)) < size) {
				strncpy(newArray, bufferString, size);
				r = 0;
				break;
			}
			printf("%s", messageError);
		}
	}
	return r;
}

int general_getAlphanumericWithMin(char newArray[], int size, int min,
		char message[], char messageError[], int retries) {
	int r = -1;
	char bufferString[4096];
	if (newArray != NULL && size > 0 && message != NULL && messageError != NULL
			&& retries > 0) {
		while (retries >= 0) {
			retries--;
			printf("%s", message);
			if (getAlphanumeric(bufferString, sizeof(bufferString)) == 0) {
				if (strnlen(bufferString, sizeof(bufferString)) < size
						&& strnlen(bufferString, sizeof(bufferString)) >= min) {
					strncpy(newArray, bufferString, size);
					r = 0;
					break;
				} else {
					printf("Minimo 4 caracteres.\n");
				}
			}

			printf("%s", messageError);
		}
	}
	return r;
}

int getAlphanumeric(char newArray[], int size) {
	int r = -1;
	char buffer[4096];
	if (newArray != NULL && size > 0) {
		if (getString(buffer, sizeof(buffer)) == 0) {
			if (verifyAlphanumeric(buffer, sizeof(buffer)) == 0) {
				strncpy(newArray, buffer, size);
				r = 0;
			} else {
				printf("ups");
			}
		}
	}
	return r;
}

int verifyAlphanumeric(char newArray[], int size) {
	int r = -1;
	int i;
	int isNumber = 0;
	int isAlpha = 0;

	if (newArray != NULL) {
		for (i = 0; newArray[i] != '\0' && i < size; i++) {
			if ((newArray[i] > 'A' && newArray[i] < 'Z')
					|| (newArray[i] > 'a' && newArray[i] < 'z')) {
				isAlpha = 1;
			}
			if (newArray[i] > '0' && newArray[i] < '9') {
				isNumber = 1;
			}
		}
		if (isNumber == 1 && isAlpha == 1) {
			r = 0;
		}
	}
	return r;
}

int printExamMenu(int type) {
	int r = -1;
	if (type >= 0) {
		if (type == 0) {
			printf("*************************\n");
			printf("**1er EXAMEN LAB I - 1H **\n");
			printf("*************************\n\n");
		} else {
			if (type == 1) {
				printf("*************************\n");
				printf("**1er EXAMEN LAB I - 1H **\n");
				printf("********USUARIO********\n");
				printf("*************************\n\n");
			} else {
				if (type == 2) {
					printf("*************************\n");
					printf("**1er EXAMEN LAB I - 1H **\n");
					printf("*********ADMIN**********\n");
					printf("*************************\n\n");
				} else {
					printf(
							"Ha habido un error. Compruebe su estado de usuario.\n");
				}
			}
		}
		r = 0;
	}
	return r;
}

//Others

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
			fflush(stdin);
			puts("");
			fflush(stdin);
			printf("\n*  %s  *\n", message);
			fflush(stdin);
			puts("");
			fflush(stdin);
			printf("%s*****\n\n", asterisks);
			fflush(stdin);
		} else {
			if (type == 1) {
				fflush(stdin);
				printf("\n%s\n", message);
				fflush(stdin);
				printf("%s", asterisks);
				fflush(stdin);
				puts("");
				fflush(stdin);
			}
		}

	}
	return r;
}

int produceAsterisks(char asterisks[], int size) { //No sirve. Toma valores basura los ultimos digitos.
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
		printf(messageError);
	}

	return r;
}

