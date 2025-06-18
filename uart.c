#include "uart.h"

volatile unsigned char uart_data ;
uint8_t DBG_RxProBuf[100];
uint8_t TCK_RxProBuf[100];
uint8_t CTL_RxProBuf[100];

uint8_t *pdbgReader=DBG_RxProBuf;
uint8_t *ptckReader=TCK_RxProBuf;
uint8_t *pctlReader=CTL_RxProBuf;

//串口发送单个字符
void uart0_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, ch);
}
//







//串口发送字符串
void uart0_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart0_send_char(*str++);
    }
}
//





//
void UART_0_INST_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	switch( DL_UART_getPendingInterrupt(UART_0_INST) )
	{
	case DL_UART_IIDX_RX://如果是接收中断
		//接发送过来的数据保存在变量中
		*pdbgReader = DL_UART_Main_receiveData(UART_0_INST);
//		//将保存的数据再发送出去
//		uart0_send_char(uart_data);
		pdbgReader++;
		if(*(pdbgReader-1)==';')
		{
			pdbgReader=DBG_RxProBuf;
//			debugUartISR();
		}
		break;

	default://其他的串口中断
		break;
	}



}










//


//串口发送单个字符
void uart1_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_1_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_1_INST, ch);
}
//串口发送字符串
void uart1_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart1_send_char(*str++);
    }
}
//



//
void UART_1_INST_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);	
	switch( DL_UART_getPendingInterrupt(UART_1_INST) )
	{
	case DL_UART_IIDX_RX://如果是接收中断
		//接发送过来的数据保存在变量中
		uart_data = DL_UART_Main_receiveData(UART_1_INST);
		//将保存的数据再发送出去
		uart1_send_char(uart_data);
		break;

	default://其他的串口中断
		break;
	}



}
//





uint8_t RollL, RollH, PitchL, PitchH, YawL, YawH, VL, VH, SUM;
float Pitch_1,Roll_1,Yaw_1;
float zero_yaw;
// ????????
#define WAIT_HEADER1 0
#define WAIT_HEADER2 1
#define RECEIVE_DATA 2

uint8_t RxState = WAIT_HEADER1;
uint8_t receivedData[9];
uint8_t dataIndex = 0;



//??????????
void Serial_JY61P_Zero_Yaw(void)
	{
	
	    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X69);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X88);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XB5);
    delay_ms(200);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X24);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X01);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
    delay_ms(200);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
    delay_ms(100);
	
    DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X69);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X88);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XB5);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X01);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X04);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART3_jy901_INST,0X00);
	
}


void UART3_jy901_INST_IRQHandler(void) {
    uint8_t uartdata = DL_UART_Main_receiveData(UART3_jy901_INST); // ????uint8_t??

    switch (RxState) {
    case WAIT_HEADER1:
        if (uartdata == 0x55) {
            RxState = WAIT_HEADER2;
        }
        break;
    case WAIT_HEADER2:
        if (uartdata == 0x53) {
            RxState = RECEIVE_DATA;
            dataIndex = 0;
        } else {
            RxState = WAIT_HEADER1; // ???????????,????
        }
        break;
    case RECEIVE_DATA:
        receivedData[dataIndex++] = uartdata;
        if (dataIndex == 9) {
            // ??????,????????
            RollL = receivedData[0];
            RollH = receivedData[1];
            PitchL = receivedData[2];
            PitchH = receivedData[3];
            YawL = receivedData[4];
            YawH = receivedData[5];
            VL = receivedData[6];
            VH = receivedData[7];
            SUM = receivedData[8];

            // ??SUM????
            uint8_t calculatedSum = 0x55 + 0x53 + RollH + RollL + PitchH + PitchL + YawH + YawL + VH + VL;
            if (calculatedSum == SUM) {
                // ????,????????
                if((float)(((uint16_t)RollH << 8) | RollL)/32768*180>180){
                    Roll_1 = (float)(((uint16_t)RollH << 8) | RollL)/32768*180 - 360;
                }else{
                    Roll_1 = (float)(((uint16_t)RollH << 8) | RollL)/32768*180;
                }

                if((float)(((uint16_t)PitchH << 8) | PitchL)/32768*180>180){
                    Pitch_1 = (float)(((uint16_t)PitchH << 8) | PitchL)/32768*180 - 360;
                }else{
                    Pitch_1 = (float)(((uint16_t)PitchH << 8) | PitchL)/32768*180;
                }

                if((float)(((uint16_t)YawH << 8) | YawL)/32768*180 >180){
                    Yaw_1 = (float)(((uint16_t)YawH << 8) | YawL)/32768*180 - 360;
                }else{
                    Yaw_1 = (float)(((uint16_t)YawH << 8) | YawL)/32768*180;
                }
                
                
            } else {
                // ????,????
            }

            RxState = WAIT_HEADER1; // ?????????????
        }
        break;
    }

//DL_UART_Main_transmitData(UART3_jy901_INST, uartdata); // ??:????????
}









void Int_UART(void)
{
    //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_1_INST_INT_IRQN);    
	//清除串口中断标志
    NVIC_ClearPendingIRQ(UART3_jy901_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART3_jy901_INST_INT_IRQN);
	
}










