#include "sys.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"
#include "can.h"

typedef struct _CANMAGS_ST{
      u16 mags[2];              //磁条位图。从左至右低位排列。1，检测到。
      u8  OnMag[2];             //磁条点位数
      s8  magdata[2];        //磁条位置数据
      s8  zyfx;              //左右转向。
      u8  DRVERR[2];       //驱动器故障 .1秒频率的错误累加。
}xCANMAGS_D;

extern QueueHandle_t xCANMAGS;  //从中断接收
extern xCANMAGS_D CAR_MAGS;
extern void MAGS_task(void *pv);//启动读卡器命令

