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
				printf("%sReintentos restantes: (%d)\n", error, retries);
				scanfReturn = scanf("%d", &aux);
				retries--;
			} else {
				retries = 0;
				*number1 = aux;
				r = 0;
			}
		}while(retries > 0);
		if(r == -1){
			printf("Reintentos agotados. Intentelo nuevamente");
		}
	}
	return r;
}

int options(char* message,int *option,  float number1, float number2, float number3, int min, int max){ //Remasterizar función
	int r = -1;
	int aux;
	int scanfReturn;

	if(message != NULL && option != NULL){
		printf(message, number1, number2, number3);
		scanfReturn = scanf("%d", &aux);
		if(scanfReturn != 1 || aux > max || aux < min){
			printf("Ha habido un error. Intentelo de nuevo\n");
		} else {
			*option = aux;
			r = 0;
		}
	}

	return r;

}
