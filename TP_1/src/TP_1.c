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

#define DISCOUNT 10
#define INTEREST 25
#define BITCOIN 4606954.55

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

	printf(
			"*********************************\n¡Bienvenidx a nuestro programa!\n\n*********************************\n");
	while (response != 6) {
		if (options(
				"\n-----------------------\nElija entre nuestras opciones:\n"
						"1-Ingresar kilometros a viajar:(km = %.2f) \n2-Ingresar precio de vuelos: (Aerolineas = $%.4f, Latam = $%.4f)\n"
						"3-Calcular los costos:\n a)Tarjeta de debito(descuento 10%%)\n b)Tarjeta de credito(interes 25%%)\n c)Bitcoin: (1BTC ---> $4606954.55 pesos argentinos)\n d)Mostrar precio por km (precio unitario)\n e)Mostrar diferencia de precio ingresada\n4-Informar resultados.\n5-Cargar nuestros datos.\n6-Salir\n-----------------------\n",
				&response, x, y, z, 1, 6) == -1) {
			printf("Por favor, elija un numero del 1 al 6");
		} else {
			switch (response) {
			case 1:
				if (getInfo("Ingrese kilometros: ", &x, 3, 0,
						"\nHa habido un error. Intentelo nuevamente.\n")
						!= -1) {
					printf(
							"¡Kilometros cargados correctamente! \nProceda a cargar los precios de vuelos (Opcion 2).\n");
				}
				break;
			case 2:
				if (getInfo("Precio vuelo Aerolineas: \n", &y, 3, 0,
						"\nHa habido un error. Intentelo nuevamente.\n") != -1
						&& getInfo("Precio vuelo Latam: \n", &z, 3, 0,
								"\nHa habido un error. Intentelo nuevamente.\n")
								!= -1) {
					printf(
							"\n¡Precios cargados correctamente! Proceda a calcularlos (Opcion 3).\n");
				} else {
					y = 0;
					z = 0;
					printf(
							"\nHubo un error en la carga de precios, tenga en cuenta que no se admiten numeros negativos.\n");
				}

				break;
			case 3:
				if (x == 0 || y == 0 || z == 0) {
					printf(
							"No ingresó todos los valores a calcular (Opciones 1 y 2).\n");
					break;
				} else {
					calculated = 1;
					/**********DISCOUNT*************/
					resultWithDiscount(y, DISCOUNT, &discountPriceAerolineas);
					/**********INCREMENT*************/
					resultWithInterest(y, INTEREST, &interestPriceAerolineas);
					/**********BITCOIN*************/
					bitcoinConverter(y, BITCOIN, &bitcoinPriceAerolineas);
					/**********PRICE P/KM**********/
					pricePerKm(x, y, &kilometerPriceAerolineas);

					//LATAM
					/**********DISCOUNT*************/
					resultWithDiscount(z, DISCOUNT, &discountPriceLatam);
					/**********INCREMENT*************/
					resultWithInterest(z, INTEREST, &interestPriceLatam);
					/**********BITCOIN*************/
					bitcoinConverter(z, BITCOIN, &bitcoinPriceLatam);
					/**********PRICE P/KM**********/
					pricePerKm(x, z, &kilometerPriceLatam);
					//DIFFERENCE
					differenceOfNumbers(y, z, &priceDifference);
					printf(
							"¡Cálculos realizados! Proceda a ver los resultados (Opcion 4).\n");
					break;
				}

			case 4:
				if (x == 0 || y == 0 || z == 0) {
					printf(
							"Por favor, ingrese los datos a calcular (Opcion 1 y 2). \n");
					break;
				}

				if (calculated == 1) {
					//MESSAGES
					printf("KMs Ingresados: %.2f km\n\n", x);
					printf(
							"Aerolineas: \na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin: $%.2f\nd)Precio unitario: $%.2f\n\n",
							discountPriceAerolineas, interestPriceAerolineas,
							bitcoinPriceAerolineas, kilometerPriceAerolineas);
					printf(
							"Latam: \na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin: $%.2f\nd)Precio unitario: $%.2f\n\n",
							discountPriceLatam, interestPriceLatam,
							bitcoinPriceLatam, kilometerPriceLatam);

					printf("La diferencia de precio es de: $%.2f\n",
							priceDifference);
					break;
				} else {
					printf(
							"Por favor, calcule primero los datos ingresados. (Opcion 3).\n");
					break;
				}

			case 5:
				x = 7090;
				y = 162965;
				z = 159339;
				resultWithDiscount(y, DISCOUNT, &discountPriceAerolineas);
				resultWithInterest(y, INTEREST, &interestPriceAerolineas);
				bitcoinConverter(y, BITCOIN, &bitcoinPriceAerolineas);
				pricePerKm(x, y, &kilometerPriceAerolineas);

				resultWithDiscount(z, DISCOUNT, &discountPriceLatam);
				resultWithInterest(z, INTEREST, &interestPriceLatam);
				bitcoinConverter(z, BITCOIN, &bitcoinPriceLatam);
				pricePerKm(x, z, &kilometerPriceLatam);

				differenceOfNumbers(y, z, &priceDifference);

				printf(
						"KMs Ingresados: %.2f\n\nPrecio Aerolineas: $%.2f \na)Precio con tarjeta de debito: $%.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin:$ %.2f\nPrecio unitario: $%.2f\n\n" "Precio Latam: $%.2f\na)Precio con tarjeta de debito:$ %.2f\nb)Precio con tarjeta de credito: $%.2f\nc)Precio pagando con Bitcoin: $%.2f\nPrecio unitario: $%.2f \nLa diferencia de precio es: $%.2f",
						x, y, discountPriceAerolineas, interestPriceAerolineas,
						bitcoinPriceAerolineas, kilometerPriceAerolineas, z,
						discountPriceLatam, interestPriceLatam,
						bitcoinPriceLatam, kilometerPriceLatam,
						priceDifference);
				x = 0;
				y = 0;
				z = 0;
				break;
			case 6:
				printf("\n¡Gracias por usar nuestro programa!\n");
				break;
			}
		}

	}

	return EXIT_SUCCESS;
}
