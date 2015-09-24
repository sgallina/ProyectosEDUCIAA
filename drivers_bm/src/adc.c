/*
 * adc.c
 *
 *  Created on: 24/9/2015
 *      Author: MarcosDario
 */
#include "adc.h"
#include "stdint.h"



void Configurar_Canal_ADC(uint8_t canal){

	switch(canal){
	 case 1:
		 	 Chip_SCU_ADC_Channel_Config(ADC0,canal);
		 	 break;
	 case 2:
		 	 Chip_SCU_ADC_Channel_Config(ADC0,canal);
		 	 break;
	 case 3:
		 	 Chip_SCU_ADC_Channel_Config(ADC0,canal);
		 	break;
	}

}

void Inicializar_ADC(uint8_t canal){

	ADC_CLOCK_SETUP_T ADC_CLKSetup;

	 ADC_CLKSetup.adcRate = ADC_MAX_SAMPLE_RATE;;
	 ADC_CLKSetup.bitsAccuracy = ADC_10BITS;
	 ADC_CLKSetup.burstMode = false;


 switch(canal){
	case 1:

			Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);

			Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH1 ,ENABLE);



		break;
	case 2:
			Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);

			Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH2,ENABLE);

			Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);
			break;

	case 3:
			Chip_ADC_Init(LPC_ADC0, &ADC_CLKSetup);

			Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH3,ENABLE);

			Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);
			break;

	}


}


int LeerADC(uint8_t canal){
	uint16_t dato;

	switch(canal){
	case 1:
				Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);

				while(Chip_ADC_ReadStatus(LPC_ADC0,ADC_CH1,ADC_DR_DONE_STAT) != SET);


				Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &dato);



			break;
	case 2:
				Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);

				while(Chip_ADC_ReadStatus(LPC_ADC0,ADC_CH2,ADC_DR_DONE_STAT) != SET);

				Chip_ADC_ReadValue(LPC_ADC0, ADC_CH2, &dato);


			break;
	case 3:
				Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);

				while(Chip_ADC_ReadStatus(LPC_ADC0,ADC_CH3,ADC_DR_DONE_STAT) != SET);

				Chip_ADC_ReadValue(LPC_ADC0, ADC_CH3, &dato);


			break;
	}

	return dato;
}
