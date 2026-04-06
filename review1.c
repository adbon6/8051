#include <reg51.h>

sbit LED1 = P1^0;
sbit SWITCH1 = P1^5;
sbit LED2 = P1^1;
sbit SWITCH2 = P1^6;
sbit SWITCH3 = P1^7;

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void main(void) {
    while (1) {
        if (SWITCH1 == 0) {
            LED1 = 0; 
        } else {
            LED1 = 1; 
        }
				if (SWITCH2 == 0) {
            LED2 = 0; 
        } else {
            LED2 = 1;
        }
				if (SWITCH3 == 0){
						LED1 = 0;
						delay(1000);
						LED2 = 0;
						delay(1000);
						LED1 = 1;
						delay(1000);
				} else {
						LED1 = 1;
						LED2 = 1;
				}
					
					
			
					
					
					
					
    }
}
		




