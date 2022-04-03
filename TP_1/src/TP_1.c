/*
 ============================================================================
 Name        : TP_1.c
 Author      : Gonzalo Vidal - Divisi�n H
 Version     :
 Copyright   : Your copyright notice
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
	//DECLARACION DE VARIABLES
	float x;
	float y;
	float z;
	int calculated;
	float discountPriceAerolineas;
	float discountPriceLatam;
	float interestPriceAerolineas;
	float interestPriceLatam;
	float bitcoinPriceAerolineas;
	float bitcoinPriceLatam;
	float priceDifference;
	int response;
	int hardCodedValue;

	x = 0;
	y = 0;
	z = 0;

	while (response != 6) {
		response =
				options(
						"Bienvenidx a nuestro programa. Elija entre nuestras opciones para comenzar el proceso. \n"
								"1-Ingresar kilometros a viajar: \n2-Ingresar precio de vuelos:\n"
								"3-Calcular los costos.\n4-Informar resultados.\n5-Cargar nuestros datos.\n6-Salir\n");
		switch (response) {
		case 1:
			printf("Ingrese kilometros");
			scanf("%f", &x);
			printf("�Kilometros cargados correctamente! \nProceda a cargar los precios de vuelos (Opcion 2).\n");
			break;
		case 2:
			printf("Ingrese el precio del vuelo con Aerolineas");
			scanf("%f", &y);
			printf("Ingrese el precio del vuelo con Latam");
			scanf("%f", &z);
			printf("\n�Precios cargados correctamente! Proceda a calcularlos (Opcion 3).\n");
			break;
		case 3:
			if(hardCodedValue == 1){
				printf("Se han detectado valores cargados forzosamente. \nIntentelo nuevamente cargando sus propios valores (Opcion 1).\n");
				x = 0;
				y = 0;
				z = 0;
				hardCodedValue = 0;
				break;
			}
			if (x == 0 || y == 0 || z == 0) {
				printf("No ingres� ningun valor a calcular. \n");
				break;
			} else {
				calculated = 1;
				/**********DESCUENTO*************/
				discountPriceAerolineas = resultWithDiscount(y, DISCOUNT);
				/**********AUMENTO*************/
				interestPriceAerolineas = resultWithInterest(y, INTEREST);
				/**********BITCOIN*************/
				bitcoinPriceAerolineas = bitcoinConverter(y, BITCOIN);

				//LATAM
				/**********DESCUENTO*************/
				discountPriceLatam = resultWithDiscount(z, DISCOUNT);
				/**********AUMENTO*************/
				interestPriceLatam = resultWithInterest(z, INTEREST);
				/**********BITCOIN*************/
				//DIFFERENCE
				bitcoinPriceLatam = bitcoinConverter(z, BITCOIN);
				if (y > z) {
					priceDifference = y - z;
				} else {
					priceDifference = z - y;
				}
				printf("�C�lculos realizados! Proceda a ver los resultados (Opcion 4).\n");
				break;
			}

		case 4:
			if (calculated == 1) {
				//MENSAJES
				printf("Precio con descuento con Aerolineas: %.2f \n",
						discountPriceAerolineas);
				printf("Precio con descuento con Latam: %.2f \n",
						discountPriceLatam);
				printf("Precio con inter�s con Aerolineas: %.2f \n",
						interestPriceAerolineas);
				printf("Precio con inter�s con Latam: %.2f \n",
						interestPriceLatam);
				printf("Precio en BTC con Aerolineas: %.5f \n",
						bitcoinPriceAerolineas);
				printf("Precio en BTC con Latam: %.5f \n", bitcoinPriceLatam);
				printf(
						"La diferencia de precio entre Aerolineas y Latam es de: %.2f\n",
						priceDifference);
				break;
			} else {
				printf("Por favor, calcule primero los datos ingresados. (Opcion 3)\n");
				break;
			}

		case 5:
			x = 7090;
			y = 162965;
			z = 159339;
			hardCodedValue = 1;
			discountPriceAerolineas = resultWithDiscount(y, DISCOUNT);
			interestPriceAerolineas = resultWithInterest(y, INTEREST);
			bitcoinPriceAerolineas = bitcoinConverter(y, BITCOIN);

			discountPriceLatam = resultWithDiscount(z, DISCOUNT);
			interestPriceLatam = resultWithInterest(z, INTEREST);
			bitcoinPriceLatam = bitcoinConverter(z, BITCOIN);

			printf(
					"KMs Ingresados: %f \n \n Precio Aerolineas: %f \na)Precio con tarjeta de debito: %f\nb)Precio con tarjeta de credito: %f\nc)Precio pagando con Bitcoin: %f\n" "Precio Latam: %f\na)Precio con tarjeta de debito: %f\nb)Precio con tarjeta de credito: %f\nc)Precio pagando con Bitcoin: %f \n",
					x, y, discountPriceAerolineas, interestPriceAerolineas,
					bitcoinPriceAerolineas, z, discountPriceLatam, interestPriceLatam, bitcoinPriceLatam);

			break;
		case 6:
			printf("\n�Gracias por usar nuestro programa!\n");
			break;
		default:
			printf("Por favor ingrese un numero del 1 al 6.\n");
		}
	}

	return EXIT_SUCCESS;
}
