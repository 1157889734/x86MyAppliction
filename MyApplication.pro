#-------------------------------------------------
#
# Project created by QtCreator 2021-07-21T01:26:24
#
#-------------------------------------------------

QT       += core gui widgets virtualkeyboard multimedia multimediawidgets sql


TARGET = monitor_ytj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

#QMAKE_CFLAGS += -strip
#QMAKE_CXXFLAGS += -strip

#QMAKE_CFLAGS += -g -O0
#QMAKE_CXXFLAGS += -g -O0

INCLUDEPATH += $$PWD/include
INCLUDEPATH += /home/cftc/toolchain/host/aarch64-buildroot-linux-gnu/sysroot/usr/include/rockchip/
#INCLUDEPATH += /home/cftc/toolchain/host/aarch64-buildroot-linux-gnu/sysroot/usr/include/libdrm
INCLUDEPATH += /home/cftc/toolchain/host/aarch64-buildroot-linux-gnu/sysroot/usr/include/rga/
LIBS += -L$$PWD/lib/  -ldl -lz -lbz2 -lrockchip_mpp -lrga -lpthread -lwayland-client

SOURCES += \
    ckeyboard.cpp \
    cmplayer.cpp \
    ctcppisclient.c \
    debugout/debug.c \
    led.c \
    main.cpp \
    MyApplication.cpp \
    choicelogindevwidget.cpp \
    loginwidget.cpp \
    mutex.cpp \
    pvmsmenuwidget.cpp \
    pvmsmonitorwidget.cpp \
    recordplaywidget.cpp \
#    inteanalywidget.cpp \
    devmanagewidget.cpp \
    devupdatewidget.cpp \
    alarmwidget.cpp \
    fileConfig.cpp \
    rtsp/Base64EncDec.c \
    rtsp/md5.c \
    rtsp/ourMD5.c \
    rtsp/rtcp.c \
    rtsp/rtp.c \
    rtsp/rtsp.c \
    rtsp/rtspApi.c \
    rtsp/rtspComm.c \
    shm.cpp \
    state.cpp \
#    timeset.cpp \
    gb2312_utf8.c \
    log.c \
    pmsgcli.c \
    presetpasswdconfirm.cpp \
    myslider.cpp \
#    qplayer.cpp \
#    useredit.cpp \
#    useradd.cpp \
#    usermanage.cpp \
    ftpApi.c \
    rs485serv.c \
    vdec.cpp \
    waitloginwidget.cpp \
    usergroupmanage.cpp
#    usermanageconfig.cpp

HEADERS += \
    MyApplication.h \
    choicelogindevwidget.h \
    ckeyboard.h \
    cmplayer.h \
    ctcppisclient.h \
    debugout/debug.h \
    define.h \
    led.h \
    loginwidget.h \
    mutex.h \
    pvmsmenuwidget.h \
    pvmsmonitorwidget.h \
    recordplaywidget.h \
#    inteanalywidget.h \
    devmanagewidget.h \
    devupdatewidget.h \
    alarmwidget.h \
#    debug.h \
    fileConfig.h \
    gb2312_utf8.h \
    log.h \
    pmsgcli.h \
    rtsp/Base64EncDec.h \
    rtsp/md5.h \
    rtsp/mutex.h \
    rtsp/ourMD5.h \
    rtsp/rtcp.h \
    rtsp/rtp.h \
    rtsp/rtsp.h \
    rtsp/rtspApi.h \
    rtsp/rtspComm.h \
    rtsp/types.h \
    shm.h \
    state.h \
#    timeset.h \
    types.h \
    presetpasswdconfirm.h \
    myslider.h \
#    qplayer.h \
#    useredit.h \
#    useradd.h \
#    usermanage.h \
    ftpApi.h \
    rs485serv.h \
    vdec.h \
    waitloginwidget.h \
    usergroupmanage.h
#    usermanageconfig.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
#    res.qrc \
    res.qrc

FORMS += \
    choicelogindevwidget.ui \
    ckeyboard.ui \
    loginwidget.ui \
    pvmsmenuwidget.ui \
    pvmsmonitorwidget.ui \
    recordplaywidget.ui \
#    inteanalywidget.ui \
    devmanagewidget.ui \
    devupdatewidget.ui \
    alarmwidget.ui \
    presetpasswdconfirm.ui \
    useredit.ui \
    useradd.ui \
    usermanage.ui \
    usergroupmanage.ui \
    waitloginwidget.ui \
    usermanageconfig.ui \
    devupdatewidget_base.ui

