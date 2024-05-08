
#ifndef I2C_FUNTION_H
#define	I2C_FUNTION_H

#include <xc.h> // include processor files - each processor file is guarded.  

void i2c_Start(void);
void i2c_data(uint8_t);
void i2c_ACK(void);
void i2c_Stop(void);

#endif	/* XC_HEADER_TEMPLATE_H */

