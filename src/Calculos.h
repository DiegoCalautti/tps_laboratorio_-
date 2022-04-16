/*
 * Calculos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Diego Calautti
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/** \brief Funcion que muestra el menu
 *
 * \param int opcion lo que hace es retornar la opcion solicitada
 * \param
 * \return
 *
 */
 int menu();


/** \brief Realiza el calculo del descuento del 10% utilizando debito
 *
 * \param precioVuelo float operador que utiliza para la resta, division y multiplicacion
 * \param pResultado float* puntero que se utiliza para guardar el resultado
 * \return int retorno de ejecucion correcta o fallida
 *
 */
int calculoDescuentoConDebito(float precioVuelo, float* pResultado);


/** \brief Realiza el calculo del aumento del 25% sobre el precio del operador1
 *
 * \param operador1 float Se utiliza para la resta, division y multiplicacion
 * \param pResultado float* Puntero que guarda el resultado de calculo
 * \return int Retorno de ejecucion correcta o fallida
 *
 */
int calculoTarjetaCredito(float operador1, float* pResultado);

/** \brief Realiza calculo del precio de los vuelos pagando con bitcoin
 *
 * \param operador1 float Operador que se utiliza en la division como un nominador
 * \param pResultado float* resultado
 * \return int Retorno de ejecucion correcta o fallida
 *
 */
int calculoPagandoConBitcoin(float operador1, float* pResultado);


/** \brief Realiza calculo de precio unitario (por km)
 *
* \param operador1 float Operador que se utiliza en la division como un nominador
 * \param punteroKm float Puntero que se utiliza en la division como un denominador
 * \param pResultado float* Puntero que se utiliza para guardar el resultado del calculo
 * \return int
 *
 */
int calculoPrecioPorKm(float operador1, float* punteroKm, float* pResultado);

/** \brief Calcula la diferencia entre operador1-operador2
 *
 * \param float*operador1 Puntero que utilizo para pasar un dato
 * \param float*operador2 Puntero que utilizo para pasar un dato
 * \param pResultado float* Puntero que devuelve la resolucion del calculo
 * \return int
 *
 */
int diferenciaPrecioVuelos(float* operador1, float*operador2, float* pResultado);


#endif /* CALCULOS_H_ */
