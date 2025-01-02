#include "types.h"

void delay_us(u32 dlyUS)
{
	 dlyUS*=12;   
 	 while(dlyUS--); 
}

void delay_ms(u32 dlyMS)
{
	 dlyMS*=12000;   
 	 while(dlyMS--); 
}
