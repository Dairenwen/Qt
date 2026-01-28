#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QTimer>
#include <QDebug>
#include <time.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    srand((unsigned int)time(nullptr));
    ui->setupUi(this);
    // ========== 1. label：文本垂直+水平居中 ==========
    // 设置对齐方式：水平居中（HCenter） + 垂直居中（VCenter）
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    // 设置显示文本
    ui->label->setText("垂直水平居中的文本");

    // ========== 2. label_2：左上对齐 + 自动换行 ==========
    // 设置对齐方式：顶部对齐（Top） + 左对齐（Left）
    ui->label_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // 开启自动换行（文本超出label宽度时自动折行）
    ui->label_2->setWordWrap(true);
    // 长文本测试自动换行
    ui->label_2->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");

    // ========== 3. label_3：左上对齐 + 首行缩进 ==========
    ui->label_3->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // 设置所有行缩进（缩进20像素）
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(20);
    ui->label_3->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");

    // ========== 4. label_4：左上对齐 + 内边距 ==========
    ui->label_4->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // 设置label内部边距（文本与label边框的距离为20像素，四个方向都有）
    ui->label_4->setMargin(20);
    ui->label_4->setText("这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本这是一个很长的文本");

    ui->label->setBuddy(ui->radioButton);


    // 1. 创建标签（文本含快捷键&U）
   QLabel* label = new QLabel("用户名(&U)", this);
   label->setGeometry(50, 50, 80, 30);

   // 2. 创建输入框
   QLineEdit* edit = new QLineEdit(this);
   edit->setGeometry(140, 50, 200, 30);

   // 3. 设置buddy关联：标签的快捷键指向输入框
   label->setBuddy(edit);


   timer_1=new QTimer(this);
   connect(timer_1,&QTimer::timeout,this,&Widget::handler);
   timer_1->start(1000);

   timer_2=new QTimer(this);
   connect(timer_2,&QTimer::timeout,this,&Widget::handler_prg);
   timer_2->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handler()
{
    int value=ui->lcdNumber->intValue();
    if(value<=0)
    {
        timer_1->stop();
    }
    else
    {
        ui->lcdNumber->display(value-1);
    }

}

void Widget::handler_prg()
{
    int value=ui->progressBar->value();
    if(value>=100)
    {
        timer_2->stop();
    }
    else
    {
        ui->progressBar->setValue(value+rand()%10+1);
    }
}


void Widget::on_calendarWidget_selectionChanged()
{
    qDebug()<<ui->calendarWidget->selectedDate()<<endl;
}
