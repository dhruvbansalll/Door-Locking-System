#include <reg51.h>

void DELAY_ms(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<100;j++);
    }
}
int main() 
{
    while(1)
    {
        P2 = 0xff; /* Turn ON all the leds connected to P2 */
        DELAY_ms(500);
        
        P2 = 0x00; /* Turn OFF all the leds connected to P2 */
        DELAY_ms(500);
    }
    return (0);
}