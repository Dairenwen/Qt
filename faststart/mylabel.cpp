#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent)
    :QLabel(parent)
{
    qDebug()<<"mylabel constructed!";
}

MyLabel::~MyLabel()
{
    qDebug()<<"mylabel destroyed!";
}
