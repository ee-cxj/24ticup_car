#ifndef uart_h
#define uart_h
#include "board.h"
#include "stdio.h"
void uart0_send_char(char ch);
void uart0_send_string(char* str);
void UART_0_INST_IRQHandler(void);
void uart1_send_char(char ch);
void uart1_send_string(char* str);
void UART_1_INST_IRQHandler(void);
void uart3_send_char(char ch);
void uart3_send_string(char* str);
void UART_3_INST_IRQHandler(void);
void Int_UART(void);
void Serial_JY61P_Zero_Yaw(void);
extern float Pitch_1,Roll_1,Yaw_1;

#endif
