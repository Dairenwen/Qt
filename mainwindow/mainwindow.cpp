#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <iostream>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QPushButton>
#include <ctime>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,timer(new QTimer(this))
    ,progress(new QProgressBar(this))

{
    ui->setupUi(this);
    srand((unsigned int)time(nullptr));
    //menubar();

    //toolbar();

    //statusbar();

//    dockwidget();

    centrallayout();

}

void MainWindow::menubar()
{
    QMenuBar* menubar=this->menuBar();
    this->setMenuBar(menubar);

    QMenu* menu1=new QMenu("文件(&F)");
    menubar->addMenu(menu1);
    QMenu* menu2=new QMenu("编辑(&E)");
    menubar->addMenu(menu2);
    QMenu* menu3=new QMenu("构建(&B)");
    menubar->addMenu(menu3);
    QMenu* menuchild=new QMenu("子菜单");

    menu1->addMenu(menuchild);
    menuchild->setIcon(QIcon(":/favicon.png"));

    QAction* menu1_action1=new QAction("新建文件或项目");
    menuchild->addAction(menu1_action1);
    menuchild->addSeparator();
    QAction* menu1_action2=new QAction("打开文件或项目");
    menuchild->addAction(menu1_action2);
    menuchild->addSeparator();
    QAction* menu1_action3=new QAction("最近访问的文件");
    menuchild->addAction(menu1_action3);

//    menu1_action1->setShortcut(QKeySequence(Qt::ControlModifier+ Qt::Key_N));
//    menu1_action2->setShortcut(QKeySequence(Qt::ControlModifier+Qt::Key_O));

    //    connect(menu1_action1,&QAction::triggered,this,&MainWindow::handler);
}

void MainWindow::toolbar()
{
    //QToolBar可以创建多个，且不会自动创建
    QToolBar* toolbar=new QToolBar(this);
    this->addToolBar(toolbar);
    QAction* action1=new QAction("新建文件或项目");
    toolbar->addAction(action1);
    QAction* action2=new QAction("打开文件或项目");
    toolbar->addAction(action2);

    toolbar->setFloatable(false);
    //图标会覆盖文字,设置的文字自动转为tooltip，也可以重新设定tooltip
    action1->setIcon(QIcon(":/gridinsert.png"));
    action2->setIcon(QIcon(":/downline.png"));

    connect(action1,&QAction::triggered,this,&MainWindow::handler);
    connect(action2,&QAction::triggered,this,&MainWindow::handler);
}

void MainWindow::statusbar()
{
    //同样因为ui会自动生成，采用自动生成的，防止内存泄漏
    QStatusBar* statusbar=this->statusBar();
    this->setStatusBar(statusbar);

    statusbar->showMessage("正在执行文件拷贝...");

    progress->setRange(0,100);

    statusbar->addPermanentWidget(progress);

    connect(timer,&QTimer::timeout,this,&MainWindow::handler_timeout);
    timer->start(1000);


}

void MainWindow::dockwidget()
{
    QDockWidget* dockwidget=new QDockWidget(this);
    //可以使用addDockWidget来指定位置
    this->addDockWidget(Qt::LeftDockWidgetArea,dockwidget);

    //设置标题
    dockwidget->setWindowTitle("dock widget");

    //需要先添加一个widget到dockwidget，再添加子控件到widget
    QWidget* widget=new QWidget();
    dockwidget->setWidget(widget);

    QPushButton* button=new QPushButton(widget);
    button->setGeometry(widget->x(),widget->y(),200,200);

    dockwidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::TopDockWidgetArea);
}

void MainWindow::centrallayout()
{
}

void MainWindow::handler()
{
    qDebug()<<"处理信号";
}

void MainWindow::handler_timeout()
{
    int value=progress->value();
    if(value>=100) {
        timer->stop();
        return;
    }
    else progress->setValue(value+rand()%10+1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

