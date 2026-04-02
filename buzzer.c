#include <reg51.h>

sbit BUZZER = P1^0;

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
        BUZZER = 1;  // Buzzer is Switched OFF
        delay_ms(2000);
        BUZZER = 0;  // Buzzer is Switched ON
        delay_ms(2000);
    }
}
