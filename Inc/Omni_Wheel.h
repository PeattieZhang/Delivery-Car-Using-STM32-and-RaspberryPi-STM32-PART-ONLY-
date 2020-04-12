/***************************************************************************************************
* @file				Omni_Wheel.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			ȫ��������ͷ�ļ����ܹ�����װ��ȫ���ֵ�С������ƽ����ת��������
*							ȫ��������Ҫ�󣺷ֲ���ͬһ��Բ�ϣ����ĵ�λ��ȫ������������ȫ���������ĵ������ȣ������ɲ������������
*							��ȫ������ʱ�뷽��Ϊ�����������ڿ�����
*							ͷ�ļ����õ�������ϵ�������ӽ��½���ͷ���ϣ���ˮƽ����ΪX�ᣬ��ֱ����ΪY�ᣬ��ת����ʱ��Ϊ����
*							��Ҫ�õ���Ƭ����Դ��
*								1.TIMER ��������PWM��
*								2.
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __OMNI_H
#define __OMNI_H

#include "stm32f1xx_hal.h"

/** �궨�� **/



/** �ṹ�� **/

/* Struct:				Omni_MOVEMENTINFO
 * Description:		С���ƶ�״̬
 */
struct Omni_MOVEMENTINFO{
	int16_t XSPEED;																						//X���ٶ�
	int16_t YSPEED;																						//Y���ٶ�
	int16_t RSPEED;																						//��ת���ٶ�(degree/s)
};

/** �ⲿ�������� **/

void Omni_Init(void);																				//��ʼ��
void Omni_DeInit(void);																			//����ʼ��
void Omni_SetMovement(struct Omni_MOVEMENTINFO INFO);				//����С���ƶ�״̬
void Omni_AddMovement(struct Omni_MOVEMENTINFO INFO);				//��ԭ�ƶ�״̬�ϼ����µķ���
struct Omni_MOVEMENTINFO Omni_GetCurrentMovement(void);			//��ȡ��ǰ���ƶ�״̬

#endif
