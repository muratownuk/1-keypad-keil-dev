/*
    keypad_main:
    this is the module where the main routine starts. 
*/
/*
    includes
*/
#include "C8051F005_Init.h"
#include "keypad.h"
#include "sevseg_display.h"

/*
    main routine
*/
void main(void){

    unsigned char pressed_key=0;

    // initialize device
    vWatchdog(OFF);
    vOSC_Init();
    vPort_Init();

    while(1){ // forever loop

        pressed_key=ucReadKeypad();

        if(pressed_key!=255){
            vDisplayNumber(pressed_key);
        }

    } 

}





