/*
 * leds.h
 *
 *  Created on: 21/9/2015
 *      Author: MarcosDario
 */
#include "stdint.h"

#ifndef LEDS_H_

#define LEDS_H_

#define LEDR   0
#define LEDG   1
#define LEDB   2
#define LED1   14
#define LED2   11
#define LED3   12

#define SALIDA  1
#define ENTRADA 0
#define PUERTO  0

void Inicializar_Led(void);
void Encender_Led(uint8_t port, uint8_t pin);
void Apagar_Led(uint8_t port, uint8_t pin);
void Invertir_Led(uint8_t port, uint8_t pin);

#endif /* LEDS_H_ */
