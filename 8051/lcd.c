#include<reg51.h>

#define display_port P2    

sbit rs = P3^2;  //pin 2 of port 3
sbit rw = P3^3;  //pin 3 of port 3
sbit e =  P3^4;  //4 of port 3


void msdelay(unsigned int time){ // delay function
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char command) {

    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}


void lcd_data(unsigned char disp_data) {

    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}


 void lcd_init()   {

    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    msdelay(10);
}

void main(){
    unsigned char a[15]="lcd display";
	  unsigned char b[15]=" new project";
    int l=0;
    lcd_init();
    while(a[l] != '\0') {
        lcd_data(a[l]);
        l++;
        msdelay(50);
    }
		l=0;
		lcd_cmd(0xC0);
		while(b[l] != '\0') {
        lcd_data(b[l]);
        l++;
        msdelay(50);
    }
}