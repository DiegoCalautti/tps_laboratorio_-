#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define TAM 10
struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
}typedef Passenger;




int mostrarEmpleado(Passenger e, int tam);
int listarEmpleados(Passenger vec[], int tam);
int cargarEmpleados(Passenger vec[], int tam);
int ordenarEmpleadosLegajoAsc(Passenger vec[], int tam);
int ordenarEmpleadosNombreAsc(Passenger vec[], int tam);
int ordenarEmpleadosSexoAsc(Passenger vec[], int tam);

int inicializarEmpleados(Passenger vec[], int tam);

int buscarEmpleadoLibre(Passenger vec[], int tam, int* pIndex);
int buscarEmpleado(Passenger vec[], int tam,int legajo, int* pIndex);
int altaEmpleado(Passenger vec[], int tam, int* pLegajo);
int bajaEmpleado(Passenger vec[], int tam);
int modificarEmpleado(Passenger vec[], int tam);
int hardcodearEmpleados(Passenger vec[], int tam, int cant, int* pLegajo);
int menuModificarEmpleado();




/** \brief Ordena un array de empleados de acuerdo al campo y modo especificado
 *
 * \param vec[] Passenger   Array de empleados
 * \param tam int   tamanio del array de empleados
 * \param campo int  campo por el cual se ordena O nombre, 1 legajo......(Se adjuntan defines)
 * \param criterio int  asc 1 desc 0
 * \return int  retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int ordenarEmpleados(Passenger vec[], int tam, int campo, int criterio);

int ordenarEmpleadosPorSexoYLegajo(Passenger vec[], int tam);



int menu();

int main()
{
    //int indice;
    char salir = 'n';
    int proximoLegajo = 10000;
    Passenger list[TAM];





    inicializarEmpleados(list, TAM);


    hardcodearEmpleados(list, TAM, 3, &proximoLegajo);

    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(list, TAM, &proximoLegajo);



            break;
        case 2:
         bajaEmpleado(list, TAM);

            break;
        case 3:
            if( modificarEmpleado(list, TAM) == 0)
            {
                printf("Problema al hacer la modificacion de empleado\n");
            }
            break;

            break;
        case 4:
            listarEmpleados(list, TAM);
            break;

        case 20:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}

int menu()
{

    int opcion;
    system("cls");
    printf("     *** ABM Pasajeros ***\n");
    printf("1- Alta de pasajero\n");
    printf("2- Baja de pasajero\n");
    printf("3- Modificar pasajero\n");
    printf("4- Listar pasajero\n");
    printf("20- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}





int mostrarEmpleado(Passenger e, int tam)
{


    printf("  %d       %s         %10s       %10f       %10s       %10d \n",
           e.id,
           e.name,
           e.lastName,
           e.price,
           e.flycode,
           e.typePassenger
          );


    return 0;
}


int listarEmpleados(Passenger vec[], int tam)
{
    int flag = 0;

        system("cls");
        printf("          *** Listado de Pasajeros ***\n\n");
        printf(" ID          Nombre        Apellido        Precio        Codigo de Vuelo        Tipo de pasajero \n");
        printf("------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarEmpleado(vec[i], tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay empleados en el sistema");
        }
        printf("\n\n");



    return 0;
}



int cargarEmpleados(Passenger vec[], int tam)
{
    int todoOk = 0;
    char auxCad[100];
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            printf("Ingrese ID: ");
            scanf("%d", &vec[i].id);

            printf("Ingrese el nombre del pasajero: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad) >= 20)
            {
                printf("Nombre demasiado largo. Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(vec[i].name, auxCad);


            printf("Ingrese el apellido del pasajero: ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad) >= 20)
            {
                printf("Apellido demasiado largo. Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(vec[i].lastName, auxCad);

              printf("Ingrese precio: ");
            scanf("%f", &vec[i].price);


             printf("Ingrese el flycode del pasajero: ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad) >= 20)
            {
                printf("flycode demasiado largo. Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(vec[i].flycode, auxCad);


            printf("Ingrese typePassenger: ");
            scanf("%d", &vec[i].typePassenger);


        }

        todoOk = 1;
    }
    return todoOk;
}





int inicializarEmpleados(Passenger vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarEmpleadoLibre(Passenger vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaEmpleado(Passenger vec[], int tam, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    Passenger nuevoEmpleado;

    if(vec != NULL && tam > 0 && pLegajo != NULL)
    {
        if( buscarEmpleadoLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

                printf("Ingrese el nombre del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoEmpleado.name, auxCad);

                 printf("Ingrese el apellido del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoEmpleado.lastName, auxCad);

                printf("Ingrese precio: ");
                scanf("%f", &nuevoEmpleado.price);

                printf("Ingrese el flycode del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoEmpleado.flycode, auxCad);


                printf("Ingrese typePassenger: ");
                fflush(stdin);
                scanf("%d", &nuevoEmpleado.typePassenger);


                nuevoEmpleado.isEmpty = 0;
                nuevoEmpleado.id = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoEmpleado;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}


int buscarEmpleado(Passenger vec[], int tam,int legajo, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && legajo > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == legajo )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaEmpleado(Passenger vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarEmpleados(vec, tam);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarEmpleado(vec, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(vec[indice], tam);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int modificarEmpleado(Passenger vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';
    char auxCad[100];
    if(vec != NULL && tam > 0)
    {
        listarEmpleados(vec, tam);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarEmpleado(vec, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(vec[indice], tam);


                do
                {
                    switch(menuModificarEmpleado())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].name, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;
/*
                    case 2:
                        printf("Ingrese nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c", &vec[indice].flycode);
                        printf("Se ha modificado el sexo\n");
                        break;

                    case 3:
                        printf("Ingrese nueva edad: ");
                        scanf("%d", &vec[indice].edad);
                        printf("Se ha modificado la edad\n");
                        break;

                        break;
                    case 4:
                        printf("Ingrese nuevo sueldo: ");
                        scanf("%f", &vec[indice].sueldo);
                        printf("Se ha modificado el sueldo\n");

                        break;*/
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int hardcodearEmpleados(Passenger vec[], int tam, int cant, int* pLegajo)
{

    int todoOk = 0;
    Passenger impostores[] =
    {
        {0, "Juan", "Gimenez",30, "abc1",5000,0},
        {0, "Daniela", "Gutierrez",23,"abc2",5000,0},
        {0, "Lucia", "Fernandez",20,"abc3",5004,0}
    };




    if(vec != NULL && tam > 0 && pLegajo != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pLegajo;
            *pLegajo = *pLegajo +1;

        }
        todoOk = 1;
    }
    return todoOk;

}

int menuModificarEmpleado()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Sexo\n");
    printf("3- Edad\n");
    printf("4- Sueldo\n");
    printf("5- Fecha de Ingreso\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}



