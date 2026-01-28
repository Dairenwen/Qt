#ifndef MYLABEL_H
#define MYLABEL_H

#include "QLabel"
#include <iostream>

class MyLabel : public QLabel
{
public:
    MyLabel(QWidget* parent);
    ~MyLabel();
};

#endif // MYLABEL_H
