#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    timerId=this->startTimer(1000);//类似于文件描述符

    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::handler);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_C&&event->modifiers()==Qt::ControlModifier)
    {
        qDebug()<<"Ctrl + C"<<endl;
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(timerId==event->timerId())//判断是当前定时器触发
    {
        int value=ui->lcdNumber->value();
        if(value<=0) this->killTimer(timerId);
        else ui->lcdNumber->display(value-1);
    }
}

void Widget::handler()
{
    int value=ui->lcdNumber->value();
    if(value<=0) timer->stop();
    else ui->lcdNumber->display(value-1);
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<event->oldSize()<<endl;
    qDebug()<<event->size()<<endl;
}

void Widget::moveEvent(QMoveEvent *event)
{
    qDebug()<<event->oldPos()<<endl;
    qDebug()<<event->pos()<<endl;
}





