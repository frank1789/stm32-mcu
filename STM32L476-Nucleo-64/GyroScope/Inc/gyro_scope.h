/*
 * gyro_scope.h
 *
 *  Created on: 2018/07/18
 */

#ifndef GYRO_SCOPE_H_
#define GYRO_SCOPE_H_

#include <stdint.h>
#include <stm32l4xx_hal.h>
#include <stm32l4xx_hal_i2c.h>

#define L3GD20_I2C_ADDRESS 0b01101011 // STMicro L3GD20 gyro scope

// Register list
#define WHO_AM_I 0x0fU
#define RES_OK 0xd4U
#define CTRL_REG1 0x20U
#define OUT_TEMP 0x26U
#define OUT_X_L 0x28U
#define OUT_X_H 0x29U
#define OUT_Y_L 0x2aU
#define OUT_Y_H 0x2bU
#define OUT_Z_L 0x2cU
#define OUT_Z_H 0x2dU

#define ENABLE 0x0fU  // power on
#define SENSIVITY 0.00875f

void write_data(uint8_t reg_addr, uint8_t data);
uint8_t read_data(uint8_t reg_addr);

uint8_t init_l3gd20(void);
int8_t get_temp(void);
int16_t get_motion(char axis);

#endif /* GYRO_SCOPE_H_ */
