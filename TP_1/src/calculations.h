/*
 * calculos.h
 *
 *  Created on: 3 abr 2022
 *      Author: Gonzalo Vidal - Division H
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>

int resultWithDiscount(float number1, int discount, float *result); //Se divide el numero con el porcentaje de descuento que el usuario ingrese para luego mostrar el resultado con el descuento.

int resultWithInterest(float number1, int interest, float *result); //Se divide el numero con el porcentaje de interés que el usuario ingrese para luego mostrar el resultado con el interés.

int pricePerKm(float number1, float kilometer, float *result); //Se divide el numero por la unidad ingresada por el usuario y muestra el resultado.

int bitcoinConverter(float number1, float bitcoinPrice, float *result); //Convierte la moneda en BTC.

int differenceOfNumbers(float number1, float number2, float *result); //Muestra la diferencia de dos numeros

int makeDifferentCalculations(float number1, float number2, float number3,
		float *result1, float *result2, float *result3, float *result4,
		float *result5, float *result6, float *result7, float *result8,
		float *result9);

#endif /* CALCULOS_H_ */
