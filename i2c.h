#ifndef i2c_h
#define i2c_h
#include "board.h"
#include "stdio.h"
#include "ti_msp_dl_config.h"


uint8_t i2c0_write_n_byte(uint8_t DevAddr, uint8_t RegAddr, uint8_t *buf, uint8_t nBytes);
void  i2c0_read_n_byte(uint8_t DevAddr, uint8_t RegAddr, uint8_t *buf, uint8_t nBytes);

void I2C_WriteReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t *reg_data, uint8_t count);
void I2C_ReadReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t *reg_data, uint8_t count);

#endif