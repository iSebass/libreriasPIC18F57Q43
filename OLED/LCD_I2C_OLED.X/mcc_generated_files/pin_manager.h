/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT1 aliases
#define POT1_TRIS                 TRISAbits.TRISA0
#define POT1_LAT                  LATAbits.LATA0
#define POT1_PORT                 PORTAbits.RA0
#define POT1_WPU                  WPUAbits.WPUA0
#define POT1_OD                   ODCONAbits.ODCA0
#define POT1_ANS                  ANSELAbits.ANSELA0
#define POT1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT1_GetValue()           PORTAbits.RA0
#define POT1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POT1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POT1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT1_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define POT1_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set POT2 aliases
#define POT2_TRIS                 TRISAbits.TRISA1
#define POT2_LAT                  LATAbits.LATA1
#define POT2_PORT                 PORTAbits.RA1
#define POT2_WPU                  WPUAbits.WPUA1
#define POT2_OD                   ODCONAbits.ODCA1
#define POT2_ANS                  ANSELAbits.ANSELA1
#define POT2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT2_GetValue()           PORTAbits.RA1
#define POT2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define POT2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define POT2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define POT2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define POT2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define POT2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set POT3 aliases
#define POT3_TRIS                 TRISAbits.TRISA2
#define POT3_LAT                  LATAbits.LATA2
#define POT3_PORT                 PORTAbits.RA2
#define POT3_WPU                  WPUAbits.WPUA2
#define POT3_OD                   ODCONAbits.ODCA2
#define POT3_ANS                  ANSELAbits.ANSELA2
#define POT3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define POT3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define POT3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define POT3_GetValue()           PORTAbits.RA2
#define POT3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define POT3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define POT3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define POT3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define POT3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define POT3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define POT3_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define POT3_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSELF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set LED_INT aliases
#define LED_INT_TRIS                 TRISFbits.TRISF3
#define LED_INT_LAT                  LATFbits.LATF3
#define LED_INT_PORT                 PORTFbits.RF3
#define LED_INT_WPU                  WPUFbits.WPUF3
#define LED_INT_OD                   ODCONFbits.ODCF3
#define LED_INT_ANS                  ANSELFbits.ANSELF3
#define LED_INT_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define LED_INT_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define LED_INT_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define LED_INT_GetValue()           PORTFbits.RF3
#define LED_INT_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define LED_INT_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define LED_INT_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define LED_INT_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define LED_INT_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define LED_INT_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define LED_INT_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define LED_INT_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/