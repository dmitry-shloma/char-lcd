#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./../libcharlcd/charlcd.h"

int main()
{
    lcd_init();
    lcd_set_display(LCD_DISPLAY_ON);
    lcd_set_cursor(LCD_CURSOR_OFF);

    const char str[] = "Hello World!";
    while(1) {
        lcd_clear();
        _delay_ms(500);
        lcd_set_cursor_pos(0, 0);
        lcd_print_text(str);
        lcd_set_cursor_pos(1, 0);
        lcd_print_text(str);
        _delay_ms(500);
    }
}
