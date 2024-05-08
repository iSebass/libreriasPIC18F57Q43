
#include "i2c_funtion.h"

void i2c_Start(void);
void i2c_data(uint8_t);
void i2c_ACK(void);
void i2c_Stop(void);

//void I2C2_Write1ByteRegister(i2c2_address_t address, uint8_t reg, uint8_t data)
//{
//    while(!I2C2_Open(address)); // sit here until we get the bus..
//    I2C2_SetDataCompleteCallback(wr1RegCompleteHandler,&data);
//    I2C2_SetBuffer(&reg,1);
//    I2C2_SetAddressNackCallback(NULL,NULL); //NACK polling?
//    I2C2_MasterWrite();
//    while(I2C2_BUSY == I2C2_Close()); // sit here until finished.
//}
