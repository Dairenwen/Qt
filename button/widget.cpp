#include "widget.h"
#include "ui_widget.h"
#include "QLineEdit"
#include "QDebug"
#include <QButtonGroup>
#include <QResizeEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    void (Widget::* sigptr)(const QString&,int)=&Widget::mysignal;
//    void (Widget::* handptr)(const QString&)=&Widget::handlerclick;

//    auto sigptr = static_cast<void (Widget::*)(const QString&,int)>(&Widget::mysignal);
//    auto handptr   = static_cast<void (Widget::*)(const QString&)>(&Widget::handlerclick);

//    mybutton = new QPushButton("Helloworld",this);
//    mybutton->move(200,200);
//    connect(mybutton,&QPushButton::clicked,this,&Widget::handlerclick);
//    connect(this,sigptr,this,handptr);
//    connect(this,&Widget::mysignal,this,[=](){
//        qDebug()<<"按钮即将要关闭啦！";
//        mybutton->close();
//    });

//    ui->pushButton->setIcon(QIcon(":/image/favicon.png"));
//    ui->up->setIcon(QIcon(":/image/up.png"));
//    ui->down->setIcon(QIcon(":/image/down.png"));
//    ui->left->setIcon(QIcon(":/image/left.png"));
//    ui->right->setIcon(QIcon(":/image/right.png"));

//    ui->pushButton->setIconSize(QSize(50,50));
//    ui->up->setIconSize(QSize(50,50));
//    ui->down->setIconSize(QSize(50,50));
//    ui->left->setIconSize(QSize(50,50));
//    ui->right->setIconSize(QSize(50,50));

//    ui->up->setToolTip("up");
//    ui->down->setToolTip("down");
//    ui->left->setToolTip("left");
//    ui->right->setToolTip("right");

//    ui->up->setShortcut(QKeySequence(Qt::Key_W+ Qt::CTRL));
//    ui->down->setShortcut(QKeySequence(Qt::Key_S));
//    ui->left->setShortcut(QKeySequence(Qt::Key_A));
//    ui->right->setShortcut(QKeySequence(Qt::Key_D));

    QButtonGroup* group=new QButtonGroup(this);
    group->addButton(ui->radioButton);
    group->addButton(ui->radioButton_2);
    group->addButton(ui->radioButton_3);

}
void Widget::resizeEvent(QResizeEvent *event)
{
    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
}
void Widget::handlerclick(const QString& str)
{
    mybutton->setText(str);
}

void Widget::handlerclick()
{

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    disconnect(this,static_cast<void (Widget::*)(const QString&,int)>(&Widget::mysignal),
               this,static_cast<void (Widget::*)(const QString&)>(&Widget::handlerclick));
    //发出自定义的信号，emit代表发送信号，emit可以省略
    emit mysignal("触发信号",0);
    //this->close();
}

void Widget::on_up_clicked()
{
    QRect rect=ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}

void Widget::on_left_clicked()
{
    QRect rect=ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}

void Widget::on_right_clicked()
{
    QRect rect=ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}

void Widget::on_down_clicked()
{
    QRect rect=ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}


void Widget::on_radioButton_2_clicked()
{
    ui->label->setText("你选择了：2");
}


void Widget::on_radioButton_3_clicked(bool checked)
{
    qDebug()<<"状态为："<<checked<<endl;
}

void Widget::on_radioButton_toggled(bool checked)
{
    qDebug()<<"状态为："<<checked<<endl;
}

void Widget::on_checkBox_clicked()
{
    ui->label->setText(ui->checkBox->text());
}



void Widget::on_checkBox_2_clicked()
{
    ui->label->setText(ui->label->text()+ui->checkBox_2->text());
}



void Widget::on_checkBox_3_clicked()
{
     ui->label->setText(ui->label->text()+ui->checkBox_3->text());
}
