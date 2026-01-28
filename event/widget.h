#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    void keyPressEvent(QKeyEvent *event);

    void timerEvent(QTimerEvent* event);

    void handler();

    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent *event);
private:
    Ui::Widget *ui;
    int timerId;
    QTimer* timer;
};
#endif // WIDGET_H
