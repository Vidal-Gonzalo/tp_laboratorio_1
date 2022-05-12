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
#define FREE 0
#define OCCUPIED 1
#define LOW -1
#define LCD 1
#define LED 2

typedef struct{
	int id;
	int isEmpty;

	int typePassenger;
	char name[MAX_SIZE_CHAR];
	char lastname[MAX_SIZE_CHAR];
	char flycode[10];
	float price;
}Passenger;

int addPassenger(Passenger *list, int len, int id, char name[], char lastname[],
		float price, int typePassenger, char flycode[]);
int Passenger_initializePassengers(Passenger PassengerList[], int size);
void Passenger_printOne(Passenger s);
int Passenger_printList(Passenger PassengerList[], int size, int status);
int Passenger_SearchSpace(Passenger PassengerList[], int size, int status);
int Passenger_Alta(Passenger PassengerList[], int size);
int Passenger_Baja(Passenger PassengerList[], int size);
int Passenger_Edit(Passenger PassengerList[], int size);
int Passenger_SearchIndexPerId(Passenger PassengerList[], int size, int ID);
int Passenger_Sort(Passenger passengersList[], int size);
Passenger Passenger_ModificarUno(Passenger s);
Passenger Passenger_LoadPassenger();


#endif /* ARRAYPASSENGER_H_ */
