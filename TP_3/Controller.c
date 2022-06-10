#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "General.h"

//Debería hacer una función que verifique en el archivo si hay datos antes de asignar un ID.
//El ID va a estar en 0 hasta el punto 8 en el que deba guardar los datos. Ahí verifica si hay
//pasajeros en la LL. Si hay, toma el último ID y le suma uno, sino se inicia en 1.

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
					"\nSi carga los datos una vez más, se duplicarán ¿Esta seguro que desea realizar esta accion?\n",
					"Ha habido un error\n") != 1) {
				return r = -2; //Carga de datos denegada
			}
		}
		pFile = fopen(path, "r");
		if (pFile == NULL) {
			printf("El archivo no existe.\n");
			r = -3; //Archivo no existente
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
	FILE *bin;

	if (path != NULL && pArrayListPassenger != NULL) {
		bin = fopen(path, "rb");
		if (bin == NULL) {
			printf("El archivo no existe.\n");
			r = -3; //Archivo no existente
		} else {
			if (parser_PassengerFromBinary(bin, pArrayListPassenger) == 0) {
				r = 0;
			} else {
				r = -4;
			}
		}
		fclose(bin);
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
					&auxPassenger.tipoPasajero);
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
					if (confirmation("¿Esta seguro que desea modificarlo?\n",
							"Ha habido un error.\n") == 1) {
						Passenger_ModificarUno(passenger);
						puts("Usuario modificado: \n");
						Passenger_printOne(passenger);
						if (confirmation("¿Los datos son correctos?\n",
								"Ha habido un error.\n") == 1) {
							ll_set(pArrayListPassenger, indexToModify,
									passenger);
							puts("Usuario modificado correctamente!\n");
						}
					}
				} else {
					printf("No se ha encontrado el ID.\n");
				}
			}
			r = 0;
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
					if (confirmation("¿Esta seguro que desea removerlo?\n",
							"Ha habido un error.\n") == 1) {
						ll_remove(pArrayListPassenger, indexToRemove);
						puts("Usuario removido correctamente.\n");
					}
				} else {
					printf("No se ha encontrado el ID.\n");
				}
			}
			r = 0;
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
	Passenger* firstAux;
	Passenger* secondAux;
	Passenger* thirdAux;

	if (path != NULL && pArrayListPassenger != NULL) {

		int linkedListLength = ll_len(pArrayListPassenger);
		for(int i = 0; i < linkedListLength; i++){
			firstAux = (Passenger*)ll_get(pArrayListPassenger, i);
			printf("Compara %s con \n", firstAux->apellido);
			for(int j = i+1; j < linkedListLength; j++){
				secondAux = (Passenger*)ll_get(pArrayListPassenger, j);
				printf("%s\n", secondAux->apellido);
				if(strcmp(secondAux->apellido, firstAux->apellido) < 0){
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
	char codigoVuelo[MAX_CHARS_FLY_CODE];
	//A funcion de parser

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			r = 0;
			fprintf(pFile,
					"ID, Name, Lastname, Price, Flycode, TypePassenger\n");
			for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				Passenger_getNombre(auxPassenger, nombre);
				Passenger_getApellido(auxPassenger, apellido);
				Passenger_getPrecio(auxPassenger, &precio);
				Passenger_getTipoPasajero(auxPassenger, &tipoPasajero);
				Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
				if (auxPassenger != NULL) {

					fprintf(pFile, "%d, %s, %s, %.3f, %s, %d\n", id, nombre,
							apellido, precio, codigoVuelo, tipoPasajero);
					printf("%d, %s, %s, %.3f, %d, %s\n", id, nombre, apellido,
							precio, tipoPasajero, codigoVuelo);
				}
			}
			fclose(pFile);
		} else {
			printf("El archivo %s no existe\n", path);
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
	return 1;
}

