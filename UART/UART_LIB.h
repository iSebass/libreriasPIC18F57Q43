#ifndef UART_LIB_H
#define	UART_LIB_H

#include <stdint.h>
#include <xc.h>
#include <stdio.h>
#include "../config.h"


#define ASYNCHRONOUS8BITS                     0
#define ASYNCHRONOUS7BITS                     1
#define ASYNCHRONOUS8BITSWITH9_ODD_PARITY     2
#define ASYNCHRONOUS8BITSWITH9_EVENT_PARITY   3
#define ASYNCHRONOUS9BITS                     4
#define DALICONTROLDEVICE                     8
#define DALICONTROLGEAR                       9
#define DMX                                   10
#define LINCLIENTONLY                         11
#define LINHOST_CLIENT                        12

#define HIGHSPEED    1
#define LOWSPEED     0    

#define UART1_MODE   ASYNCHRONOUS8BITS  
#define BAUDRATEMODE HIGHSPEED


void UART1_Init(long baudrate);
void UART1_Write(char data);
void UART1_Text(char *str);
void putch(char txData);
char UART1_Read(void);
char UART1_DATA_READY(void);

#endif	/* UART_LIB_H */