#include<reg51.h>

void msdelay(unsigned int time) {
  unsigned int i, j;
  for (i = 0; i < time; i++)
    for (j = 0; j < 710; j++);  // 1ms delay calibrated
}

void main(){
  signed int i;

  //Square Wave
  while(1){
    P1=0xFF;
    msdelay(100);
    P1=0x00;
    msdelay(100);
  }

  //Triangular Wave
  while(1){
    for(i=0;i<=255;i++){
      P1=i;
      msdelay(2);
    }

    for(i=255;i>=0;i--){
      P1=i;
      msdelay(2);
    }
  }

  //Sine wave
  unsigned char sin[]={128, 192, 238, 255, 238, 192, 128, 64, 18, 1, 18, 64};
  while(1){
    for(i=;i<12;i++){
      P1=sin[i];
      msdelay(5)
    }
  }
}