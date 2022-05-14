/*
 * general.h
 *
 *  Created on: 11 may 2022
 *      Author: gonza
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#define MAX_SIZE_CHARS 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(char message[], char messageError[], int min, int retries,
		int *number1);
int utn_getNumeroWithMax(char message[], char messageError[], int min, int max,
		int retries, int *number1);
int utn_getNumeroFlotante(char message[], char messageError[], int min,
		int retries, float *number1);
int getString(char *cadena, int longitud, char message[], char messageError[], int retries);
int getInt(int *number1);
int esNumerica(char arrayNum[]);
int myGets(char cadena[], int longitud);
int getFloat(float *number1);
int isFloat(char cadena[]);
int printMessage(char *message, int type);
int produceAsterisks(char asterisks[], int size);
int confirmation(char message[], char messageError[]);
#endif /* GENERAL_H_ */

