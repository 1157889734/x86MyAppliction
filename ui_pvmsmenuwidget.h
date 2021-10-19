/********************************************************************************
** Form generated from reading UI file 'pvmsmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVMSMENUWIDGET_H
#define UI_PVMSMENUWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pvmsMenuWidget
{
public:
    QPushButton *pvmsMonitorMenuPushButton;
    QPushButton *recordPlayMenuPushButton;
    QPushButton *devManageMenuPushButton;
    QPushButton *devUpdateMenuPushButton;
    QLabel *label;

    void setupUi(QWidget *pvmsMenuWidget)
    {
        if (pvmsMenuWidget->objectName().isEmpty())
            pvmsMenuWidget->setObjectName(QString::fromUtf8("pvmsMenuWidget"));
        pvmsMenuWidget->resize(1024, 768);
        pvmsMenuWidget->setLayoutDirection(Qt::LeftToRight);
        pvmsMenuWidget->setStyleSheet(QString::fromUtf8("#pvmsMenuWidget { \n"
"border-image: url(:/monres/Pantobg.bmp); \n"
"} \n"
"#pvmsMenuWidget * { \n"
"border-image:url(); \n"
"}\n"
""));
        pvmsMonitorMenuPushButton = new QPushButton(pvmsMenuWidget);
        pvmsMonitorMenuPushButton->setObjectName(QString::fromUtf8("pvmsMonitorMenuPushButton"));
        pvmsMonitorMenuPushButton->setGeometry(QRect(0, 35, 255, 102));
        pvmsMonitorMenuPushButton->setMinimumSize(QSize(250, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(18);
        pvmsMonitorMenuPushButton->setFont(font);
        pvmsMonitorMenuPushButton->setAutoFillBackground(false);
        pvmsMonitorMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(34, 172, 211);}\n"
"\n"
"#QPushButton:hover{border-color: rgb(255, 255, 255);border-width: 2px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}\n"
"\n"
"\n"
"\n"
""));
        pvmsMonitorMenuPushButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        pvmsMonitorMenuPushButton->setIconSize(QSize(16, 16));
        pvmsMonitorMenuPushButton->setCheckable(true);
        pvmsMonitorMenuPushButton->setChecked(false);
        pvmsMonitorMenuPushButton->setAutoRepeatDelay(300);
        pvmsMonitorMenuPushButton->setAutoRepeatInterval(100);
        pvmsMonitorMenuPushButton->setFlat(false);
        recordPlayMenuPushButton = new QPushButton(pvmsMenuWidget);
        recordPlayMenuPushButton->setObjectName(QString::fromUtf8("recordPlayMenuPushButton"));
        recordPlayMenuPushButton->setGeometry(QRect(256, 35, 255, 102));
        QFont font1;
        font1.setPointSize(18);
        recordPlayMenuPushButton->setFont(font1);
        recordPlayMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(34, 172, 211);}\n"
"\n"
"#QPushButton:hover{border-color: rgb(255, 255, 255);border-width: 2px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        recordPlayMenuPushButton->setCheckable(true);
        recordPlayMenuPushButton->setFlat(false);
        devManageMenuPushButton = new QPushButton(pvmsMenuWidget);
        devManageMenuPushButton->setObjectName(QString::fromUtf8("devManageMenuPushButton"));
        devManageMenuPushButton->setGeometry(QRect(511, 35, 255, 102));
        devManageMenuPushButton->setFont(font1);
        devManageMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(34, 172, 211);}\n"
"\n"
"#QPushButton:hover{border-color: rgb(255, 255, 255);border-width: 2px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        devManageMenuPushButton->setCheckable(true);
        devManageMenuPushButton->setFlat(false);
        devUpdateMenuPushButton = new QPushButton(pvmsMenuWidget);
        devUpdateMenuPushButton->setObjectName(QString::fromUtf8("devUpdateMenuPushButton"));
        devUpdateMenuPushButton->setEnabled(true);
        devUpdateMenuPushButton->setGeometry(QRect(766, 35, 257, 102));
        devUpdateMenuPushButton->setFont(font1);
        devUpdateMenuPushButton->setCursor(QCursor(Qt::ArrowCursor));
        devUpdateMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(34, 172, 211);}\n"
"\n"
"#QPushButton:hover{border-color: rgb(255, 255, 255);border-width: 2px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{border-color: rgb(170, 170, 170);border-width: 2px;border-style: solid;}"));
        devUpdateMenuPushButton->setIconSize(QSize(203, 102));
        devUpdateMenuPushButton->setCheckable(true);
        devUpdateMenuPushButton->setFlat(false);
        label = new QLabel(pvmsMenuWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1024, 768));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label->raise();
        pvmsMonitorMenuPushButton->raise();
        recordPlayMenuPushButton->raise();
        devManageMenuPushButton->raise();
        devUpdateMenuPushButton->raise();

        retranslateUi(pvmsMenuWidget);

        QMetaObject::connectSlotsByName(pvmsMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *pvmsMenuWidget)
    {
        pvmsMenuWidget->setWindowTitle(QCoreApplication::translate("pvmsMenuWidget", "Form", nullptr));
        pvmsMonitorMenuPushButton->setText(QString());
        recordPlayMenuPushButton->setText(QString());
        devManageMenuPushButton->setText(QString());
        devUpdateMenuPushButton->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pvmsMenuWidget: public Ui_pvmsMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVMSMENUWIDGET_H
