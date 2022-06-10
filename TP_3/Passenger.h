/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

#define MAX 10
#define MAX_CHARS_NAME 50
#define MAX_CHARS_LASTNAME 50
#define MAX_CHARS_FLY_CODE 16

typedef struct {
	int id;
	char nombre[MAX_CHARS_NAME];
	char apellido[MAX_CHARS_LASTNAME];
	float precio;
	int tipoPasajero;
	char codigoVuelo[MAX_CHARS_FLY_CODE]; //Falta statusflight

} Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametrosTxt(char *id, char *nombre, char *apellido,
		char *precio, char *tipoPasajero, char *codigoVuelo);

Passenger* Passenger_newParametros(int *id, char *nombre, char *apellido,
		float *precio, char *codigoVuelo, int *tipoPasajero);

void Passenger_delete(Passenger *this); // --> free(this)

int Passenger_setId(Passenger *this, int id);
int Passenger_getId(Passenger *this, int *id);

int Passenger_setIdTxt(Passenger *this, char *id);
int Passenger_getIdTxt(Passenger *this, char *id);

int Passenger_setNombre(Passenger *this, char *nombre);
int Passenger_getNombre(Passenger *this, char *nombre);

int Passenger_setApellido(Passenger *this, char *apellido);
int Passenger_getApellido(Passenger *this, char *apellido);

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo);
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo);

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero);

int Passenger_setTipoPasajeroTxt(Passenger *this, char *tipoPasajero);
int Passenger_getTipoPasajeroTxt(Passenger *this, char *tipoPasajero);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_setPrecioTxt(Passenger *this, char *precio);
int Passenger_getPrecioTxt(Passenger *this, char *precio);



int Passenger_LoadPassenger(Passenger *this);
void Passenger_printOne(Passenger* p);
int Passenger_printPassengers(LinkedList pArrayPassengers[], int size);
int Passenger_SearchIndexPerId(Passenger passengerList[], int size, int ID);
int Passenger_ModificarUno(Passenger* p);
int Passenger_getUniqueId();
#endif /* PASSENGER_H_ */
