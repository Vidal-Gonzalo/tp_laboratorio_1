/*
 * Passengers_And_Flights.c
 *
 *  Created on: 12 may 2022
 *      Author: gonza
 */

#include "Passengers_And_Flights.h"
#include "general.h"

static int idAI = 2000;
static int Flight_getUniqueId() {
	return idAI++;
}

/** \brief Gives membership to a new passenger and to a new flight.
 *
 * \param list Passenger*
 * \param lenPassenger int
 *  * \param list Flight*
 * \param lenFlight int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int relationship_membershipPassengerAndFlight(Passenger passengerList[],
		int passengersSize, Flight flightList[], int flightSize) {
	int r = -1;

	if (passengerList != NULL && passengersSize >= 0 && flightList != NULL
			&& flightSize >= 0) {

		if (Passenger_Membership(passengerList, passengersSize) == 0) {
			if (relationship_membershipFlight(flightList, flightSize,
					passengerList, passengersSize) == 0) {
				r = 0;
			}
		}

	}
	return r;
}

/** \brief Gives membership to a new flight only if the flight code is not repeated.
 *
 * \param list Passenger*
 * \param lenPassenger int
 *  * \param list Flight*
 * \param lenFlight int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int relationship_membershipFlight(Flight flightList[], int flightSize,
		Passenger passengersList[], int passengersSize) {
	int r = -1;
	Flight auxFlight;
	int indexFlight;
	int indexPassenger;
	int repeatedFlight = 0;

	if (flightList != NULL && flightSize > 0 && passengersList != NULL
			&& passengersSize > 0) {
		indexFlight = Flight_SearchFlightSpace(flightList, flightSize,
		INACTIVE);
		indexPassenger = Passenger_SearchFlightStatus(passengersList,
				passengersSize, INPROCESS);
		if (indexFlight != -1) {
			if (indexFlight == 0) {
				puts("¡Sos el primer pasajero de tu vuelo!\n");
				auxFlight.id = Flight_getUniqueId();
				auxFlight.isEmpty = OCCUPIED;
				auxFlight.statusFlight = ACTIVE;
				strncpy(auxFlight.flycode,
						passengersList[indexPassenger].flycode, 10);
				passengersList[indexPassenger].statusFlight = ACTIVE;
				flightList[indexFlight] = auxFlight;
			} else {
				for (int i = 0; i < indexFlight; i++) {
					if (strcmp(flightList[i].flycode,
							passengersList[indexPassenger].flycode) == 0) {
						repeatedFlight = 1;
					}
				}
				if (repeatedFlight == 0) {
					auxFlight.id = Flight_getUniqueId();
					auxFlight.isEmpty = OCCUPIED;
					strncpy(auxFlight.flycode,
							passengersList[indexPassenger].flycode, 10);
					passengersList[indexPassenger].statusFlight = ACTIVE;
					flightList[indexFlight] = auxFlight;
					printf("¡Sos el primer pasajero de tu vuelo!\n");
				} else {
					printf("¡Tu vuelo te esta esperando!");
					passengersList[indexPassenger].statusFlight = ACTIVE;
				}
			}
			r = 0;
		}
	}

	return r;
}
