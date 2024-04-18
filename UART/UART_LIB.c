#include "UART.h"

void UART1_Init(void){
    //
    U1RXB = 0x0; 
    //RXCHK disabled; 
    U1RXCHK = 0x0; 
    //TXB disabled; 
    U1TXB = 0x0; 
    //TXCHK disabled; 
    U1TXCHK = 0x0; 
    //P1L 0x0; 
    U1P1L = 0x0; 
    //P1H 0x0; 
    U1P1H = 0x0; 
    //P2L 0x0; 
    U1P2L = 0x0; 
    //P2H 0x0; 
    U1P2H = 0x0; 
    //P3L 0x0; 
    U1P3L = 0x0; 
    //P3H 0x0; 
    U1P3H = 0x0;
 
#ifdef HIGHSPEED
    //MODE Asynchronous 8-bit mode; RXEN enabled; TXEN enabled; ABDEN disabled; BRGS high speed
    U1CON0 = 0xB0;
#endif
    
#ifdef LOWSPEED
    U1CON0 = 0x30;
#endif

    //SENDB disabled; BRKOVR disabled; RXBIMD Set RXBKIF on rising RX input; WUE disabled; ON enabled; 
    U1CON1 = 0x80;
    
    //FLO off; TXPOL not inverted; C0EN Add all TX and RX characters; STP Transmit 1Stop bit, receiver verifies first Stop bit; RXPOL not inverted; RUNOVF RX input shifter stops all activity; 
    U1CON2 = 0x8; 
    
    //SET BAUDRATE 
    U1BRGH = (VALBRGH & 0xFF00)>>8;
    U1BRGL = (VALBRGH & 0x00FF)>>0;
    
    //TXBE empty; STPMD in middle of first Stop bit; TXWRE No error; 
    U1FIFO = 0x2E; 
    //ABDIE disabled; ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; 
    U1UIR = 0x0; 
    //TXCIF equal; RXFOIF not overflowed; RXBKIF No Break detected; FERIF no error; CERIF No Checksum error; ABDOVF Not overflowed; PERIF no parity error; TXMTIF empty; 
    U1ERRIR = 0x80; 
    //TXCIE disabled; RXFOIE disabled; RXBKIE disabled; FERIE disabled; CERIE disabled; ABDOVE disabled; PERIE disabled; TXMTIE disabled; 
    U1ERRIE = 0x0;
    
    //Pines para data visualizer opcional    
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
