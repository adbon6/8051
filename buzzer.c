#include <reg51.h>

sbit BUZZER = P1^0;

void delay(unsigned int ms)
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
        delay(2000);
        BUZZER = 0;  // Buzzer is Switched ON
        delay(2000);
    }
}
