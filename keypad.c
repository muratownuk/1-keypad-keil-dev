/*
    keypad: 
    this routine handles reading of key press on the keypad. 
*/
#define _KEYPAD_C_

/*
    includes
*/
#include <c8051F000.h>
#include "keypad.h"

/*
    global variables
*/
sbit row1=P1^0;                         // rows are outputs
sbit row2=P1^1; 
sbit row3=P1^2; 
sbit row4=P1^3; 
sbit col1=P1^4;                         // columns are inputs
sbit col2=P1^5; 
sbit col3=P1^6; 

/*
    routines
*/
/*
    ucReadKeypad: 
    reads in the key pressed on keypad. 

    parameters: none
    return    : key
        unsigned char key: 
        the key pressed on keypad. 
*/
unsigned char ucReadKeypad(void){
    

}




















