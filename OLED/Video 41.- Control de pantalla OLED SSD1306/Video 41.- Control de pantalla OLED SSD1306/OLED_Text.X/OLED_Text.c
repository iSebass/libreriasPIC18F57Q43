#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>

#include "i2c.h"                                // Libreria del protocolo i2c
#include "ssd1306_oled.h"                       // Libreria de la pantalla oled i2c

void main()
{
    ADCON1bits.PCFG = 0x0F;                     // Coloca todos los pines como digitales
    I2C_Init_Master(I2C_400KHZ);                // Inicializa el protocolo i2c
    OLED_Init();                                // Inicializa la pantalla oled
    
    while(1)
    {
        OLED_SetFont(FONT_1);
        OLED_Write_Text(16, 10, "OLED I2C SSD1306");
        OLED_Update();
        __delay_ms(1500);
        
        OLED_SetFont(FONT_2);
        OLED_Write_Text(10, 20, "Con PIC18F4550");
        OLED_Update();
        __delay_ms(1500);
        
        OLED_SetFont(FONT_3);
        OLED_Write_Text(40, 40, "XC8");
        OLED_Update();
        __delay_ms(1500);
        
        OLED_ClearDisplay();
        OLED_Update();
        __delay_ms(500);
    }
}