#include <reg52.h>

// 1. Define your pins
sbit SDA = P2^0;
sbit SCL = P2^1;

// 2. Adjust address if needed (0x4E is standard, 0x7E is the alternative)
#define ADDR 0x4E 

void Delay(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++)
        for(j=0; j<120; j++);
}

// Simple I2C Start
void I2C_Start() {
    SDA = 1; SCL = 1; SDA = 0; SCL = 0;
}

// Simple I2C Stop
void I2C_Stop() {
    SDA = 0; SCL = 1; SDA = 1;
}

// Send 8 bits to the I2C bus
void I2C_SendByte(unsigned char dat) {
    unsigned char i;
    for(i=0; i<8; i++) {
        SDA = (dat & 0x80) >> 7;
        SCL = 1; SCL = 0;
        dat <<= 1;
    }
    SDA = 1; SCL = 1; SCL = 0; // Acknowledgement bit (ignored for simplicity)
}

// Send data to the LCD via the PCF8574 adapter
// bit 3 (0x08) is the Backlight
void LCD_RawWrite(unsigned char val) {
    I2C_Start();
    I2C_SendByte(ADDR);
    I2C_SendByte(val | 0x08); 
    I2C_Stop();
    Delay(1);
}

// The LCD needs data in two "nibbles" (4 bits at a time)
void LCD_Cmd(unsigned char cmd, unsigned char type) {
    unsigned char high = (cmd & 0xF0);
    unsigned char low = (cmd << 4) & 0xF0;
    
    // Send High Nibble: Pulse Enable (0x04) High then Low
    LCD_RawWrite(high | type | 0x04); 
    LCD_RawWrite(high | type);       

    // Send Low Nibble: Pulse Enable (0x04) High then Low
    LCD_RawWrite(low | type | 0x04);  
    LCD_RawWrite(low | type);        
}

void main() {
    // 3. Initialization sequence for 4-bit mode
    Delay(50);
    LCD_Cmd(0x02, 0); // Initialize LCD in 4-bit mode
    LCD_Cmd(0x28, 0); // 2 lines, 5x7 matrix
    LCD_Cmd(0x0C, 0); // Display ON, Cursor OFF
    LCD_Cmd(0x01, 0); // Clear Screen
    Delay(5);

    // 4. Write "HI"
    LCD_Cmd('H', 1); // Type 1 is for DATA (characters)
    LCD_Cmd('I', 1);

    while(1); // Stay here forever
}
