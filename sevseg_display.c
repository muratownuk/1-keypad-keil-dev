/*
    sevseg_display: 
    this module contains routines to display number/nothing on the 7-segment 
    display. 
*/
#define _SEVSEG_DISPLAY_C_

/*
    includes
*/
#include <c8051F000.h>
#include "sevseg_display.h"

/*
    routines
*/
/*
    vDisplayNumber: 
    displays the number on the 7-segemnt LED display. 

    parameters: number
        unsigned char number: 
        the number to display. 
    return    : none
*/
void vDisplayNumber(unsigned char number){

    switch(number){
        case 1: 
            P0=0x06; 
            break; 
        case 2: 
            P0=0x5B; 
            break; 
        case 3: 
            P0=0x4F; 
            break; 
        case 4: 
            P0=0x66; 
            break; 
        case 5: 
            P0=0x6D; 
            break; 
        case 6: 
            P0=0x7D; 
            break; 
        case 7: 
            P0=0x07; 
            break; 
        case 8: 
            P0=0x7F; 
            break; 
        case 9: 
            P0=0x6F; 
            break; 
        case 11:                        // '0' zero key 
            P0=0x3F; 
            break; 
        default:                        // show blank on '*' & '#' keys
            P0=0x00;  

    }

}





