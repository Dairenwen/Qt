#include "widget.h"
#include "ui_widget.h"//formfile头文件
#include "QLabel"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);//将formfile生成的文件与Widget关联

    MyLabel* mylabel=new MyLabel(this);
    mylabel->setText("hello world!");

}

Widget::~Widget()
{
    delete ui;
}

