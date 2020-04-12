#include "Track_Detect.h"

/** 外部函数定义 **/

/* Function:			TD_Init()
 * Description:		初始化
 * Input:					要初始化的传感器组
 */
void TD_Init(enum TD_GROUP GROUP){
}
/* Function:			TD_DeInit()
 * Description:		反初始化
 * Input:					要反初始化的传感器组
 */
void TD_DeInit(enum TD_GROUP GROUP){
}
/* Function:			TD_CurrentGroup()
 * Description:		获取当前传感器组
 * Return:				当前传感器组					
 */
enum TD_GROUP TD_CurrentGroup(void){
}
/* Function:			TD_DetectFlag()
 * Description:		查看相应侧传感器是否检测到黑线
 * Input:					要查看的一侧
 * Output:				是否检测到黑线
 */
uint8_t TD_DetectFlag(enum TD_SIDE SIDE){
}
