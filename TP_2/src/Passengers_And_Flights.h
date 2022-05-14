/*
 * Passengers_And_Flights.h
 *
 *  Created on: 12 may 2022
 *      Author: gonza
 */

#ifndef PASSENGERS_AND_FLIGHTS_H_
#define PASSENGERS_AND_FLIGHTS_H_

#include "ArrayPassenger.h"
#include "ArrayFlights.h"

#include <stdio.h>
#include <stdlib.h>

int relationship_membershipPassengerAndFlight(Passenger passengerList[],
		int passengersSize, Flight flightList[], int flightSize);

int relationship_membershipFlight(Flight flightList[], int flightSize,
		Passenger passengersList[], int passengersSize);

#endif /* PASSENGERS_AND_FLIGHTS_H_ */
