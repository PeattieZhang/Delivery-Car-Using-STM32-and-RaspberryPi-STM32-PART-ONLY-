/***************************************************************************************************
* @file				Branch_Detect.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			分支口检测红外传感器头文件，主要为对红外传感器输出的获取并产生中断
*							需要用到的片内资源：
*								1.GPIO	传感器输入
*								2.NVIC	外部中断
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __BD_H
#define __BD_H

#include "stm32f1xx_hal.h"

/** 枚举 **/

/* Enum:					BD_SIDE
 * Description:		左右侧传感器，一般用于中断后判断分支在左、右or两侧都有分支（十字点）
 */
enum BD_SIDE{
	BD_LEFT,
	BD_RIGHT,
};

/** 外部函数声明 **/

void BD_Init(void);																	//初始化
void BD_DeInit(void);																//反初始化
uint8_t BD_DetectFlag(enum BD_SIDE SIDE);						//查看相应侧传感器是否检测到黑线

//ITR()

#endif
