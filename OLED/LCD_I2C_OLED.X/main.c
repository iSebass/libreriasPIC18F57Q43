
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "LCD_I2C_LIB.h"
#include "ssd1306_oled.h"


char buffer[50];

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    
    printf("Programa I2C LCD Iniciado \r\n");
    __delay_ms(1000);
    __delay_ms(1000);
    __delay_ms(1000);
    __delay_ms(1000);
    printf("Corriendo Main \r\n");
    
    I2C_LCD_Init();
    
    //I2C_LCD_Write_Text(1,2,"TEXTO");
    OLED_Init();                                // Inicializa la pantalla oled
    
    OLED_SetFont(FONT_2);
    OLED_Write_Text(30, 0, "VALOR POT");		// Texto inicial
    OLED_Rectangle(6, 20, 121, 63, WHITE);		// Dibuja un rectangulo
    OLED_Update();       

    while (1)
    {
        int valor_adc = ADCC_GetSingleConversion(POT1);
        sprintf(buffer, "%u ", valor_adc);
        OLED_SetFont(FONT_3);
        OLED_Write_Text(30, 26, buffer);
        
        if(valor_adc > 2800)
        {
            LED_INT_SetLow();
            OLED_SetFont(FONT_1);
            OLED_Write_Text(30, 50, "LED = ON ");
        }
        else
        {
            LED_INT_SetHigh();
            OLED_SetFont(FONT_1);
            OLED_Write_Text(30, 50, "LED = OFF");
        }
        OLED_Update();
        
        
        __delay_ms(500);
    }
}
/**
 End of File
*/