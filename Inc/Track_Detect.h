/***************************************************************************************************
* @file				Track_Detect.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			循迹红外传感器头文件，主要为对红外传感器输出的获取并产生中断
*							需要用到的片内资源：
*								1.GPIO	传感器输入
*								2.NVIC	外部中断
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __TD_H
#define __TD_H

#include "stm32f1xx_hal.h"

/** 枚举 **/

/* Enum:					TD_SIDE
 * Description:		左右侧传感器，一般用于中断后判断偏左or偏右
 */
enum TD_SIDE{
	TD_LEFT,																		//左侧传感器
	TD_RIGHT,																		//右侧传感器
};
/* Enum:					ED_GROUP
 * Description:		传感器组
 */
enum TD_GROUP{
	TD_FRONT,																		//前方两个传感器组成的传感器组
	TD_BACK,																		//后方两个传感器组成的传感器组
	TD_BOTH,																		//选中两个传感器组
	TD_NONE,																		//没有选中传感器组
};

/** 外部函数声明 **/

void TD_Init(enum TD_GROUP GROUP);						//初始化
void TD_DeInit(enum TD_GROUP GROUP);					//反初始化
enum TD_GROUP TD_CurrentGroup(void);					//获取当前传感器组
uint8_t TD_DetectFlag(enum TD_SIDE SIDE);			//查看相应侧传感器是否检测到黑线

#endif
