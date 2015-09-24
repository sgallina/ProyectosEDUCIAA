/* Copyright 2015, Ejercicio 1 de HM
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "Proyecto3.h"       /* <= own header */



#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

uint8_t contadorled=1;
uint8_t puerto0=0, puerto1=1, incremento=10;
uint32_t MAXDAC = 900, MAXvalorDAC = 900, Valor_DAC = 0;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void ISRsalidaanalogica(void){
	/* Encender_Led(puerto0, LED1);
	 Encender_Led(puerto1, LED2);
	 Encender_Led(puerto1, LED3);
    */
	limpiarinterrpTimer();

	Actualizar_ValorDAC(Valor_DAC);

	if (Valor_DAC <= MAXvalorDAC){
		Valor_DAC = Valor_DAC + incremento;
		Encender_Led(5, LEDR);
	}
	else{
		Valor_DAC = 0;
		Encender_Led(5, LEDB);
	}

}


int main(void)
{

	   Inicializar_Led();
	   /* apaga todos los leds */
	   Apagar_Led(puerto0, LED1);
	   Apagar_Led(puerto1, LED2);
	   Apagar_Led(puerto1, LED3);

	   Inicializar_Pulsador();

	   InicializarTimer(1, 11);

	   Configuracion_DAC();
	   Inicializar_DAC();

	   while(1){

           /* leo el pulsador y cambio el valor maximo */

		   if(!Estado_Pulsador(puerto0, PULSADOR1)){
		 		   Encender_Led(puerto0, LED1);  /*velocidad nominal */
		 		  incremento = 10;
		 		   MAXvalorDAC = MAXDAC;
	 	      	   Apagar_Led(puerto1, LED2);
	 	      	   Apagar_Led(puerto1, LED3);
		   }

		 	if(!Estado_Pulsador(puerto0, PULSADOR2)){
		 	   	   Encender_Led(puerto1, LED2);    /*velocidad nominal + 25%*/
		 	   	   incremento = 15;
		 	   	   MAXvalorDAC = MAXDAC * 1.5;
		 	   	   Apagar_Led(puerto0, LED1);
	 	   		   Apagar_Led(puerto1, LED3);
		 	}

		 	if(!Estado_Pulsador(puerto0, PULSADOR3)){
		 	   	   Encender_Led(puerto1, LED3);   /*velocidad nominal - 25% */
		 	   	   incremento = 5;
		 	   	   MAXvalorDAC = MAXDAC * 0.5;
		 	       Apagar_Led(puerto0, LED1);
		 	       Apagar_Led(puerto1, LED2);
		 	}

       }

       return 0;

}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

