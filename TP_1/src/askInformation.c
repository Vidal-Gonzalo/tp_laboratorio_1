/*
 * askInformation.c
 *
 *  Created on: 5 abr 2022
 *      Author: Gonzalo Vidal - Division H
 */

#include "askInformation.h"

void getInfo(char* message, float *number1){
	printf(message);
	scanf("%f", number1);
}

int options(char* message, float number1, float number2, float number3){
	int response;
	printf(message, number1, number2, number3);
	scanf("%d", &response);
	return response;
}
