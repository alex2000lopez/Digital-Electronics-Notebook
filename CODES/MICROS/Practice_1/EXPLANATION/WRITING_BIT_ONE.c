#define MyBIT 2
...
PORTA |= (1 << MyBIT); /* Sets bit 2 at PortA on 1 */
PORTA &= ~(1 << MyBIT); /* Deletes bit 2 at PortA */