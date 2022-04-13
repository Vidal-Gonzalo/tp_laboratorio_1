/*
 * calculations.c
 *
 *  Created on: 3 abr 2022
 *      Author: Gonzalo Vidal - División H
 */

#include "calculations.h"
#define DISCOUNT 10
#define INTEREST 25
#define BITCOIN 4606954.55

//Sacar void
//Meter todos los calculos en una función? ---> A tener en cuenta / Intentarlo
int resultWithDiscount(float number1, int defaultDiscount, float *result) {
	int r = -1;
	if (number1 == 0 || defaultDiscount == 0) {
		printf("Ha habido un error en el calculo de descuento.\n");
	} else {
		float discount;
		float calculation;
		discount = number1 * ((float) defaultDiscount / 100);
		calculation = number1 - discount;
		*result = calculation;
		r = 0;
	}
	return r;
}

int resultWithInterest(float number1, int defaultInterest, float *result) {
	int r = -1;
	if (number1 == 0 || defaultInterest == 0) {
		printf("Ha habido un error en el calculo de interes.\n");
	} else {
		float interest;
		float calculation;
		interest = number1 * ((float) defaultInterest / 100);
		calculation = number1 + interest;
		*result = calculation;
		r = 0;
	}
	return r;
}

int pricePerKm(float number1, float kilometer, float *result) {
	int r = -1;
	if (number1 == 0 || kilometer == 0) {
		printf("Ha habido un error en el calculo de precio por kilometro.\n");
	} else {
		float calculation;
		calculation = number1 / kilometer;
		*result = calculation;
		r = 0;
	}
	return r;
}

int bitcoinConverter(float number1, float bitcoinPrice, float *result) {
	int r = -1;
	if (number1 == 0 || bitcoinPrice == 0) {
		printf("Ha habido un error en el calculo de Bitcoin.\n");
	} else {
		float calculation;
		calculation = number1 / bitcoinPrice;
		*result = calculation;
		r = 0;
	}
	return r;
}

int differenceOfNumbers(float number1, float number2, float *result) {
	int r = -1;
	float calculation;
	if (number1 < 0 || number2 < 0) {
		printf("Ha habido un error en el calculo de diferencia de numeros.\n");
	} else {
		if (number1 > number2) {
			calculation = number1 - number2;
		} else {
			calculation = number2 - number1;
		}
		*result = calculation;
		r = 0;
	}
	return r;
}

int makeDifferentCalculations(float number1, float number2, float number3, float *result1, float *result2, float *result3,
		float *result4, float *result5, float *result6, float *result7,
		float *result8, float *result9) {
	int r = -1;
	if (number1 > 0 && number2 > 0 && number3 > 0) {
		r = 0;
		/***Aerolineas***/
		resultWithDiscount(number2, DISCOUNT, result1);
		resultWithInterest(number2, INTEREST, result2);
		pricePerKm(number2, number1, result3);
		bitcoinConverter(number2, BITCOIN, result4);

		/***Latam***/
		resultWithDiscount(number3, DISCOUNT,result5);
		resultWithInterest(number3, INTEREST,result6);
		pricePerKm(number3, number1, result7);
		bitcoinConverter(number3, BITCOIN, result8);
		differenceOfNumbers(number1, number2, result9);
	} else {
		printf("%f %f %f", number1, number2, number3);
	}
	return r;
}

