#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget> //QWidget头文件，Qt中头文件和类名是一致的，方便包含

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; } // UI设计界面的命名空间
QT_END_NAMESPACE

class Widget : public QWidget //Widght继承自QWidget
{
    Q_OBJECT // 启用信号与槽机制的宏

public:
    Widget(QWidget *parent = nullptr); //对象树机制，新增节点需要挂到树上
    ~Widget();

private:
    Ui::Widget *ui; // 指向UI设计界面的指针，用于访问可视化组件（与form file相关）
};
#endif // WIDGET_H
