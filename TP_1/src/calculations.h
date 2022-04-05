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


float resultWithDiscount(float number1, int discount); //Se divide el numero con el porcentaje de descuento que el usuario ingrese para luego mostrar el resultado con el descuento.

float resultWithInterest(float number1, int interest); //Se divide el numero con el porcentaje de interés que el usuario ingrese para luego mostrar el resultado con el interés.

float pricePerKm(float kilometer, float number1); //Se divide el numero por la unidad ingresada por el usuario y muestra el resultado.

float bitcoinConverter(float number1, float bitcoinPrice); //Convierte la moneda en BTC.

float differenceOfNumbers (float number1, float number2); //Muestra la diferencia de dos numeros


#endif /* CALCULOS_H_ */
