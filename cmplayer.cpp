#include "cmplayer.h"
#include "math.h"


typedef struct _T_CMP_INFO
{
    QMediaPlayer* pQqlayer;
    QVideoWidget* pQVideo;

} T_CMP_INFO;


int CMP_Init(void)
{



}
int CMP_UnInit(void)
{


}



CMPHandle CMP_CreateMedia(QWidget *palywidget)
{
    T_CMP_INFO *ptCmpInfo = NULL;

    ptCmpInfo = (T_CMP_INFO *)malloc(sizeof(T_CMP_INFO));
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return NULL;
    }

    ptCmpInfo->pQqlayer = new QMediaPlayer(palywidget,QMediaPlayer::LowLatency);
    ptCmpInfo->pQVideo= new QVideoWidget(palywidget);
    if(palywidget->winId() != 6)
        ptCmpInfo->pQVideo->setGeometry(0,0,730,555);
    else
        ptCmpInfo->pQVideo->setGeometry(0,0,782,630);

    ptCmpInfo->pQVideo->setStyleSheet("QWidget{background-color: rgb(0, 0, 0);}");     //设置播放窗口背景色为黑色
    ptCmpInfo->pQVideo->setObjectName("playbin");
    ptCmpInfo->pQqlayer->setVideoOutput(ptCmpInfo->pQVideo);

    return (CMPHandle)ptCmpInfo;

}


int CMP_ChangeWnd(CMPHandle hPlay, WId QWnd)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;

    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQVideo->setGeometry(0,0,1024,768);


}
int CMP_DestroyMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO*)hPlay;

    if (ptCmpInfo)
    {
        delete ptCmpInfo->pQqlayer;
        ptCmpInfo->pQqlayer = NULL;

        delete ptCmpInfo->pQVideo;
        ptCmpInfo->pQVideo = NULL;

        free(ptCmpInfo);
        ptCmpInfo = NULL;
    }
    return 0;

}
int CMP_OpenMediaPreview(CMPHandle hPlay,const char *pcRtspFile,int iTcpFlag)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;

    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }

    const QString str = QString::fromUtf8(pcRtspFile);
    QUrl url(str);

    ptCmpInfo->pQqlayer->setMedia(url);
    ptCmpInfo->pQqlayer->play();
    ptCmpInfo->pQVideo->show();

    return 0;

}

int CMP_OpenMediaFile(CMPHandle hPlay, const char *pcRtspFile,int iTcpFlag)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    const QString str = QString::fromUtf8(pcRtspFile);
    QUrl url(str);
    ptCmpInfo->pQqlayer->setMedia(url);
    ptCmpInfo->pQqlayer->play();
    ptCmpInfo->pQVideo->show();

    return 0;

}

int CMP_SetWndDisplayEnable(CMPHandle hPlay, int iEnable)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    if(1 == iEnable)
        ptCmpInfo->pQVideo->show();
    else
        ptCmpInfo->pQVideo->hide();

}
int CMP_CloseMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQqlayer->stop();

    return 0;

}

int CMP_GetPlayStatus(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    return ptCmpInfo->pQqlayer->state();
}

int CMP_PlayMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQqlayer->play();
    return 0;

}
int CMP_PauseMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQqlayer->pause();
    return 0;

}

int CMP_SetPosition(CMPHandle hPlay, int nPosTime)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
     ptCmpInfo->pQqlayer->setPosition(nPosTime);
     return 0;

}
int CMP_SetPlaySpeed(CMPHandle hPlay, double dSpeed)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQqlayer->setMuted(dSpeed);
    return 0;

}
int CMP_GetPlayRange(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    return  ptCmpInfo->pQqlayer->duration();
}
int CMP_GetCurrentPlayTime(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    return  ptCmpInfo->pQqlayer->position();

}
int CMP_SetPlayRate(CMPHandle hPlay,qreal rate)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    ptCmpInfo->pQqlayer->setPlaybackRate(rate);

    return 0;
}
