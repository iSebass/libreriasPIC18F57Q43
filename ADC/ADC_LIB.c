#include "ADC_LIB.h"


void ADC_Init(){
    ADCON2bits.MD   = _MODE; 
    ADCON0bits.FM   = JUSTIFY;
    ADCON0bits.CS   = CSVALUE;
    ADCON0bits.CONT = 0;
    ADREFbits.NREF  = _NREF;
    ADREFbits.PREF  = _PREF;
    ADCON0bits.ON = 1;
}

uint16_t ADC_Read(uint8_t ch){
    ADPCH = ch;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO==1);
    return( (uint16_t)( (ADRESH<<8) | ADRESL  ) );
}
