/***************************************************************************************************
* @file				Omni_Wheel.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			全向轮驱动头文件，能够控制装有全向轮的小车进行平移与转动操作。
*							全向轮配置要求：分布于同一个圆上（中心点位于全向轮轴线上且全向轮与中心点距离相等），且由步进电机驱动。
*							以全向轮逆时针方向为正（由外向内看）。
*							头文件中用到的坐标系：俯视视角下将车头朝上，则水平向右为X轴，竖直向上为Y轴，旋转以逆时针为正。
*							需要用到的片内资源：
*								1.TIMER 用于生成PWM波
*								2.
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __OMNI_H
#define __OMNI_H

#include "stm32f1xx_hal.h"

/** 宏定义 **/



/** 结构体 **/

/* Struct:				Omni_MOVEMENTINFO
 * Description:		小车移动状态
 */
struct Omni_MOVEMENTINFO{
	int16_t XSPEED;																						//X轴速度
	int16_t YSPEED;																						//Y轴速度
	int16_t RSPEED;																						//旋转角速度(degree/s)
};

/** 外部函数声明 **/

void Omni_Init(void);																				//初始化
void Omni_DeInit(void);																			//反初始化
void Omni_SetMovement(struct Omni_MOVEMENTINFO INFO);				//设置小车移动状态
void Omni_AddMovement(struct Omni_MOVEMENTINFO INFO);				//在原移动状态上加上新的分量
struct Omni_MOVEMENTINFO Omni_GetCurrentMovement(void);			//获取当前的移动状态

#endif
