#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPushButton *mybutton;
private slots:
    void on_pushButton_clicked();
    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_radioButton_2_clicked();


    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void resizeEvent(QResizeEvent *event);

public slots:
    void handlerclick(const QString&);
    //可以是 void handlerclick(QString str) 或 const QString&
    //通常用 const QString& 是为了避免拷贝，同时保证不在槽里修改这个参数
    void handlerclick();
signals:
    void mysignal(const QString& ,int);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
