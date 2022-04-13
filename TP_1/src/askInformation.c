/*
 * askInformation.c
 *
 *  Created on: 5 abr 2022
 *      Author: Gonzalo Vidal - Division H
 */

#include "askInformation.h"

int getInfo(char *message, float *number1, int retries, int min, char *error) {
	int r = -1;
	int aux;
	int scanfReturn;

	if (message != NULL && error != NULL && number1 != NULL && retries > 0) {
		printf("%s\n", message);
		scanfReturn = scanf("%d", &aux);
		do {
			if (scanfReturn != 1 || aux < min) {
				printf("%sReintentos restantes: (%d)\n", error, retries);
				scanfReturn = scanf("%d", &aux);
				retries--;
			} else {
				retries = 0;
				*number1 = aux;
				r = 0;
			}
		} while (retries > 0);
		if (r == -1) {
			printf("Reintentos agotados. Intentelo nuevamente");
		}
	}
	return r;
}

int options(char *message, int *option, float number1, float number2,
		float number3, int min, int max) {
	int r = -1;
	int aux;
	int scanfReturn;

	if (message != NULL && option != NULL) {
		printf(message, number1, number2, number3);
		scanfReturn = scanf("%d", &aux);
		if (scanfReturn != 1 || aux > max || aux < min) {
			printf("Ha habido un error. Intentelo de nuevo\n");
		} else {
			*option = aux;
			r = 0;
		}
	}

	return r;

}

int printResults(float number1, float number2, float number3, float result1,
		float result2, float result3, float result4, float result5,
		float result6, float result7, float result8, float result9) {
	int r = -1;
	if (number1 > 0 && number2 > 0 && number3 > 0) {
		r = 0;
		printf(
				"KMs Ingresados: %.2f\n\nPrecio Aerolineas: $%.2f \na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin:$ %.2f\nPrecio unitario: $%.2f\n\n" "Precio Latam: $%.2f\na)Precio con tarjeta de debito:$ %.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin: $%.2f\nPrecio unitario: $%.2f \nLa diferencia de precio es: $%.2f",
				number1, number2, result1, result2, result3, result4, number3,
				result5, result6, result7, result8, result9);
	} else {
		printMessage("Ha habido un error. Intentelo nuevamente, por favor.", 2);
	}
	return r;
}

int printMessage(char *message, int size) {
	int r = -1;
	if (message != NULL && size > 0) {
		r = 0;
		if (size == 1) {
			printf("\n**********\n%s\n**********\n", message);

		} else {
			if (size == 2) {
				printf("\n********************\n\n%s\n\n********************\n",
						message);
			} else {
				printf(
						"\n\n******************************\n%s\n\n******************************\n\n",
						message);
			}
		}
	}
	return r;
}

int confirmation() {
	int r = -1;
	int aux = 0;
	int scanfReturn = 0;
	do {
		printMessage(
				"¿Esta seguro que desea realizar esta operacion? Sus datos se eliminarán. Si = 1 / Otro numero = No",
				2);
		scanfReturn = scanf("%d", &aux);
	} while (scanfReturn != 1);
	if (aux == 1) {
		r = 1;
	}
	return r;
}
