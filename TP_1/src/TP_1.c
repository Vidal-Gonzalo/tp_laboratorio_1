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
	z = 0;

	printf(
			"*********************************\n¡Bienvenidx a nuestro programa!\n\n*********************************\n");
	while (response != 6) {
		response =
				options(
						"\n-----------------------\nElija entre nuestras opciones:\n"
								"1-Ingresar kilometros a viajar:(km = %.2f) \n2-Ingresar precio de vuelos: (Aerolineas = %.4f, Latam = %.4f)\n"
								"3-Calcular los costos:\n a)Tarjeta de debito(descuento 10%%)\n b)Tarjeta de credito(interes 25%%)\n c)Bitcoin: (1BTC ---> 4606954.55 pesos argentinos)\n d)Mostrar precio por km (precio unitario)\n e)Mostrar diferencia de precio ingresada\n4-Informar resultados.\n5-Cargar nuestros datos.\n6-Salir\n-----------------------\n",
						x, y, z);
		switch (response) {
		case 1:
			printf("Ingrese kilometros\n");
			scanf("%f", &x);
			printf(
					"¡Kilometros cargados correctamente! \nProceda a cargar los precios de vuelos (Opcion 2).\n");
			break;
		case 2:
			printf("Precio vuelo Aerolineas:\n");
			scanf("%f", &y);
			printf("Precio vuelo Latam:\n");
			scanf("%f", &z);
			printf(
					"\n¡Precios cargados correctamente! Proceda a calcularlos (Opcion 3).\n");
			break;
		case 3:
			if (x == 0 || y == 0 || z == 0) {
				printf(
						"No ingresó todos los valores a calcular (Opciones 1 y 2).\n");
				break;
			} else {
				calculated = 1;
				/**********DISCOUNT*************/
				discountPriceAerolineas = resultWithDiscount(y, DISCOUNT);
				/**********INCREMENT*************/
				interestPriceAerolineas = resultWithInterest(y, INTEREST);
				/**********BITCOIN*************/
				bitcoinPriceAerolineas = bitcoinConverter(y, BITCOIN);
				/**********PRICE P/KM**********/
				kilometerPriceAerolineas = pricePerKm(x, y);

				//LATAM
				/**********DISCOUNT*************/
				discountPriceLatam = resultWithDiscount(z, DISCOUNT);
				/**********INCREMENT*************/
				interestPriceLatam = resultWithInterest(z, INTEREST);
				/**********BITCOIN*************/
				bitcoinPriceLatam = bitcoinConverter(z, BITCOIN);
				/**********PRICE P/KM**********/
				kilometerPriceLatam = pricePerKm(x, z);
				//DIFFERENCE
				if (y > z) {
					priceDifference = y - z;
				} else {
					priceDifference = z - y;
				}
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
						"Aerolineas: \na)Precio con tarjeta de debito: %.2f\nb)Precio con tarjeta de credito: %.2f\nc)Precio pagando con Bitcoin: %.2f\nd)Precio unitario: %.2f\n\n",
						discountPriceAerolineas, interestPriceAerolineas,
						bitcoinPriceAerolineas, kilometerPriceAerolineas);
				printf(
						"Latam: \na)Precio con tarjeta de debito: %.2f\nb)Precio con tarjeta de credito: %.2f\nc)Precio pagando con Bitcoin: %.2f\nd)Precio unitario: %.2f\n\n",
						discountPriceLatam, interestPriceLatam,
						bitcoinPriceLatam, kilometerPriceLatam);

				printf("La diferencia de precio es de: %.2f\n",
						priceDifference);
				break;
			} else {
				printf(
						"Por favor, calcule primero los datos ingresados (Opcion 3).\n");
				break;
			}

		case 5:
			x = 7090;
			y = 162965;
			z = 159339;
			discountPriceAerolineas = resultWithDiscount(y, DISCOUNT);
			interestPriceAerolineas = resultWithInterest(y, INTEREST);
			bitcoinPriceAerolineas = bitcoinConverter(y, BITCOIN);
			kilometerPriceAerolineas =  pricePerKm(x, y);

			discountPriceLatam = resultWithDiscount(z, DISCOUNT);
			interestPriceLatam = resultWithInterest(z, INTEREST);
			bitcoinPriceLatam = bitcoinConverter(z, BITCOIN);
			kilometerPriceLatam = pricePerKm(x, z);

			if (y > z) {
				priceDifference = y - z;
			} else {
				priceDifference = z - y;
			}
			printf(
					"KMs Ingresados: %.2f\n\nPrecio Aerolineas: %.2f \na)Precio con tarjeta de debito: %.2f\nb)Precio con tarjeta de credito: %.2f\nc)Precio pagando con Bitcoin: %.2f\nPrecio unitario: %.2f\n\n" "Precio Latam: %.2f\na)Precio con tarjeta de debito: %.2f\nb)Precio con tarjeta de credito: %.2f\nc)Precio pagando con Bitcoin: %.2f\nPrecio unitario: %.2f \nLa diferencia de precio es: %.2f",
					x, y, discountPriceAerolineas, interestPriceAerolineas,
					bitcoinPriceAerolineas, kilometerPriceAerolineas, z, discountPriceLatam,
					interestPriceLatam, bitcoinPriceLatam, kilometerPriceLatam, priceDifference);
			x = 0;
			y = 0;
			z = 0;
			break;
		case 6:
			printf("\n¡Gracias por usar nuestro programa!\n");
			break;
		default:
			printf("Por favor ingrese un numero del 1 al 6.\n");
		}
	}

	return EXIT_SUCCESS;
}
