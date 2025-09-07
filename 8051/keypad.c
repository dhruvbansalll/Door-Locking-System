#include <reg51.h>

sbit rs = P3^3;    // register select pin
sbit rw = P3^7;    // read write pin
sbit e = P3^4;     // enable pin
sbit a = P1^0;     // defines row A
sbit b = P1^1;     // defines row B
sbit c = P1^2;     // defines row C
sbit d = P1^3;     // defines row D
sbit one = P3^0;   // defines column one
sbit two = P3^1;   // defines column two
sbit three = P3^2; // defines column three

void delay(unsigned int time) {
    int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void lcdcmd(unsigned char item) {
    P2 = item;
    rs = 0;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}

void lcddata(unsigned char item) {
    P2 = item;
    rs = 1;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}

char read_num() {
    a = 1;
    b = 1;
    c = 1;
    d = 1;

    one = 0;
    two = 1;
    three = 1;
    if (a == 0) return '1';
    if (b == 0) return '4';
    if (c == 0) return '7';
    if (d == 0) return '*';

    one = 1;
    two = 0;
    three = 1;
    if (a == 0) return '2';
    if (b == 0) return '5';
    if (c == 0) return '8';
    if (d == 0) return '0';

    one = 1;
    two = 1;
    three = 0;
    if (a == 0) return '3';
    if (b == 0) return '6';
    if (c == 0) return '9';
    if (d == 0) return '#';

    return -1;
}

void main() {
    char number;
    lcdcmd(0x0E); // turn display ON for cursor blinking
    lcdcmd(0x01); // clear screen
    lcdcmd(0x06); // display ON

    while (1) {
        number = read_num();
        while (number == -1) {
            number = read_num();
        }

        if (number != -1) {
            lcddata(number);
        }

        delay(100);
    }
}