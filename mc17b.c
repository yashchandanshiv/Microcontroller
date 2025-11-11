#include <reg51.h>

void msdelay(unsigned int);

void main() {
    unsigned char ch;

    for(ch = 'A'; ch <= 'Z'; ch++) {
        P2 = ch;      // Send ASCII value to LEDs
        msdelay(300);
    }

    while(1); // stop here
}

void msdelay(unsigned int time) {
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}
