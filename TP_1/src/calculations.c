/*
 * calculations.c
 *
 *  Created on: 3 abr 2022
 *      Author: Gonzalo Vidal - División H
 */

#include "calculations.h"

void resultWithDiscount(float number1, int defaultDiscount, float *result){
	if(number1 == 0 || defaultDiscount == 0){
		*result = number1;
	} else {
		float discount;
		float calculation;
		discount = number1 * ((float)defaultDiscount / 100);
		calculation = number1 - discount;
		*result = calculation;
	}
}

void resultWithInterest(float number1, int defaultInterest, float *result){
	if(number1 == 0 || defaultInterest == 0){
		*result = number1;
	} else {
		float interest;
		float calculation;
		interest = number1 * ((float)defaultInterest / 100);
		calculation = number1 + interest;
		*result = calculation;
	}

}

void pricePerKm(float kilometer, float number1, float *result){
	if(number1 == 0 || kilometer == 0){
		*result = number1;
	} else {
		float calculation;
		calculation = number1 / kilometer;
		*result = calculation;
	}

}

void bitcoinConverter(float number1, float bitcoinPrice, float *result){
	if(number1 == 0 || bitcoinPrice){
		*result = number1;
	} else {
		float calculation;
		calculation = number1 / bitcoinPrice;
		*result = calculation;
	}

}

void differenceOfNumbers (float number1, float number2, float *result){
	float calculation;
	if(number1 > number2){
		calculation = number1 - number2;
	} else {
		calculation = number2 - number1;
	}
	*result = calculation;
}

