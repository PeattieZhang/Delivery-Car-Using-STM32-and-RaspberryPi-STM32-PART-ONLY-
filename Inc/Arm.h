/***************************************************************************************************
* @file				Arm.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			机械臂驱动头文件，目前设定为只有一个抓手
*							需要用到的片内资源：
*								1.TIMER	PWM波控制
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __ARM_H
#define __ARM_H

#include "stm32f1xx_hal.h"

/** 外部函数声明 **/

void Arm_Init(void);					//初始化
void Arm_DeInit(void);				//反初始化
void Arm_Grab(void);					//抓取物块
void Arm_Release(void);				//释放物块

#endif
