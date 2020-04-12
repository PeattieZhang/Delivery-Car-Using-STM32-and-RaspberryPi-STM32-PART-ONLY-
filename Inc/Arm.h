/***************************************************************************************************
* @file				Arm.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			��е������ͷ�ļ���Ŀǰ�趨Ϊֻ��һ��ץ��
*							��Ҫ�õ���Ƭ����Դ��
*								1.TIMER	PWM������
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __ARM_H
#define __ARM_H

#include "stm32f1xx_hal.h"

/** �ⲿ�������� **/

void Arm_Init(void);					//��ʼ��
void Arm_DeInit(void);				//����ʼ��
void Arm_Grab(void);					//ץȡ���
void Arm_Release(void);				//�ͷ����

#endif
