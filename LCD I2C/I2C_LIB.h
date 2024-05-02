
#ifndef I2C1_MASTER_H
#define I2C1_MASTER_H


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    I2C1_NOERR, // The message was sent.
    I2C1_BUSY,  // Message was not sent, bus was busy.
    I2C1_FAIL   // Message was not sent, bus failure
               // If you are interested in the failure reason,
               // Sit on the event call-backs.
} i2c1_error_t;

typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} i2c1_operations_t;

typedef uint8_t i2c1_address_t;
typedef i2c1_operations_t (*i2c1_callback_t)(void *funPtr);

// common callback responses
i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr);
i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr);

/**
 * \brief Initialize I2C1 interface
 *
 * \return Nothing
 */
void I2C1_Initialize(void);

/**
 * \brief Open the I2C1 for communication
 *
 * \param[in] address The slave address to use in the transfer
 *
 * \return Initialization status.
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_Open(i2c1_address_t address);

/**
 * \brief Close the I2C1 interface
 *
 * \return Status of close operation.
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_Close(void);

/**
 * \brief Start an operation on an opened I2C1 interface
 *
 * \param[in] read Set to true for read, false for write
 *
 * \return Status of operation
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_MasterOperation(bool read);

/**
 * \brief Identical to I2C1_MasterOperation(false);
 */
i2c1_error_t I2C1_MasterWrite(void); // to be depreciated

/**
 * \brief Identical to I2C1_MasterOperation(true);
 */
i2c1_error_t I2C1_MasterRead(void); // to be depreciated

/**
 * \brief Set timeout to be used for I2C1 operations. Uses the Timeout driver.
 *
 * \param[in] to Timeout in ticks
 *
 * \return Nothing
 */
void I2C1_SetTimeout(uint8_t timeOut);

/**
 * \brief Sets up the data buffer to use, and number of bytes to transfer
 *
 * \param[in] buffer Pointer to data buffer to use for read or write data
 * \param[in] bufferSize Number of bytes to read or write from slave
 *
 * \return Nothing
 */
void I2C1_SetBuffer(void *buffer, size_t bufferSize);

// Event Callback functions.

/**
 * \brief Set callback to be called when all specifed data has been transferred.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there has been a bus collision and arbitration was lost.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted address was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted data was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there was a bus timeout.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr);

/**********************************************************************/
/*    METODOS DE USUARIO SACADOS DE LOS EJEMPLOS DE MCC CLASSIC       */
/**********************************************************************/
uint8_t  I2C1_Read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t I2C1_Read2ByteRegister(i2c1_address_t address, uint8_t reg);
void I2C1_Write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void I2C1_Write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);
void I2C1_WriteNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadDataBlock(i2c1_address_t address, uint8_t reg, uint8_t *data, size_t len);

//METODO PROPIO PARA PROBAR PCF
void I2C1_Write(i2c1_address_t address, uint8_t data);




#endif //I2C1_MASTER_H

