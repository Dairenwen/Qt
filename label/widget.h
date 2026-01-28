#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handler();
    void handler_prg();

private slots:
    void on_calendarWidget_selectionChanged();

private:
    QTimer* timer_1;
    QTimer* timer_2;
    Ui::Widget *ui;
};
#endif // WIDGET_H
