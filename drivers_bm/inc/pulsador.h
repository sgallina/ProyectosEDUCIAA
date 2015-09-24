/*
 * pulsador.h
 *
 *  Created on: 22/9/2015
 *      Author: SHG
 */
#include "stdint.h"
#include "ciaaPOSIX_stdbool.h"

#ifndef PULSADOR_H_
#define PULSADOR_H_

#define PULSADOR1   4
#define PULSADOR2   8
#define PULSADOR3   9
#define PULSADOR4   9

#define SALIDA  1
#define ENTRADA 0
#define PUERTO  0

void Inicializar_Pulsador(void);

bool Estado_Pulsador(uint8_t puerto, uint8_t pulsador);



#endif /* PULSADOR_H_ */
