/*
    C8051F005_Init:
    This module contains the initialization routines for the device C8051F005
    for this project (keypad).
*/
#define _C8051F005_INIT_C_

#include <C8051F000.h>
#include "C8051F005_Init.h"


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
        return;                     // watchdog is enabled on power-on
    else{
        WDTCN=0xDE;                 // disable watchdog timer
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
    // todo

}

/*
    vPort_Init: 
    // todo

    parameters: none
    return    : none
*/
void vPort_Init(void){
    // todo

}






















































