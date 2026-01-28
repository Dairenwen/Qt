#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    manager=new QNetworkAccessManager(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString url=ui->lineEdit->text();
    //构造http请求
    QNetworkRequest request(url);
    //发送请求
    QNetworkReply* response=manager->get(request);
    //信号槽处理
    connect(response,&QNetworkReply::finished,this,[=](){
        //判断是否出错
        if(response->error()==QNetworkReply::NoError)
        {
            QString html=response->readAll();//一般访问到的都是html
            ui->listWidget->addItem(html);
        }
        else
        {
            QMessageBox::critical(this,"服务器启动错误",response->errorString());
        }

        response->deleteLater();
    });
}
