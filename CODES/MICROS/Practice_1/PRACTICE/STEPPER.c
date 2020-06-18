#include <avr/io.h>
#include <util/delay.h>  // We include the delay library
#define F_CPU 16000000UL

int main(void)
{
	/* We configure pins 0, 1, 2, 3, 7 (Of port address D) 
	as outputs -> DDDx = 1 */

	DDRD |= ((1 << DDD0) | (1 << DDD1) | (1 << DDD2));
	DDRD |= ((1 << DDD3) | (1 << DDD7));

	/* We configure pin 0 (Of port address B) as input with 
	pull-up DDB0 = 0 & PORTB0 = 1 */
	
	DDRB &= ~(1 << DDB0);
	PORTB |= (1 << PORTB0);
   
    while (1){
		// Clockwise turning
		
		if(PINB & (1 << PINB0)) {	
			PORTD = 0b10001010;
			_delay_ms(20);
			PORTD = 0b10001001;
			_delay_ms(20);
			PORTD = 0b10000101;
			_delay_ms(20);
			PORTD = 0b10000110;
			_delay_ms(20);					
		}
		
		// Counterclocwise turning
		else{		
			PORTD = 0b10000110;
			_delay_ms(20);
			PORTD = 0b10000101;
			_delay_ms(20);
			PORTD = 0b10001001;
			_delay_ms(20);
			PORTD = 0b10001010;
			_delay_ms(20);									
		}		
    }
}

