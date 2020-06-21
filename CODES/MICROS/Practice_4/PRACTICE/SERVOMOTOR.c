#define F_CPU16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>

float OCR0A_from_pot;

/* State Machine containing the possible system states */
enum state{

	pulse ,
	wait_1,
	wait_2	

} system_state;



int main(void)
{
	/* ADC Configuration*/
	
	ADMUX  |= (1<<REFS0);           /* Use AVccas the reference */
	ADMUX  |= (1<<MUX2);			/* Set address pin to ADC4 (0100) */
	ADCSRA |= (1<<ADATE);           /* Set ADC Auto Trigger */
	
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1)|(1<<ADPS0);  /* 128 prescaler for ADC */
	ADCSRA |= (1<<ADEN);            /* Enable the ADC */
	ADCSRA |= (1<<ADIE);            /* Enable Interrupts */
	

	/* Timer configuration */
	
	DDRB |= (1<<DDB5);           /* Set Pin 5 of Port B as output */
	TCCR0A |= (1 << WGM01);      /* Set the Timer Mode to CTC */
	OCR0A = 46;                  /* (Initial Value) Set the value that you want 
								    to count to  */
	TIMSK0 |= (1 << OCIE0A);     /* Set the ISR COMPA vect */
	
	sei();
	
	ADCSRA |=(1<<ADSC);          /* Start the ADC conversion */
	
	TCCR0B |= (1 << CS02);       /* (Initial Value) Set prescaler to 256 and
								     start the timer */
	
	system_state = pulse;		 /* Initial State */
	
	while(1)
	{
		/* No actions are performed in the main loop */			
	}
}

/* ADC Interrupt */

ISR(ADC_vect){

	OCR0A_from_pot = (ADCW*(94.0/1023.0)) + 46.0; /* For ADCW = 0 -> 46 
												  For ADCW = 1023 -> 140 */
}

/* Timer_0 Interrupt and FSM describing the output pulse */

ISR(TIMER0_COMPA_vect){
	
	switch(system_state){

		case pulse: /* Output a pulse with width defined by the ADC4 reading */
			OCR0A = (uint8_t)OCR0A_from_pot;
			
			TCCR0B |= (1 << CS02);
			TCCR0B &= ~((1 << CS00) | (1 << CS01));
			
			PORTB  |= (1<<PORTB5);
			
			system_state = wait_1;
			break;
		
		case wait_1: /* Output a 10ms LOW value */
			OCR0A = 156;
			TCCR0B |= ((1 << CS02) | (1 << CS00));
			TCCR0B &= ~((1 << CS01));
			PORTB  &= ~(1<<PORTB5);
			
			system_state = wait_2;
			break;
			
		case wait_2: /* Output a second 10ms LOW value */
					
			system_state = pulse;
			break;			
	}
}