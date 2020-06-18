/* Implements action, if bit No. 1 (the “second” bit) is set in PINC (1) */
if ( PINC & (1<<PINC1) ) {
/* action */}

/* Implements action, if bit No. 2 (the “third” bit) is deleted in PINB (0) */
if ( !(PINB & (1<<PINB2)) ) {
/* action */}