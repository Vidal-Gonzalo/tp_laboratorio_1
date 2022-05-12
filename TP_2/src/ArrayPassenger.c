/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may 2022
 *      Author: gonza
 */

#include "ArrayPassenger.h"
#include "general.h"

static int idAI = 1000;
static int Passenger_getUniqueId() {
	return idAI++;
}

void Passenger_printOne(Passenger s) {
	printf(
			"ID %d\nNombre: %sApellido: %sCodigo de vuelo: %sPrecio: %f\nTipo de pasajero: %d\n",
			s.id, s.name, s.lastname, s.flycode, s.price, s.typePassenger);

}

int Passenger_printList(Passenger passengerList[], int size, int status) {
	int r = -1;
	if (passengerList != NULL) {
		if (size > 0) {
			r = 0;
			for (int i = 0; i < size; i++) {
				if (passengerList[i].isEmpty == status) {
					Passenger_printOne(passengerList[i]);
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

int Passenger_initializePassengers(Passenger *passengerList, int size) {
	int r = -1;
	int i;

	if (passengerList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			passengerList[i].isEmpty = FREE;
		}
	}
	return r;
}

int Passenger_Alta(Passenger passengerList[], int size) {
	int r = -1;
	Passenger auxPassenger;

	int index = Passenger_SearchSpace(passengerList, size, FREE);

	if (index != -1) {
		auxPassenger = Passenger_LoadPassenger();
		auxPassenger.id = Passenger_getUniqueId();
		if (addPassenger(passengerList, size, auxPassenger.id,
				auxPassenger.name, auxPassenger.lastname, auxPassenger.price,
				auxPassenger.typePassenger, auxPassenger.flycode) == 0) {
			r = 0;
		}

	}

	return r;
}

/** \brief add in a existing list of passengers the values received as parameters
 * in the first empty position
 * \param list passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param typePassenger int
 * \param flycode[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok*/

int addPassenger(Passenger *list, int len, int id, char name[], char lastname[],
		float price, int typePassenger, char flycode[]) {
	int r = -1;
	Passenger aux;
	if (list != NULL
			&& len
					> 0&& id > 0 && name != NULL && lastname != NULL && price > 0 && typePassenger > 0 && flycode != NULL) {
		int freeIndex = Passenger_SearchSpace(list, len, FREE);
		strncpy(aux.name, name, sizeof(aux.name));
		strncpy(aux.lastname, lastname, sizeof(aux.lastname));
		strncpy(aux.flycode, flycode, sizeof(aux.flycode));
		aux.id = id;
		aux.price = price;
		aux.typePassenger = typePassenger;
		aux.isEmpty = OCCUPIED;
		list[freeIndex] = aux;
		r = 0;
	}

	return r;
}

int Passenger_Edit(Passenger passengerList[], int size) {
	int r = -1;
	int indexToModify;
	int ID;
	Passenger aux;

	if (passengerList != NULL) {
		if (size > 0) {
			Passenger_printList(passengerList, size, OCCUPIED);
			if (utn_getNumero("Ingrese el ID a modificar:", "Hubo un error", 0,
					3, &ID) == 0) {
				indexToModify = Passenger_SearchIndexPerId(passengerList, size,
						ID);
				if (indexToModify == -1) {
					printMessage("No se encontro el ID en la lista.\n", 1);
					return r;
				} else {
					printMessage("El pasajero a modificar es el siguiente:\n",
							1);
					Passenger_printOne(passengerList[indexToModify]);
					aux = passengerList[indexToModify];
					aux = Passenger_ModificarUno(aux);
					if (confirmation(
							"¿Esta seguro que quiere modificar los datos?(1-Si/Otro numero-No)\n",
							"Ha habido un error en relacion al numero ingresado. Intentelo nuevamente.\n")
							== 1) {
						passengerList[indexToModify] = aux;
						r = 0;
					}
				}
			}
		} else {
			r = -3;
		}
	} else {
		r = -2;
	}
	return r;
}

int Passenger_Baja(Passenger passengerList[], int size) {
	int r = -1;
	int indexLow;
	int ID = 0;

	if (passengerList != NULL) {
		if (size > 0) {
			Passenger_printList(passengerList, size, OCCUPIED);
			if (utn_getNumero("Ingrese el ID a dar de baja:\n",
					"Hubo un error\n", 0, 3, &ID) == 0) {
				indexLow = Passenger_SearchIndexPerId(passengerList, size, ID);
				if (indexLow == -1) {
					printMessage("No se encontro el ID en la lista.\n", 1);
					return r;
				} else {
					printMessage("El pasajero a dar de baja es el siguiente:\n",
							1);
					Passenger_printOne(passengerList[indexLow]);
					if (confirmation(
							"¿Esta seguro que quiere darlo de baja?(1-Si/Otro numero-No)\n",
							"Ha habido un error en relacion al numero ingresado. Intentelo nuevamente.\n")
							== 1) {
						passengerList[indexLow].isEmpty = LOW;
						r = 0;
					}

				}
			}

		} else {
			r = -3;
		}
	} else {
		r = -2;
	}
	return r;
}

Passenger Passenger_ModificarUno(Passenger s) {
	int opcion;
	do {
		if (utn_getNumero(
				"¿Que campo desea modificar? 1-Nombre\n2-Apellido\n3-Codigo de vuelo\n4-Tipo de pasajero\n5-Precio\n6-Salir\n",
				"Ha habido un error. Intentelo nuevamente.\n", 0, 3, &opcion)
				== 0) {
			switch (opcion) {
			case 1:
				getString(s.name, MAX_SIZE_CHAR, "Nombre:\n",
						"Ha habido un error\n");
				break;
			case 2:
				getString(s.lastname, MAX_SIZE_CHAR, "Apellido:\n",
						"Ha habido un error\n");
				break;
			case 3:
				getString(s.flycode, 10, "Codigo de vuelo:\n",
						"Ha habido un error.\n");

				break;
			case 4:
				utn_getNumero("Tipo de pasajero: 1)Economico / 2)Clase alta\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&s.typePassenger);
				break;
			case 5:
				utn_getNumeroFlotante("Precio:\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&s.price);
				break;
			case 6:
				break;
			default:
				printMessage("Por favor, ingrese un numero entre 1 y 6.\n", 1);
			}
		}
	} while (opcion != 6);

	return s;
}

int Passenger_SearchSpace(Passenger passengerList[], int size, int status) {
	int r = -1;
	int i;

	if (passengerList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (passengerList[i].isEmpty == status) {
				r = i;
				break;
			}
		}
	}

	return r;
}

Passenger Passenger_LoadPassenger() {
	Passenger auxiliar;

	getString(auxiliar.name, MAX_SIZE_CHAR, "Nombre del pasajero: ", "Error. ");
	getString(auxiliar.lastname, MAX_SIZE_CHAR, "Apellido: ", "Error. ");
	getString(auxiliar.flycode, 10, "Codigo de vuelo:", "Error.");
	utn_getNumeroFlotante("Precio: ", "Error", 0, 3, &auxiliar.price);
	utn_getNumero("Opcion: ", "Error", 0, 3, &auxiliar.typePassenger);

	return auxiliar;

}

/** \brief find a Passenger by Id en returns the index position in passengersList.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return passenger index position or (-1) if [Invalid length or
 NULL pointer received or passenger not found]
 *
 */
int Passenger_SearchIndexPerId(Passenger passengerList[], int size, int ID) {
	int r = -1;
	int i;

	if (passengerList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (passengerList[i].id
					== ID&& passengerList[i].isEmpty == OCCUPIED) {
				r = i;
				break;
			}
		}
	}

	return r;
}

int Passenger_Sort(Passenger passengersList[], int size) {
	int r = -1;
	int i;
	int j;
	Passenger aux;
	if (passengersList != NULL && size > 0) {
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (passengersList[i].isEmpty == OCCUPIED
						&& passengersList[j].isEmpty == OCCUPIED) {
					if (passengersList[i].typePassenger
							> passengersList[j].typePassenger) {
						if (strcmp(passengersList[i].lastname,
								passengersList[j].lastname) > 0) {
							aux = passengersList[i];
							passengersList[i] = passengersList[j];
							passengersList[j] = aux;
						} else {
							aux = passengersList[j];
							passengersList[j] = passengersList[i];
							passengersList[i] = aux;
						}
					} else {
						aux = passengersList[j];
						passengersList[j] = passengersList[i];
						passengersList[i] = aux;
					}
				}
			}
		}
		fflush(stdin);
		Passenger_printList(passengersList, MAX_PASSENGERS, OCCUPIED);
		r = 0;
	}
	return r;
}
