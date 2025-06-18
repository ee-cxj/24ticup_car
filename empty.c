
#include "board.h"
#include "stdio.h"
#include "uart.h"
#include "encoder.h"
#include "i2c.h"
#include "control.h"
#include "timer.h"
#include "OLED.h"
extern int gEncoderCountA;
extern int gEncoderCountB; 
char send_date_tem[70];
char qwe[100];//uart string
int gray_state=0;//gray_state middle0 left1 right2
int giao=0;
int Circle_count=0;
void Gray_Get()
{		
				if(motion_state==1)//action_1
		{
				if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN)&&e_distance<3100)
//			if(e_distance<2800)
			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=7;
			y=7;
			}	
			else
			{
										x=0;y=0;
										delay_ms(100);
										AIN1_OUT(0);
										AIN2_OUT(0);
										BIN1_OUT(0);
										BIN2_OUT(0);
										bee_time=20;
			}
		}	
		else if(motion_state==2)
		{
			if(road==0)
			{
				if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN)&&e_distance<3300)
//						if(e_distance<2850)
			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=7;
			y=7;
			}	
				else
				{      	
								road=1;
								bee_time=40;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
			else if(road==1)
			{
			if(  (Yaw_1)>-175 &&  (Yaw_1)<175  )
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=7;
								y=7;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=7;
								y=4;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=4;
								y=7;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=7;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=7;
							gray_state=2;
							}
			}
				else
				{      	
								road=2;
								e_distance=0;
								bee_time=20;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
		}
				else if(road==2)
			{
			if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN)&&e_distance<3300)
//						if(e_distance<2900)

			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=7;
			y=7;
			}	
				else
				{      	
								road=3;
								bee_time=20;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
		else if(road==3)
			{
			if(e_distance<7900)
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=7;
								y=7;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=7;
								y=4;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=4;
								y=7;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=7;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=7;
							gray_state=2;
							}
			}
			else{
										x=0;y=0;
										delay_ms(100);
										AIN1_OUT(0);
										AIN2_OUT(0);
										BIN1_OUT(0);
										BIN2_OUT(0);
										bee_time=20;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
//								delay_ms(1000);
							}
						}
	}
		
		else if(motion_state==3)
		{
			if(ride==0)
			{
				if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN)&&e_distance<3600)
//						if(e_distance<2850)
			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=7;
			y=7;
			}	
				else
				{      	
								ride=1;
								bee_time=40;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
			else if(ride==1)
			{
			if(  ( (Yaw_1)>-180 && (Yaw_1)<-145) ||  (Yaw_1)>-135)  
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=7;
								y=7;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=7;
								y=4;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=4;
								y=7;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=7;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=7;
							gray_state=2;
							}
			}
				else
				{      	
								ride=2;
								bee_time=40;					
								e_distance=0;
				}
		}
				else if(ride==2)
			{
			if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
//						if(e_distance<2900)
			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=7;
			y=7;
			}	
				else
				{      	
								ride=3;
								bee_time=40;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
		else if(ride==3)
			{
			if(e_distance<9000)
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=7;
								y=7;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=7;
								y=4;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=4;
								y=7;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=7;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=7;
							gray_state=2;
							}
			}
			else{
										x=0;y=0;
										delay_ms(100);
										AIN1_OUT(0);
										AIN2_OUT(0);
										BIN1_OUT(0);
										BIN2_OUT(0);
										bee_time=20;
							}
						}
	}
		else if(motion_state==4)
		{
			if(last==0)
			{
				if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN)/*&&e_distance<3800*/)
//						if(e_distance<2850)
			{
      AIN1_OUT(1);
      AIN2_OUT(0);
      BIN1_OUT(1);
      BIN2_OUT(0);
			x=10;
			y=10;
			}
				else
				{      	
								last=1;
								bee_time=20;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
			else if(last==1)
			{
			if(  (Yaw_1)>-172 &&  (Yaw_1)<172/* &&e_distance<10000*/)   
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=9;
								y=9;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=8;
								y=5;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=5;
								y=8;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=8;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=8;
							gray_state=2;
							}
			}
				else
				{      	
								last=2;
								e_distance=0;
								bee_time=20;
				}
		}
				else if(last==2)
			{
			if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN) /*&& e_distance<3800*/)
//						if(e_distance<2900)
			{
									AIN1_OUT(1);
									AIN2_OUT(0);
									BIN1_OUT(1);
									BIN2_OUT(0);
									x=10;
									y=10;
			}	
				else
				{      	
									last=3;
									bee_time=20;
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
				}
			}
		else if(last==3)
			{
			if((Yaw_1<-6||Yaw_1>6)&&e_distance<10000)
//				if(1)
			{
						AIN1_OUT(1);
						AIN2_OUT(0);
						BIN1_OUT(1);
						BIN2_OUT(0);
							if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//middle
								x=9;
								y=9;
							gray_state=0;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small left
								x=8;
								y=5;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//small right
								x=5;
								y=8;
							gray_state=2;
							}
							else if(DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{// big left
								x=8;
								y=2;
							gray_state=1;
							}
							else if(!DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR1_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR2_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR3_PIN) && !DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR4_PIN) && DL_GPIO_readPins(GPIO_GRAY_SENSOR_PORT,GPIO_GRAY_SENSOR_SENSOR5_PIN))
							{//big right
								x=2;
								y=8;
							gray_state=2;
							}
			}
						else{
							  Circle_count++;
								last=0;
								e_distance=0;							
								bee_time=20;
									if(Circle_count>=3)
									{
										last=4;
										x=0;y=0;										
										delay_ms(100);
										AIN1_OUT(0);
										AIN2_OUT(0);
										BIN1_OUT(0);
										BIN2_OUT(0);

										bee_time=20;
									}
							  }
						}
	}
}

int main(void)
{
	SYSCFG_DL_init();
    int i = 0;
	DL_TimerG_setCaptureCompareValue(PWM_1_INST,999,GPIO_PWM_1_C0_IDX);	//4khz	 50%占空比 right
	DL_TimerG_setCaptureCompareValue(PWM_0_INST,999,GPIO_PWM_0_C0_IDX); //4khz	 50%占空比 left
	Int_Timer();	
	Int_UART();
	Int_Encoder();
	DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);//led and beep pull dowm	
	OLED_Init();

	delay_ms(1000);
	Serial_JY61P_Zero_Yaw();
	bee_time = 20;
	OLED_ShowString(10,1,"Motion:");
 while (1)
    {

			Gray_Get();

    }
}














