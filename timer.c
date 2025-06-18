#include "board.h"
#include "stdio.h"
#include "ti_msp_dl_config.h"
#include "timer.h"
#include "encoder.h"
#include "control.h"
#include "uart.h"
#include "i2c.h"
int bee_time=0;
void Int_Timer(void)
{
    NVIC_ClearPendingIRQ(TIMER_10ms_INST_INT_IRQN);
    //ʹ�ܶ�ʱ���ж�
    NVIC_EnableIRQ(TIMER_10ms_INST_INT_IRQN);
}

uint32_t times=0;
int a=1;//�˶�ģʽ
int x=0,y=0;
//��ʱ�����жϷ����� ������Ϊ10ms������
//								DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);						 
//								delay_ms(100);
//								DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
void bee(void)
{
    if(bee_time)
    {
        bee_time--;
				DL_GPIO_setPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);		
    }
    else
    {
				DL_GPIO_clearPins(GPIO_BEEP_PORT_PORT,GPIO_BEEP_PORT_BEEP1_PIN| GPIO_BEEP_PORT_LED1_PIN);
    }
}
void TIMER_10ms_INST_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(TIMER_10ms_INST_INT_IRQN);
    //��������˶�ʱ���ж�
    switch( DL_TimerG_getPendingInterrupt(TIMER_10ms_INST) )
    {
        case DL_TIMER_IIDX_ZERO://�����0����ж�
				{
								GetSpeed();
								DL_TimerG_setCaptureCompareValue(PWM_1_INST,999-Velocity_B(gEncoderCountB,x),GPIO_PWM_1_C0_IDX);	//4khz	 50%ռ�ձ�
	              DL_TimerG_setCaptureCompareValue(PWM_0_INST,999-Velocity_A(gEncoderCountA,y),GPIO_PWM_0_C0_IDX); //4khz	 50%ռ�ձ�						
								bee();
				}
            break;

        default://�����Ķ�ʱ���ж�
            break;
    }
}







