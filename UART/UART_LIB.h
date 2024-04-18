/* 
 * File:   UART.h
 * Author: iSebas
 *
 * Created on 30 de marzo de 2024, 07:44 PM
 */

#ifndef UART_H
#define	UART_H


#include <stdint.h>
#include <xc.h>
#include <stdio.h>
#include "config.h"


#define BAUDRATE      9600
#define HIGHSPEED

#ifdef HIGHSPEED
    #define VALBRGH      (uint16_t)( (_XTAL_FREQ/ (4.0*BAUDRATE) )-1 )
#endif

#ifdef LOWSPEED
    #define VALBRGH      (uint16_t)( (_XTAL_FREQ/ (16.0*BAUDRATE) )-1 )
#endif
void UART1_Init(void);
void UART1_Write(char data);
void UART1_Text(char *str);
void putch(char txData);
char UART1_Read(void);
char UART1_DATA_READY(void);

#endif	/* UART1_H */

