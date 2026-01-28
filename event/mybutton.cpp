#include "mybutton.h"
#include "widget.h"

mybutton::mybutton(QWidget *parent)
    :QPushButton(parent)
{
    this->setMouseTracking(true);
}
mybutton::~mybutton()
{

}

void mybutton::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入"<<endl;
}

void mybutton::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开"<<endl;
}

void mybutton::mousePressEvent(QMouseEvent *ev) {
    // 鼠标左键（窗口内坐标）
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标左键: x=%1, y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << str.toUtf8().data();
    }
    // 鼠标右键（屏幕坐标）
    if (ev->button() == Qt::RightButton) {
        QString str = QString("鼠标右键: 屏幕 x=%1, 屏幕 y=%2").arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str.toUtf8().data();
    }
}


void mybutton::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "鼠标左键被双击";
    }
    else if(event->button()==Qt::RightButton)
    {
        qDebug() << "鼠标右键被双击";
    }
}

void mybutton::mouseMoveEvent(QMouseEvent *event)
{
    // 输出鼠标当前窗口内坐标
    qDebug() << "[" << event->x() << "," << event->y() << "]";
}

void mybutton::wheelEvent(QWheelEvent *event)
{
    static int x = 0;
    x += event->delta(); // delta() 每次滚动默认返回 ±120
    if (event->delta() > 0) {
        qDebug() << "滚轮往前" << x;
    } else {
        qDebug() << "滚轮往后" << x;
    }
}
