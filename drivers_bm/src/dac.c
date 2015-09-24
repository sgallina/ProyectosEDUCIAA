/*
 * dac.c
 *
 *  Created on: 23/9/2015
 *      Author: MarcosDario
 */
#include "dac.h"
#include "stdint.h"
#include "chip.h"
#include "ciaaPOSIX_stdbool.h"

void Configuracion_DAC(void){

	Chip_SCU_DAC_Analog_Config();
}

void Inicializar_DAC(void){

	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_DMA_ENA);
}

void Actualizar_ValorDAC(uint32_t valor_DAC){

	Chip_DAC_UpdateValue(LPC_DAC, valor_DAC);
}
