#define F_CPU16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <7SEG_HC595.h>

float ADCvalue_vol;
uint8_t ones, tenth, hundredth;
uint16_t disp_hu, disp_te, disp_on;


int main(void)
{
	ADMUX  |= (1<<REFS0);             // use AVccas the reference
	ADMUX  |= (1<<MUX2);			  // Set address pin to ADC4 (0100)
	ADCSRA |= (1<<ADATE);             // Set ADC Auto Trigger
	
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1)|(1<<ADPS0);   // 128 prescale for 16Mhz
	ADCSRA |= (1<<ADEN);              // Enable the ADC
	ADCSRA |= (1<<ADIE);              // EnableInterrupts
	
	
	sei();
	ADCSRA |=(1<<ADSC);               // Start the ADC conversion
	
	HC595Init();                      //Initialize HC595 system
	
	while(1)
	{
		/* Extract the float ones */
		ones=(unsigned int)(ADCvalue_vol*10)%10; 

		/* Convert the ones into 7-segment common anode code */ 
		ones=led_pattern[ones]; 


		/* Extract the float tenth */									
		tenth=(unsigned long int)(ADCvalue_vol*100)%10; 

		/* Convert the tenth into 7-segment common anode code */
		tenth=led_pattern[tenth]; 
		

		/* Extract the float hundredth */
		hundredth=(unsigned long int)(ADCvalue_vol*1000)%10;

		/* Convert the hundredth into 7-segment common anode code */
		hundredth=led_pattern[hundredth]; 
		
		/*Form a word with the high part for the data and the low
		 for the display */

		disp_on=((ones<<8)|0x02);
		disp_te=((tenth<<8)|0x04);
		disp_hu=((hundredth<<8)|0x08);
		
		HC595Write(0X7F04);		/* Point ones */
		HC595Write(disp_on);	/* Write the ones data to HC595 */
		HC595Write(disp_te);	/* Write the tenth data to HC595 */
		HC595Write(disp_hu);	/* Write the hundredthdata to HC595 */
		HC595Write(0XFF01);		/* thousands off */
		
	}
}

ISR(ADC_vect){
	
	ADCvalue_vol=(ADCW*5.0)/1024.0; /* Calculate the input voltage 
									   from the ADC reading*/
}