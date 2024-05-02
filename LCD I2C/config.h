/* 
 * File:   config.h
 * Author: iProf
 *
 * Created on May 1, 2024, 9:00 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#define _XTAL_FREQ 64000000UL


#define LED_Toggle()  LATFbits.LATF3 ^=1

void ClockInit();
void PinInit();

#endif	/* CONFIG_H */

