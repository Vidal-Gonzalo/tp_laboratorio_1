#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 *
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger) {
	//fOpen lo realizó la función q llama a este parser
	int r = -1;
	FILE *idFile;
	Passenger *passenger = NULL;
	char id[5];
	int auxId = 0;
	char nombre[MAX_CHARS_NAME];
	char apellido[MAX_CHARS_LASTNAME];
	char precio[50];
	char tipoPasajero[50];
	char codigoVuelo[MAX_CHARS_FLY_CODE];

	if (pFile != NULL && pArrayListPassenger != NULL) {
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,
					nombre, apellido, precio, codigoVuelo, tipoPasajero) == 6) {
				if (strcmp("ID", id) != 0) {
					passenger = Passenger_newParametrosTxt(id, nombre, apellido,
							precio, codigoVuelo, tipoPasajero);
					if (passenger != NULL) {
						if (passenger->id > auxId) {
							auxId = passenger->id;
							idFile = fopen("maxId", "w");
							fprintf(idFile, "%d", auxId);
							fclose(idFile);
						}
						ll_add(pArrayListPassenger, passenger);
					}
				}
			}
		} while (!feof(pFile));
		r = 0;
	}
	return r;
}

int parser_ReadPassengerFromText(FILE *pFile, Passenger *pArrayListPassenger) {
	//fOpen lo realizó la función q llama a este parser
	int r = -1;
	Passenger *passenger = NULL;
	int i = 0;
	char id[5];
	char nombre[MAX_CHARS_NAME];
	char apellido[MAX_CHARS_LASTNAME];
	char precio[50];
	char tipoPasajero[50];
	char codigoVuelo[MAX_CHARS_FLY_CODE];

	if (pFile != NULL && pArrayListPassenger != NULL) {
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,
					nombre, apellido, precio, codigoVuelo, tipoPasajero) == 6) {
				if (strcmp("ID", id) != 0) {
					passenger = Passenger_newParametrosTxt(id, nombre, apellido,
							precio, codigoVuelo, tipoPasajero);
					if (passenger != NULL) {
						pArrayListPassenger[i] = *passenger;
						i++;
					}
				}
			}
		} while (!feof(pFile));
		r = 0;
	}
	return r;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger) {

	return 1;
}
