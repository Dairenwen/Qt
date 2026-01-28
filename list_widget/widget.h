#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initlistwidget();
    void inittablewidget();
    void inittreewidget();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    // 新增一行按钮的槽函数
    void on_pushButton_addRow_clicked();
    // 删除选中行按钮的槽函数
    void on_pushButton_delRow_clicked();
    // 新增一列按钮的槽函数
    void on_pushButton_addCol_clicked();
    // 删除选中列按钮的槽函数
    void on_pushButton_delCol_clicked();

    void on_add_top_clicked();

    void on_add_choose_clicked();

    void on_del_choose_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
