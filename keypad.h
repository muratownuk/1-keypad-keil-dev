#ifndef _KEYPAD_H_
    #define _KEYPAD_H

    #define OFF 0
    #define ON  1

    #ifdef _KEYPAD_C_
        // function prototypes (for local)
        unsigned char ucReadKeypad(void);    
    
    #else
        // function prototypes (for external)
        extern unsigned char ucReadKeypad(void);
        
    #endif

#endif


