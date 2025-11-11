#include <reg51.h>

void delay(unsigned int time){
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void main() {
    signed char tens, ones;   // IMPORTANT: use SIGNED for downward loop

    while(1) {

        // -------------------------
        // Up-counting : 00 → 99
        // -------------------------
        for(tens = 0; tens <= 9; tens++) {
            for(ones = 0; ones <= 9; ones++) {
                P2 = (tens << 4) | ones;   // Output BCD
                delay(200);
            }
        }

        // -------------------------
        // Down-counting : 99 → 00
        // -------------------------
        for(tens = 9; tens >= 0; tens--) {
            for(ones = 9; ones >= 0; ones--) {
                P2 = (tens << 4) | ones;
                delay(200);

                if(tens == 0 && ones == 0)  // stop exactly at 00
                    break;
            }
            if(tens == 0) break;
        }
    }
}
