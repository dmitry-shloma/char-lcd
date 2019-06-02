#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "./../char-lcd/charlcd.h"

void lcd_clear()
{
    char buf[] = "                ";
    lcd_goto(0, 0);
    lcd_puts(buf);
    lcd_goto(0, 1);
    lcd_puts(buf);
}

int main()
{
    lcd_init();
    while(1) {
        lcd_clear();
        lcd_goto(0, 0);
        lcd_puts("Hello World!" );
        _delay_ms(1000);
        lcd_clear();
        lcd_goto(0, 1);
        lcd_puts("Hello World!" );
        _delay_ms(1000);
    }
    return 0;
}
