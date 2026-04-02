#include <reg51.h>

sbit LED = P1^0;

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);  
}

void main(void)
{
    while (1)
    {
        LED = 0;  // Switches the LED ON
        delay_ms(500);
        LED = 1;  // Switches the LED OFF
        delay_ms(500);
    }
}
