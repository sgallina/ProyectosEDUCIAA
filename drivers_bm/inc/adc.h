/*
 * adc.h
 *
 *  Created on: 24/9/2015
 *      Author: MarcosDario
 */
#include "stdint.h"
#include "ciaaPOSIX_stdbool.h"
#include "chip.h"

#ifndef ADC_H_
#define ADC_H_


#define ADC0 0
#define ADC1 1
#define ADC_MAXIMO_MUESTRA	400000
#define ADC_BITS10			0
#define falso     0

void Configurar_Canal_ADC(uint8_t canal);
void Inicializar_ADC(uint8_t canal);
int LeerADC(uint8_t canal);
#endif /* ADC_H_ */
