

// PIC18F57Q43 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC = ECH    // External Oscillator Selection (EC (external clock) above 8 MHz)
#pragma config RSTOSC = HFINTOSC_64MHZ// Reset Oscillator Selection (HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1)

// CONFIG2
#pragma config CLKOUTEN = OFF   // Clock out Enable bit (CLKOUT function is disabled)
#pragma config PR1WAY = ON      // PRLOCKED One-Way Set Enable bit (PRLOCKED bit can be cleared and set only once)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)

// CONFIG3
#pragma config MCLRE = EXTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR )
#pragma config PWRTS = PWRT_OFF // Power-up timer selection bits (PWRT is disabled)
#pragma config MVECEN = ON      // Multi-vector enable bit (Multi-vector enabled, Vector table used for interrupts)
#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit (IVTLOCKED bit can be cleared and set only once)
#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (Low-Power BOR disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)

// CONFIG4
#pragma config BORV = VBOR_1P9  // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 1.9V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit (PPSLOCKED bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle)
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)

// CONFIG5
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)

// CONFIG6
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG7
#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
#pragma config DEBUG = ON       // Background Debugger (Background Debugger enabled)

// CONFIG8
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not Write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not Write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not Write protected)
#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)

// CONFIG10
#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "config.h"

void ClockInit(){
    //SELECCIONAMOS FRECUENCIA INTERNA DE 64 MHZ
    OSCFRQ = 0b1000;
    
    //SELECCIONAMOS HFINTOSC CON DIV 1
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0x0;
}


void PinInit(){
    
    //TODO EL PUERTO F COMO DIGITAL
    ANSELF = 0x00;
    
    //CONFIGURAMOS EL LED INTERNO PARA FUNCIONAMIENTO
    TRISFbits.TRISF3 = 0;
    
    //INICIAMOS EL LED EN UN ESTADO BAJO
    LATFbits.LATF3 = 1;
    
    
    /*
     * PARA EL BUS I2C   RC5= SCL, RC6=SDA
    */
    //CONFIGURAMOS LOS PINES COMO DIGITALES
    ANSELCbits.ANSELC5 = 0; 
    ANSELCbits.ANSELC6 = 0; 
    
    //CONFIGRUAMOS LOS PINES DE SALIDA
    TRISCbits.TRISC5   = 0; 
    TRISCbits.TRISC6   = 0;
    
    //DESHABILITAMOS PULL UP INTERNAS
    WPUCbits.WPUC5 = 0;
    WPUCbits.WPUC6 = 0;
    
    //AJUSTAMOS LAS SALIDAS I2C COMO BUS OPEN DRAIN (NECESITA RESISTENCIAS PULL UP EXTERNAS)
    ODCONCbits.ODCC5 = 1;
    ODCONCbits.ODCC6 = 1;
    
    //AJUSTAMOS LOS REGISTROS RXYI2C 
    RB1I2C = 0x00;
    RB2I2C = 0x00;
    RC3I2C = 0x00;
    RC4I2C = 0x00;
    
    //AJUSTAMOS LOS PPS PARA REMAPEAR LOS PINES I2C
    I2C1SDAPPS = 0x16;   //RC6->I2C1:SDA1;    
    RC5PPS     = 0x37;   //RC5->I2C1:SCL1;    
    RC6PPS     = 0x38;   //RC6->I2C1:SDA1;    
    I2C1SCLPPS = 0x15;   //RC5->I2C1:SCL1;
    
}
