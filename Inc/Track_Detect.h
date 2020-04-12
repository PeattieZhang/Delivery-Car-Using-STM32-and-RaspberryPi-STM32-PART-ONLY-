/***************************************************************************************************
* @file				Track_Detect.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			ѭ�����⴫����ͷ�ļ�����ҪΪ�Ժ��⴫��������Ļ�ȡ�������ж�
*							��Ҫ�õ���Ƭ����Դ��
*								1.GPIO	����������
*								2.NVIC	�ⲿ�ж�
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __TD_H
#define __TD_H

#include "stm32f1xx_hal.h"

/** ö�� **/

/* Enum:					TD_SIDE
 * Description:		���Ҳഫ������һ�������жϺ��ж�ƫ��orƫ��
 */
enum TD_SIDE{
	TD_LEFT,																		//��ഫ����
	TD_RIGHT,																		//�Ҳഫ����
};
/* Enum:					ED_GROUP
 * Description:		��������
 */
enum TD_GROUP{
	TD_FRONT,																		//ǰ��������������ɵĴ�������
	TD_BACK,																		//��������������ɵĴ�������
	TD_BOTH,																		//ѡ��������������
	TD_NONE,																		//û��ѡ�д�������
};

/** �ⲿ�������� **/

void TD_Init(enum TD_GROUP GROUP);						//��ʼ��
void TD_DeInit(enum TD_GROUP GROUP);					//����ʼ��
enum TD_GROUP TD_CurrentGroup(void);					//��ȡ��ǰ��������
uint8_t TD_DetectFlag(enum TD_SIDE SIDE);			//�鿴��Ӧ�ഫ�����Ƿ��⵽����

#endif
