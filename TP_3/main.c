#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

//ACLARACIÓN: ECLIPSE NO ME DEJA CREAR NI LEER ARCHIVOS CON FORMATO ESPECÍFICO, SOLO PUEDE TRABAJAR CON ARCHIVOS
//SIN FORMATO.

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int r = 0;
	int dataLoadedResponse = 0;
	int dataLoaded;
	int dataSaved = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();

	do {
		printf("opcion:\n");
		scanf("%d", &option); //Cambiar por utn_getNumero;
		switch (option) {
		case 1:
			dataLoadedResponse = controller_loadFromText("data2",
					listaPasajeros);
			if (dataLoadedResponse == 1) {
				printf(
						"El archivo no existe, asi que creamos uno para que comiences a cargar tus propios datos :)\n");
				dataLoaded = 1;
			} else {
				if (dataLoadedResponse == 0) {
					puts("Datos cargados correctamente!\n");
					dataLoaded = 1;
				} else {
					puts("Hubo un error en la carga de datos.\n");
				}
			}
			break;
		case 2:

			break;
		case 3:
			if (dataLoaded == 1) {
				if (controller_addPassenger("data2", listaPasajeros) == 0) {
					puts("todo bien");
				} else {
					puts("todo mal");
				}
			} else {
				puts("¡Todavia no cargaste la data!\n");
			}
			break;
		case 4:
			if (dataLoaded == 1) {
				if (controller_editPassenger("data2", listaPasajeros) == 0) {
					puts("todo bien");
				} else {
					puts("todo mal");
				}
			}
			break;
		case 5:
			if (dataLoaded == 1) {
				if (controller_removePassenger("data2", listaPasajeros) == 0) {
					puts("Todo bien");
				} else {
					puts("Todo mal");
				}
			}
			break;
		case 6:
			if (dataLoaded == 1) {
				if (controller_ListPassenger("data2", listaPasajeros) == 0) {
					puts("Todo bien");
				} else {
					puts("Todo mal");
				}
			}
			break;
		case 7:
			if (dataLoaded == 1) {
				if (controller_sortPassenger("data2", listaPasajeros) == 0) {
					puts("Todo bien");
				} else {
					puts("Todo mal");
				}
			}
			break;
		case 8:
			if (controller_saveAsText("data2", listaPasajeros) == 0) {
				dataSaved = 1;
			} else {
				puts("todo mal");
			}
			break;
		case 9:
			r = ll_len(listaPasajeros);
			printf("%d", r);
			break;
		case 10:
			if (dataSaved == 0) {
				puts("Por favor, guarda los cambios antes de irte.\n");
				option = 0;
			}
			break;
		}
	} while (option != 10);

	return 0;
}

