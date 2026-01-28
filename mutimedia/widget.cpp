#include "widget.h"
#include "ui_widget.h"
#include <QSound>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSound* sound=new QSound(":/tk.WAV",this);

    connect(ui->btn, &QPushButton::clicked, [=]() {
           sound->play();
       });
}

Widget::~Widget()
{
    delete ui;
}

