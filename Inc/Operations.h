/***************************************************************************************************
* @file				Operations.h
* @author 		PeattieZhang
* @version		1.0
* @date				04-12-2020 
* @brief			���ڷ��ɻ������ж���ͷ�ļ�����main.c���ñ��ļ��еĺ�����ʵ�ֶԻ����˵Ŀ��ơ�
*							��Ҫ�и���ģ���������Ϊ֧�֣���Ӧ��ͷ�ļ���Operations.c�������á�
*							��Ҫ�õ���Ƭ����Դ��������ģ����������
*								1.����
* @updates		NULL
* 
***************************************************************************************************/
#ifndef __OP_H
#define __OP_H

#include "stm32f1xx_hal.h"

/** �궨�� **/

#define			LINE_SPEED						1			//ѭ��ʱ���ٶȣ���λ��ûȷ��
#define			BRANCH_NUM						3			//��֧����
#define			ROBOT_LENGTH					300		//������ǰ�󳤶�(mm)
#define			FORWARD_COEFFICIENT		0.6		//�������ڲ��ת������ʮ�ֵ��ͷǰ�ƶ�ϵ��

/** ö�� **/

/* Enum:					Op_STATUS
 * Description:		�����˵�ǰ״̬
 */
enum Op_STATUS{
	NOT_ON_LINE,													//�޷�ȷ���Ƿ������·��һ��ֻ�ڳ�ʼ�������
	READY,																//����ָ�������������׼��ѭ��
	BRANCH,																//�ڷ�֧��
	CROSS,																//��ʮ�ֵ㣨����������HOME���ı�־��
};

/** �ⲿ�������� **/

extern uint8_t STOP_FLAG;								//������ֹͣ�ж�FLAG

/** �ⲿ�������� **/

void Op_Init(void);											//��ʼ��
void Op_DeInit(void);										//����ʼ��
void Op_GetOnLine(void);								//����ʱȷ��������·
void Op_Line(void);											//ѭ��
void Op_Branch(void);										//��֧�ڲ���
void Op_Cross(void);										//ʮ�ֵ����
enum Op_STATUS Op_GetStatus(void);			//��ȡ��ǰ״̬

#endif
