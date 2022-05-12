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

int main(void) {
	setbuf(stdout, NULL);
	Passenger passengersList[MAX_PASSENGERS];
	int option;

	Passenger_initializePassengers(passengersList, MAX_PASSENGERS);

	printMessage("¡Bienvenidx a nuestro programa!", 2);

	do {
		utn_getNumero(
				"1-Alta pasajero.\n2-Modificar datos de pasajero.\n3-Dar de baja a pasajero.\n4-Informar.\n5-Mostrar pasajeros.\n6-Salir\n",
				"Ha habido un error, intentelo nuevamente por favor.", 0, 3,
				&option);
		switch (option) {
		case 1:
			if (Passenger_Alta(passengersList, MAX_PASSENGERS) == 0) {
				printMessage("Alta realizada", 2);
			} else {
				printMessage("HA HABIDO UN ERROR", 2);
			}
			break;
		case 2:
			if (Passenger_Edit(passengersList, MAX_PASSENGERS) == 0) {
				printMessage("Modificacion realizada", 2);
			} else {
				printMessage("HA HABIDO UN ERROR", 2);
			}
			break;
		case 3:
			if (Passenger_Baja(passengersList, MAX_PASSENGERS) == 0){
				printMessage("Baja realizada", 1);
			} else {
				printMessage("HA HABIDO UN ERROR", 2);
			}
			break;
		case 4:
			if (Passenger_Sort(passengersList, MAX_PASSENGERS) == 0){
				printMessage("Ordenamiento realizado", 2);
			} else {
				printMessage("HA HABIDO UN ERROR", 2);
			}
			break;
		case 5:
			Passenger_printList(passengersList, MAX_PASSENGERS, OCCUPIED);
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
