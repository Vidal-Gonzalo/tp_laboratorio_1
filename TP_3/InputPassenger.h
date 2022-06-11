/*
 * InputPassenger.h
 *
 *  Created on: 11 jun 2022
 *      Author: gonza
 */

#ifndef INPUTPASSENGER_H_
#define INPUTPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "Passenger.h"

#define MAX 10
#define MAX_CHARS_NAME 50
#define MAX_CHARS_LASTNAME 50
#define MAX_CHARS_FLY_CODE 16

int Passenger_LoadPassenger(Passenger *auxiliar);

int Passenger_ModificarUno(Passenger *p);

#endif /* INPUTPASSENGER_H_ */
