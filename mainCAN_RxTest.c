#include <LPC21xx.h> 

#include "can.h" 
#include "lcd.h"
#include "defines.h"


int main()   
{  
	int ch;
	struct CAN_Frame rxFrame; 
	WRITEBIT(IODIR0,8,1);
	 
  Init_CAN1();
	LCD_Init();
	Write_CMD_LCD(0x80);
	Write_str_LCD("CAN RX NODE");
	while(1)   
	{   
        CAN1_Rx(&rxFrame); 
		ch = (rxFrame.Data1 & 0xFF);
		Write_CMD_LCD(0xC0);
		Write_str_LCD("Distance: ");
		Write_int_LCD(ch);
		Write_str_LCD("cm ");
		if(ch<6)
		WRITEBIT(IOPIN0,8,0);//,Write_str_LCD("XXX");
		else
		WRITEBIT(IOPIN0,8,1);
		


	}    
	
}   
