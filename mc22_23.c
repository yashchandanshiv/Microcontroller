#include <p18f4550.h>
#include "vector_relocate.h"

#define LCD_DATA  PORTD              
#define en PORTEbits.RE2              
#define rw PORTEbits.RE1             
#define rs PORTEbits.RE0              

// ---------- Delay Function ----------
void myMsDelay(unsigned int me)
{
    unsigned int i, j;
    for (i = 0; i < me; i++)
        for (j = 0; j < 710; j++);
}

// ---------- LCD Commands ----------
void LCD_cmd(unsigned char cmd)
{
    LCD_DATA = cmd;
    rs = 0;        // Command Register
    rw = 0;        // Write Mode
    en = 1;
    myMsDelay(5);
    en = 0;
    myMsDelay(5);
}

// ---------- LCD Write ----------
void LCD_write(unsigned char data)
{
    LCD_DATA = data;
    rs = 1;        // Data Register
    rw = 0;        // Write
    en = 1;
    myMsDelay(5);
    en = 0;
    myMsDelay(5);
}

// ---------- LCD Initialization ----------
void init_LCD(void)
{
    LCD_cmd(0x38);     // 8-bit mode, 2 lines
    myMsDelay(15);

    LCD_cmd(0x01);     // Clear display
    myMsDelay(15);

    LCD_cmd(0x0C);     // Display ON, cursor OFF
    myMsDelay(15);
    
    LCD_cmd(0x80);     // First line, position 0
    myMsDelay(15);
}

// ---------- MAIN PROGRAM ----------
void main(void)
{
    unsigned int temp, ADC_Result = 0;
    unsigned char i, str[] = "Result:";
    unsigned int val[4];

    TRISD = 0x00;   // LCD data output
    TRISE = 0x00;   // LCD control output
    TRISA = 0xFF;   // AN0 input

    init_LCD();

    // ---------- ADC Configuration ----------
    ADCON1 = 0x0C;     // AN0 analog, Vref = VDD/VSS
    ADCON2 = 0x8E;     // Right Justified, 4TAD, Fosc/64
    ADCON0 = 0x01;     // ADC enabled, Select AN0

    // Display "Result:"
    LCD_cmd(0x80);
    for(i = 0; str[i] != '\0'; i++)
    {
        LCD_write(str[i]);
        myMsDelay(50);
    }

    // ---------- Main Loop ----------
    while(1)
    {
        ADCON0bits.GO = 1;          // Start conversion
        while(ADCON0bits.GO == 1);  // Wait until done

        ADC_Result = ((unsigned int)ADRESH << 8) | ADRESL;   // 10-bit result

        temp = ADC_Result;

        // ------ Convert ADC value to ASCII ------
        for(i = 0; i < 4; i++)
        {
            val[i] = (temp % 10) + 0x30;
            temp = temp / 10;
        }

        // ------ Display Value ------
        LCD_cmd(0x87);              // Position cursor
        LCD_write(val[3]);
        LCD_write(val[2]);
        LCD_write(val[1]);
        LCD_write(val[0]);

        myMsDelay(100);
    }
}
