/*
 * uart.h
 *
 *  Created on: 24/9/2015
 *      Author: SHG
 */

#include "stdint.h"

#ifndef UART_H_
#define UART_H_


void configurarUART(void);
int recibirUART(void);
void enviarUART(char);

#endif /* UART_H_ */
