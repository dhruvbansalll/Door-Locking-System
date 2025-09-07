#include <reg51.h>

#define display_port P2

sbit rs = P3^3;    // register select pin
sbit rw = P3^7;    // read write pin
sbit e = P3^4;     // enable pin
sbit a = P1^0;     // defines row A
sbit b = P1^1;     // defines row B
sbit c = P1^2;     // defines row C
sbit d = P1^3;     // defines row D
sbit col1 = P3^0;   // defines column col1
sbit col2 = P3^1;   // defines column col2
sbit col3 = P3^2;   // defines column col3
sbit output=P1^4;  		//Output to motor
int count;
int n;

unsigned char pin[] = "12345";
unsigned char Epin[5];
int i = 0;
unsigned int key=0;
void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char command) {
    display_port = command;
    rs = 0;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}


void lcd_data(unsigned char disp_data) {
    display_port = disp_data;
    rs = 1;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}
void timer(int msec){	 // Function for timer
	int m;
	TR1=1;
	for(m=0;m<msec;m++)
	{
		while(TF1==0);
		TF1=0;
	}
	TR1=0;
}

char read_num() {
    a = 1;
    b = 1;
    c = 1;
    d = 1;

    col1 = 0;
    col2 = 1;
    col3 = 1;
    if (a == 0) return '1';
    if (b == 0) return '4';
    if (c == 0) return '7';
    if (d == 0) return '*';

    col1 = 1;
    col2 = 0;
    col3 = 1;
    if (a == 0) return '2';
    if (b == 0) return '5';
    if (c == 0) return '8';
    if (d == 0) return '0';

    col1 = 1;
    col2 = 1;
    col3 = 0;
    if (a == 0) return '3';
    if (b == 0) return '6';
    if (c == 0) return '9';
    if (d == 0) return '#';

    return -1;
}



void lcd_init() {
    lcd_cmd(0x38);
    delay(1);
    lcd_cmd(0x0E);
    delay(1);
    lcd_cmd(0x01);
    delay(1);
    lcd_cmd(0x80);
    delay(1);
}
void lcd_display(char *p){
	while(*p!='\0'){
		lcd_data(*p);
		delay(10);
		p++;
	}
}
void main() {
    unsigned char a[15] = "Enter Password";
	
    int l = 0;

    lcd_init();

    while (a[l] != '\0') {
        lcd_data(a[l]);
        l++;
        delay(20);
    }

    lcd_cmd(0xC0);
while(read_num()==-1){
	read_num();
}
    Epin[0]=read_num();
delay(50);
lcd_data(Epin[0]);
while(read_num()==-1){
	read_num();
}
Epin[1]=read_num();
lcd_data(Epin[1]);
delay(50);
while(read_num()==-1){
	read_num();
}
Epin[2]=read_num();
lcd_data(Epin[2]);
delay(50);
while(read_num()==-1){
	read_num();
}
Epin[3]=read_num();
lcd_data(Epin[3]);
delay(50);
while(read_num()==-1){
	read_num();
}
Epin[4]=read_num();
lcd_data(Epin[4]);

		lcd_init();
    

    if (pin[0] == Epin[0] && pin[1]== Epin[1] && pin[2]==Epin[2] && pin[3]==Epin[3] && pin[4]==Epin[4]) {
        lcd_display("CORRECT PIN");
		lcd_cmd(0x01);
		delay(50);
		lcd_display("DOOR OPENED");
		
	TMOD=0x20; 		// Mode2
	TH1= -23;		// 50usec timer
	output=0;
	count=14;
	while(1)
	{
		if(count>=100)
			count=14;
		else
			count=count+5;
		for(n=0;n<200;n++)
		{
			output=1;
			timer(count);		 
			output=0;
			timer(360);
		}
		delay(100);
	}
		
        delay(200);
		
        lcd_cmd(0x01);
		
    }
		else {
        lcd_display("WRONG PIN");
			lcd_cmd(0xC0);
        delay(100);
        lcd_cmd(0x01);
			lcd_display("TRY AGAIN");
			
    }
}