#include "ti_msp_dl_config.h"
#include "OLED.h"
#include "OLED_Font.h"
#include <stdio.h>
 
#define OLED_ADDR   0x3C
 
//?OLED????????byte???
int I2C_WriteByte(uint8_t addr,uint8_t data)
{
  uint8_t buff[2] = {0};
  buff[0] = addr;
  buff[1] = data;
  /* Wait for I2C to be Idle */
  while (!(
            DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE))
            ;
 
        /* Send the packet to the controller.
         * This function will send Start + Stop automatically.
         */
        DL_I2C_startControllerTransfer(I2C_0_INST, OLED_ADDR,
            DL_I2C_CONTROLLER_DIRECTION_TX, 2);
        DL_I2C_fillControllerTXFIFO(I2C_0_INST, &buff[0], 2);
      /* Poll until the Controller writes all bytes */
      while (DL_I2C_getControllerStatus(I2C_0_INST) &
                     DL_I2C_CONTROLLER_STATUS_BUSY_BUS)
                  ;
 
      /* Trap if there was an error */
      if (DL_I2C_getControllerStatus(I2C_0_INST) &
          DL_I2C_CONTROLLER_STATUS_ERROR) {
          /* LED will remain high if there is an error */
          __BKPT(0);
      }
    return 0;
}
 
 
 
//???
void OLED_WriteCommand(unsigned char I2C_Command)
{
        I2C_WriteByte(0x00,I2C_Command);
}
 
//???
void OLED_WriteData(unsigned char I2C_Data)
{
        I2C_WriteByte(0x40,I2C_Data);
}
 
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//??Y??
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//??X???4?
	OLED_WriteCommand(0x00 | (X & 0x0F));			//??X???4?
}
 
/**
  * @brief  OLED??
  * @param  ?
  * @retval ?
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}
 
/**
  * @brief  OLED??????
  * @param  Line ???,??:1~4
  * @param  Column ???,??:1~16
  * @param  Char ????????,??:ASCII????
  * @retval ?
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//???????????
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//????????
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//???????????
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//????????
	}
}
 
/**
  * @brief  OLED?????
  * @param  Line ?????,??:1~4
  * @param  Column ?????,??:1~16
  * @param  String ???????,??:ASCII????
  * @retval ?
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}
 
/**
  * @brief  OLED????
  * @retval ?????X?Y??
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}
 
/**
  * @brief  OLED????(???,??)
  * @param  Line ?????,??:1~4
  * @param  Column ?????,??:1~16
  * @param  Number ??????,??:0~4294967295
  * @param  Length ????????,??:1~10
  * @retval ?
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}
 
/**
  * @brief  OLED????(???,????)
  * @param  Line ?????,??:1~4
  * @param  Column ?????,??:1~16
  * @param  Number ??????,??:-2147483648~2147483647
  * @param  Length ????????,??:1~10
  * @retval ?
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}
 
/**
  * @brief  OLED????(????,??)
  * @param  Line ?????,??:1~4
  * @param  Column ?????,??:1~16
  * @param  Number ??????,??:0~0xFFFFFFFF
  * @param  Length ????????,??:1~8
  * @retval ?
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}
 
/**
  * @brief  OLED????(???,??)
  * @param  Line ?????,??:1~4
  * @param  Column ?????,??:1~16
  * @param  Number ??????,??:0~1111 1111 1111 1111
  * @param  Length ????????,??:1~16
  * @retval ?
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}
 
/**
  * @brief  OLED???
  * @param  ?
  * @retval ?
  */
void OLED_Init(void)
{
	uint32_t i, j;
	
	for (i = 0; i < 1000; i++)			//????
	{
		for (j = 0; j < 1000; j++);
	}
	
	
	OLED_WriteCommand(0xAE);	//????
	
	OLED_WriteCommand(0xD5);	//?????????/?????
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//???????
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//??????
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//???????
	
	OLED_WriteCommand(0xA1);	//??????,0xA1?? 0xA0????
	
	OLED_WriteCommand(0xC8);	//??????,0xC8?? 0xC0????
 
	OLED_WriteCommand(0xDA);	//??COM??????
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//???????
	OLED_WriteCommand(0xCF);
 
	OLED_WriteCommand(0xD9);	//???????
	OLED_WriteCommand(0xF1);
 
	OLED_WriteCommand(0xDB);	//??VCOMH??????
	OLED_WriteCommand(0x30);
 
	OLED_WriteCommand(0xA4);	//????????/??
 
	OLED_WriteCommand(0xA6);	//????/????
 
	OLED_WriteCommand(0x8D);	//?????
	OLED_WriteCommand(0x14);
 
	OLED_WriteCommand(0xAF);	//????
		
	OLED_Clear();				//OLED??
}