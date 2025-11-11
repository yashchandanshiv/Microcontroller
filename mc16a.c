#include <reg51.h>

void msdelay(unsigned int);

void main() {
    while(1) {
        P2 = 0x00;    // LEDs ON (assuming active low)
        msdelay(100); // 100 ms delay
        P2 = 0xFF;    // LEDs OFF
        msdelay(100);
    }
}

void msdelay(unsigned int time) {
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}
