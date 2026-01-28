#include "widget.h"
#include "ui_widget.h"
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//      this->setStyleSheet("#pushButton{ color:red; } #pushButton_2{ color:green; }");

//    QString style = "";
//    style += "QPushButton { color: red; }";       // 默认红色
//    style += "QPushButton:!hover { color: green; }";// 悬停绿色
//    style += "QPushButton:!pressed { color: blue; }";// 按下蓝色
//    this->setStyleSheet(style);


//    QString style = "QPushButton { border: 5px solid red  }";
//    ui->pushButton->setStyleSheet(style);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::readFile()
{
    QFile file(":/file.txt");
    QString str;
    if (file.open(QIODevice::ReadOnly)) {
        str = file.readAll();
        file.close();
    }
    return str;
}

