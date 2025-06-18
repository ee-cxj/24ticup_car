#include "encoder.h"
#include "control.h"
#include "OLED.h"

int motion_state_1;

void Int_Encoder(void)
{

    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//使能外部中断	
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);//使能外部中断	
}


int gEncoderCountA;
int gEncoderCountB; 
void GROUP1_IRQHandler(void)
{
    
	uint32_t gpiob = DL_GPIO_getEnabledInterruptStatus(KEY1_USER_PORT,KEY1_USER_PIN_24_PIN);
			if((gpiob &KEY1_USER_PIN_24_PIN )==KEY1_USER_PIN_24_PIN)
			{ 
				delay_ms(50);
				motion_state_1 = motion_state_1<4 ? (motion_state_1+1): 1;
				OLED_ShowNum(10,10,motion_state_1,1);
			  	
				
				DL_GPIO_clearInterruptStatus(KEY1_USER_PORT,KEY1_USER_PIN_24_PIN);
			}
		uint32_t gpioa28 = DL_GPIO_getEnabledInterruptStatus(KEY2_USER_PORT,KEY2_USER_PIN_28_PIN);
			if((gpioa28 &KEY2_USER_PIN_28_PIN )==KEY2_USER_PIN_28_PIN)
			{ 
				delay_ms(50);
				
			  motion_state = motion_state_1;
				delay_ms(2000);
				
				DL_GPIO_clearInterruptStatus(KEY2_USER_PORT,KEY2_USER_PIN_28_PIN);
			}
	
	
	
	
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIO_EncoderA_PORT,
	GPIO_EncoderA_PIN_EncoderA1_PIN | GPIO_EncoderA_PIN_EncoderA2_PIN);
	
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB,
    GPIO_EncoderB_PIN_EncoderB1_PIN | GPIO_EncoderB_PIN_EncoderB2_PIN); 
	
    if((gpioA & GPIO_EncoderA_PIN_EncoderA1_PIN) == GPIO_EncoderA_PIN_EncoderA1_PIN)
    {
        //Pin0上升沿
        if(!DL_GPIO_readPins(GPIOA,GPIO_EncoderA_PIN_EncoderA2_PIN))//P1为高电平
        {
            gEncoderCountA++;
        }
        else//P1为低电平
        {
            gEncoderCountA--;
        }
		
    }
    
    else if((gpioA & GPIO_EncoderA_PIN_EncoderA2_PIN) == GPIO_EncoderA_PIN_EncoderA2_PIN)
    {
        //Pin1上升沿
        if(!DL_GPIO_readPins(GPIOA,GPIO_EncoderA_PIN_EncoderA1_PIN))//P0为高电平
        {
            gEncoderCountA--;
        }
        else//P1为低电平
        {
            gEncoderCountA++;
        }
    }

    //
	
	
	//
	if((gpioB & GPIO_EncoderB_PIN_EncoderB1_PIN) == GPIO_EncoderB_PIN_EncoderB1_PIN)
    {
        //Pin0上升沿
        if(!DL_GPIO_readPins(GPIOB,GPIO_EncoderB_PIN_EncoderB2_PIN))//P1为高电平
        {
            gEncoderCountB++;
        }
        else//P1为低电平
        {
            gEncoderCountB--;
        }
    }
    
    else if((gpioB & GPIO_EncoderB_PIN_EncoderB2_PIN) == GPIO_EncoderB_PIN_EncoderB2_PIN)
    {
        //Pin1上升沿
        if(!DL_GPIO_readPins(GPIOB,GPIO_EncoderB_PIN_EncoderB1_PIN))//P0为高电平
        {
            gEncoderCountB--;
        }
        else//P1为低电平
        {
            gEncoderCountB++;
        }
    }


    
    
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_EncoderA_PIN_EncoderA1_PIN|GPIO_EncoderA_PIN_EncoderA2_PIN);
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_EncoderB_PIN_EncoderB1_PIN|GPIO_EncoderB_PIN_EncoderB2_PIN);

}

int16_t Left_count;
int16_t Right_count;
float L_jishu;
float R_jishu;
float e_distance=0;




void GetSpeed(void)
{
		Left_count	=	gEncoderCountA;
		Right_count	=	gEncoderCountB;	
		//L_CarSpeed = (float)gEncoderCountA /350;
	  //R_CarSpeed =(float)gEncoderCountB /350;
//		L_CarSpeed = (float)gEncoderCountA *0.02857;
//	  R_CarSpeed =(float)gEncoderCountB *0.02857;
		


		
//	if(Left_count<0) Left_count = -Left_count; 
//	if(Right_count<0) Right_count = -Right_count;
//		l_filter[3] = l_filter[2];
//	  l_filter[2] = l_filter[1];
//	  l_filter[1] = l_filter[0];	
//		r_filter[3] = r_filter[2];
//	  r_filter[2] = r_filter[1];
//	  r_filter[1] = r_filter[0];

//    l_filter[0]=Left_count;			
//    r_filter[0]=Right_count;
//		L_CarSpeed = (L_CarSpeed*0.15 + 0.85*(0.4*l_filter[0]+0.3*l_filter[1]+0.2*l_filter[2]+0.1*l_filter[3]) * SPEED_F / L_QD_UNIT); 
//    R_CarSpeed = (R_CarSpeed*0.15 + 0.85*(0.4*r_filter[0]+0.3*r_filter[1]+0.2*r_filter[2]+0.1*r_filter[3]) * SPEED_F / R_QD_UNIT);   
//    if (L_CarSpeed > 2)L_CarSpeed = 2;//
//    if (R_CarSpeed > 2)R_CarSpeed = 2;
		//printf("LA %d RB %d L_CarSpeed:%f",gEncoderCountA,gEncoderCountB,L_CarSpeed);
		//printf(" R_CarSpeed:%f\r\n",R_CarSpeed);
		//printf(" L_SpeedOutput:%f\r\n",L_SpeedOutput);
				gEncoderCountA=0 ;	
				gEncoderCountB=0;
//		speed_aver = (L_CarSpeed+R_CarSpeed)/2;
//	   L_jishu=0.4*l_filter[0]+0.3*l_filter[1]+0.2*l_filter[2]+0.1*l_filter[3];
//     R_jishu=0.4*r_filter[0]+0.3*r_filter[1]+0.2*r_filter[2]+0.1*r_filter[3];
	   //e_distance += (Left_count+Right_count)/(2*35);
		 e_distance += (Left_count+Right_count)*0.5;
}









