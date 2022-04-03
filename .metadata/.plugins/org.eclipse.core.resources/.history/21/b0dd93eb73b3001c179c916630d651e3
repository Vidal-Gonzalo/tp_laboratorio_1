/*
 * calculations.c
 *
 *  Created on: 3 abr 2022
 *      Author: Gonzalo Vidal - División H
 */

#include "calculations.h"

float resultWithDiscount(float number1, int defaultDiscount){
	float discount;
	float result;
	discount = number1 * ((float)defaultDiscount / 100);
	result = number1 - discount;
	return result;
}

float resultWithInterest(float number1, int defaultInterest){
	float interest;
	float result;
	interest = number1 * ((float)defaultInterest / 100);
	result = number1 - interest;
	return result;
}

float bitcoinConverter(float number1, float bitcoinPrice){
	float result;
	result = number1 / bitcoinPrice;
	return result;
}

int options(char* message){
	int response;
	printf(message);
	scanf("%d", &response);
	return response;
}

