/*
 * ArrayFlights.c
 *
 *  Created on: 12 may 2022
 *      Author: gonza
 */

#include "ArrayFlights.h"
#include "general.h"

void Flight_printOne(Flight s) {
	printf("ID %d\nCodigo de vuelo: %s", s.id, s.flycode);
	if (s.statusFlight == 0) {
		puts("Inactivo");
	} else {
		if (s.statusFlight == 1) {
			puts("Activo");
		} else {
			puts("Error");
		}
	}
}

int Flight_printList(Flight flightList[], int size, int status) {
	int r = -1;
	if (flightList != NULL) {
		if (size > 0) {
			r = 0;
			for (int i = 0; i < size; i++) {
				if (flightList[i].statusFlight == status) {
					Flight_printOne(flightList[i]);
				}
			}
		} else {
			r = -2;
		}
	} else {
		r = -3;
	}
	return r;
}

int Flight_initializeFlights(Flight *flightList, int size) {
	int r = -1;
	int i;

	if (flightList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			flightList[i].statusFlight = INACTIVE;
		}
	}
	return r;
}

int Flight_SearchFlightSpace(Flight flightList[], int size, int status) {
	int r = -1;
	int i;

	if (flightList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (flightList[i].isEmpty == status) {
				r = i;
				break;
			}
		}
	}

	return r;
}

