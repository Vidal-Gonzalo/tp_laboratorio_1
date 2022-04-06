/*
 * askInformation.c
 *
 *  Created on: 5 abr 2022
 *      Author: Gonzalo Vidal - Division H
 */

#include "askInformation.h"

int getInfo(char* message, float *number1, int retries, int min, char* error){
	int r = -1;
	int aux;
	int scanfReturn;

	if(message != NULL && error != NULL && number1 != NULL && retries > 0){
		printf("%s\n", message);
		scanfReturn = scanf("%d", &aux);
		do{
			if(scanfReturn != 1 || aux < min){
				printf("%s. Reintentos restantes: (%d)\n", error, retries);
				scanfReturn = scanf("%d", &aux);
				retries--;
			} else {
				retries = 0;
				*number1 = aux;
				r = 0;
			}
		}while(retries > 0);
	}
	return r;
}

int options(char* message, float number1, float number2, float number3){
	int response;
	printf(message, number1, number2, number3);
	scanf("%d", &response);
	return response;
}
