#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./../char-lcd/charlcd.h"

int main()
{
    lcdInit();
    lcdSetDisplay(LCD_DISPLAY_ON);
    lcdSetCursor(LCD_CURSOR_OFF);

    const char str[] = "Hello World!";
    while(1) {
        lcdClear();
        _delay_ms(500);
        lcd_set_cursor_pos(0, 0);
        lcd_print_text(str);
        lcd_set_cursor_pos(1, 0);
        lcd_print_text(str);
        _delay_ms(500);
    }
}
