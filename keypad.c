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
    
    unsigned char i, k, key; 
    
    // initialize values 
    key=0; 
    k=1; 
    // turn all rows on and set all columns for input 
    P1=0xFF;                            

    for(i=1; i<=4; i++, k+=3){          // traverse all rows (matrix)
                                        // increment by 3 for next row keys    
        switch(i){                      // all rows ON at this point

            case 1:                     // turn row 1 OFF; all other rows ON
                P1^=0x01; 
                break; 

            case 2:                     // turn row 2 OFF; all other rows ON
                P1^=0x03; 
                break; 

            case 3:                     // turn row 3 OFF; all other rows ON
                P1^=0x06;  
                break; 
            
            case 4:                     // turn row 4 OFF; all other rows ON
                P1^=0x0C;
                break; 
        
        }

        if(!col1){                      // check when coln goes low 
            key=k+0;                    // pressed key on column 1 
            while(!col1) 
                ;                       // wait for key release
            return key; 
        }

        if(!col2){                       
            key=k+1;                    // pressed key on column 2 
            while(!col2) 
                ; 
            return key; 
        }

        if(!col3){  
            key=k+2;                    // pressed key on column 3 
            while(!col3) 
                ; 
            return key; 
        }
        
    }
    
    // return unsigned char max if no key pressed
    return 255; 

}


