#include <xc.h>
#include "CONFIG.h"
#include "PWM_LIB.h"

unsigned short duty_long_reg = 0;

void PWM1_Init(long freq){
    int valPre;
    
    switch(TMR2_PRE_SELECT){
        case PRE1:    valPre = 1;   break;
        case PRE2:    valPre = 2;   break;
        case PRE4:    valPre = 4;   break;
        case PRE8:    valPre = 8;   break;
        case PRE16:   valPre = 16;  break;
        case PRE32:   valPre = 32;  break;
        case PRE64:   valPre = 64;  break;
        case PRE128:  valPre = 128; break;
    }
    CCP1CONbits.FMT  = 0;
    CCP1CONbits.EN   = 1;
    CCP1CONbits.MODE = 0b1100;
    
    T2TMR  = 0;
    T2PR   = (unsigned char)(_XTAL_FREQ / (4.0*freq*valPre));
    CCPR1  = (unsigned short)(2.0*T2PR);
    
    CCPTMRS0bits.C1TSEL = 0b01;
    
    //Clear IF Timer2
    PIR3bits.TMR1IF = 0;
    
    T2CONbits.CKPS  = TMR2_PRE_SELECT;
    T2CONbits.OUTPS = 0;
    T2CONbits.ON    = 0;
    T2CLKCON        = 1;
    
    //Habilitar los pines para CCP1
    ANSELCbits.ANSELC2 = 0;
    TRISCbits.TRISC2   = 0;
    RC2PPS             = 0x15;
}

void PWM2_Init(long freq){
    int valPre;
    
    switch(TMR2_PRE_SELECT){
        case PRE1:    valPre = 1;   break;
        case PRE2:    valPre = 2;   break;
        case PRE4:    valPre = 4;   break;
        case PRE8:    valPre = 8;   break;
        case PRE16:   valPre = 16;  break;
        case PRE32:   valPre = 32;  break;
        case PRE64:   valPre = 64;  break;
        case PRE128:  valPre = 128; break;
    }
    CCP2CONbits.FMT  = 0;
    CCP2CONbits.EN   = 1;
    CCP2CONbits.MODE = 0b1100;
    
    T2TMR  = 0;
    T2PR   = (unsigned char)(_XTAL_FREQ / (4.0*freq*valPre));
    CCPR2  = (unsigned short)(4.0*T2PR);
    
    CCPTMRS0bits.C2TSEL = 0b01;
    
    //Clear IF Timer2
    PIR3bits.TMR1IF = 0;
    
    T2CONbits.CKPS  = TMR2_PRE_SELECT;
    T2CONbits.OUTPS = 0;
    T2CONbits.ON    = 0;
    T2CLKCON        = 1;
    
    //Habilitar los pines para CCP1
    ANSELCbits.ANSELC3 = 0;
    TRISCbits.TRISC3   = 0;
    RC3PPS             = 0x16;
}
void PWM3_Init(long freq){
    int valPre;
    
    switch(TMR2_PRE_SELECT){
        case PRE1:    valPre = 1;   break;
        case PRE2:    valPre = 2;   break;
        case PRE4:    valPre = 4;   break;
        case PRE8:    valPre = 8;   break;
        case PRE16:   valPre = 16;  break;
        case PRE32:   valPre = 32;  break;
        case PRE64:   valPre = 64;  break;
        case PRE128:  valPre = 128; break;
    }
    CCP3CONbits.FMT  = 0;
    CCP3CONbits.EN   = 1;
    CCP3CONbits.MODE = 0b1100;
    
    T2TMR  = 0;
    T2PR   = (unsigned char)(_XTAL_FREQ / (4.0*freq*valPre));
    CCPR3  = (unsigned short)(2.0*T2PR);
    
    CCPTMRS0bits.C3TSEL = 0b01;
    
    //Clear IF Timer2
    PIR3bits.TMR1IF = 0;
    
    T2CONbits.CKPS  = TMR2_PRE_SELECT;
    T2CONbits.OUTPS = 0;
    T2CONbits.ON    = 0;
    T2CLKCON        = 1;
    
    //Habilitar los pines para CCP1
    ANSELBbits.ANSELB2 = 0;
    TRISBbits.TRISB2   = 0;
    RB2PPS             = 0x17;
}

void PWM1_Set_Duty(int duty){
    CCPR1  = (unsigned short)( (duty/100.0)*4.0*T2PR);
}
void PWM2_Set_Duty(int duty){
    CCPR2  = (unsigned short)( (duty/100.0)*4.0*T2PR);
}
void PWM3_Set_Duty(int duty){
    CCPR3  = (unsigned short)( (duty/100.0)*4.0*T2PR);
}
void PWM1_Start(void){
    T2CONbits.ON    = 1;
    PWM1_Set_Duty(0);
    PWM2_Set_Duty(0);
    PWM3_Set_Duty(0);
}
void PWM1_Stop(void){
    T2CONbits.ON    = 0;
}

