#include <reg51.h>

sbit BUZZER = P1^0;
sbit SWITCH = P1^5;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void main(void) {
    while (1) {
        if (SWITCH == 0) {
            BUZZER = 0; // BUZZER ON
        } else {
            BUZZER = 1; // BUZZER OFF
        }
    }
}
