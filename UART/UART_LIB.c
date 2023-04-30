#include "UART_LIB.h"

void UART1_Init(long baudrate){
    float params = BAUDRATEMODE == HIGHSPEED ? 4.0 : 16.0;
    
    U1BRG = (_XTAL_FREQ/(params*baudrate))-1;
    
    switch(BAUDRATEMODE){
        case HIGHSPEED: U1CON0bits.BRGS = 1; break;
        case LOWSPEED:  U1CON0bits.BRGS = 0; break;
    }
    
    ANSELF = 0x00;
    TRISFbits.TRISF0 = 0;
    TRISFbits.TRISF1 = 1;

    INTCON0bits.GIEH = 1;
    PIE4bits.U1RXIE  = 1;
    U1CON0bits.MODE  = 0;
    U1CON0bits.TXEN  = 1;
    U1CON0bits.RXEN  = 1;
    U1CON1bits.ON    = 1; 
    
    
    RF0PPS      = 0x20;
    U1RXPPS     = 0x29; 
    
    
}
void UART1_Write(char data){
    while(U1ERRIRbits.TXMTIF==0);
    U1TXB = data;
    
}
void UART1_Text(char *str){
    while(*str){
        UART1_Write(*str);
        str++;     
    }
}
void putch(char txData){
    UART1_Write(txData);
}

char UART1_Read(void){
    
    while(!PIR4bits.U1RXIF);
        return U1RXB;
}
char UART1_DATA_READY(void){
    return PIR4bits.U1RXIF;
}