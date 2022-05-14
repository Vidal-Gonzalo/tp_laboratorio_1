/*
 * ArrayFlights.c
 *
 *  Created on: 12 may 2022
 *      Author: gonza
 */

#include "ArrayFlights.h"
#include "general.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list flightList* Pointer to array of flight
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

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

/** \brief Search an especific flight status in the array
*
* \param list flightList*
* \param len int
* \param id statusFlight (to search)
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/

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

