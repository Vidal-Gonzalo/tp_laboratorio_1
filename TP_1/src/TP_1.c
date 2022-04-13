/*
 ============================================================================
 Name        : TP_1.c
 Author      : Gonzalo Vidal - División H
 Version     :
 Copyright   :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"
#include "askInformation.h"

int main(void) {
	setbuf(stdout, NULL);
	//VARIABLES
	float x;
	float y;
	float z;
	int calculated;
	float discountPriceAerolineas;
	float interestPriceAerolineas;
	float bitcoinPriceAerolineas;
	float kilometerPriceAerolineas;
	float discountPriceLatam;
	float interestPriceLatam;
	float bitcoinPriceLatam;
	float kilometerPriceLatam;
	float priceDifference;
	int response;

	x = 0;
	y = 0;
	y = 0;

	printMessage("¡Bienvenidx a nuestro programa!", 3);
	while (response != 6) {
		if (options(
				"\n-----------------------\nElija entre nuestras opciones:\n"
						"1-Ingresar kilometros a viajar:(km = %.2f) \n2-Ingresar precio de vuelos: (Aerolineas = $%.4f, Latam = $%.4f)\n"
						"3-Calcular los costos:\n a)Tarjeta de debito(descuento 10%%)\n b)Tarjeta de credito(interes 25%%)\n c)Bitcoin: (1BTC ---> $4606954.55 pesos argentinos)\n d)Mostrar precio por km (precio unitario)\n e)Mostrar diferencia de precio ingresada\n4-Informar resultados.\n5-Cargar nuestros datos.\n6-Salir\n-----------------------\n",
				&response, x, y, z, 1, 6) == -1) {
			printMessage("Por favor, elija un numero del 1 al 6", 2);
		} else {
			switch (response) {
			case 1:
				if (getInfo("Ingrese kilometros: ", &x, 3, 0,
						"\nHa habido un error. Intentelo nuevamente.\n")
						!= -1) {
					printMessage(
							"¡Kilometros cargados correctamente! \nProceda a cargar los precios de vuelos (Opcion 2).",
							1);
				}
				break;

			case 2:
				if (getInfo("Precio vuelo Aerolineas: \n", &y, 3, 0,
						"\nHa habido un error. Intentelo nuevamente.\n") != -1
						&& getInfo("Precio vuelo Latam: \n", &z, 3, 0,
								"\nHa habido un error. Intentelo nuevamente.\n")
								!= -1) {
					printMessage(
							"\n¡Precios cargados correctamente! Proceda a calcularlos (Opcion 3).",
							1);
				} else {
					y = 0;
					z = 0;
					printMessage(
							"\nHubo un error en la carga de precios, tenga en cuenta que no se admiten numeros negativos.",
							2);
				}

				break;

			case 3:
				if (x == 0 || y == 0 || z == 0) {
					printMessage(
							"No ingresó todos los valores a calcular (Opciones 1 y 2).",
							2);
					break;
				} else {
					calculated = 1;
					if (makeDifferentCalculations(x, y, z,
							&discountPriceAerolineas, &interestPriceAerolineas,
							&bitcoinPriceAerolineas, &kilometerPriceAerolineas,
							&discountPriceLatam, &interestPriceLatam,
							&bitcoinPriceLatam, &kilometerPriceLatam,
							&priceDifference) != -1) {
						printMessage(
								"¡Cálculos realizados! Proceda a ver los resultados (Opcion 4).",
								1);
					} else {
						printMessage(
								"Ha habido un error. Por favor, revise que se hayan ingresado correctamente los precios de vuelos.",
								1);
						calculated = 0;
					}

					break;
				}

			case 4:
				if (x == 0 || y == 0 || z == 0) {
					printMessage(
							"Por favor, ingrese los datos a calcular (Opcion 1 y 2).",
							2);
					break;
				}

				if (calculated == 1) {
					//MESSAGES
					if (printResults(x, y, z, discountPriceAerolineas,
							interestPriceAerolineas, bitcoinPriceAerolineas,
							kilometerPriceAerolineas, discountPriceLatam,
							interestPriceLatam, bitcoinPriceLatam,
							kilometerPriceLatam, priceDifference) != -1) {
						break;
					} else {
						printMessage(
								"Ha habido un error. Intentelo nuevamente, por favor.",
								2);
					}

					break;
				} else {
					printMessage(
							"Por favor, calcule primero los datos ingresados. (Opcion 3).",
							2);
					break;
				}

			case 5:
				if (confirmation(1, 0) != 1) {
					break;
				} else {
					x = 7090;
					y = 162965;
					z = 159339;
					if (makeDifferentCalculations(x, y, z,
							&discountPriceAerolineas, &interestPriceAerolineas,
							&bitcoinPriceAerolineas, &kilometerPriceAerolineas,
							&discountPriceLatam, &interestPriceLatam,
							&bitcoinPriceLatam, &kilometerPriceLatam,
							&priceDifference) != -1) {
						if (printResults(x, y, z, discountPriceAerolineas,
								interestPriceAerolineas, bitcoinPriceAerolineas,
								kilometerPriceAerolineas, discountPriceLatam,
								interestPriceLatam, bitcoinPriceLatam,
								kilometerPriceLatam, priceDifference) != -1) {
							x = 0;
							y = 0;
							z = 0;
							break;
						} else {
							printMessage(
									"Ha habido un error a la hora de imprimir los resultados.",
									2);
							break;
						}

					} else {
						printMessage(
								"Ha habido un error a la hora de calcular los precios.",
								2);
						break;
					}
				}
			case 6:
				printMessage("¡Gracias por usar nuestro programa!", 3);
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
