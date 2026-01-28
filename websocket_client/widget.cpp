#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    ui->pushButton->setShortcut(QKeySequence(Qt::Key_Return | Qt::Key_Enter));

    connect(ui->lineEdit, &QLineEdit::returnPressed, ui->pushButton, &QPushButton::click);
    //handlerudpres();
    handlertcpres();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    auto sendudp=[=](const QString& str){
        QNetworkDatagram requestDatagram(str.toUtf8(),QHostAddress("127.0.0.1"),8080);
        udpsocket->writeDatagram(requestDatagram);
    };

    auto sendtcp=[=](const QString& str){
        tcpsocket->write(str.toUtf8());
    };

    QString str=ui->lineEdit->text();
    ui->lineEdit->setText("");

    ui->listWidget->addItem("发送: "+str);
    //构建发送请求
    sendtcp(str);

}

void Widget::handlerudpres()
{
    udpsocket=new QUdpSocket(this);

    connect(udpsocket, &QUdpSocket::readyRead, this, [=](){
        const QNetworkDatagram& recieveDatagarm=udpsocket->receiveDatagram();
        QString request=recieveDatagarm.data();

        ui->listWidget->addItem("收到: "+ request);
    });

}

void Widget::handlertcpres()
{
    tcpsocket=new QTcpSocket(this);
    //与服务器建立连接(非阻塞)
    tcpsocket->connectToHost("127.0.0.1",8080);
    //判断建立结果
    if( tcpsocket->waitForConnected()==false)
    {
        QMessageBox::critical(this,"服务器启动错误",tcpsocket->errorString());
    }

    connect(tcpsocket, &QTcpSocket::readyRead, this, [=](){

        QString request=tcpsocket->readAll();

        ui->listWidget->addItem("收到: "+ request);
    });

}


