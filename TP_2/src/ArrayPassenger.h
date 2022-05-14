/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may 2022
 *      Author: gonza
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 2000
#define MAX_SIZE_CHAR 51
#define MAX 10
#define FREE 0
#define OCCUPIED 1
#define INACTIVE 0
#define INPROCESS 1
#define LOW -1
#define LCD 1
#define LED 2

typedef struct {
	int id;
	int isEmpty;

	int typePassenger;
	char name[MAX_SIZE_CHAR];
	char lastname[MAX_SIZE_CHAR];
	char flycode[10];
	int statusFlight;
	float price;
} Passenger;

int addPassenger(Passenger *list, int len, int id, char name[], char lastname[],
		float price, int typePassenger, char flycode[]);
int Passenger_initializePassengers(Passenger PassengerList[], int size);
void Passenger_printOne(Passenger s);
int Passenger_printPassengers(Passenger passengersList[], int size);
int Passenger_SearchSpace(Passenger PassengerList[], int size, int status);
int Passenger_SearchFlightStatus(Passenger passengerList[], int size,
		int statusFlight);
int Passenger_Membership(Passenger PassengerList[], int size);
int Passenger_Baja(Passenger PassengerList[], int size);
int Passenger_Edit(Passenger PassengerList[], int size);
int Passenger_SearchIndexPerId(Passenger PassengerList[], int size, int ID);
int Passenger_AveragePrice(Passenger passengerList[], int size);
int Passenger_Sort(Passenger passengersList[], int size, int order);
int Passenger_SortByFlightcode(Passenger passengersList[], int size, int order);
Passenger Passenger_ModificarUno(Passenger s);
Passenger Passenger_LoadPassenger();

#endif /* ARRAYPASSENGER_H_ */
