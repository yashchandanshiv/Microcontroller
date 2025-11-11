#include<p18f4550.h>
#include<vector_relocate.h>


#define sw0 PORTBbits.RB1
#define sw1 PORTBbits.RB0
#define buzzer PORTCbits.RC2
#define relay PORTDbits.RD7


void msdelay(unsigned int time){
  unsigned int i,j;
  for(i=0;i<time;i++){
    for(j=0;j<710;j++){
      
    }
  }
}
void main(){
  signed char i;
  unsigned char val=0;
  INTCON2bits.RBPU=0;
  ADCON1=0x0f;
  TRISBbits.RB1=1;
  TRISBbits.RB0=1;
  TRISCbits.TRISC2=0;
  TRISDbits.TRISD7=0;
  TRISA=0x00;

  PORTA=0x00;
  relay=0;
  buzzer=0;

  while(1){
    if(sw0==0) val=1;
    if(sw1==0) val=2;

    if(val==1){
      relay=1;
      buzzer=1;
      for(i=0;i<8;i++){
        PORTA=(1<<i);
        msdelay(200);
      }
    }

    if(val==2){
      relay=0;
      buzzer=0;
      for(int i=8;i>0;i--){
        PORTA=(1<<(i-1));
        msdelay(200);
      }
    }
  }
}