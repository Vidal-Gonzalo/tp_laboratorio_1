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

void getInfo(char* message, float *number1); //Se imprime el mensaje que el desarrollador elija y el usuario deber� ingresar un n�mero que se guardar� en la variable correspondiente.

int options(char* message, float number1, float number2, float number3); //Se imprime el mensaje que el desarrollador elija y se podr�n mostrar, en el mismo mensaje, tres variables de tipo "float".

#endif /* ASKINFORMATION_H_ */
