#ifndef USERGROUPMANAGE_H
#define USERGROUPMANAGE_H

#include <QWidget>

namespace Ui {
class usergroupManage;
}

class usergroupManage : public QWidget
{
    Q_OBJECT

public:
    explicit usergroupManage(QWidget *parent = nullptr);
    ~usergroupManage();

private:
    Ui::usergroupManage *ui;
};

#endif // USERGROUPMANAGE_H
