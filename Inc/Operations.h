/***************************************************************************************************
* @file				Operations.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			用于分派机器人行动的头文件，在main.c调用本文件中的函数可实现对机器人的控制。
*							需要有各个模块的驱动作为支持，相应的头文件在Operations.c中有引用。
*							需要用到的片内资源（不包含模块驱动）：
*								1.待定
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __OP_H
#define __OP_H

#include "stm32f1xx_hal.h"

/** 宏定义 **/

#define			LINE_SPEED						1			//循迹时的速度，单位还没确定
#define			BRANCH_NUM						3			//分支数量
#define			ROBOT_LENGTH					300		//机器人前后长度(mm)
#define			FORWARD_COEFFICIENT		0.6		//机器人在岔口转向后或在十字点调头前移动系数

/** 枚举 **/

/* Enum:					Op_STATUS
 * Description:		机器人当前状态
 */
enum Op_STATUS{
	NOT_ON_LINE,													//无法确定是否对齐线路，一般只在初始化后出现
	READY,																//已在指定点结束动作，准备循迹
	BRANCH,																//在分支口
	CROSS,																//在十字点（物块放置区与HOME区的标志）
};

/** 外部变量声明 **/

extern uint8_t STOP_FLAG;								//机器人停止行动FLAG

/** 外部函数声明 **/

void Op_Init(void);											//初始化
void Op_DeInit(void);										//反初始化
void Op_GetOnLine(void);								//启动时确保对齐线路
void Op_Line(void);											//循迹
void Op_Branch(void);										//分支口操作
void Op_Cross(void);										//十字点操作
enum Op_STATUS Op_GetStatus(void);			//获取当前状态

#endif
