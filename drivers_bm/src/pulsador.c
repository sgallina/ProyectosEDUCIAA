/*
 * pulsador.c
 *
 *  Created on: 22/9/2015
 *      Author: SHG
 */
#include "pulsador.h"
#include "stdint.h"
#include "chip.h"


void Inicializar_Pulsador(void){

	Chip_GPIO_Init(LPC_GPIO_PORT);

	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_0 en GPIO 0[4], SW1 */
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_1 en GPIO 0[8], SW2 */
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_2 en GPIO 0[9], SW3 */
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_6 en GPIO 1[9], SW4 */


	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 4, ENTRADA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 8, ENTRADA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 9, ENTRADA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, 9, ENTRADA);

}


bool Estado_Pulsador(uint8_t puerto, uint8_t pulsador){

	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, puerto, pulsador);

}





