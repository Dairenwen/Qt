#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&th,&thread::notify,this,&Widget::handler);

    th.start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handler()
{
    qDebug()<<"线程触发信号"<<endl;
}

