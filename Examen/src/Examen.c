/* Copyright 2015, Examen
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
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "Examen.h"       /* <= own header */



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
char mensaje[9];
/*==================[internal functions declaration]=========================*/
int valor_dato = 0;
int mtipant=9;
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/


void ISRleeranalogica(void){
    Invertir_Led(puerto0, LED1);

    limpiarinterrpTimer();

    valor_dato = LeerADC(1);

}


void EnvioSalidaUART(int mtipomensaje){

	int x, m;
	const char mensaje0[9] ="Nominal";
	const char mensaje1[9] ="Aumenta";
	const char mensaje2[9] ="Reduce ";
	const char mensaje3[9] ="Mute...";
	switch(mtipomensaje){
    	case 0:
            for(x=0; x<8; x++){
            	enviarUART(mensaje0[x]);
            	for(m=0; m<100000; m++);
            }
    //		enviarUART('I');
    		break;
    	case 1:
            for(x=0; x<8; x++){
            	enviarUART(mensaje1[x]);
             	for(m=0; m<100000; m++);
            }
    	//	enviarUART('A');
    		break;
    	case 2:
            for(x=0; x<8; x++){
            	enviarUART(mensaje2[x]);
             	for(m=0; m<100000; m++);
            }
    //		enviarUART('D');
    		break;
    	case 3:
            for(x=0; x<8; x++){
            	enviarUART(mensaje3[x]);
             	for(m=0; m<100000; m++);
            }
    	//	enviarUART('M');
    		break;

       }

       //for(x=0; x<8; x++)  enviarUART(mensaje[x]);
	   enviarUART('\n');
	   enviarUART('\r');
}


int main(void)
{

      Inicializar_Led();
      
      Inicializar_Pulsador();



      Configuracion_DAC();
      Inicializar_DAC();

      Configurar_Canal_ADC(1);
      Inicializar_ADC(1);

      configurarUART();

      InicializarTimer(100, 11);

      float mFactor = 1;

      int mtipmj=0;
      EnvioSalidaUART(mtipmj);

      while(1){

    	  /* leo el pulsador y cambio el valor maximo */

    	  if(!Estado_Pulsador(puerto0, PULSADOR1)){
    		     Apagar_Led(5, LEDB);
    		     Encender_Led(5, LEDR);  /*velocidad nominal */
    		     Apagar_Led(5, LEDG);
    	 		 mFactor = 1.2;  // incrementa
    	 		 mtipmj = 1;
    	   	   EnvioSalidaUART(mtipmj);
    	  }

    	   if(!Estado_Pulsador(puerto0, PULSADOR2)){
    		    Apagar_Led(5, LEDR);
    		    Encender_Led(5, LEDB);
    		    Apagar_Led(5, LEDG);
    	 		mFactor = 0.8;
    	 		mtipmj = 2;  // disminuye
    		 	   EnvioSalidaUART(mtipmj);
    	   }

 	 	   if(!Estado_Pulsador(puerto0, PULSADOR3)){
 	 		 Apagar_Led(5, LEDR);
 	 		 Apagar_Led(5, LEDB);
  	 		 Apagar_Led(5, LEDG);
    		 mFactor = 0;
    		 mtipmj = 3;
  	 	   EnvioSalidaUART(mtipmj);  //"Mute.....");
 	 	   }

	 	   if(!Estado_Pulsador(puerto0, PULSADOR4)){
 	 		 Encender_Led(5, LEDG);
    		 mFactor = 1;
    		 mtipmj = 0;
  	 	   EnvioSalidaUART(mtipmj);  // restaura inicial
	 	   }



	 	  // for(x=0; x<10000; x++);

	 	  /* saco la salida analogica */
 	 	Valor_DAC = Valor_DAC * mFactor;
 	 	Actualizar_ValorDAC(Valor_DAC);


      }

       return 0;

}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

