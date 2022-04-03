/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

#define DESCUENTO 10
#define INTERES 25
#define BITCOIN 4606954.55

int main(void) {
	setbuf(stdout, NULL);
	//DECLARACION DE VARIABLES
	float kilometros;
	float aerolineas;
	float latam;
	float descuentoLatam;
	float precioConDescuentoAerolineas;
	float precioConDescuentoLatam;
	float aumentoAerolineas;
	float aumentoLatam;
	float precioConAumentoAerolineas;
	float precioConAumentoLatam;
	float precioAerolineasConBTC;
	float precioLatamConBTC;
	float diferenciaDePrecio;

	//PEDIDO DE DATOS
	printf("Ingrese kilometros");
	scanf("%f", &kilometros);
	printf("Ingrese el precio del vuelo con Aerolineas");
	scanf("%f", &aerolineas);
	printf("Ingrese el precio del vuelo con Latam");
	scanf("%f", &latam);

	//AEROLINEAS
	/**********DESCUENTO*************/
	precioConDescuentoAerolineas = resultWithDiscount(aerolineas, DESCUENTO);
	/**********AUMENTO*************/
	aumentoAerolineas = aerolineas * ((float)INTERES / 100);
	precioConAumentoAerolineas = aerolineas + aumentoAerolineas;
	/**********BITCOIN*************/
	precioAerolineasConBTC = aerolineas / (float)BITCOIN;

	//LATAM
	/**********DESCUENTO*************/
	descuentoLatam = latam * ((float)DESCUENTO / 100);
	precioConDescuentoLatam = latam - descuentoLatam;
	/**********AUMENTO*************/
	aumentoLatam = latam * ((float)INTERES / 100);
	precioConAumentoLatam = latam + aumentoLatam;
	/**********BITCOIN*************/
	precioLatamConBTC = latam / (float)BITCOIN;


	//DIFERENCIA
	if(aerolineas > latam){
		diferenciaDePrecio = aerolineas - latam;
	} else {
		diferenciaDePrecio = latam - aerolineas;
	}

	//MENSAJES
	printf("Precio con descuento con Aerolineas: %.2f \n",
			precioConDescuentoAerolineas);
	printf("Precio con descuento con Latam: %.2f \n", precioConDescuentoLatam);
	printf("Precio con inter�s con Aerolineas: %.2f \n",
			precioConAumentoAerolineas);
	printf("Precio con inter�s con Latam: %.2f \n", precioConAumentoLatam);
	printf("Precio en BTC con Aerolineas: %.2f \n", precioAerolineasConBTC);
	printf("Precio en BTC con Latam: %.2f \n", precioLatamConBTC);
	printf("La diferencia de precio entre Aerolineas y Latam es de: %.2f", diferenciaDePrecio);

	return EXIT_SUCCESS;
}