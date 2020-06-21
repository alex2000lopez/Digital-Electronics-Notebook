#include "keypad3x4.h" // To include the library

GetKeyPressed(); // Get the char keycode of pressed key

/*******************************************************
Function returns the keycode of key pressed on the Keypad.

       KEYPAD  Membrane
COL1 ->  PD0  -> PD2
COL2 ->  PD1  -> PD1
COL3 ->  PD2  -> PD0
ROW1 ->  PD3  -> PD6
ROW2 ->  PD4  -> PD5
ROW3 ->  PD5  -> PD4
ROW4 ->  PD6  -> PD3

Return:
[1] [2] [3]
[4] [5] [6]
[7] [8] [9]
[*] [0] [#]

255 (hex 0xFF) if NO key pressed.
*******************************************/