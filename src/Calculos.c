/*
 * Calculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Diego Calautti
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int menu(){
    int opcion;

        system("cls");
      //system("cls"); //Limpiar consola
        printf("Menu de opciones: \n\n");
        printf("1- Ingresar Kilometros \n");
        printf("2- Ingresar Precio de Vuelos \n");
        printf("3- Calcular todos los costos \n");
        printf("4- Informar resultados \n");
        printf("5- Carga forzada de datos \n");
        printf("6- Salir \n");


        //Cuando salir valga 's', salgo del do while
        printf("Ingrese la opcion:\n");
        scanf("%d", &opcion);
          system("cls");

    return opcion;
    }

int calculoDescuentoConDebito(float precioVuelo, float* pResultado)
{
   float descuento=10;
   int retorno = -1;
   if (pResultado != NULL && precioVuelo != 0)
   {
   *pResultado= precioVuelo-((precioVuelo*descuento)/100);
   retorno=0;
   }
   return retorno;
}

int calculoTarjetaCredito(float operador1, float* pResultado)
{
    float interes=25;
    int retorno = -1;
    if (pResultado != NULL && operador1 != 0)
    {
    *pResultado= operador1+((operador1/100)*interes);
    retorno=0;
    }
    return retorno;
}

int calculoPagandoConBitcoin(float operador1, float* pResultado)
{
    float precioPagandoConBitcoin=4606954.55;
    int retorno = -1;
    if (pResultado != NULL && operador1 != 0)
    {
    *pResultado= operador1/precioPagandoConBitcoin;
    retorno=0;
    }
    return retorno;
}
int calculoPrecioPorKm(float operador1, float* punteroKm, float* pResultado)
{
    int retorno = -1;
    if (pResultado != NULL && operador1 != 0&& punteroKm != 0)
    {
    *pResultado= operador1/(*punteroKm);
    retorno=0;
    }
    return retorno;
}

int diferenciaPrecioVuelos(float* operador1, float*operador2, float* pResultado)
{
    int retorno = -1;
    if (pResultado != NULL && operador1 != 0 && operador2 != 0)
    {
        if((*operador1)<(*operador2))
        {
            *pResultado= (*operador2)-(*operador1);
             retorno=0;
        }
        else{
            *pResultado= (*operador1)-(*operador2);
            }
    }
    return retorno;
}
