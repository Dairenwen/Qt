#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPushButton* button=new QPushButton("按钮",this);
//    button->move(200,250);
//    button->setEnabled(false);

//    connect(button,&QPushButton::click,this,&Widget::handlerfunc);

    this->setWindowTitle("这是我的窗口");
    this->setWindowIcon(QIcon(":/favicon.png"));
    //this->setCursor(QCursor(Qt::WaitCursor));

    QPixmap pixmap(":/favicon.png");
    // 缩放图⽚为 64 * 64 的尺⼨.
    pixmap = pixmap.scaled(64, 64);
    // 创建 QCursor 对象, 并指定 "热点"(⿏标点击时生效的位置) 为 (2, 2) 坐标位置，默认生效位置在左上角。
    QCursor cursor(pixmap, 2, 2);
    // 设置光标
    this->setCursor(cursor);

    ui->pushButton_target->setFont(QFont("JetBrains Mono",20,7,false));

    ui->pushButton_target->setToolTip("<font color='#336699' size='3'>点击该按钮执行提交操作</font>");
    ui->pushButton_target->setToolTipDuration(3000);

    ui->lineEdit->setFocusPolicy(Qt::ClickFocus);

    ui->pushButton_target->setStyleSheet("font-family:'JetBrains Mono';font-size: 18px;background-color: #282C34; color: yellow");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::handlerfunc()
{
    qDebug()<<"handler";
}



void Widget::on_pushButton_target_clicked()
{

}

void Widget::on_pushButton_up_clicked()
{
    QRect rect=ui->pushButton_target->geometry();//获取到rect后更改并注意要重新set回去
    qDebug()<<rect;
    //rect.setY(rect.y()-5);
    ui->pushButton_target->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect=ui->pushButton_target->geometry();
    qDebug()<<rect;
    //rect.setX(rect.x()-5);
    ui->pushButton_target->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    QRect rect=ui->pushButton_target->geometry();
    qDebug()<<rect;
    //rect.setX(rect.x()+5);
    ui->pushButton_target->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    QRect rect=ui->pushButton_target->geometry();
    qDebug()<<rect;
    //rect.setY(rect.y()+5);
    ui->pushButton_target->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}
