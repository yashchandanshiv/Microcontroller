#include<reg51.h>

void msdelay(unsigned int time) {
  unsigned int i, j;
  for (i = 0; i < time; i++)
    for (j = 0; j < 710; j++);  // 1ms delay calibrated
}

void main(){
  unsigned int k;

  //clockwise
  while(1){
    P1=0x06;
    msdelay(200);
    P1=0x0C;
    msdelay(200);
    P1=0x09;
    msdelay(200);
    P1=0x03;
    msdelay(200);
  }

  //Anti-clockwise
  while(1){
    P1=0x03;
    msdelay(200);
    P1=0x09;
    msdelay(200);
    P1=0x0C;
    msdelay(200);
    P1=0x06;
    msdelay(200);
  }

  //90* 
  while(1){
    for(k=0;k<3;k++){
      P1=0x06;
      msdelay(200);
      P1=0x0C;
      msdelay(200);
      P1=0x09;
      msdelay(200);
      P1=0x03;
      msdelay(200);
    }
  }

  //180*
  while(1){
    for(k=0;k<6;k++){
      P1=0x06;
      msdelay(200);
      P1=0x0C;
      msdelay(200);
      P1=0x09;
      msdelay(200);
      P1=0x03;
      msdelay(200);
    }
  }
}