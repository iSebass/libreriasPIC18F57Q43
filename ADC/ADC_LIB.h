
#ifndef ADC_LIB_H
#define	ADC_LIB_H


#include <xc.h>
#include <stdint.h>

#define ANA0              0
#define ANA1              1
#define ANA2              2
#define ANA3              3
#define ANA4              4
#define ANA5              5
#define ANA6              6
#define ANA7              7

#define ANB0              8
#define ANB1              9
#define ANB2              10
#define ANB3              11
#define ANB4              12
#define ANB5              13
#define ANB6              14
#define ANB7              15

#define ANC0              16
#define ANC1              17
#define ANC2              18
#define ANC3              19
#define ANC4              20
#define ANC5              21
#define ANC6              22
#define ANC7              23

#define AND0              24
#define AND1              25
#define AND2              26
#define AND3              27
#define AND4              28
#define AND5              29
#define AND6              30
#define AND7              31

#define ANE0              32
#define ANE1              33
#define ANE2              24

#define ANF0              40
#define ANF1              41
#define ANF2              42
#define ANF3              43
#define ANF4              44
#define ANF5              45
#define ANF6              46
#define ANF7              47

#define LOWPASS_FILTER    4
#define BURST_AVERAGE     3
#define AVERAGE           2
#define ACCUMULATED       1
#define _BASIC             0

#define RIGHT             1
#define LEFT              0

#define FOSC              0
#define ADCRC             1

#define AVSS              0
#define VDD               0
#define VREFP             2
#define VREFN             1
#define FVR               3

#define JUSTIFY           RIGHT
#define CSVALUE           ADCRC
#define _MODE              _BASIC

#define _NREF              AVSS
#define _PREF              VDD

void ADC_Init();
uint16_t ADC_Read(uint8_t ch);

#endif	/* ADC_LIB_H */

