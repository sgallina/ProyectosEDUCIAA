/*
 * interrup.c
 *
 *  Created on: 22/9/2015
 *      Author: SHG
 */


#include "interrup.h"
#include "stdint.h"
#include "chip.h"


void InicializarTimer(uint32_t tiempo_ms, uint32_t myIRQ){
	NVIC_EnableIRQ(myIRQ);
	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_SetTimerInterval(LPC_RITIMER, tiempo_ms);

}


void limpiarinterrpTimer(void){
	Chip_RIT_ClearInt(LPC_RITIMER);
}
