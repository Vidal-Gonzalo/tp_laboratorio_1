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

float resultWithDiscount(float number1, int discount);

float resultWithInterest(float number1, int interest);

float bitcoinConverter(float number1, float bitcoinPrice);

int options(char* message);

#endif /* CALCULOS_H_ */
