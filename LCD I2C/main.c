#include <xc.h>
#include "config.h"
#include "I2C_LIB.h"
#include "I2C_LCD.h"


char contador;

void main(void){
    
    ClockInit();
    I2C1_Initialize();
    PinInit();
    
    i2c_lcd_init();
    
    i2c_lcd_puts("iSebas");
    
    while(1){
        
        contador++;
        contador = contador > 15 ? 0 : contador;
        LED_Toggle();
        __delay_ms(200);
    }
    
    return;
}
