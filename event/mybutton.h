#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <iostream>
#include <QMouseEvent>
#include <QWheelEvent>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    mybutton(QWidget *parent = nullptr);
    ~mybutton();

    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent* event);

    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
};

#endif // MYBUTTON_H
