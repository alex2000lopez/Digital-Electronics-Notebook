#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/eeprom.h> 
#include <util/delay.h> 
// #include <stdint.h> Not needed 
#include "lcd.h" 
#include "keypad3x4.h"

// Reserves an array of 3 bits, called "code" in the EEPROM

uint8_t EEMEM pass[3];

int main(void)
{
	// Assigns the value 123 to the constant password

	char password[3] = "123";
		
	/* The variable password is written in the memory address associated 
	to code */

	eeprom_write_byte(&pass[0], password[0]);
	eeprom_write_byte(&pass[1], password[1]);
	eeprom_write_byte(&pass[2], password[2]);

	// Sets PC0 as output

	DDRC |= (1<<DDC0); /* Pin PC0 as output */
		
	/* Initialization of display
	   Display on, cursor off */

	lcd_init(LCD_DISP_ON); 

	char key;
	char keyarr[3];
	char dumpeeprom[3];
		
    while (1) 
    {
		
		lcd_clrscr(); //Clear display and set cursor to home position (0,0)
		lcd_puts("Digit:");
					
		int i=0;

		/* Reads the introduced password and stores it into an array 
		called keyarr. */

		while(i<3){
			
			key = GetKeyPressed(); //Get the keycode of pressed key
						
			if (key != 0XFF) { //No key press: No display
							
				lcd_gotoxy(0,1); //Set cursor to second line
				lcd_putc(key); //Display Key
				keyarr[i] = key; //Save Key pressed
				i++;
			}
						
			_delay_ms(300);
						
		}
		
		
		// Dumps the contents of the EEPROM into an arrays called dumpeeprom. 
		
		for(int i=0; i<3; i++){
			
			dumpeeprom[i] = eeprom_read_byte(&pass[i]);
			
		}
		
		// Checks that whether the password is correct or not.
	
		if(dumpeeprom[0] == keyarr[0] && dumpeeprom[1] == keyarr[1] 
		   && dumpeeprom[2] == keyarr[2]){
			
			lcd_clrscr(); //Clear display and set cursor to (0,0)
			lcd_puts("CORRECT");
						
			PORTC |= (1 << PORTC0);
			_delay_ms(1000);
			PORTC &= ~(1 << PORTC0);
			
		}
		else{
			
			lcd_clrscr(); //Clear display and set cursor to (0,0)
			lcd_puts("INCORRECT");
			PORTC &= ~(1 << PORTC0);
			_delay_ms(1000);
			
		}	
	}
}

