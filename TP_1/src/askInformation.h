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

/// @fn int getInfo(char*, float*, int, int, char*)
/// @brief Checks if numbers and pointers are correct, then print a message(char*) and ask to the user for a number. If everything went right, return a 0, otherwise return -1.
///
/// @param message
/// @param number1
/// @param retries
/// @param min
/// @param error
/// @return
int getInfo(char *message, float *number1, int retries, int min, char *error);

/// @fn int options(char*, int*, float, float, float, int, int)
/// @brief Checks if numbers and pointers are correct, then print a message with different floats and ask to the user for a number. If everything went right, return a 0, otherwise return -1.
///
/// @param message
/// @param option
/// @param number1
/// @param number2
/// @param number3
/// @param min
/// @param max
/// @return
int options(char *message, int *option, float number1, float number2,
		float number3, int min, int max);

/// @fn int printResults(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief This function can be used to print different results in one simple function. Before printing, the function will check if the floats are above 0.
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
int printResults(float number1, float number2, float number3, float result1,
		float result2, float result3, float result4, float result5,
		float result6, float result7, float result8, float result9);

/// @fn int printMessage(char*, int)
/// @brief Prints a personalized message with some asterisks. The amount of asterisks will vary in function of the variable "size"(1 = Small / 2 = Medium / 3+ = Large).
/// If size is less than 1 the function will return -1.
/// @param message
/// @param size
/// @return
int printMessage(char *message, int size);

/// @fn int confirmation(int, int)
/// @brief Ask to the user if he wants to procceed with his operation.
///
/// @param max
/// @param min
/// @return
int confirmation();
#endif /* ASKINFORMATION_H_ */
