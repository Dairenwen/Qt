#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("服务端");

    tcpserver();
}

void Widget::udpserver()
{
    //创建套接字
    udpsocket=new QUdpSocket(this);
    //绑定信号槽
    connect(udpsocket,&QUdpSocket::readyRead,this,&Widget::handlerudp);
    //绑定端口号
    if(udpsocket->bind(QHostAddress::Any,8080)==false)
    {
        QMessageBox::critical(this,"服务器启动错误",udpsocket->errorString());
    }
}

void Widget::tcpserver()
{
    //创建套接字
    tcpsocket=new QTcpServer(this);
    //绑定信号槽
    connect(tcpsocket,&QTcpServer::newConnection,this,&Widget::handlertcp);
    //绑定端口号
    if(tcpsocket->listen(QHostAddress::Any,8080)==false)
    {
        QMessageBox::critical(this,"服务器启动错误",tcpsocket->errorString());
    }

}


Widget::~Widget()
{
    delete ui;
}

void Widget::handlerudp()
{
    auto handlerresponse = [&](const QString& req){
        return "resp:"+req;
    };
    //1.读取请求
    const QNetworkDatagram& requestDatagarm=udpsocket->receiveDatagram();
    QString request=requestDatagarm.data();
    //2.处理请求
    const QString& response= handlerresponse(request);
    //3.发回请求
    udpsocket->writeDatagram(QNetworkDatagram(response.toUtf8(),requestDatagarm.senderAddress(),requestDatagarm.senderPort()));

    ui->listWidget->addItem("[" + requestDatagarm.senderAddress().toString() + ":"
                                    + QString::number(requestDatagarm.senderPort())
                            + "] req: " + request + ", resp: " + response);
}

void Widget::handlertcp()
{
    //获得socket对象，通过这个与客户端进行通信
    QTcpSocket* clientSocket = tcpsocket->nextPendingConnection();
    //绑定信号槽
    connect(clientSocket,&QTcpSocket::readyRead,this,[=](){
        auto handlerresponse = [&](const QString& req){
            return "resp:"+req;
        };
        //1.读取请求
        QString request=clientSocket->readAll();
        //2.处理请求
        const QString& response= handlerresponse(request);
        //3.发回请求
        clientSocket->write(response.toUtf8());

        ui->listWidget->addItem("[" + clientSocket->peerAddress().toString() + ":"
                                        + QString::number(clientSocket->peerPort())
                                + "] req: " + request + ", resp: " + response);
    });

    //处理断开连接
    connect(clientSocket,&QTcpSocket::disconnected,this,[=](){
        ui->listWidget->addItem("[" + clientSocket->peerAddress().toString() + ":"
                                        + QString::number(clientSocket->peerPort())
                                + "] 连接断开");

        clientSocket->deleteLater();//将缓冲区内存读取完毕再销毁，better than 直接delete
    });
}

