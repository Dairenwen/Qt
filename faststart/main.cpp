#include "widget.h"
#include <QApplication> // 应用程序类头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 创建应用程序对象（有且仅有一个）
                                // Qt图形化程序，一定要有QApplication对象
    Widget w; // 创建项目选择的类，父类为QWidget
    w.show(); // 显示窗口（默认隐藏）
    return a.exec(); // 进入事件循环，等待用户交互
}
