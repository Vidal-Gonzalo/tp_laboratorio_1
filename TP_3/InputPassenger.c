/*
 * InputPassenger.c
 *
 *  Created on: 11 jun 2022
 *      Author: gonza
 */

#include "InputPassenger.h"

int Passenger_LoadPassenger(Passenger *auxiliar) {
	int r = -1;

	if (utn_getString(auxiliar->nombre, MAX_CHARS_NAME, "Nombre de pasajero:\n",
			"Error, vuelva a intentar.\n", 3) == 0) {
		if (utn_getString(auxiliar->apellido, MAX_CHARS_LASTNAME,
				"Apellido de pasajero:\n", "Error, vuelva a intentar.\n", 3)
				== 0) {
			if (utn_getNumeroFlotante("Precio:\n",
					"Error, vuelva a intentar.\n", 1, 3, &auxiliar->precio)
					== 0) {
				if (general_getAlphanumeric(auxiliar->codigoVuelo,
				MAX_CHARS_FLY_CODE, "Codigo de vuelo:\n",
						"Error, vuelva a intentar.\n", 3) == 0) {
					if (utn_getNumero(
							"Tipo de pasajero: (1-EconomyClass/2-FirstClass/3-ExecutiveClass\n",
							"Error, vuelva a intentar.\n", 0, 3,
							&auxiliar->tipoPasajero) == 0) {
						if (utn_getNumero(
								"Estado de vuelo (1-En demora/2-En horario/3-En vuelo/4-Aterrizado:\n",
								"Error, vuelva a intentar.\n", 0, 3,
								&auxiliar->statusFlight) == 0) {
							r = 0;
						}
					}
				}
			}
		}
	}

	return r;
}

int Passenger_ModificarUno(Passenger *p) {
	int r = -1;
	int opcion;
	do {
		if (utn_getNumero(
				"¿Que campo desea modificar?\n 1-Nombre\n2-Apellido\n3-Codigo de vuelo\n4-Tipo de pasajero\n5-Precio\n6-Estado vuelo\n7-Salir\n",
				"Ha habido un error. Intentelo nuevamente.\n", 0, 3, &opcion)
				== 0) {
			r = 0;
			switch (opcion) {
			case 1:
				utn_getString(p->nombre, MAX_CHARS_NAME, "Nombre:\n",
						"Ha habido un error\n", 3);
				break;
			case 2:
				utn_getString(p->apellido, MAX_CHARS_NAME, "Apellido:\n",
						"Ha habido un error\n", 3);
				break;
			case 3:
				general_getAlphanumeric(p->codigoVuelo, 10,
						"Codigo de vuelo:\n", "Ha habido un error.\n", 3);

				break;
			case 4:
				utn_getNumero(
						"Tipo de pasajero: 1)Economico / 2)Clase alta / 3)Clase ejecutiva\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&p->tipoPasajero);
				break;
			case 5:
				utn_getNumeroFlotante("Precio:\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&p->precio);
				break;
			case 6:
				utn_getNumero(
						"Estado de vuelo: 1)En demora / 2)En horario / 3)En vuelo / 4)Aterrizado\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&p->statusFlight);
				break;
			case 7:
				printf("Saliendo...\n");
				break;
			default:
				printf("Por favor, ingrese un numero entre 1 y 7.\n");
			}
		}
	} while (opcion != 7);
	return r;
}
