#include <reg51.h>

void delay(){
    unsigned int i, j;
    for (i = 0; i < 1000; i++){
        for (j = 0; j < 20; j++){
            // Inner loop used for creating a delay
        }
    }
}

void main(){
    while (1){
        // Control Port 2 (P2) with the same pattern as Port 1
        P2 = 0x81; // Binary: 10000001
        delay();
        P2 = 0xC3; // Binary: 11000011
        delay();
        P2 = 0xE7; // Binary: 11100111
        delay();
        P2 = 0xFF; // Binary: 11111111
        delay();
        P2 = 0xE7; // Binary: 11100111
        delay();
        P2 = 0xC3; // Binary: 11000011
        delay();
        P2 = 0x81; // Binary: 10000001
        delay();
        P2 = 0x00; // Binary: 00000000
        delay();
    }
}