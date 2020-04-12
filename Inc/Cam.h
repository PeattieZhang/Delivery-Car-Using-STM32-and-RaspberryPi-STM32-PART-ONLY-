/***************************************************************************************************
* @file				Cam.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			摄像头信息获取头文件，用于自动分派机器人。
*							本头文件没有对摄像头的控制，仅进行与树莓派之间的串行通讯（也可为其它能够对摄像头进行处理的设备）。
*							本项目要求有两个摄像头，一个位于机械臂上，用于识别物块颜色；一个位于底盘中心，用于识别特征点颜色。
*							需要有各个模块的驱动作为支持，相应的头文件在Operations.c中有引用。
*							需要用到的片内资源：
*								1.USART 异步串行与树莓派通信
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __CAM_H
#define __CAM_H

#include "stm32f1xx_hal.h"

/** 枚举 **/

/* Enum:					CAM
 * Description:		摄像头编号
 */
enum CAM{
	CAM0,																			//物块颜色识别摄像头
	CAM1,																			//特征点颜色识别摄像头
};
/* Enum:					COLOR
 * Description:		摄像头识别颜色返回值
 */
enum COLOR{
	BLUE,
	YELLOW,
	RED,
	BLACK,																		//一般为在直角拐弯点识别到的颜色
};

/** 外部函数声明 **/

void Cam_Init(void);												//初始化
void Cam_DeInit(void);											//反初始化
enum COLOR Cam_GetColour(enum CAM CAMx);		//获取摄像头识别的颜色

#endif
