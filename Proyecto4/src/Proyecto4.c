/* Copyright 2015, Eduardo Filomena, Juan Manuel Reta
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
#include "Proyecto4.h"       /* <= own header */



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
void Titilar_Led(uint8_t led_num);
void Teclas(uint8_t pulsador);
void TeclasSW4(uint8_t pulsador);
void Led_Analogicos(void);

void Secuencias_LedIRQ(void);
uint8_t contador = 1;

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
   Inicializar_Led();
   Inicializar_Teclas();
   Configurar_Canal_ADC(1);
   Inicializar_ADC(1);



   /* perform the needed initialization here */

while(1){

Led_Analogicos();
}
         return 0;

}

void Led_Analogicos(void){
   int valor_dato = 0;

   valor_dato = LeerADC(1);

      if(valor_dato < 400 ){
            Encender_Led(LED1);

         }
      else {

         Apagar_Led(LED1);
      }
      if(valor_dato >=401 && valor_dato<= 800){
         Encender_Led(LED2);
      }
      else {
         Apagar_Led(LED2);
      }
      if (valor_dato > 800){

         Encender_Led(LED3);
      }
      else {
         Apagar_Led(LED3);
      }
}

void Secuencia_LedIRQ(void){

   if(contador == 1){
      Encender_Led(LEDR);
      Encender_Led(LEDG);
      Encender_Led(LEDB);

   }

   if(contador == 2){
      Encender_Led(LED1);
       Apagar_Led(LEDR);
       Apagar_Led(LEDG);
       Apagar_Led(LEDB);
   }

   if(contador == 3){
      Encender_Led(LED2);
      Apagar_Led(LED1);

   }
   if(contador == 4){
      Encender_Led(LED3);
      Apagar_Led(LED2);

   }
   if (contador == 5){
      Apagar_Led(LED3);

   }
   contador = contador +1;
   if (contador >5){
      contador = 1;
   }

   Clean_Timer();

}

void Titilar_Led(uint8_t led_num){
    int i;
   Invertir_Led(led_num);

      for(i=0;i<10000000;i++);

      Invertir_Led(led_num);

      for(i=0;i<10000000;i++);
}


void TeclasSW4(uint8_t pulsador){

   if(Presionar_TeclaRGB(pulsador) ==0){
            /*   Encender_Led(LEDR);
               Encender_Led(LEDG);
               Encender_Led(LEDB);
               }
               else{
               Apagar_Led(LEDR);
               Apagar_Led(LEDG);
               Apagar_Led(LEDB);*/
      Timer(350);
               }
   else{
      //Timer(250);
   }
}

void Teclas(uint8_t pulsador){

   switch(pulsador){
   case SW1:
            if(Presionar_Teclas(SW1) == 0){

               if(Leer_PuertoGPIO(PUERTO0, LED1)==0){
                  //Encender_Led(LED1);
                  Encender_Led(LEDR);
                  Encender_Led(LEDG);
                  Encender_Led(LEDB);
                  Apagar_Led(LED2);
                  Apagar_Led(LED3);
               }
                  if(Leer_PuertoGPIO(PUERTO1, LED2)==0){
                  //Encender_Led(LED2);
                  Encender_Led(LED1);
                  Apagar_Led(LED3);
                  Apagar_Led(LEDR);
                  Apagar_Led(LEDG);
                  Apagar_Led(LEDB);
                  }
                      if(Leer_PuertoGPIO(PUERTO1, LED3)==0){
                        //Encender_Led(LED3);
                        Encender_Led(LED2);
                        Apagar_Led(LED1);
                        Apagar_Led(LEDR);
                        Apagar_Led(LEDG);
                        Apagar_Led(LEDB);
                     }

            }

            else{

               //Timer(250);
               }
            break;
   case SW2:
            if(Presionar_Teclas(SW2) ==0){
               Encender_Led(LED2);
            }
            else{

            //   Apagar_Led(LED2);
            }
            break;
   case SW3:
            if(Presionar_Teclas(SW3) ==0){
               Timer(100);
            }
            else{
               //Timer(250);
            }

            break;


   }



}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

