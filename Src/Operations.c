#include "Operations.h"

/** 各个模块驱动的头文件 **/

#include "Arm.h"
#include "Branch_Detect.h"
#include "Track_Detect.h"
#include "Cam.h"
#include "Omni_Wheel.h"

/** 枚举 **/

/* Name:					BRANCH_DECISION
 * Description:		分支口决策
 */
enum BRANCH_DECISION{
	DECITION_LEFT 		= 	 1,												//分支口左转决策
	DECITION_FORWARD 	= 	 0,												//分支口直行决策
	DECITION_RIGHT 		= 	-1,												//分支口右转决策
};

/** 参数声明 **/

uint8_t STOP_FLAG;																//机器人停止行动FLAG
enum Op_STATUS STATUS;														//机器人状态
enum COLOR OBJECT_COLOR;													//抓取物块的颜色
uint8_t IS_GRABBED;																//是否抓有物块
uint8_t IS_BACK;																	//是否在返回HOME区途中
uint8_t BRANCH_CNT;																//当前路过分支口数量
enum BRANCH_DECISION BRANCH_HISTORY[BRANCH_NUM];	//分支口决策历史，用于返回时的分支口决策


/** 内部函数定义 **/

/* Function:			Internal_Stop()
 * Description:		机器人减速到停止
 */
void Internal_Stop(void){
}
/* Function:			Internal_Forward()
 * Description:		机器人向前前进一段距离
 * Input:					前进距离(mm)（精确度不高）
 */
void Internal_Forward(int16_t DISTANCE){
}
/* Function:			Internal_Rotate()
 * Description:		机器人旋转一定角度
 * Input:					旋转角度(Degree)（精确度不高，需要中断辅助）
 */
void Internal_Rotate(int16_t DEGREE){
}

/** 外部函数定义 **/

/* Function:			Op_Init()
 * Description:		初始化
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
 * Description:		反初始化
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
 * Description:		机器人自动对齐线路
 *								STOP_FLAG=1或对齐完毕退出
 */
void Op_GetOnLine(void){//////////////////////////////////////////////////未完成，是否需要按键控制？
	
}
/* Function:			Op_Line()
 * Description:		机器人自动循迹
 *								操作内容如下:
 *									1.开启（初始化）BD与TD_BACK
 *									2.前行
 *								STOP_FLAG=1时退出
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
 * Description:		在分支口的操作
 *								操作内容如下：
 *									0.校正对齐（由中断完成）
 *									1.识别颜色
 *									2.转向
 *								转向完毕退出
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
 * Description:		在十字点的操作
 *								操作内容如下：
 *									0.校正对齐（由中断完成）
 *									2.抓取/放置
 *									3.调头
 *								调头完毕退出
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
		else{/////////////////////////////////////////////////////////////////////////////先抓再识别 or 先识别再抓？//没有新物块时应该在这里停下！！！
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
 * Description:		获取机器人当前状态
 * Return:				机器人当前状态(Op_STATUS)
 */
enum Op_STATUS Op_GetStatus(void){
	return STATUS;
}

/** 中断函数定义 **/

//1Branch分叉
//2Track分叉
