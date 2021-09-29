#include "cmplayer.h"


typedef struct _T_CMP_INFO
{
    QMediaPlayer* pQqlayer;
    QVideoWidget* pQVideo;
    QMediaPlaylist* pQplaylist;
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
    ptCmpInfo->pQVideo = new QVideoWidget(palywidget);
    ptCmpInfo->pQVideo->setGeometry(0,0,782,630);
    ptCmpInfo->pQVideo->setStyleSheet("QWidget{background-color: rgb(0, 0, 0);}");     //设置播放窗口背景色为黑色
    ptCmpInfo->pQVideo->setObjectName("playbin");
    ptCmpInfo->pQqlayer->setVideoOutput(ptCmpInfo->pQVideo);

    ptCmpInfo->pQplaylist = new QMediaPlaylist();

    return (CMPHandle)ptCmpInfo;



}
int CMP_DestroyMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;

    if (ptCmpInfo)
    {
        delete ptCmpInfo->pQVideo;
        ptCmpInfo->pQVideo = NULL;

        delete ptCmpInfo->pQqlayer;
        ptCmpInfo->pQqlayer = NULL;

        delete ptCmpInfo->pQplaylist;
        ptCmpInfo->pQplaylist = NULL;

        free(ptCmpInfo);
        ptCmpInfo = NULL;
    }
    return 0;

}
int CMP_OpenMediaPreview(CMPHandle hPlay, const char *pcRtspUrl,int iTcpFlag)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;

    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    const QString str = QString::fromUtf8(pcRtspUrl);
    QUrl url(str);
    ptCmpInfo->pQplaylist->addMedia(url);
    ptCmpInfo->pQplaylist->setCurrentIndex(1);
    ptCmpInfo->pQplaylist->setPlaybackMode(QMediaPlaylist::Loop);
    ptCmpInfo->pQqlayer->setPlaylist( ptCmpInfo->pQplaylist);
    ptCmpInfo->pQqlayer->play();
    ptCmpInfo->pQVideo->show();
    qDebug()<<"*****CMP_OpenMediaPreview"<<__FUNCTION__<<__LINE__<<endl;
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
    ptCmpInfo->pQqlayer->setVideoOutput(ptCmpInfo->pQVideo);
    ptCmpInfo->pQqlayer->play();

    qDebug()<<"***********"<<__FUNCTION__<<__LINE__<<endl;
    return 0;

}

int CMP_SetWndDisplayEnable(CMPHandle hPlay, int iEnable)
{
//    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
//    if (NULL == ptCmpInfo)
//    {
//        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
//        return 0;
//    }
//    qDebug()<<"***********"<<ptCmpInfo<<__FUNCTION__<<__LINE__<<endl;
//    if(1 == iEnable)
//        ptCmpInfo->pQVideo->show();
//    else
//        ptCmpInfo->pQVideo->hide();

}
int CMP_CloseMedia(CMPHandle hPlay)
{
    T_CMP_INFO *ptCmpInfo = (T_CMP_INFO *)hPlay;
    if (NULL == ptCmpInfo)
    {
        qDebug()<<"****error****"<<__FUNCTION__<<__LINE__<<endl;
        return 0;
    }
    qDebug()<<"***"<<__LINE__<<endl;

    ptCmpInfo->pQqlayer->stop();
    qDebug()<<"*****CMP_CloseMedia"<<__FUNCTION__<<__LINE__<<endl;

    return 0;

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


