/*
 * askInformation.h
 *
 *  Created on: 5 abr 2022
 *      Author: Gonzalo Vidal - Division H
 */

#ifndef ASKINFORMATION_H_
#define ASKINFORMATION_H_
#include <stdio.h>
#include <stdlib.h>

int getInfo(char *message, float *number1, int retries, int min, char *error); //Se imprime el mensaje que el desarrollador elija y el usuario deberá ingresar un número que se guardará en la variable correspondiente.

int options(char *message, int *option, float number1, float number2,
		float number3, int min, int max); //Se imprime el mensaje que el desarrollador elija y se podrán mostrar, en el mismo mensaje, tres variables de tipo "float".

int printResults(float number1, float number2, float number3, float result1,
		float result2, float result3, float result4, float result5,
		float result6, float result7, float result8, float result9);

int printMessage(char *message, int size);

int confirmation(int option1, int option2);
#endif /* ASKINFORMATION_H_ */
