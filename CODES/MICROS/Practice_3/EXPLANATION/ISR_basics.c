#include <avr/interrupt.h> /* To include the Interrupt header, which contains 
                            the functions for interrupt processing. */


sei();
/* The macro sei () switches on the interrupts (Sets the Interrupt Enable Bit 
in the SREG to 1). No other action is performed. */

cli();
/* The macro cli () switches the interrupts off (Sets the Interrupt Enable Bit 
in the SREG to 0). No other action is performed. */                


/* To define the ISR we use the following syntax */

ISR(interrupt vector name){
    //ISR code
}

/* The interrupt vector name can be found in the header file iom328p.h */