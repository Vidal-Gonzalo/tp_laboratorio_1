/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "general.h"
#include "ArrayPassenger.h"
#include "Passengers_And_Flights.h"
#include "ArrayFlights.h"

int main(void) {
	setbuf(stdout, NULL);
	Passenger passengersList[MAX_PASSENGERS];
	Flight flightList[MAX_FLIGHTS];
	int option;
	int newOption;
	int order;

	Passenger_initializePassengers(passengersList, MAX_PASSENGERS);
	Flight_initializeFlights(flightList, MAX_FLIGHTS);
	printMessage("¡Bienvenidx a nuestro programa!", 2);

	do {
		utn_getNumero(
				"1-Alta pasajero.\n2-Modificar datos de pasajero.\n3-Dar de baja a pasajero.\n4-Informar.\n5-Mostrar pasajeros.\n6-Salir\n",
				"Ha habido un error, intentelo nuevamente por favor.", 0, 3,
				&option);
		switch (option) {
		case 1:
			if (relationship_membershipPassengerAndFlight(passengersList, MAX_PASSENGERS,
					flightList, MAX_FLIGHTS) == 0) {
				printMessage("Alta realizada", 2);
			} else {
				printMessage("HA HABIDO UN ERROR", 2);
			}
			break;
		case 2:
			if (Passenger_SearchFlightStatus(passengersList, MAX_PASSENGERS, ACTIVE)
					== 0) {
				if (Passenger_Edit(passengersList, MAX_PASSENGERS) == 0) {
					printMessage("Modificacion realizada", 2);
				} else {
					printMessage("HA HABIDO UN ERROR", 2);
				}
			} else {
				printMessage("¡Todavía no hay pasajeros en la lista!", 2);
			}

			break;
		case 3:
			if (Passenger_SearchFlightStatus(passengersList, MAX_PASSENGERS, ACTIVE)
					== 0) {
				if (Passenger_Baja(passengersList, MAX_PASSENGERS) == 0) {
					printMessage("Baja realizada", 1);
				} else {
					printMessage("HA HABIDO UN ERROR", 2);
				}
			} else {
				printMessage("¡Todavía no hay pasajeros en la lista!", 2);
			}

			break;
		case 4:
			if (Passenger_SearchFlightStatus(passengersList, MAX_PASSENGERS, ACTIVE)
					== 0) {
				if (utn_getNumero(
						"1)Listado de pasajeros ordenados alfabeticamente por apellido y tipo de pasajero\n2)Total y promedio de los pasajes y cuantos superan el precio promedio\n3)Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n4)Volver\n",
						"Hubo un error, intentelo de nuevo", 0, 3, &newOption)
						== 0) {
					switch (newOption) {
					case 1:
						if (utn_getNumeroWithMax(
								"Ordenar de manera ascendente (1) o descendente (0)\n",
								"Hubo un error, intentelo nuevamente\n", 0, 1,
								3, &order) == 0) {
							if (Passenger_Sort(passengersList, MAX_PASSENGERS,
									order) == 0) {
								printMessage("Ordenamiento realizado", 2);
							} else {
								printMessage("HA HABIDO UN ERROR", 2);
							}
						}
						break;
					case 2:
						if (Passenger_AveragePrice(passengersList,
						MAX_PASSENGERS) == 0) {
							printMessage("Calculos realizados", 2);
						} else {
							printMessage("HA HABIDO UN ERROR", 2);
						}
						break;
					case 3:
						if (Passenger_SortByFlightcode(passengersList,
						MAX_PASSENGERS, 0) == 0) {
							printMessage("Lista realizada", 2);
						} else {
							printMessage("HA HABIDO UN ERROR", 2);
						}
						break;
					case 4:
						break;
					default:
						break;
					}
				}
			} else {
				printMessage("¡Todavía no hay pasajeros en la lista!", 2);
			}

			break;
		case 5:
			if (Passenger_SearchFlightStatus(passengersList, MAX_PASSENGERS, ACTIVE)
					== 0) {
				if (Passenger_printPassengers(passengersList, MAX_PASSENGERS)
						== 0) {
					printMessage("Pasajeros impresos", 2);
				} else {
					printMessage("HA HABIDO UN ERROR", 2);
				}
			} else {
				printMessage("¡Todavía no hay pasajeros en la lista!", 2);
			}
			break;
		case 6:
			printMessage("¡Gracias por usar nuestro programa!", 2);
			break;
		default:
			printMessage("Por favor, ingrese un numero del 1 al 6.", 2);
			break;
		}
	} while (option != 6);

	return EXIT_SUCCESS;

}
