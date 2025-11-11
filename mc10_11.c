#include<p18f4550.h>


void msdelay(unsigned int time){
  unsigned int i,j;
  for(i=0;i<time;i++){
    for(j=0;j<710;j++){
      
    }
  }
}

void main(){
  TRISCbits.TRISC2=0;
  TRISD=0;
  PR2=0xBB;
  CCP1CON=0x0C;
  T2CON=0x07;
  PORTDbits.RD5=0;
  PORTDbits.RD6=1;
  while(1){
    //50% duty cycle
    CCP1CONbits.DC1B1=1;
    CCP1CONbits.DC1B0=0;
    CCPR1L=0x5D;
    msdelay(2000);

  }
}