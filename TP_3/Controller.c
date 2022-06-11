#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputPassenger.h"
#include "parser.h"
#include "General.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	FILE *pFile;

	if (path != NULL && pArrayListPassenger != NULL) {
		if (ll_len(pArrayListPassenger) > 0) {
			if (confirmation(
					"\nSi carga los datos una vez más, se eliminaran los anteriores\n¿Esta seguro que desea realizar esta accion?(1:Si/Otro numero:No)\n",
					"Ha habido un error\n") == 1) {
				ll_clear(pArrayListPassenger);
			} else {
				return r = -2; //Carga de datos denegada
			}
		}
		pFile = fopen(path, "r");
		if (pFile == NULL) {
			pFile = fopen(path, "w");
			fclose(pFile);
			r = 1;
		} else {
			if (parser_PassengerFromText(pFile, pArrayListPassenger) == 0) {
				r = 0;
			} else {
				r = -4;
			}
		}
		fclose(pFile);
	}

	return r;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	FILE *binFile;

	if (path != NULL && pArrayListPassenger != NULL) {
		if (ll_len(pArrayListPassenger) > 0) {
			if (confirmation(
					"\nSi carga los datos una vez más, se eliminaran los anteriores ¿Esta seguro que desea realizar esta accion?(1:Si/Otro numero:No)\n",
					"Ha habido un error\n") == 1) {
				ll_clear(pArrayListPassenger);
			} else {
				return r = -2; //Carga de datos denegada
			}
		}
		binFile = fopen(path, "rb");
		if (binFile == NULL) {
			fclose(binFile);
			binFile = fopen(path, "wb");
			fclose(binFile);
			r = 1; //Archivo no existente
		} else {
			if (parser_PassengerFromBinary(binFile, pArrayListPassenger) == 0) {
				r = 0;
			} else {
				r = -4;
			}
		}
		fclose(binFile);
	}
	return r;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *Trabajo sobre los datos que me traje del archivo, añado, remuevo, etc. y luego los guardo en el punto 8
 */
int controller_addPassenger(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	Passenger auxPassenger;
	Passenger *passenger;

	if (path != NULL && pArrayListPassenger != NULL) {
		if (Passenger_LoadPassenger(&auxPassenger) == 0) {
			auxPassenger.id = Passenger_getUniqueId();
			passenger = Passenger_newParametros(&auxPassenger.id,
					auxPassenger.nombre, auxPassenger.apellido,
					&auxPassenger.precio, auxPassenger.codigoVuelo,
					&auxPassenger.tipoPasajero, &auxPassenger.statusFlight);
			puts("Pasajero añadido: \n");
			Passenger_printOne(passenger);
			ll_add(pArrayListPassenger, passenger);
			r = 0;
		}
	}
	return r;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	Passenger *passenger;
	int idToModify;
	int indexToModify = -1;

	if (path != NULL && pArrayListPassenger != NULL) {

		int linkedListLength = ll_len(pArrayListPassenger);

		if (Passenger_printPassengers(pArrayListPassenger, linkedListLength)
				== 0) {
			if (utn_getNumero("Ingrese el ID del pasajero a modificar:\n",
					"Error, vuelva a intentar.\n", 1, 3, &idToModify) == 0) {
				for (int i = 0; i < linkedListLength; i++) {
					passenger = (Passenger*) ll_get(pArrayListPassenger, i);
					if (passenger->id == idToModify) {
						indexToModify = i;
						break;
					}
				}
				if (indexToModify != -1) {
					puts("El pasajero que deseas modificar es:\n");
					Passenger_printOne(passenger);
					if (confirmation(
							"¿Esta seguro que desea modificarlo?\n(1:Si/Otro numero:No)\n",
							"Ha habido un error.\n") == 1) {
						Passenger_ModificarUno(passenger);
						puts("Usuario modificado: \n");
						Passenger_printOne(passenger);
						if (confirmation(
								"¿Los datos son correctos?\n(1:Si/Otro numero:No)\n",
								"Ha habido un error.\n") == 1) {
							ll_set(pArrayListPassenger, indexToModify,
									passenger);
							r = 0;
						}
					}
				} else {
					printf("No se ha encontrado el ID.\n");
					r = -2;
				}
			}

		}
	}
	return r;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	Passenger *passenger;
	int idToRemove;
	int indexToRemove = -1;

	if (path != NULL && pArrayListPassenger != NULL) {

		int linkedListLength = ll_len(pArrayListPassenger);

		if (Passenger_printPassengers(pArrayListPassenger, linkedListLength)
				== 0) {
			if (utn_getNumero("Ingrese el ID del pasajero a dar de baja:\n",
					"Error, vuelva a intentar.\n", 1, 3, &idToRemove) == 0) {
				for (int i = 0; i < linkedListLength; i++) {
					passenger = (Passenger*) ll_get(pArrayListPassenger, i);
					if (passenger->id == idToRemove) {
						indexToRemove = i;
						break;
					}
				}
				if (indexToRemove != -1) {
					puts("El pasajero que deseas remover es:\n");
					Passenger_printOne(passenger);
					if (confirmation(
							"¿Esta seguro que desea removerlo?\n(1:Si/Otro numero:No)\n",
							"Ha habido un error.\n") == 1) {
						ll_remove(pArrayListPassenger, indexToRemove);
						r = 0;
					}
				} else {
					printf("No se ha encontrado el ID.\n");
					r = -2;
				}
			}

		}
	}
	return r;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;

	if (path != NULL && pArrayListPassenger != NULL) {

		int linkedListLength = ll_len(pArrayListPassenger);

		if (Passenger_printPassengers(pArrayListPassenger, linkedListLength)
				== 0) {
			r = 0;
		}
	}
	return r;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	Passenger *firstAux;
	Passenger *secondAux;
	Passenger *thirdAux;

	if (path != NULL && pArrayListPassenger != NULL) {

		int linkedListLength = ll_len(pArrayListPassenger);
		for (int i = 0; i < linkedListLength; i++) {
			firstAux = (Passenger*) ll_get(pArrayListPassenger, i);
			for (int j = i + 1; j < linkedListLength; j++) {
				secondAux = (Passenger*) ll_get(pArrayListPassenger, j);
				if (strcmp(secondAux->codigoVuelo, firstAux->codigoVuelo) < 0) {
					thirdAux = firstAux;
					firstAux = secondAux;
					secondAux = thirdAux;
					ll_set(pArrayListPassenger, j, secondAux);
					ll_set(pArrayListPassenger, i, firstAux);
				}
			}
		}
		r = 0;
	}
	return r;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	FILE *pFile = NULL;
	Passenger *auxPassenger;
	int id;
	char nombre[MAX_CHARS_NAME];
	char apellido[MAX_CHARS_LASTNAME];
	float precio;
	int tipoPasajero;
	char tipoPasajeroTxt[50];
	char codigoVuelo[MAX_CHARS_FLY_CODE];
	int statusFlight;
	char statusFlightTxt[50];
	//A funcion de parser

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			r = 0;
			fprintf(pFile,
					"id, Name, Lastname, Price, Flycode, Type Passenger, Status Flight\n");
			for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				Passenger_getNombre(auxPassenger, nombre);
				Passenger_getApellido(auxPassenger, apellido);
				Passenger_getPrecio(auxPassenger, &precio);
				Passenger_getTipoPasajero(auxPassenger, &tipoPasajero);
				Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
				Passenger_getStatusFlight(auxPassenger, &statusFlight);

				if (auxPassenger != NULL) {
					Passenger_readTypePassengerAndStatusFlight(
							&auxPassenger->tipoPasajero,
							&auxPassenger->statusFlight, tipoPasajeroTxt,
							statusFlightTxt);
					fprintf(pFile, "%d,%s,%s,%.3f,%s,%s,%s\n", id, nombre,
							apellido, precio, codigoVuelo, tipoPasajeroTxt,
							statusFlightTxt);
					puts("Datos guardados: \n");
					printf("%d, %s, %s, %.3f, %s, %s, %s\n", id, nombre,
							apellido, precio, codigoVuelo, tipoPasajeroTxt,
							statusFlightTxt);
				}
			}
			fclose(pFile);

		}
	}

	return r;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	int r = -1;
	FILE *pFile = NULL;
	Passenger *auxPassenger;
	//A funcion de parser

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "wb");
		if (pFile != NULL) {
			r = 0;
			for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				if (auxPassenger != NULL) {
					fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
				}
			}
			fclose(pFile);
		}

	}

	return r;
}

