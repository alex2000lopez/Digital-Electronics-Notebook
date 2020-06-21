#include <avr/eeprom.h> // To include the library

uint8_t EEMEM yourVar[n]; // Allocate an n-bit array in the EEPROM

/****************************************************************************
                                WRITING OPERATION
****************************************************************************/ 
/* The basic command to perform a writing operation is */

eeprom_write_byte(arg_1, arg_2);

/*  Where:

arg_1 -> ADDRESS (NOT variable) in the EEPROM where the value is going to be 
         stored. To obtain the address of a variable we put a & before the 
         variable:

arg_2 -> Value to be stored.

An example of this might be:

eeprom_write_byte(&yourVar, value); /* To write the value "value" into the 
                                       EEPROM variable "yourVar" */
*/

/****************************************************************************
                                READING OPERATION
****************************************************************************/ 

value = eeprom_read_byte(&yourVar); // To read the value from the EEPROM

// The variables are bytes, so uint8_t and char can be used as variables