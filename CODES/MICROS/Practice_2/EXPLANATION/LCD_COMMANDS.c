#include "lcd.h" // To include the library

lcd_init(uint8_t dispAttr); // Initialize display and select type of cursor.

/*  Parameters

dispAttr    LCD_DISP_OFF display off
            LCD_DISP_ON display on, cursor off
            LCD_DISP_ON_CURSOR display on, cursor on
            LCD_DISP_ON_CURSOR_BLINK display on, cursor on flashing

*/


lcd_gotoxy (uint8_t x, uint8_t y); // Set cursor to specified position.

/*  Parameters

x   horizontal position (0: left most position)
y   vertical position (0: first line)

*/


lcd_clrscr(); // Clear display and set cursor to home position.


lcd_puts(const char *s);

/*  Parameters

s   string to be displayed

*/