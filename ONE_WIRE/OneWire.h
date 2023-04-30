#define ONEWIRE_PORT PORTBbits.RB0
#define ONEWIRE_TRIS TRISBbits.TRISB0

ONEWIRE_TRIS = 0; //Configuramos el pin como salida


void OneWire_Init(void);
void OneWire_WriteBit(unsigned char bit);
void OneWire_WriteBit(unsigned char bit);
unsigned char OneWire_ReadBit(void);
void OneWire_WriteByte(unsigned char byte);
unsigned char OneWire_ReadByte(void);
unsigned char OneWire_Search(unsigned char *address);