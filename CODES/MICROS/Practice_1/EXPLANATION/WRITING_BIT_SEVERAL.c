DDRC &= ~((1<<PC0) | (1<<PC3) ); /* PC0 and PC3 as inputs */
PORTC |= (1<<PC0) | (1<<PC3); /* internal Pull UP for both switched on */


DDRB = 0x1F; /* direct assignment - unclearly */
DDRB = 0b00011111; /* direct assignment – Clearer */

/* more typing work though clearer: */
DDRB = ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3) | (1 << DDB4));