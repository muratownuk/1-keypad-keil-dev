/*
    C8051F005_Init:
    This module contains the initialization routines for the device C8051F005
    for this project (keypad).
*/
#define _C8051F005_INIT_C_

/*
    includes
*/
#include <C8051F000.h>
#include "C8051F005_Init.h"

/*
    routines
*/
/*
    vWatchdog:
    turn watchdog timer ON or OFF.

    parameters: status
        bit status: 
        pass ON(1) or OFF(0) to keep watchdog ON or OFF, respectively. 
    return    : none
*/
void vWatchdog(bit status){
    
    if(status==ON)
        return;                         // watchdog is enabled on power-on
    else{
        WDTCN=0xDE;                     // disable watchdog timer
        WDTCN=0xAD;
    }

}

/*
    vOSC_Init:
    use internal oscillator (OSCICN) at 16MHz (SYSCLK) and turn off external
    oscillator (OSCXCN)

    parameters: none
    return    : none
*/
void vOSC_Init(void){
    
    // XOSCMD2-0=000 (off) and XFCN2-0=000 (default)
    OSCXCN&=~0x70; 
    // MSCLKE=1, CLKSL=0 (internal), IOSCEN=1 (default) and IFCN1-0=11 16MHz
    OSCICN|=0x83;                                    

}

/*
    vPort_Init: 
    enable cross-bar (XBARE in XBR2) for outputs and weak pull-ups. further
    configure P0.0-7 (port 0) as push-pull outputs and initialize outputs to 
    low. further configure P1.0-3 (port 1) as push-pull outputs and keep 
    outputs high (default); P1.4-7 are open-drain, make sure turn them high
    explicitly to make them input mode. 

    parameters: none
    return    : none
*/
void vPort_Init(void){
    
    // WEAKPUD=0 (weak pull-ups enabled), XBARE=1 (xbar enable for outputs)
    XBR2|=0x40; 
    // P0.0-7 output mode push-pull (7-seg. LEDs)
    PRT0CF|=0xFF; 
    // P1.0-3 output mode push-pull(rows), P1.4-7 output mode open-drain(cols)
    PRT1CF|=0x0F; 
    // toggle P0.0-7 (port 0) register low
    P0&=~0xFF;                          // only P0.0-6 will be used
    // toggle P1.0-3 (port 1) high (output), P1.4-7 high (input)
    P1|=0xFF; 

}

