#include <reg51.h>

void msdelay(unsigned int);

void main() {
    unsigned int num;

    while(1) {
        // Up-counting (00 → FF)
        for(num = 0x00; num <= 0xFF; num++) {
            P2 = num;
            msdelay(50);
        }

        // Down-counting (FF → 00)
        for(num = 0xFF; num >= 0x00; num--) {
            P2 = num;
            msdelay(50);
        }
    }
}

void msdelay(unsigned int time) {
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}
