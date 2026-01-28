#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpacerItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QLabel* label1=new QLabel("姓名",this);
//    QLabel* label2=new QLabel("年龄",this);
//    QLabel* label3=new QLabel("电话",this);
//    QLineEdit* edit1=new QLineEdit(this);
//    QLineEdit* edit2=new QLineEdit(this);
//    QLineEdit* edit3=new QLineEdit(this);

//    QPushButton* button=new QPushButton("commit",this);

//    QFormLayout* form=new QFormLayout();
//    form->addRow(label1,edit1);
//    form->addRow(label2,edit2);
//    form->addRow(label3,edit3);
//    form->addRow(nullptr,button);
//    this->setLayout(form);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::Grid()
{
    QPushButton* button1=new QPushButton("按钮1",this);
    QPushButton* button2=new QPushButton("按钮2",this);
    QPushButton* button3=new QPushButton("按钮3",this);
    QPushButton* button4=new QPushButton("按钮4",this);
    QPushButton* button5=new QPushButton("按钮5",this);
    QPushButton* button6=new QPushButton("按钮6",this);
    button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QGridLayout* grid=new QGridLayout();
    this->setLayout(grid);

    grid->addWidget(button1,0,0);
    grid->addWidget(button2,0,1);
    grid->addWidget(button3,1,0);
    grid->addWidget(button4,1,1);
    grid->addWidget(button5,2,0);
    grid->addWidget(button6,2,1);

//    //设置水平拉伸系数
//    //第 0 列拉伸比例为 1
//    grid->setColumnStretch(0,1);
//    //第 1 列不参与拉伸，保持固定大小
//    grid->setColumnStretch(1,0);
//    //第 2 列拉伸比例为 2
//    grid->setColumnStretch(2,2);

//    //设置垂直拉伸系数
//    grid->setRowStretch(0,1);
//    grid->setRowStretch(1,0);
//    grid->setRowStretch(2,2);

}

