#include "widget.h"
#include "ui_widget.h"
#include <fstream>
#include <QString>
#include <QDebug>
#include <QRegExpValidator>
#include <QShortcut>
#include <QRegExp>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->name->setMaxLength(30);
    ui->name->setClearButtonEnabled(true);
    ui->name->setPlaceholderText("请输入姓名，长度不超过30");

    ui->age->setMaxLength(2);
    ui->age->setClearButtonEnabled(true);
    ui->age->setPlaceholderText("请输入两位数年龄");

    ui->tel->setMaxLength(11);
    ui->tel->setClearButtonEnabled(true);
    ui->tel->setPlaceholderText("请输入电话，你的隐私有我们守护");
    ui->tel->setEchoMode(QLineEdit::Password);

    ui->com_but->setEnabled(false);
    QRegExp telregex("^1\\d{10}$");
    ui->tel->setValidator(new QRegExpValidator(telregex));


    for(int i=0;i<100;++i) ui->year->addItem(QString::number(1999 + i));
    for(int i=0;i<12;i++)  ui->month->addItem(QString::number(i+1));
    for(int i=0;i<30;i++)  ui->day->addItem(QString::number(i+1));

    initcombox();

    ui->horizontalSlider->setMinimum(500);
    ui->horizontalSlider->setMaximum(2000);
    ui->horizontalSlider->setSingleStep(100);
    ui->horizontalSlider->setValue(500);
    ui->verticalSlider->setMinimum(500);
    ui->verticalSlider->setMaximum(2000);
    ui->verticalSlider->setSingleStep(100);
    ui->verticalSlider->setValue(500);

    ui->verticalSlider->setInvertedAppearance(true);

    QShortcut* cut1=new QShortcut(this),*cut2=new QShortcut(this);
    cut1->setKey(QKeySequence(Qt::Key_Left));
    cut2->setKey(QKeySequence(Qt::Key_Right));
    connect(cut1,&QShortcut::activated,this,&Widget::left);
    connect(cut2,&QShortcut::activated,this,&Widget::right);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initcombox()
{
    std::fstream ifs("C:/Users/19624/Desktop/1.txt",std::ios::in);
    if(ifs.is_open()==false) return;
    std::string instr;
    while(std::getline(ifs,instr))
    {
        ui->comboBox->addItem(QString::fromStdString(instr));
    }
    ifs.close();
}

void Widget::on_com_but_clicked()
{
    qDebug()<<"你的信息如下：请核实"<<endl;
    qDebug()<<ui->name->text()<<endl;
    qDebug()<<ui->age->text()<<endl;
    if(ui->boy_but->isChecked()) qDebug()<<"boy"<<endl;
    else qDebug()<<"girl"<<endl;
    qDebug()<<ui->tel->text()<<endl;
}

void Widget::on_tel_textEdited(const QString &arg1)
{
    QString content=arg1;
    int pos=0;
    if(ui->tel->validator()->validate(content,pos)==QValidator::Acceptable) ui->com_but->setEnabled(true);
    else ui->com_but->setEnabled(false);
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked==true) ui->tel->setEchoMode(QLineEdit::Normal);
    else ui->tel->setEchoMode(QLineEdit::Password);
}

void Widget::on_textEdit_2_textChanged()
{
    ui->textEdit_1->setText(ui->textEdit_2->toPlainText());
}

void Widget::on_textEdit_1_textChanged()
{
    //文本发生改变
    qDebug() << "[textChanged] " << ui->textEdit_1->toPlainText();
}

void Widget::on_textEdit_1_selectionChanged()
{
    //选中范围发生改变
    const QTextCursor& cursor = ui->textEdit_1->textCursor();
     qDebug() << "[selectionChanged] " << cursor.selectedText();
}

void Widget::on_textEdit_1_cursorPositionChanged()
{
    //光标发生改变
    const QTextCursor& cursor = ui->textEdit_1->textCursor();
     qDebug() << "[cursorPositionChanged] " << cursor.position();

}

void Widget::on_textEdit_1_redoAvailable(bool b)
{
    //是否可以进行redo恢复操作（ctrl+Z）
    qDebug() << "[redoAvailable] " << b;
}

void Widget::on_textEdit_1_undoAvailable(bool b)
{
    //是否可以进行undo撤销操作（ctrl+Y）
    qDebug() << "[undoAvailable] " << b;
}

void Widget::on_textEdit_1_copyAvailable(bool b)
{
    //选中内容后进行是都开可以进行copy操作
    qDebug() << "[copyAvailable] " << b;
}

void Widget::on_pushButton_clicked()
{
    //这里用于计算日期差
    QDateTime timeOld = ui->date_1->dateTime();
    QDateTime timeNew=ui->date_2->dateTime();
    int seconds=timeOld.secsTo(timeNew);
    int days=seconds/(24*60*60);
    int hours=(seconds-days*24*60*60)/3600;
    ui->pushButton->setText("日期差："+QString::fromStdString(std::to_string(days)+"天,"+std::to_string(hours)+"小时"));
}

void Widget::on_dial_valueChanged(int value)
{
    this->setWindowOpacity(value*1.0/100);
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    QRect rect=this->geometry();
    this->setGeometry(rect.x(),rect.y(),value,rect.height());
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    QRect rect=this->geometry();
    this->setGeometry(rect.x(),rect.y(),rect.width(),value);
}

void Widget::left()
{
    int value=ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value-20);
}
void Widget::right()
{
    int value=ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value+20);
}
