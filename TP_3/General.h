/*
 * General.h
 *
 *  Created on: 14 may 2022
 *      Author: gonza
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(char message[], char messageError[], int min, int retries,
		int *number1);
int utn_getNumeroWithMax(char message[], char messageError[], int min, int max,
		int retries, int *number1);
int utn_getNumeroFlotante(char message[], char messageError[], float min,
		int retries, float *number1);
int utn_getString(char newArray[], int size, char message[],
		char messageError[], int retries);
int utn_getShortInt(char message[], char messageError[], int min, int max,
		int retries, short int *number1);
int utn_getStringWithMin(char newArray[], int size, int min, char message[],
		char messageError[], int retries);
int getShortInt(short int *number1);
int getInt(int *number1);
int isNumber(char arrayNum[]);
int myGets(char newArray[], int size);
int getFloat(float *number1);
int isFloat(char newArray[]);
int getString(char *newArray, int size);
int getName(char *newArray, int size);
int isName(char newArray[], int size);
int general_getEmail(char newArray[], int size, char message[],
		char messageError[], int retries);
int getEmail(char newArray[], int size);
int verifyAt(char email[], int size);
int general_getAlphanumeric(char newArray[], int size, char message[],
		char messageError[], int retries);
int general_getAlphanumericWithMin(char newArray[], int size, int min,
		char message[], char messageError[], int retries);
int getAlphanumeric(char newArray[], int size);
int verifyAlphanumeric(char newArray[], int size);
int produceAsterisks(char asterisks[], int size);
int printExamMenu(int type);
int confirmation(char message[], char messageError[]);

#endif /* GENERAL_H_ */
