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
#include "Proyecto1.h"       /* <= own header */



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

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



int main(void)
{
   uint8_t puerto0, puerto1;
   puerto0 = 0;
   puerto1 = 1;

   Inicializar_Pulsador();

   Inicializar_Led();
   /* apaga todos los leds */
   //Encender_Led(puerto0, LED1);
   Apagar_Led(puerto0, LED1);
   Apagar_Led(puerto1, LED2);
   Apagar_Led(puerto1, LED3);

   /* perform the needed initialization here */
   int i, j;

   while(1){

	   /* consultar pulsador */
	   if(!Estado_Pulsador(puerto0, PULSADOR1)){
		   Encender_Led(puerto0, LED1);
	   }
	   else{
		   Apagar_Led(puerto0, LED1);
	   }

	   if(!Estado_Pulsador(puerto0, PULSADOR2)){
	   	   Encender_Led(puerto1, LED2);
	      }
	   else{
	   	   Apagar_Led(puerto1, LED2);
	      }

	   if(!Estado_Pulsador(puerto0, PULSADOR3)){
	   	   Encender_Led(puerto1, LED3);
	      }
	   else{
	   	   Apagar_Led(puerto1, LED3);
	      }

	   if(!Estado_Pulsador(puerto1, PULSADOR4)){
	   	   	   Encender_Led(puerto0, LED1);
	   	   	   Encender_Led(puerto1, LED2);
	   	       Encender_Led(puerto1, LED3);
	   	      }
	   	   else{
	   	   	   Apagar_Led(puerto0, LED1);
	   	   	   Apagar_Led(puerto1, LED2);
	   	       Apagar_Led(puerto1, LED3);
	   	      }

	   /* si dos teclas teclas pulsadas -  partapadea */

	    if(!Estado_Pulsador(puerto0, PULSADOR1) & !Estado_Pulsador(puerto0, PULSADOR2)){
	           for(i=0;i<10;i++){
                   Invertir_Led(puerto0, LED1);
                   for(j=0;j<10000000;j++);
	        }
	     }


}

         return 0;


}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

