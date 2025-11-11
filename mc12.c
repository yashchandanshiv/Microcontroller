#include<p18f4550.h>
#include<vector_relocate.h>

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

void main(){
  char var1[]="Welcome";
  char var2[]="To Embedded Lab";

  ADCON1=0x0F;
  TRISD=0x00;
  TRISE=0x00;

  init_LCD();
  msdelay(25);

  LCD_write_string(var1);
  msdelay(25);

  LCD_Command(0xC0);
  LCD_write_string(var2);
  msdelay(25);

  while (1);
}

void init_LCD(){
  LCD_Command(0x38);
  msdelay(25);
  LCD_Command(0x01);
  msdelay(25);
  LCD_Command(0x0C);
  msdelay(25);
  LCD_Command(0x80);
}

void LCD_Command(unsigned char cmd){
  LCD_DATA=cmd;
  rs=0;
  rw=0;
  en=1;
  msdelay(25);
  en=0;
}

void LCD_Data(unsigned char data){
  LCD_DATA=data;
  rs=1;
  rw=0;
  en=1;
  msdelay(25);
  en=0;
}

void LCD_write_string(unsigned char *str){
  unsigned int i=0;
  while (str[i]!=0)
  {
    LCD_Data(str[i]);
    msdelay(25);
    i++;
  }
  
}