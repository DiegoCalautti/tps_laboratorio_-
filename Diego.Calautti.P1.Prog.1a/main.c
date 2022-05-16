#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 5

    /*
    1- Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto
     y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.
    */
    /** \brief Recibe un entero y devuelve ese entero+5%
     *
     * \param
     * \param
     * \return
     *
     */
    int aplicarAumento (int a);


    /*
    2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres
    como primer parámetro, un carácter como segundo y otro carácter  como tercero,
    la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero
    y devolver la cantidad de veces que se reemplazo ese carácter  en la cadena
    */
    //int reemplazarCaracteres(vec[], char a, char b);

    /*
    3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo.
     Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main.
    */
    typedef struct{
        int id;
        char nombre[20];
        char tipo;
        float efectividad;
        }eVacuna;

        int ordenamientoPorTipo(eVacuna vec[], int tam);

    ///

int main()
{
    int precioInicial=100;
    float precioFinal;
    // Tercer ejercicio
    eVacuna vacuna1[TAM];
    //

    printf("El precio inicial es de %d\n", precioInicial);
    precioFinal=(float)aplicarAumento(precioInicial);


    printf("El precio con aumento es: %.2f\n",precioFinal);



    ordenamientoPorTipo(vacuna1, TAM);




    return 0;
}


int aplicarAumento (int a)
{
    float precioConAumento;


    if(a >0&& a!= NULL)
        {    precioConAumento=a+((a*5)/100);

    }

    return precioConAumento;
}

/*int reemplazarCaracteres(vecA[], char a, char b)
{

}
*/

int ordenamientoPorTipo(eVacuna vec[], int tam)
{
    int validacion = 0;
    eVacuna auxTipo;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if( ((vec[i].tipo == vec[j].tipo) &&  (vec[i].efectividad > vec[j].efectividad))
                        || ((vec[i].tipo != vec[j].tipo) &&(vec[i].tipo > vec[j].tipo) ))
                {
                    auxTipo = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxTipo;
                }

            }
        }
        validacion = 1;
    }
    return validacion;
}

