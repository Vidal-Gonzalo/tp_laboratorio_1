/*
 * ArrayFlights.h
 *
 *  Created on: 12 may 2022
 *      Author: gonza
 */

#ifndef ARRAYFLIGHTS_H_
#define ARRAYFLIGHTS_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHTS 1000
#define FREE 0
#define OCCUPIED 1
#define INACTIVE 0
#define INPROCESS 1
#define ACTIVE 2

typedef struct{
	int id;
	char flycode[10];
	int statusFlight;
	int isEmpty;
}Flight;

int Flight_initializeFlights(Flight flightList[], int size);
void Flight_printOne(Flight s);
int Flight_printList(Flight flightList[], int size, int status);
int Flight_SearchFlightSpace(Flight flightList[], int size, int status);
int Flight_SearchIndexPerId(Flight flightList[], int size, int ID);
int Flight_MembershipFlight(Flight flightList[], int flightSize);
#endif /* ARRAYFLIGHTS_H_ */
