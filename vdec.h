#ifndef _VDEC_H_
#define _VDEC_H_
#include <unistd.h>

#include "libdrm/planetest.h"

#include "mutex.h"
#include "types.h"
#include "debugout/debug.h"

#if 1

#define H264_CODE 0
#define H265_CODE 1



typedef struct
{
    pthread_t pthreadId;
    int iTaskExitFlag;

    int iLastPicWidth;
    int iLastPicHeight;
    int iX;
    int iY;
    int iWidth;
    int iHeight;

    MppPacket 		packet;
    MppFrame  		frame;

    MppCtx          ctx;
    MppApi          *mpi;

    /* end of stream flag when set quit the loop */
    RK_U32          eos;

    /* input and output */
    MppBufferGroup  frm_grp;
    MppBufferGroup  pkt_grp;

}T_VDEC_INFO;



#define STOP_STREAM_PLAY    0
#define START_STREAM_PLAY   1
#define PAUSE_STREAM_PLAY   2

typedef void* VDEC_HADNDLE;
typedef struct _T_DATA_PACKET
{
    char *pcData;
    int iLen;
    unsigned int iPts;
}T_DATA_PACKET, *PT_DATA_PACKET;

typedef struct _T_DATA_PACKET_LIST
{
    T_DATA_PACKET tPkt;
    struct _T_DATA_PACKET_LIST *next;
}T_DATA_PACKET_LIST, *PT_DATA_PACKET_LIST;

typedef struct _T_PACKET_QUEUE {
    T_DATA_PACKET_LIST *first_pkt, *last_pkt;
    int nb_packets;
    CMutexLock *mutex;
}T_PACKET_QUEUE;

typedef struct _T_VIDEO_DEC_INFO
{
    T_PACKET_QUEUE tPacketQueue;
    pthread_t hVideoDecodecThread;
    CMutexLock cMute;
    volatile int iVideoExitFlag;
    volatile int iVideoExitFlagOver;
    volatile int iStartPlayFlag;
    int iDecType;  //CMP_VDEC_TYPE
    T_WND_INFO  *ptWndInfo;
    T_VDEC_INFO *ptDecInfo;
    //RGA_HANDLE   pRgaHandle;

}T_VIDEO_DEC_INFO, *PT_VIDEO_DEC_INFO;


/*************************************************
  函数功能:     VDEC_Init
  函数描述:     初使化视频解码
  输入参数:     无
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-20
  修改:   
  备注：一个应用程序只需调用一次
*************************************************/
int VDEC_Init(void);

/*************************************************
  函数功能:     VDEC_Uninit
  函数描述:     反初使化视频解码
  输入参数:     无
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-20
  修改:   
*************************************************/
int VDEC_Uninit();

/*************************************************
  函数功能:     VDEC_CreateVideoDecCh
  函数描述:     创建视频解码通道
  输入参数:     iDecType解码类型（硬解码、软解码...）CMP_VDEC_TYPE
				hWnd 窗口句柄
  输出参数:     无
  返回值:       返回视频解码句柄,失败的话为空
  作者:         丁金奇
  日期:         2015-08-31
  修改:   
*************************************************/
VDEC_HADNDLE VDEC_CreateVideoDecCh(T_WND_INFO *pWndInfo, int iWidth, int iHeight,int iDecType,int iCodecID);
/*************************************************
  函数功能:     VDEC_DestroyVideoDecCh
  函数描述:     销毁视频解码通道
  输入参数:     VHandle:视频解码通道句柄
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2015-08-31
  修改:   
*************************************************/
int VDEC_DestroyVideoDecCh(VDEC_HADNDLE VHandle);

/*************************************************
  函数功能:     VDEC_SendStream
  函数描述:     发送解码流到视频解码模块
  输入参数:     pData:视频流
                iLen: 视频流长度
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-20
  修改:   
*************************************************/
int VDEC_SendVideoStream(VDEC_HADNDLE VHandle, void *pData, int iLen, unsigned int iPts);


/*************************************************
  函数功能:     VDEC_ChangeWindow
  函数描述:     改变显示窗口
  输入参数:     hWnd:新显示窗口
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-20
  修改:   
*************************************************/
int VDEC_ChangeWindow(VDEC_HADNDLE VHandle, const T_WND_INFO *pWndInfo);

/*************************************************
  函数功能:     VDEC_StartPlayStream
  函数描述:     开始播放解码流
  输入参数:     无
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-30
  修改:   
*************************************************/
int VDEC_StartPlayStream(VDEC_HADNDLE VHandle);

/*************************************************
  函数功能:     VDEC_StopPlayStream
  函数描述:     停止播放解码流
  输入参数:     无
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-30
  修改:   
*************************************************/
int VDEC_StopPlayStream(VDEC_HADNDLE VHandle);

/*************************************************
  函数功能:     VDEC_PausePlayStream
  函数描述:     暂停播放解码流
  输入参数:     无
  输出参数:     无
  返回值:       0:成功, 否则:失败
  作者:         丁金奇
  日期:         2014-04-30
  修改:   
*************************************************/
int VDEC_PausePlayStream(VDEC_HADNDLE VHandle);

#endif
#endif
