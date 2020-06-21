/* Initialize HC595 system */

HC595Init();

/* To write data to the 4 7-seg displays we use the following command*/

HC595Write(var); // Where "var" is a variable of type uint16_t
