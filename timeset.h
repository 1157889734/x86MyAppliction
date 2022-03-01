#ifndef TIMESET_H
#define TIMESET_H

#include <QWidget>
#include <QTimer>
#include <QButtonGroup>

namespace Ui {
class timeset;
}

class timeset : public QWidget
{
    Q_OBJECT

public:
    explicit timeset(QWidget *parent = nullptr);
    ~timeset();

    void setTimeLabelText(int year, int month, int day, int hour, int min, int sec);
    QButtonGroup *timeGroupButton;
    int clickButtonNum;

public slots:
    void cancleButtonClick();
    void okButtonClick();
    void stButtonClick(int id);

signals:
    void timeSetSendMsg(QString year, QString month, QString day, QString hour, QString min, QString sec);
    void cancleMsg();

private:
    Ui::timeset *ui;


};

#endif // TIMESET_H
