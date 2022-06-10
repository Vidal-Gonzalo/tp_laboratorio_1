/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"
#include "LinkedList.h"
#include "General.h"

static int isNamePassenger(char newArray[], int size) {
	int i = 0;
	int r = 1;

	if (newArray != NULL && size > 0) {
		for (i = 0; newArray[i] != '\0' && i < size; i++) {
			if ((newArray[i] > 'A' || newArray[i] < 'Z')
					&& (newArray[i] > 'a' || newArray[i] < 'z')) {
				r = 0;
				break;
			}
		}
	}
	return r;
}

Passenger* Passenger_new() {
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametrosTxt(char *id, char *nombre, char *apellido,
		char *precio, char *codigoVuelo, char *tipoPasajero) {
	Passenger *aux = Passenger_new();
	int isValid = 0;
	if (aux != NULL) {
		//Validaciones -------------------- FALTA STATUSFLIGHT ---------------------
		if (Passenger_setIdTxt(aux, id) == 0) {
			if (Passenger_setNombre(aux, nombre) == 0) {
				if (Passenger_setApellido(aux, apellido) == 0) {
					if (Passenger_setPrecioTxt(aux, precio) == 0) {
						if (Passenger_setCodigoVuelo(aux, codigoVuelo) == 0) {
							if (Passenger_setTipoPasajeroTxt(aux, tipoPasajero)
									== 0) {
								printf("\n¡Datos cargados correctamente!\n");
								isValid = 1;
							} else {
								printf("Error tipoPasajero: %s", tipoPasajero);
							}
						} else {
							printf("Error codigoVuelo: %s", codigoVuelo);
						}
					} else {
						printf("Error precio: %s", precio);
					}
				} else {
					printf("Error apellido: %s", apellido);
				}
			} else {
				printf("Error nombre: %s", nombre);
			}
		} else {
			printf("Error id: %s", id);
		}
		if (isValid == 0) {
			printf("no es valido");
			free(aux);
		}
	}
	return aux;
}

Passenger* Passenger_newParametros(int *id, char *nombre, char *apellido,
		float *precio, char *codigoVuelo, int *tipoPasajero) {
	Passenger *aux = Passenger_new();
	int isValid = 0;
	if (aux != NULL) {
		//Validaciones -------------------- FALTA STATUSFLIGHT ---------------------
		if (Passenger_setId(aux, *id) == 0) {
			if (Passenger_setNombre(aux, nombre) == 0) {
				if (Passenger_setApellido(aux, apellido) == 0) {
					if (Passenger_setPrecio(aux, *precio) == 0) {
						if (Passenger_setCodigoVuelo(aux, codigoVuelo) == 0) {
							if (Passenger_setTipoPasajero(aux, *tipoPasajero)
									== 0) {
								printf("\n¡Datos cargados correctamente!\n");
								isValid = 1;
							}
						}
					}
				}
			}
		}
		if (isValid == 0) {
			printf("no es valido");
			free(aux);
		}
	}
	return aux;
}

void Passenger_delete(Passenger *this) {
	if (this != NULL) {
		free(this);
	}
}

int Passenger_setId(Passenger *this, int id) {
	int r = -1;
	if (this != NULL && id >= 0) {
		r = 0;
		this->id = id;
	}
	return r;
}

int Passenger_setIdTxt(Passenger *this, char *id) {
	int r = -1;
	if (this != NULL && id != NULL) {
		if (isNumber(id) == 0) {
			r = 0;
			this->id = atoi(id);
		} else {
			printf("Setid TXT: %s", id);
		}
	}
	return r;
}

int Passenger_getId(Passenger *this, int *id) {
	int r = -1;
	if (this != NULL && id != NULL) {
		r = 0;
		*id = this->id;
	}
	return r;
}

int Passenger_getIdTxt(Passenger *this, char *id) {
	int r = -1;
	if (this != NULL && id != NULL) {
		r = 0;
		sprintf(id, "%d", this->id);
	}
	return r;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	int r = -1;
	if (this != NULL && nombre != NULL) {
		if (isNamePassenger(nombre, MAX_CHARS_NAME) == 0) {
			r = 0;
			strncpy(this->nombre, nombre, MAX_CHARS_NAME);
		}
	}
	return r;
}

int Passenger_getNombre(Passenger *this, char *nombre) {
	int r = -1;
	if (this != NULL && nombre != NULL) {
		r = 0;
		strncpy(nombre, this->nombre, MAX_CHARS_NAME);
	}
	return r;
}

int Passenger_setApellido(Passenger *this, char *apellido) {
	int r = -1;
	if (this != NULL && apellido != NULL) {
		if (isNamePassenger(apellido, MAX_CHARS_LASTNAME) == 0) {
			r = 0;
			strncpy(this->apellido, apellido, MAX_CHARS_LASTNAME);
		}
	}
	return r;
}
int Passenger_getApellido(Passenger *this, char *apellido) {
	int r = -1;
	if (this != NULL && apellido != NULL) {
		r = 0;
		strncpy(apellido, this->apellido, MAX_CHARS_LASTNAME);
	}
	return r;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int r = -1;
	if (this != NULL && codigoVuelo != NULL) {
		if (verifyAlphanumeric(codigoVuelo, MAX_CHARS_FLY_CODE) == 0) {
			r = 0;
			strncpy(this->codigoVuelo, codigoVuelo, MAX_CHARS_FLY_CODE);
		}
	}
	return r;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int r = -1;
	if (this != NULL && codigoVuelo != NULL) {
		r = 0;
		strncpy(codigoVuelo, this->codigoVuelo, MAX_CHARS_FLY_CODE);
	}
	return r;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	int r = -1;
	if (this != NULL && tipoPasajero >= 0) {
		r = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return r;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	int r = -1;
	if (this != NULL && tipoPasajero != NULL) {
		r = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return r;
}

int Passenger_setTipoPasajeroTxt(Passenger *this, char *tipoPasajero) {
	int r = -1;
	if (this != NULL && tipoPasajero >= 0) {
		if (isNumber(tipoPasajero) == 0) {
			r = 0;
			this->tipoPasajero = atoi(tipoPasajero);
		}
	}
	return r;
}

int Passenger_getTipoPasajeroTxt(Passenger *this, char *tipoPasajero) {
	int r = -1;
	if (this != NULL && tipoPasajero != NULL) {
		r = 0;
		sprintf(tipoPasajero, "%d", this->tipoPasajero);
	}
	return r;
}

int Passenger_setPrecio(Passenger *this, float precio) {
	int r = -1;
	if (this != NULL && precio >= 0) {
		r = 0;
		this->precio = precio;
	}
	return r;
}

int Passenger_getPrecio(Passenger *this, float *precio) {
	int r = -1;
	if (this != NULL && precio != NULL) {
		r = 0;
		*precio = this->precio;
	}
	return r;
}

int Passenger_setPrecioTxt(Passenger *this, char *precio) {
	int r = -1;
	if (this != NULL && precio >= 0) {
		if (isFloat(precio) == 0) {
			r = 0;
			this->precio = atof(precio);
		}
	}
	return r;
}

int Passenger_getPrecioTxt(Passenger *this, char *precio) {
	int r = -1;
	if (this != NULL && precio != NULL) {
		r = 0;
		sprintf(precio, "%f", this->precio);
	}
	return r;
}

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
					if (utn_getNumero("Tipo de pasajero:\n",
							"Error, vuelva a intentar.\n", 0, 3,
							&auxiliar->tipoPasajero) == 0) {
						r = 0;
					}
				}
			}
		}
	}

	return r;
}

int Passenger_getUniqueId() {
	FILE *pFile;
	int id = 0;

	pFile = fopen("maxId", "r");
	if (pFile != NULL) {
		if (fscanf(pFile, "%d", &id) == 1) {
			id++;
		}
		fclose(pFile);
		pFile = fopen("maxId", "w");
		if (pFile != NULL) {
			fprintf(pFile, "%d", id);
			fclose(pFile);
		}
	}

	return id;
}

void Passenger_printOne(Passenger* p) {
	printf(
			"ID %d\nNombre: %s\nApellido: %s\nPrecio: %.2f\nCodigo vuelo: %s\nTipo de pasajero: %d\n",
			p->id, p->nombre, p->apellido, p->precio, p->codigoVuelo,
			p->tipoPasajero);

}

int Passenger_printPassengers(LinkedList pArrayPassengers[], int size) {
	int r = -1;
	Passenger *passenger;

	if (pArrayPassengers != NULL) {
		if (size > 0) {
			printf("%*s | %*s | %*s | %*s | %*s | %*s\n", -4, "ID", -MAX,
					"Nombre", -MAX, "Apellido", -MAX, "Precio", -MAX,
					"Codigo vuelo", -MAX, "Tipo pasajero");
			printf("%*c | %*c | %*c | %*c | %*c | %*c\n", -4, '-', -MAX, '-',
					-MAX, '-', -MAX, '-', -MAX, '-', -MAX, '-');
			for (int i = 0; i < size; i++) {
				passenger = (Passenger*) ll_get(pArrayPassengers, i);
				printf("%-4d | %-10s | %-10s | %-10.2f | %-10s | %-4d\n",
						passenger->id, passenger->nombre, passenger->apellido,
						passenger->precio, passenger->codigoVuelo,
						passenger->tipoPasajero);
				r = 0;

			}
		}
	}

	return r;
}

int Passenger_ModificarUno(Passenger* p) {
	int r = -1;
	int opcion;
	do {
		if (utn_getNumero(
				"¿Que campo desea modificar?\n 1-Nombre\n2-Apellido\n3-Codigo de vuelo\n4-Tipo de pasajero\n5-Precio\n6-Salir\n",
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
				general_getAlphanumeric(p->codigoVuelo, 10, "Codigo de vuelo:\n",
						"Ha habido un error.\n", 3);

				break;
			case 4:
				utn_getNumero("Tipo de pasajero: 1)Economico / 2)Clase alta\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&p->tipoPasajero);
				break;
			case 5:
				utn_getNumeroFlotante("Precio:\n",
						"Ha habido un error. Intentelo nuevamente.\n", 0, 3,
						&p->precio);
				break;
			case 6:
				printf("Saliendo...\n");
				break;
			default:
				printf("Por favor, ingrese un numero entre 1 y 6.\n");
			}
		}
	} while (opcion != 6);
	return r;
}

int Passenger_SearchIndexPerId(Passenger passengerList[], int size, int ID) {
	int r = -1;
	int i;

	if (passengerList != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (passengerList[i].id == ID) {
				r = i;
				break;
			}
		}
	}

	return r;
}

