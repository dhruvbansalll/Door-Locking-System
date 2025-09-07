
// Program to rotate servo by 5 degree from previous position starting from 0 degree

// 0 degree = 700us 
// 180 degree = 5500us
// Timer1 pulse after 50us	-23

#include<reg51.h>
sbit output=P1^0;  		//Output to motor
int count;

void delay(unsigned int msec)   // Function for delay
{
	int i,j;
	for(i=0;i<msec;i++)
		for(j=0;j<1275;j++);
} 

void timer(int msec){	 // Function for timer
	int i;
	TR1=1;
	for(i=0;i<msec;i++)
	{
		while(TF1==0);
		TF1=0;
	}
	TR1=0;
}
void main()
{
	int i;
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
		for(i=0;i<200;i++)
		{
			output=1;
			timer(count);		 
			output=0;
			timer(360);
		}
		delay(100);
	}
}