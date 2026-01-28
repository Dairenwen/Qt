#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void handler();
    void handler_timeout();
    void menubar();
    void toolbar();
    void statusbar();
    void dockwidget();
    void centrallayout();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QProgressBar* progress;

};
#endif // MAINWINDOW_H
