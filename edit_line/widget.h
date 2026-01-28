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

    void initcombox();
    void left();
    void right();
private slots:

    void on_com_but_clicked();

    void on_tel_textEdited(const QString &arg1);

    void on_checkBox_toggled(bool checked);

    void on_textEdit_2_textChanged();

    void on_textEdit_1_textChanged();

    void on_textEdit_1_selectionChanged();

    void on_textEdit_1_cursorPositionChanged();

    void on_textEdit_1_redoAvailable(bool b);

    void on_textEdit_1_copyAvailable(bool b);

    void on_textEdit_1_undoAvailable(bool b);

    void on_pushButton_clicked();

    void on_dial_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
