#include <lpc21xx.h>    
#include "types.h"    
#include "can.h"  
#include "delay.h"
#include "lcd.h"
#include "ADC.h"
#include "adc_defines.h"
#include "gp2d12.h"

f32 AR1;
u32 distanceCM;

int main(void)    
{    
  struct CAN_Frame txFrame;    
	txFrame.ID=2;   txFrame.vbf.RTR=0; //data frame   
	txFrame.Data1=0x87654321; txFrame.Data2=0x38392635;    
  Init_CAN1();   
	LCD_Init();
	Init_ADC();
	Write_CMD_LCD(0x80);
	Write_str_LCD("CAN TX NODE");
	
	while(1)    
  {
  		
		AR1 = Read_ADC(CH1);
		distanceCM = ADCValueToDiatance(AR1);
		Write_CMD_LCD(0xC0);
		Write_str_LCD("Distance : ");
		Write_int_LCD(distanceCM);
		Write_str_LCD("cm");
		Write_str_LCD("   ");
		delay_ms(1000);
	
		txFrame.Data1 = distanceCM;
		txFrame.vbf.DLC=1;    
		CAN1_Tx(txFrame); 
		delay_ms(1000);
  
  }    
}

