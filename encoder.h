#ifndef encoder_h
#define encoder_h
#include "board.h"
#include "stdio.h"
#include "ti_msp_dl_config.h"

#define GPIO_EncoderA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
void Int_Encoder(void);
#define AIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(GPIO_AIN_PORT,GPIO_AIN_AIN1_PIN)) : (DL_GPIO_clearPins(GPIO_AIN_PORT,GPIO_AIN_AIN1_PIN)) )
#define AIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(GPIO_AIN_PORT,GPIO_AIN_AIN2_PIN)) : (DL_GPIO_clearPins(GPIO_AIN_PORT,GPIO_AIN_AIN2_PIN)) )

#define BIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(GPIO_BIN_PORT,GPIO_BIN_BIN1_PIN)) : (DL_GPIO_clearPins(GPIO_BIN_PORT,GPIO_BIN_BIN1_PIN)) )
#define BIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(GPIO_BIN_PORT,GPIO_BIN_BIN2_PIN)) : (DL_GPIO_clearPins(GPIO_BIN_PORT,GPIO_BIN_BIN2_PIN)) )
extern int gEncoderCountA;
extern int gEncoderCountB; 
extern int16_t Left_count;
extern int16_t Right_count;
#define SPEED_F 100  //10ms中断
#define L_QD_UNIT 3530//
#define R_QD_UNIT 3530

extern float e_distance;
void GetSpeed(void);
#endif