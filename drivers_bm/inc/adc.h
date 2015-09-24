/*
 * adc.h
 *
 *  Created on: 23/9/2015
 *      Author: SHG
 */

#include "stdint.h"
/*
#include "ciaaPOSIX_stdbool.h"
#include "chip.h"
*/
#define ADC0 0
#define ADC1 1
#define ADC_MAXIMO_MUESTRA   400000
#define ADC_BITS10         0
#define falso     0


#ifndef ADC_H_
#define ADC_H_

void configuracanalADC(uint32_t ADC_ID, uint8_t canaladc);

void initADC(uint8_t canaladc);

// void habilitacanalADC(LPC_ADC, ADC_CHANNEL_T canaladc, FunctionalState NewState);

// void selmodostartADC(LPC_ADC, ADC_START_MODE_T modoadc, ADC_EDGE_CFG_T EdgeOption);

void leerestadoADC(uint8_t canaladc);

void leervalorADC(uint8_t canaladc, uint16_t *data);


#endif /* ADC_H_ */
