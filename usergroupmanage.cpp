#include "usergroupmanage.h"
#include "ui_usergroupmanage.h"

usergroupManage::usergroupManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usergroupManage)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setSectionsClickable(false); //设置表头不可点击
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    ui->tableWidget->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白
    ui->tableWidget->horizontalHeader()->resizeSection(0,46); //设置表头第一列的宽度为46
    ui->tableWidget->horizontalHeader()->resizeSection(1,136);
    ui->tableWidget->horizontalHeader()->resizeSection(2,136);
    ui->tableWidget->horizontalHeader()->resizeSection(3,136);
    ui->tableWidget->horizontalHeader()->resizeSection(4,116);
    ui->tableWidget->horizontalHeader()->resizeSection(5,116);
    ui->tableWidget->horizontalHeader()->resizeSection(6,111);


}

usergroupManage::~usergroupManage()
{
    delete ui;
}
