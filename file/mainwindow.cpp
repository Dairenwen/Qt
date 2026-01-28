#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMenuBar(this->menuBar());
    QMenu* menu1=new QMenu("文件(&F)");
    menuBar()->addMenu(menu1);

    QAction* action1=new QAction("打开文件");
    action1->setShortcut(QKeySequence(Qt::ControlModifier+ Qt::Key_N));
    QAction* action2=new QAction("保存文件");
    action2->setShortcut(QKeySequence(Qt::ControlModifier+ Qt::Key_O));
    menu1->addAction(action1);
    menu1->addAction(action2);

    this->setCentralWidget(ui->textEdit);

    connect(action1,&QAction::triggered,this,&MainWindow::handleraction1);
    connect(action2,&QAction::triggered,this,&MainWindow::handleraction2);
}

void MainWindow::handleraction1()
{
    QString str=QFileDialog::getOpenFileName(this,"选择一个文件","C:/");
    QStatusBar* statusbar=this->statusBar();
    this->setStatusBar(this->statusBar());

    statusbar->showMessage(str);

    QFile file(str);
    bool ret=file.open(QIODevice::ReadOnly);
    if(ret==false) return;
    else
    {
        QString text=file.readAll();
        ui->textEdit->setText(text);
    }
    file.close();
}

void MainWindow::handleraction2()
{
    QString str=QFileDialog::getSaveFileName(this,"选择一个文件","C:/");
    QStatusBar* statusbar=this->statusBar();
    this->setStatusBar(this->statusBar());

    statusbar->showMessage(str);

    QFile file(str);
    bool ret=file.open(QIODevice::WriteOnly);
    if(ret==false) return;
    else
    {
        QString text=ui->textEdit->toPlainText();
        file.write(text.toUtf8());
    }
    file.close();
}


MainWindow::~MainWindow()
{
    delete ui;
}
