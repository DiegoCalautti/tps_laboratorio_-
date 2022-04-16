/*
 ============================================================================
 Name        : TP 01
 Author      : Diego Calautti
 Version     :
 Copyright   :
 Description : TP 01 finalizado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculos.h"




int main(void) {
	setbuf(stdout, NULL);
    char salir;
    int flagOpcionUno;
    int flagOpcionDos;
    int flagOpcionTres;
    float km;
    float precioVueloAerolineas;
    float precioVueloLatam;
    float resultadoDescDebitoAerolineas;
    float resultadoDescDebitoLatam;
    //interes con credito
    float resultPrecioConInteresCreditoAerolineas;
    float resultPrecioConInteresCreditoLatam;
    //bitcoin
    float resultPrecioBtcAero;
    float resultPrecioBtcLatam;
    //precio por kilometro: precio unitario
    float resultPrecioPorKmAerolineas;
    float resultPrecioPorKmLatam;
    //Diferencia precio de vuelos entre Aerolineas y Latam
    float resultadoDiferenciaVuelos;

    flagOpcionUno = 1; //Si vale 1, significa que todavia no se ingresaron kilometros en la opcion 1
    flagOpcionDos = 1; //Si vale 1, significa que todavia no se ingreso el precio de los vuelos en la opcion 2
    flagOpcionTres = 1; //Si vale 1, significa que todavia no se ingreso a la opcion 2

    do
    {
        switch(menu())
        {
        case 1:
            //Ingresando KM

            printf("Ingrese los Kilometros \n");
            scanf("%f", &km);
            while(km<100||km>100000)
            {
            printf("Error, los Kilometros ingresados no pueden ser menores a 100 y mayores a 100 mil \n");
            scanf("%f", &km);
            }
            printf("Has ingresado %.0f km\n", km);
            flagOpcionUno=0;
            system("pause");
            break;
        case 2:
            //Ingresando precio de vuelos
            if(flagOpcionUno==0)
            {
                //ingresando precio de los vuelos de Aerolineas
                printf("Ingrese el precio de los vuelos de Aerolineas \n");
                scanf("%f", &precioVueloAerolineas);

                //Validando precio de los vuelos de aerolineas
                while(precioVueloAerolineas<1)
                {
                    printf("Error, el precio del vuelo en Aerolineas no puede ser menor a 0. Ingrese el precio nuevamente: \n");
                     scanf("%f", &precioVueloAerolineas);
                }
                printf("El precio que has ingresado de los vuelos de aerolineas es $ %.2f \n\n", precioVueloAerolineas);

                //ingresando precio de los vuelos de LATAM
                printf("Ingrese el precio de los vuelos de LATAM \n");
                scanf("%f", &precioVueloLatam);

                //Validando precio de los vuelos de LATAM
                  while(precioVueloLatam<1)
                {
                    printf("Error, el precio del vuelo en LATAM no puede ser menor a 0. Ingrese el precio nuevamente: \n");
                    scanf("%f", &precioVueloLatam);
                }
                 printf("El precio que has ingresado de los vuelos de LATAM es $ %.2f \n", precioVueloLatam);

                flagOpcionDos=0;
            }
            else
            {
                printf("Para ingresar precio de vuelos primero debe ingresar kilometros en la opcion 1\n");
            }

            system("pause");
            break;
        case 3:
            //El programa calcula los costos

            if(flagOpcionDos==0)
            {
                printf("Excelente, los costos han sido calculados. Ingrese cualquier tecla para volver al menu \n");
                //Utilizando funcion para calcular el descuento con debito de las dos empresas de vuelos
                calculoDescuentoConDebito(precioVueloAerolineas, &resultadoDescDebitoAerolineas);
                calculoDescuentoConDebito(precioVueloLatam, &resultadoDescDebitoLatam);
                //credito
                calculoTarjetaCredito(precioVueloAerolineas, &resultPrecioConInteresCreditoAerolineas);
                calculoTarjetaCredito(precioVueloLatam, &resultPrecioConInteresCreditoLatam);
                //btc
                calculoPagandoConBitcoin(precioVueloAerolineas, &resultPrecioBtcAero);
                calculoPagandoConBitcoin(precioVueloLatam, &resultPrecioBtcLatam);
                //precio por km
                calculoPrecioPorKm (precioVueloAerolineas, &km, &resultPrecioPorKmAerolineas);
                calculoPrecioPorKm (precioVueloLatam, &km, &resultPrecioPorKmLatam);
                //Diferencia de precio entre Latam y Aerolineas. Calculando y despues mostrando
                diferenciaPrecioVuelos(&precioVueloAerolineas, &precioVueloLatam, &resultadoDiferenciaVuelos);
                //printf("La diferencia entre el valor de %.2f del vuelo de Aerolineas, frente al valor %.2f del vuelo de Latam es: %.2f \n", precioVueloAerolineas, precioVueloLatam, resultadoDiferenciaVuelos);


                flagOpcionTres=0;

            }
            else if(flagOpcionUno==1)
                {
                printf("Para poder usar la opcion 3, debe primero ingresar los Kilometros y luego ir a la Opcion 2\n");
                }
                else {
                    printf("Para poder usar la opcion 3, debe ingresar el precio de los vuelos en la Opcion 2\n");
                }
            system("pause");
            break;
        case 4:
             if(flagOpcionTres==0)
            {
            //CASE 4, OPCION 4 INFORMA LO PREVIAMENTE INGRESADO Y LO PREVIAMENTE CALCULADO:
            printf("Latam:\n");
            printf("a) Precio con tarjeta de debito: $ %.2f\n", resultadoDescDebitoLatam);
            printf("b) Precio con tarjeta de credito: $ %.2f\n",resultPrecioConInteresCreditoLatam);
            printf("c) Precio pagando con Bitcoin: %.8f btc\n", resultPrecioBtcLatam);
            printf("Precio unitario: %.2f\n\n", resultPrecioPorKmLatam);

            printf("Aerolineas:\n");
            printf("a) Precio con tarjeta de debito: $ %.2f\n", resultadoDescDebitoAerolineas);
            printf("b) Precio con tarjeta de credito: $ %.2f\n",resultPrecioConInteresCreditoAerolineas);
            printf("c) Precio pagando con Bitcoin: %.8f btc\n", resultPrecioBtcAero);
            printf("Precio unitario: %.2f\n\n", resultPrecioPorKmAerolineas);
            //
            printf("La diferencia de precio es: %.2f \n", resultadoDiferenciaVuelos);
            }
            else if(flagOpcionDos==1)
                {
                printf("Para poder usar la opcion 4, debe llevar a cabo las Opciones anteriores\n");
                }
                else{
                    printf("Para poder usar la Opcion 4, debe calcular los montos en la Opcion 3\n");
                }
            system("pause");
            break;
        case 5:
            //CARGA FORZADA DE DATOS guardandolas en variables
            km=7090;
            precioVueloAerolineas=162965;
            precioVueloLatam=159339;
            //
            //Utilizando funcion para calcular el descuento con debito de las dos empresas de vuelos
            calculoDescuentoConDebito(precioVueloAerolineas, &resultadoDescDebitoAerolineas);
            calculoDescuentoConDebito(precioVueloLatam, &resultadoDescDebitoLatam);
            //credito
            calculoTarjetaCredito(precioVueloAerolineas, &resultPrecioConInteresCreditoAerolineas);
            calculoTarjetaCredito(precioVueloLatam, &resultPrecioConInteresCreditoLatam);
            //btc
            calculoPagandoConBitcoin(precioVueloAerolineas, &resultPrecioBtcAero);
            calculoPagandoConBitcoin(precioVueloLatam, &resultPrecioBtcLatam);
            //precio por km
            calculoPrecioPorKm (precioVueloAerolineas, &km, &resultPrecioPorKmAerolineas);
            calculoPrecioPorKm (precioVueloLatam, &km, &resultPrecioPorKmLatam);
            //Diferencia de precio entre Latam y Aerolineas. Calculando y despues mostrando
            diferenciaPrecioVuelos(&precioVueloAerolineas, &precioVueloLatam, &resultadoDiferenciaVuelos);

            printf("KMs ingresados: %.2f km\n\n", km);

            printf("Precio Aerolineas: $ %.2f \n", precioVueloAerolineas);
            printf("a) Precio con tarjeta de debito: $ %.2f\n", resultadoDescDebitoAerolineas);
            printf("b) Precio con tarjeta de credito: $ %.2f\n",resultPrecioConInteresCreditoAerolineas);
            printf("c) Precio pagando con Bitcoin: %.8f btc\n", resultPrecioBtcAero);
            printf("d) Mostrar precio unitario: %.2f\n\n", resultPrecioPorKmAerolineas);
            //
            printf("Precio Latam: $ %.2f \n", precioVueloLatam);
            printf("a) Precio con tarjeta de debito: $ %.2f\n", resultadoDescDebitoLatam);
            printf("b) Precio con tarjeta de credito: $ %.2f\n",resultPrecioConInteresCreditoLatam);
            printf("c) Precio pagando con Bitcoin: %.8f btc\n", resultPrecioBtcLatam);
            printf("d) Mostrar precio unitario: %.2f\n\n", resultPrecioPorKmLatam);

            printf("La diferencia de precio es: %.2f \n", resultadoDiferenciaVuelos);
            //
            system("pause");
            break;
        case 6:
            printf("6- Salir \n");
            printf("Estas seguro que queres salir? Ingrese S por si y N por no\n");
            fflush(stdin);
            scanf("%c", &salir);
            system("pause");
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            break;

        }

    }while(salir!='s');

    printf("Apretaste opcion 6 y despues pusiste 's'. Saliste del programa!\n");

	return EXIT_SUCCESS;
}
