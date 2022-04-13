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

/// @fn int resultWithDiscount(float, int, float*)
/// @brief Takes a number and a discount. The (casted) discount is divided by one hundred and multiplies it to the number given in the
/// first place. Now, with the discount calculated, we store the value of the first number substracted by the discount in a pointer.
/// @param number1
/// @param discount
/// @param result
/// @return
int resultWithDiscount(float number1, int discount, float *result);

/// @fn int resultWithInterest(float, int, float*)
/// @brief Takes a number and an interest. The (casted) interest is divided by one hundred and multiplies it to the number given in the
/// first place. Now, with the interest calculated, we store the value of the first number plus the interest in a pointer.
///
/// @param number1
/// @param interest
/// @param result
/// @return
int resultWithInterest(float number1, int interest, float *result);

/// @fn int pricePerKm(float, float, float*)
/// @brief Takes two numbers. The second number is divided by one hundred and multiplies it to the first number and store the value in a pointer.
///
/// @param number1
/// @param kilometer
/// @param result
/// @return
int pricePerKm(float number1, float kilometer, float *result);

/// @fn int bitcoinConverter(float, float, float*)
/// @brief Takes one number and the bitcoin price, then divides the first number with the bitcoin price and store the value in a pointer
///
/// @param number1
/// @param bitcoinPrice
/// @param result
/// @return
int bitcoinConverter(float number1, float bitcoinPrice, float *result);

/// @fn int differenceOfNumbers(float, float, float*)
/// @brief Takes two numbers and checks which one is the highest to substract one to another. The function store the value in a pointer.
///
/// @param number1
/// @param number2
/// @param result
/// @return
int differenceOfNumbers(float number1, float number2, float *result); //Muestra la diferencia de dos numeros

/// @fn int makeDifferentCalculations(float, float, float, float*, float*, float*, float*, float*, float*, float*, float*, float*)
/// @brief Takes 3 numbers and 9 pointers to call different functions and store the results in pointers.
///
/// @param number1
/// @param number2
/// @param number3
/// @param result1
/// @param result2
/// @param result3
/// @param result4
/// @param result5
/// @param result6
/// @param result7
/// @param result8
/// @param result9
/// @return
int makeDifferentCalculations(float number1, float number2, float number3,
		float *result1, float *result2, float *result3, float *result4,
		float *result5, float *result6, float *result7, float *result8,
		float *result9);

#endif /* CALCULOS_H_ */
