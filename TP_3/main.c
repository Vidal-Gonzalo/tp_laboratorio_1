#include <stdio.h>
#include <stdlib.h>
#include "General.h"
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
	int dataLoadedResponse = 0;
	int dataBinLoadedResponse = 0;
	int changedDataResponse = 0;
	int dataLoaded;
	int dataSaved = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();

	do {
		if (utn_getNumero("opcion:\n", "Hubo un error, vuelva a intentar\n", 0,
				3, &option) == 0) {
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
				dataBinLoadedResponse = controller_loadFromBinary("data2.bin",
						listaPasajeros);
				if (dataBinLoadedResponse == 1) {
					printf(
							"El archivo no existe, asi que creamos uno para que comiences a cargar tus propios datos :)\n");
					dataLoaded = 2;
				} else {
					if (dataBinLoadedResponse == 0) {
						puts("Datos cargados correctamente!\n");
						dataLoaded = 2;
					} else {
						puts("Hubo un error en la carga de datos\n");
					}
				}
				break;
			case 3:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de agregar pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						if (controller_addPassenger("data2", listaPasajeros)
								== 0) {
							puts("Datos cargados correctamente\n");
						} else {
							puts("Hubo un error.\n");
						}
					} else {
						puts("¡Todavia no cargaste la data!\n");
					}
				}
				break;
			case 4:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de editar pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						changedDataResponse = controller_editPassenger("data2",
								listaPasajeros);
						if (changedDataResponse == 0) {
							puts("Datos modificados correctamente\n");
						} else {
							if (changedDataResponse == -1) {
								puts("Hubo un error\n");
							}
						}
					} else {
						puts("¡Todavia no cargaste la data!\n");
					}
				}
				break;
			case 5:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de remover pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						changedDataResponse = controller_removePassenger(
								"data2", listaPasajeros);
						if (changedDataResponse == 0) {
							puts("Pasajero removido correctamente\n");
						} else {
							if (changedDataResponse == -1) {
								puts("Hubo un error\n");
							}
						}
					} else {
						puts("¡Todavia no cargaste la data!\n");
					}
				}
				break;
			case 6:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de listar pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						if (controller_ListPassenger("data2", listaPasajeros)
								== 0) {
							puts("Se listaron los pasajeros correctamente\n");
						} else {
							puts("Hubo un error\n");
						}
					} else {
						puts("¡Todavia no cargaste la data!\n");
					}
				}
				break;
			case 7:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de ordenar pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						if (controller_sortPassenger("data2", listaPasajeros)
								== 0) {
							puts("Pasajeros ordenados por codigo de vuelo\n");
						} else {
							puts("Hubo un error\n");
						}
					} else {
						puts("¡Todavia no cargaste la data!\n");
					}
				}

				break;
			case 8:
				if (dataLoaded == 2) {
					puts(
							"La informacion cargada está en formato binario.\nPor favor, antes de guardar pasajeros cargue la informacion en formato de texto.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					} else {
						puts("\nElija otra opcion.\n");
					}
					break;
				} else {
					if (dataLoaded == 1) {
						if (controller_saveAsText("data2", listaPasajeros)
								== 0) {
							dataSaved = 1;
							puts("La informacion fue guardada!\n");
						} else {
							puts("Hubo un error\n");
						}
					} else {
						puts("No hay informacion para guardar!\n");
					}
				}

				break;
			case 9:
				if (dataLoaded == 1) {
					puts(
							"La informacion cargada está en formato de texto.\nPor favor, antes de guardarla en binario cargue la informacion en formato binario.\n");
					if (confirmation(
							"¿Desea eliminar la informacion cargada?\n(1:Si/Otro numero:No)\n",
							"Hubo un error\n") == 1) {
						ll_clear(listaPasajeros);
						dataLoaded = 0;
					}
					break;
				} else {
					if (dataLoaded == 2) {
						if (controller_saveAsBinary("data2.bin", listaPasajeros)
								== 0) {
							dataSaved = 1;
							puts("La informacion fue guardada!\n");
						} else {
							puts("Hubo un error.\n");
						}
					} else {
						puts("No hay informacion para guardar.\n");
					}
				}

				break;
			case 10:
				if (dataSaved == 0) {
					puts("Por favor, guarda los cambios antes de irte.\n");
					option = 0;
				}
				break;
			}
		}

	} while (option != 10);

	return 0;
}

