int main(void){
    /* Sets the direction register of the PORTB on 0xff 
    (all pins as output): */
    DDRB = 0xFF; 
    /* PORTB sets remaining on 0x03, bit 0 and 1 “high”, “low”: */
    PORTB = 0x03;
...}