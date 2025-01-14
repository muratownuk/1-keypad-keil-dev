#ifndef _C8051F005_INIT_H_
    #define _C8051F005_INIT_H_
    
    #define OFF 0
    #define ON  1
    #define SYSCLK 16000000                         // chip operating freq.              

    #ifdef _C8051F005_INIT_C_
        // function prototypes (for local)
        void vWatchdog(bit status);
        void vOSC_Init(void);
        void vPort_Init(void);
        
    #else
        // function prototypes (for external)
        extern void vWatchdog(bit status);
        extern void vOSC_Init(void);
        extern void vPort_Init(void);

    #endif


#endif

