#include<reg51.h>
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.

{
    unsigned i,j ;
    for(i=0;i<time;i++)    

    for(j=0;j<1275;j++);

}
void main()
{
    unsigned char no_code[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};//Array for hex values (0-9) for common anode 7 segment

    unsigned int k;
    while(1)
    {
        for(k=0;k<10;k++)
        {
         P2=no_code[k]; 
         msdelay(100);
        }
    }
}