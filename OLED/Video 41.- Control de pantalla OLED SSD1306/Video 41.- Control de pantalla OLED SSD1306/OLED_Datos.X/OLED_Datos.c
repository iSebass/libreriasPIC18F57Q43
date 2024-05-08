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

#include "adc.h"                                // Libreria del adc
#include "i2c.h"                                // Libreria del protocolo i2c
#include "ssd1306_oled.h"                       // Libreria de la pantalla oled i2c

char buffer[20];

void main()
{
    ADC_Init(AN0_ANALOG);                       // Inicializa el adc
    TRISDbits.RD7 = 0;                          // Pin RD7 como salida
    LATDbits.LD7 = 0;
    I2C_Init_Master(I2C_400KHZ);                // Inicializa el protocolo i2c
    OLED_Init();                                // Inicializa la pantalla oled
    
    OLED_SetFont(FONT_2);
    OLED_Write_Text(30, 0, "Valor ADC");		// Texto inicial
    OLED_Rectangle(6, 20, 121, 63, WHITE);		// Dibuja un rectangulo
    OLED_Update();								// Muestra el contenido en la pantalla oled
    
    while(1)
    {
        int valor_adc = ADC_Read(0);
        sprintf(buffer, "%u ", valor_adc);
        OLED_SetFont(FONT_3);
        OLED_Write_Text(30, 26, buffer);
        
        if(valor_adc > 900)
        {
            LATDbits.LD7 = 1;
            OLED_SetFont(FONT_1);
            OLED_Write_Text(30, 50, "LED = ON ");
        }
        else
        {
            LATDbits.LD7 = 0;
            OLED_SetFont(FONT_1);
            OLED_Write_Text(30, 50, "LED = OFF");
        }
        OLED_Update();
    }
}