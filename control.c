#include "control.h"
#include "encoder.h"
#include "math.h"
#include "uart.h"
int  road=0;
int 	ride=0;
int motion_state=0;//
int last=0;

int Velocity_B(int encoderB,int v_B)//left
{  
    static double velocity,Encoder_Least,Encoder_bias;
      static double Encoder_Integral;
   //================速度PI控制器=====================//    
        Encoder_Least =v_B-encoderB;                    //获取最新速度偏差=目标速度（�-测量速度（编码器� 

        Encoder_bias = Encoder_Least;                                  //一阶低通滤波器，减缓速度变化 
//				if(Encoder_bias<3&&Encoder_bias>-3)
//				{
//					Encoder_Integral +=Encoder_bias;      				
//				}              //积分出位移 积分时间：10ms
//        if(Encoder_Integral>50)      Encoder_Integral=50;             //积分限幅
//        if(Encoder_Integral<-50)      Encoder_Integral=-50;            //积分限幅
	
	
				if(motion_state==1)
				{
					if(road==0&&e_distance<2600)
					{
        velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)Yaw_1;    //速度控制					
					}
				}
				else if(motion_state==2)
				{

					if(road==0&&e_distance<2600)
					{
        velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)Yaw_1;    //速度控制					
					}
					else if(road==2&&e_distance<2600)
					{
							if(Yaw_1>150)
							{
					        velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)(180-Yaw_1);    //速度控制									
							}
	
							else if(Yaw_1<-150)
							{
					        velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)(180+Yaw_1);    //速度控制									
							}
					}
					else
					{
								velocity=Encoder_bias*40+Encoder_Integral*1;    //速度控制					
					}
				}
				else if(motion_state==3)
				{
					if(ride==0&&e_distance<2600)
					{
							velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)Yaw_1;    //速度控制
					}
					else if(ride==2&&e_distance<2600)
					{
					        velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)(-100-Yaw_1);    //速度控制
					}							
					else
					{
				velocity=Encoder_bias*40+Encoder_Integral*1;    //速度控制					
					}
			 } 
				
				else if(motion_state==4)
				{
					if(last==0&&e_distance<3500)
					{
					        velocity=Encoder_bias*42+Encoder_Integral*1+2.8*(int)(-40-Yaw_1);    //速度控制
					}
					else if(last==2&&e_distance<3500)
					{
						if(Yaw_1<-90)
						{
						velocity=Encoder_bias*42+Encoder_Integral*1+2.8*(int)(-142-Yaw_1);    //速度控制						
						}
						else if(Yaw_1>90)
						{
						velocity=Encoder_bias*42+Encoder_Integral*1+2.8*(int)(220-Yaw_1);    //速度控制		
						}
					}
					else
					{
				velocity=Encoder_bias*42+Encoder_Integral*1;    //速度控制					
					}
			 }
        if(encoderB==30){
        Encoder_bias=0;
        Encoder_Integral=0;
        velocity=750;
    }
        if(velocity<0)velocity=-velocity;
        return velocity;
    
}

int Velocity_A(int encoderA,int v_A)//left
{  
    static double velocity,Encoder_Least,Encoder_bias;
      static double Encoder_Integral;
   //================速度PI控制器=====================//    
        Encoder_Least =v_A-encoderA;                    //获取最新速度偏差=目标速度（�-测量速度（编码器� 

        Encoder_bias = Encoder_Least;         
//				if(Encoder_bias<3&&Encoder_bias>-3)
//				{
//        Encoder_Integral +=Encoder_bias;      				
//				}
				//一阶低通滤波器，减缓速度变化 
                            //积分出位移 积分时间：10ms
//        if(Encoder_Integral>500)      Encoder_Integral=500;             //积分限幅
//        if(Encoder_Integral<-500)      Encoder_Integral=-500;            //积分限幅    
				
				if(motion_state==1)
				{
					if(road==0&&e_distance<2600)
					{
						velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)Yaw_1;    //速度控制					
					}
				}
				else	if(motion_state==2)
				{
					
					if(road==0&&e_distance<2600)
					{
						velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)Yaw_1;    //速度控制					
					}
					else if(road==2&&e_distance<2600)
					{
							if(Yaw_1>150)
							{
					        velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)(180-Yaw_1);    //速度控制									
							}
	
							else if(Yaw_1<-150)
							{
					        velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)(180+Yaw_1);    //速度控制									
							}
					}
					else
					{
				velocity=Encoder_bias*40+Encoder_Integral*1;    //速度控制					
					} 
				}
				
				else if(motion_state==3)
				{
					if(ride==0&&e_distance<3500)
					{
						velocity=Encoder_bias*40+Encoder_Integral*1+5*(int)Yaw_1;    //速度控制		
					}
					else if(ride==2&&e_distance<2600)
					{
					        velocity=Encoder_bias*40+Encoder_Integral*1-5*(int)(-100-Yaw_1);    //速度控制
					}
					else
					{
				velocity=Encoder_bias*40+Encoder_Integral*1;    //速度控制					
					}
				 }
				
				else if(motion_state==4)
				{
					if(last==0&&e_distance<3500)
					{
					        velocity=Encoder_bias*42+Encoder_Integral*1-2.8*(int)(-40-Yaw_1);    //速度控制
					}
					else if(last==2&&e_distance<3500)
					{
						if(Yaw_1<-90)
						{
						velocity=Encoder_bias*42+Encoder_Integral*1-2.8*(int)(-142-Yaw_1);    //速度控制						
						}
						else if(Yaw_1>90)
						{
						velocity=Encoder_bias*42+Encoder_Integral*1-2.8*(int)(220-Yaw_1);    //速度控制		
						}
					}
					else
					{
				velocity=Encoder_bias*42+Encoder_Integral*1;    //速度控制					
					}
			 }
					if(encoderA==30)
					{
        Encoder_bias=0;
        Encoder_Integral=0;
        velocity=750;
					}
        if(velocity<0)velocity=-velocity;
        return velocity;
}
