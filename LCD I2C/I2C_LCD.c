#include "I2C_LCD.h"
#include "config.h"
#include <stdint.h>

static uint8_t _lcd_params;
uint8_t word, statusLED=1;

void _write_nibble(uint8_t nibble);
void _send_byte(uint8_t value, uint8_t mode);
void PCF_Wr(uint8_t data);


void PCF_Wr(uint8_t data){
    if(statusLED==1) data |= (1<<_LCD_LED); else data &= ~(1<<_LCD_LED);
    I2C1_Write(0x27, data);
}



void _write_nibble(uint8_t nibble){
    if( (nibble & 0x01) == 0) word &= ~(1<<_LCD_D4); else word |= (1<<_LCD_D4);
    if( (nibble & 0x02) == 0) word &= ~(1<<_LCD_D5); else word |= (1<<_LCD_D5);
    if( (nibble & 0x04) == 0) word &= ~(1<<_LCD_D6); else word |= (1<<_LCD_D6);
    if( (nibble & 0x08) == 0) word &= ~(1<<_LCD_D7); else word |= (1<<_LCD_D7);
    
    word &= ~(1<<_LCD_EN); PCF_Wr(word);
    word |=  (1<<_LCD_EN); PCF_Wr(word);
    word &= ~(1<<_LCD_EN); PCF_Wr(word);
    
    __delay_us(300);
}

void  _send_byte(uint8_t value, uint8_t mode){
    
    switch(mode){
        case _COMMAND_: word &= ~(1<<_LCD_RS); break;
        case _DATA_:    word |=  (1<<_LCD_RS); break;
    }
    _write_nibble(value>>4);
    _write_nibble(value&0x0F);
}

void i2c_lcd_write(uint8_t letra){
    _send_byte(letra,_DATA_);
}
void i2c_lcd_command(uint8_t cmd){
    _send_byte(cmd,_COMMAND_);
}

void i2c_lcd_init(){

       
   
    __delay_ms(15);
    _write_nibble(0x03);
    __delay_ms(5);
    _write_nibble(0x03);
    __delay_us(100);
    _write_nibble(0x03);
    _write_nibble(0x02);
    
    i2c_lcd_command( _LCD_FUNTIONSET | _LCD_4BITMODE | _LCD_2LINE | _LCD_5x8DOTS );
    __delay_us(37);
    
    _lcd_params = _LCD_DISPLAY_ON | _LCD_CURSOR_ON | _LCD_BLINK_ON;
    i2c_lcd_command(_LCD_DISPLAYCONTROL | _lcd_params);
    __delay_us(37);
    
    i2c_lcd_command(_LCD_CLEARDISPLAY);
    __delay_ms(2);
}

 

void i2c_lcd_puts(char *str){
    while(*str){
        i2c_lcd_write(*str);
        str++;
    } 
}

void i2c_lcd_set_cursor(uint8_t row, uint8_t col){
	
	switch(row){
        case 1:  i2c_lcd_command(0x80+col-1); break;
        case 2:  i2c_lcd_command(0xC0+col-1); break;
        case 3:  i2c_lcd_command(0x94+col-1); break;
        case 4:  i2c_lcd_command(0xD4+col-1); break;
    }
}


void i2c_lcd_clear(void){
	i2c_lcd_command(_LCD_CLEARDISPLAY);
	_delay_ms(2);
}
void lcd_return_home(void){
	i2c_lcd_command(_LCD_RETURNHOME);
	_delay_ms(2);
}

void i2c_lcd_on(void){
	_lcd_params |=  _LCD_DISPLAY_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void lcd_off(void){
	_lcd_params &=  ~_LCD_DISPLAY_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_enable_blink(void){
	_lcd_params |= _LCD_BLINK_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void lcd_disable_blink(void){
	_lcd_params &= ~_LCD_BLINK_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_enable_cursor(void){
	_lcd_params |= _LCD_CURSOR_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}
void i2c_lcd_disable_cursor(void){
	_lcd_params &= ~_LCD_CURSOR_ON;
	i2c_lcd_command(_LCD_DISPLAYCONTROL |_lcd_params);
	_delay_us(37);
}

void i2c_lcd_scroll_left(void){
	 i2c_lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVELEFT);
	 _delay_us(37);
}
void i2c_lcd_scroll_right(void){
	 i2c_lcd_command(_LCD_CURSORDISPLAYSHIFT | _LCD_DISPLAY_SHIFT | _LCD_MOVERIGHT);
	 _delay_us(37);
}

void i2c_lcd_custom_char(uint8_t mem, uint8_t *charmap){
	i2c_lcd_command(_LCD_SET_CGRAM_ADDR |  ((mem&0x07)<<3) );
	for(uint8_t i=0; i<=7; i++){
		i2c_lcd_write(charmap[i]);
	}
	i2c_lcd_command(_LCD_SET_DDRAM_ADDR);
	_delay_us(37);
}
void i2c_lcd_out(char row, char col, char *str){
    i2c_lcd_set_cursor(row,col);
    while(*str){
        i2c_lcd_write(*str);
        str++;
    } 
    
}
void i2c_lcd_char(char row, char col, char letra){
    i2c_lcd_set_cursor(row,col);
    i2c_lcd_write(letra);
}
