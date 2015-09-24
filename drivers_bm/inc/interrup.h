/*
 * interrup.h
 *
 *  Created on: 22/9/2015
 *      Author: SHG
 */

#include "stdint.h"

#ifndef INTERRUP_H_
#define INTERRUP_H_

void InicializarTimer(uint32_t tiempo_ms, uint32_t myIRQ);

void limpiarinterrpTimer(void);

#endif /* INTERRUP_H_ */
