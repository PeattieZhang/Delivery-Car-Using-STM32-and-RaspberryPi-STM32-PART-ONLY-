#include "Operations.h"

/** ����ģ��������ͷ�ļ� **/

#include "Arm.h"
#include "Branch_Detect.h"
#include "Track_Detect.h"
#include "Cam.h"
#include "Omni_Wheel.h"

/** ö�� **/

/* Name:					BRANCH_DECISION
 * Description:		��֧�ھ���
 */
enum BRANCH_DECISION{
	DECITION_LEFT 		= 	 1,												//��֧����ת����
	DECITION_FORWARD 	= 	 0,												//��֧��ֱ�о���
	DECITION_RIGHT 		= 	-1,												//��֧����ת����
};

/** �������� **/

uint8_t STOP_FLAG;																//������ֹͣ�ж�FLAG
enum Op_STATUS STATUS;														//������״̬
enum COLOR OBJECT_COLOR;													//ץȡ������ɫ
uint8_t IS_GRABBED;																//�Ƿ�ץ�����
uint8_t IS_BACK;																	//�Ƿ��ڷ���HOME��;��
uint8_t BRANCH_CNT;																//��ǰ·����֧������
enum BRANCH_DECISION BRANCH_HISTORY[BRANCH_NUM];	//��֧�ھ�����ʷ�����ڷ���ʱ�ķ�֧�ھ���


/** �ڲ��������� **/

/* Function:			Internal_Stop()
 * Description:		�����˼��ٵ�ֹͣ
 */
void Internal_Stop(void){
}
/* Function:			Internal_Forward()
 * Description:		��������ǰǰ��һ�ξ���
 * Input:					ǰ������(mm)����ȷ�Ȳ��ߣ�
 */
void Internal_Forward(int16_t DISTANCE){
}
/* Function:			Internal_Rotate()
 * Description:		��������תһ���Ƕ�
 * Input:					��ת�Ƕ�(Degree)����ȷ�Ȳ��ߣ���Ҫ�жϸ�����
 */
void Internal_Rotate(int16_t DEGREE){
}

/** �ⲿ�������� **/

/* Function:			Op_Init()
 * Description:		��ʼ��
 */
void Op_Init(void){
	STOP_FLAG = 1;
	STATUS = NOT_ON_LINE;
	IS_GRABBED = 0;
	IS_BACK = 0;
	BRANCH_CNT = 0;
	Arm_Init();
	Cam_Init();
	Omni_Init();
}
/* Function:			Op_Init()
 * Description:		����ʼ��
 */
void Op_DeInit(void){
	STOP_FLAG = 1;
	IS_GRABBED = 0;
	Arm_DeInit();
	BD_DeInit();
	TD_DeInit(TD_FRONT);
	TD_DeInit(TD_BACK);
	Cam_DeInit();
	Omni_DeInit();
}
/* Function:			Op_GetOnLine()
 * Description:		�������Զ�������·
 *								STOP_FLAG=1���������˳�
 */
void Op_GetOnLine(void){//////////////////////////////////////////////////δ��ɣ��Ƿ���Ҫ�������ƣ�
	
}
/* Function:			Op_Line()
 * Description:		�������Զ�ѭ��
 *								������������:
 *									1.��������ʼ����BD��TD_BACK
 *									2.ǰ��
 *								STOP_FLAG=1ʱ�˳�
 */
void Op_Line(void){
	if(STATUS != READY) return;
	
	BD_Init();
	TD_Init(TD_BACK);
	struct Omni_MOVEMENTINFO LINE = {
		.XSPEED = 0,
		.YSPEED = LINE_SPEED,
		.RSPEED = 0,
	};
	Omni_SetMovement(LINE);
	while(!STOP_FLAG);
}
/* Function:			Op_Branch()
 * Description:		�ڷ�֧�ڵĲ���
 *								�����������£�
 *									0.У�����루���ж���ɣ�
 *									1.ʶ����ɫ
 *									2.ת��
 *								ת������˳�
 */
void Op_Branch(void){
	if(STATUS != BRANCH) return;
	
	if(IS_BACK){
		BRANCH_CNT --;
		Internal_Rotate(-BRANCH_HISTORY[BRANCH_CNT]*90);
	}
	else if(Cam_GetColour(CAM1) == OBJECT_COLOR || Cam_GetColour(CAM1) == BLACK){
		if(BD_DetectFlag(BD_RIGHT)) BRANCH_HISTORY[BRANCH_CNT] = DECITION_RIGHT;
		if(BD_DetectFlag(BD_LEFT)) 	BRANCH_HISTORY[BRANCH_CNT] = DECITION_LEFT;
		Internal_Rotate(BRANCH_HISTORY[BRANCH_CNT]*90);
		BRANCH_CNT ++;
	}
	else{
		BRANCH_HISTORY[BRANCH_CNT] = DECITION_FORWARD;
		BRANCH_CNT++;
	}
	Internal_Forward(ROBOT_LENGTH*FORWARD_COEFFICIENT);
	STATUS = READY;
}
/* Function:			Op_Cross()
 * Description:		��ʮ�ֵ�Ĳ���
 *								�����������£�
 *									0.У�����루���ж���ɣ�
 *									2.ץȡ/����
 *									3.��ͷ
 *								��ͷ����˳�
 */
void Op_Cross(void){
	if(STATUS != CROSS) return;
	
	if(IS_BACK && BRANCH_CNT){
		BRANCH_CNT --;
		Internal_Rotate(-BRANCH_HISTORY[BRANCH_CNT]*90);
		Internal_Forward(ROBOT_LENGTH*FORWARD_COEFFICIENT);
	}
	else{
		if(IS_GRABBED){
			Arm_Release();
			IS_BACK = 1;
		}
		else{/////////////////////////////////////////////////////////////////////////////��ץ��ʶ�� or ��ʶ����ץ��//û�������ʱӦ��������ͣ�£�����
			Arm_Grab();
			OBJECT_COLOR = Cam_GetColour(CAM0);
			IS_BACK = 0;
		}
		Internal_Forward(-ROBOT_LENGTH*FORWARD_COEFFICIENT);
		Internal_Rotate(180);
	}
	STATUS = READY;
}
/* Function:			Op_GetStatus()
 * Description:		��ȡ�����˵�ǰ״̬
 * Return:				�����˵�ǰ״̬(Op_STATUS)
 */
enum Op_STATUS Op_GetStatus(void){
	return STATUS;
}

/** �жϺ������� **/

//1Branch�ֲ�
//2Track�ֲ�
