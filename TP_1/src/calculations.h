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


void resultWithDiscount(float number1, int discount, float *result); //Se divide el numero con el porcentaje de descuento que el usuario ingrese para luego mostrar el resultado con el descuento.

void resultWithInterest(float number1, int interest, float *result); //Se divide el numero con el porcentaje de interés que el usuario ingrese para luego mostrar el resultado con el interés.

void pricePerKm(float kilometer, float number1, float *result); //Se divide el numero por la unidad ingresada por el usuario y muestra el resultado.

void bitcoinConverter(float number1, float bitcoinPrice, float *result); //Convierte la moneda en BTC.

void differenceOfNumbers (float number1, float number2, float *result); //Muestra la diferencia de dos numeros


#endif /* CALCULOS_H_ */
