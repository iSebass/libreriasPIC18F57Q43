/* 
 * File:   PWM_LIB.h
 * Author: usuario
 *
 * Created on December 6, 2022, 11:41 AM
 */

#ifndef PWM_LIB_H
#define	PWM_LIB_H

#include <xc.h>
#include "CONFIG.h"

#define PRE128     7
#define PRE64      6
#define PRE32      5
#define PRE16      4
#define PRE8       3
#define PRE4       2
#define PRE2       1
#define PRE1       0

#define TMR2_PRE_SELECT  PRE64

void PWM1_Init(long freq);
void PWM2_Init(long freq);
void PWM3_Init(long freq);
void PWM1_Set_Duty(int duty);
void PWM2_Set_Duty(int duty);
void PWM3_Set_Duty(int duty);
void PWM1_Start(void);
void PWM1_Stop(void);


#endif	/* PWM_LIB_H */

