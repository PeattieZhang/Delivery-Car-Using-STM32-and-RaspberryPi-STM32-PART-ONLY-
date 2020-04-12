/***************************************************************************************************
* @file				Branch_Detect.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			��֧�ڼ����⴫����ͷ�ļ�����ҪΪ�Ժ��⴫��������Ļ�ȡ�������ж�
*							��Ҫ�õ���Ƭ����Դ��
*								1.GPIO	����������
*								2.NVIC	�ⲿ�ж�
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __BD_H
#define __BD_H

#include "stm32f1xx_hal.h"

/** ö�� **/

/* Enum:					BD_SIDE
 * Description:		���Ҳഫ������һ�������жϺ��жϷ�֧������or���඼�з�֧��ʮ�ֵ㣩
 */
enum BD_SIDE{
	BD_LEFT,
	BD_RIGHT,
};

/** �ⲿ�������� **/

void BD_Init(void);																	//��ʼ��
void BD_DeInit(void);																//����ʼ��
uint8_t BD_DetectFlag(enum BD_SIDE SIDE);						//�鿴��Ӧ�ഫ�����Ƿ��⵽����

//ITR()

#endif
