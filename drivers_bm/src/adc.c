/*
 * adc.c
 *
 *  Created on: 23/9/2015
 *      Author: SHG
 */

#include "adc.h"
#include "stdint.h"
#include "chip.h"
#include "ciaaPOSIX_stdbool.h"

void configuracanalADC(uint32_t ADC_ID, uint8_t canaladc){
	switch(canal){
	    case 1:
	           Chip_SCU_ADC_Channel_Config(ADC_ID, canaladc);
	           break;
	    case 2:
	           Chip_SCU_ADC_Channel_Config(ADC_ID, canaladc);
	           break;
	    case 3:
	           Chip_SCU_ADC_Channel_Config(ADC_ID, canaladc);
	          break;
	}

}

void initADC(canaladc){

	  ADC_CLOCK_SETUP_T ADC_CLKSetup;
      /* esto puedo no definirlo y el soft lo toma por defecto */
	    ADC_CLKSetup.adcRate = ADC_MAXIMO_MUESTRA;
	    ADC_CLKSetup.bitsAccuracy = ADC_BITS10;
	    ADC_CLKSetup.burstMode = falso;

	 switch(canaladc){
	   case 1:
	         Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);
	         Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH1 ,ENABLE);
	         Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW ,ADC_TRIGGERMODE_RISING );
 	         break;
	   case 2:
	         Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);
	         Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH2,ENABLE);
	         Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW ,ADC_TRIGGERMODE_RISING );
	         break;
	   case 3:
	         Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);
	         Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH3, ENABLE);
	         Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW ,ADC_TRIGGERMODE_RISING );
	         break;
	   }

}

/*
void habilitacanalADC(LPC_CHANNEL_T canaladc, FunctionalState NewState){
	Chip_ADC_EnableChannel(LPC_ADC0, canaladc, NewState)
}

void selmodostartADC(LPC_ADC, ADC_START_MODE_T modoadc, ADC_EDGE_CFG_T EdgeOption){
	Chip_ADC_SetStartMode(LPC_ADC, modoadc, EdgeOption)
}
*/

uint8_t leerestadoADC(uint8_t canaladc){

	uint8_t new_estado = 0;

	switch(canaladc){
	   case 1:
		     new_estado = Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT);
		     break;
	   case 2:
	   		 new_estado = Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH2, ADC_DR_DONE_STAT);
	   		 break;
	   case 3 :
	         new_estado = Chip_ADC_ReadStatus(LPC_ADC1, ADC_CH3, ADC_DR_DONE_STAT);
	         break;
     }
	 return new_estado;

}

uint8_t  leervalorADC(uint8_t canaladc, uint16_t *nvodato){

     uint8_t resultado = 0;

     switch(canaladc){
     case 1:
         resultado = Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &nvodato);
         break;
     case 2:
    	 resultado = Chip_ADC_ReadValue(LPC_ADC0, ADC_CH2, &nvodato);
      }
     case 3:
    	 resultado = Chip_ADC_ReadValue(LPC_ADC0, ADC_CH2, &nvodato);
      }

     return resultado;
}
