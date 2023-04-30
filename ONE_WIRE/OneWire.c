#include "OneWire.h"

void OneWire_Init(void)
{
    ONEWIRE_PORT = 0;
    ONEWIRE_TRIS = 0;
    __delay_us(480);
    ONEWIRE_TRIS = 1;
    __delay_us(480);
}

void OneWire_WriteBit(unsigned char bit)
{
    ONEWIRE_PORT = 0;
    ONEWIRE_TRIS = 0;
    __delay_us(2);
    ONEWIRE_PORT = bit;
    __delay_us(60);
    ONEWIRE_PORT = 1;
}

void OneWire_WriteBit(unsigned char bit)
{
    ONEWIRE_PORT = 0;
    ONEWIRE_TRIS = 0;
    __delay_us(2);
    ONEWIRE_PORT = bit;
    __delay_us(60);
    ONEWIRE_PORT = 1;
}

unsigned char OneWire_ReadBit(void)
{
    unsigned char bit_value = 0;
    ONEWIRE_PORT = 0;
    ONEWIRE_TRIS = 0;
    __delay_us(2);
    ONEWIRE_TRIS = 1;
    __delay_us(15);
    if(ONEWIRE_PORT)
    {
        bit_value = 1;
    }
    __delay_us(45);
    return bit_value;
}

void OneWire_WriteByte(unsigned char byte)
{
    unsigned char i;
    for(i=0; i<8; i++)
    {
        OneWire_WriteBit((byte>>i) & 0x01);
    }
}

unsigned char OneWire_ReadByte(void)
{
    unsigned char byte_value = 0;
    unsigned char i;
    for(i=0; i<8; i++)
    {
        byte_value |= (OneWire_ReadBit() << i);
    }
    return byte_value;
}

unsigned char OneWire_Search(unsigned char *address)
{
    unsigned char bit_index = 0;
    unsigned char byte_index = 0;
    unsigned char bit_mask = 0x01;
    unsigned char last_zero = 0;
    unsigned char last_device = 0;
    unsigned char direction;
    unsigned char bit_value;
    OneWire_Init();
    OneWire_WriteByte(0xF0);
    do
    {
        direction = 0;
        bit_value = OneWire_ReadBit();
        if(OneWire_ReadBit())
        {
            if(bit_value)
            {
                return 0;
            }
        }
        else
        {
            if(!bit_value)
            {
                if(bit_index == last_zero)
                {
                    direction = 1;
                }
                else if(bit_index > last_zero)
                {
                    direction = 0;
                    last_device = 0;
                }
                else
                {
                    direction = ((address[byte_index] & bit_mask) > 0);
                }
                if(direction)
                {
                    address[byte_index] |= bit_mask;
                }
                else
                {
                    address[byte_index] &= ~bit_mask;
                }
                OneWire_WriteBit(direction);
                last_zero = bit_index;
            }
            else
            {
                if(bit_index == last_zero)
                {
                    return 0;
                }
            }
            bit_index++;
            if(bit_index == 8)
            {
                bit_index = 0;
                byte_index++;
                bit_mask = 0x01;
            }
            else
            {
                bit_mask <<= 1;
            }
        }
    } while(byte_index < 8);
    return 1;
}