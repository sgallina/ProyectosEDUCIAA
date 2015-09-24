/*
 * leds.c
 *
 *  Created on: 21/9/2015
 *      Author: MarcosDario
 */
#include "leds.h"
#include "stdint.h"
#include "chip.h"
//#include "Proyecto1.h"



void Inicializar_Led(void){

	Chip_GPIO_Init(LPC_GPIO_PORT);

	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); /* remapea P2_1 en GPIO5[1], LED0G y habilita el pull up */
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); /* remapea P2_2 en GPIO5[2], LED0B y habilita el pull up */
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* remapea P2_10 en GPIO0[14], LED1 y habilita el pull up */
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* remapea P2_11 en GPIO1[11], LED2 y habilita el pull up */
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* remapea P2_12 en GPIO1[12], LED3 y habilita el pull up */

	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, 0, SALIDA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, 1, SALIDA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, 2, SALIDA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 14, SALIDA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, 11, SALIDA);
	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, 12, SALIDA);

}


void Encender_Led(uint8_t port, uint8_t pin){

	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, port, pin);

}

void Apagar_Led(uint8_t port, uint8_t pin){

	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, port, pin);
}

void Invertir_Led(uint8_t port, uint8_t pin){

	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, port, pin);
}
