#include <p18f4550.h>
#include <vector_relocate.h>
#define _XTAL_FREQ 48000000   // 48 MHz oscillator

// LCD connections
#define LCD_DATA PORTD
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

// Function prototypes
void init_LCD(void);
void LCD_Command(unsigned char cmd);
void LCD_Data(unsigned char data);
void LCD_write_string(char *str);

void main() {
  char var1[] = "Microcontroller";
  char var2[] = "Embedded Lab";

  ADCON1 = 0x0F;   // Make all pins digital
  TRISD = 0x00;    // LCD data pins as output
  TRISE = 0x00;    // Control pins as output

  init_LCD();
  __delay_ms(10);

  LCD_write_string(var1);
  __delay_ms(10);

  LCD_Command(0xC0);     // Move to second line
  __delay_ms(10);

  LCD_write_string(var2);
  __delay_ms(10);

  while(1);  // infinite loop
}

void init_LCD() {
  LCD_Command(0x38);   // 8-bit mode, 2 lines
  LCD_Command(0x01);   // Clear display
  LCD_Command(0x0C);   // Display ON, Cursor OFF
  LCD_Command(0x80);   // Move to first line
}

void LCD_Command(unsigned char cmd) {
  LCD_DATA = cmd;
  rs = 0;  // Command mode
  rw = 0;  // Write mode
  en = 1;
  __delay_us(10);  // Short enable pulse
  en = 0;
  __delay_ms(2);   // Allow LCD to process
}

void LCD_Data(unsigned char data) {
  LCD_DATA = data;
  rs = 1;  // Data mode
  rw = 0;  // Write mode
  en = 1;
  __delay_us(10);  // Short enable pulse
  en = 0;
  __delay_ms(1);   // Character write delay
}

void LCD_write_string(char *str) {
  unsigned int i = 0;
  while (str[i] != 0) {
    LCD_Data(str[i]);
    i++;
  }
}
