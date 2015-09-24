/*
 * uart.c
 *
 *  Created on: 24/9/2015
 *      Author: SHG
 */

#include "uart.h"
#include "stdint.h"
#include "chip.h"


char dato;

void configurarUART(void){
	Chip_SCU_PinMux(7,1, MD_PDN, FUNC6);
	Chip_SCU_PinMux(7, 2, MD_PLN | MD_ZI, FUNC6);
	Chip_UART_Init(LPC_USART2);
	Chip_UART_SetBaud(LPC_USART2, 115200);
	Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);
	Chip_UART_TXEnable(LPC_USART2);
}

int recibirUART(void){
	Chip_UART_ReadByte(LPC_USART2);
}

void enviarUART(char dato){
	Chip_UART_SendByte(LPC_USART2, dato);
}

