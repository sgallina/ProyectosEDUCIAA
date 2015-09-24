/*
 * dac.h
 *
 *  Created on: 23/9/2015
 *      Author: MarcosDario
 */

#include "stdint.h"

#ifndef DAC_H_
#define DAC_H_

void Configuracion_DAC(void);
void Inicializar_DAC(void);
void Actualizar_ValorDAC(uint32_t valor_dac);

#endif /* DAC_H_ */
