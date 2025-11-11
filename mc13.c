#include <p18f4550.h>
#include <vector_relocate.h>

#define LCD_DATA PORTD
#define ctrl PORTE
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void init_LCD(void);
void LCD_Command(unsigned char cmd);
void LCD_Data(unsigned char data);
void LCD_write_string(unsigned char *str);
void msdelay(unsigned int time);

void main() {
  char var1[] = "Name: Yash";
  char var2[] = "Roll No.: 32109";

  ADCON1 = 0x0F;     // PORTE as digital
  TRISD = 0x00;      // PORTD output
  TRISE = 0x00;      // PORTE output

  init_LCD();        // Initialize LCD
  msdelay(15);

  LCD_write_string(var1);   // Display first line
  msdelay(15);
  
  LCD_Command(0xC0);        // Move to 2nd line
  LCD_write_string(var2);   // Display second line
  msdelay(15);

  while(1); // Infinite loop
}

void init_LCD() {
  LCD_Command(0x38);  // 8-bit, 2-line, 5x7 font
  msdelay(15);
  LCD_Command(0x01);  // Clear display
  msdelay(15);
  LCD_Command(0x0C);  // Display ON, cursor OFF
  msdelay(15);
  LCD_Command(0x80);  // Cursor at 1st line
}

void LCD_Command(unsigned char cmd) {
  LCD_DATA = cmd;
  rs = 0;     // Command mode
  rw = 0;     // Write operation
  en = 1;
  msdelay(10);
  en = 0;
}

void LCD_Data(unsigned char data) {
  LCD_DATA = data;
  rs = 1;     // Data mode
  rw = 0;     // Write operation
  en = 1;
  msdelay(10);
  en = 0;
}

void LCD_write_string(unsigned char *str) {
  unsigned int i = 0;
  while (str[i] != 0) {    // Send each character
    LCD_Data(str[i]);
    msdelay(10);
    i++;
  }
}

void msdelay(unsigned int time) {
  unsigned int i, j;
  for (i = 0; i < time; i++)
    for (j = 0; j < 710; j++);  // 1ms delay calibrated
}
