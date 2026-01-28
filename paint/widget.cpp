#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//    painter.drawEllipse(QPoint(50, 50), 50, 50); // (中心点, x半径, y半径)
//    painter.drawEllipse(0, 0, 100, 100); // 中心点(100,100)，x/y直径100 → 半径50r


//    painter.setFont(QFont("鸿蒙黑体",24));//字体名称，字号
//    painter.setPen(Qt::black);//设置画笔颜色为红色
//    painter.drawText(QRect(100,200,600,150),"别感冒！");//左上方坐标，宽度，高度，内容
//    // x: 文字基线（Baseline）的水平起始坐标（距离控件左边缘0像素）
//    // y: 文字基线（Baseline）的垂直坐标（距离控件上边缘100像素）【重点：不是文字顶部/底部】
//    // text: 要绘制的文本内容
//    painter.drawText(10, 100, "hello world");



    // 创建自定义画笔
//    QPen pen;
//    pen.setColor(Qt::darkGreen);    // 设置颜色
//    pen.setWidth(4);                // 设置宽度
//    pen.setStyle(Qt::DashDotLine);  // 设置线条风格
//    pen.setCapStyle(Qt::RoundCap);  // 设置端点样式
//    pen.setJoinStyle(Qt::RoundJoin);// 设置连接样式
//    // 应用画笔到绘图器
//    painter.setPen(pen);
//    // 用自定义画笔绘制图形
//    painter.drawRect(50, 50, 200, 150);  // 绘制带虚线边框的矩形
//    painter.drawEllipse(300, 50, 150, 150); // 绘制带虚线边框的椭圆




    // 1. 纯色填充矩形
   QBrush solidBrush(Qt::cyan, Qt::SolidPattern);
   painter.setBrush(solidBrush);
   painter.drawRect(50, 50, 100, 80);

   // 2. 交叉线条填充椭圆
   QBrush crossBrush(Qt::darkGray, Qt::DiagCrossPattern);
   painter.setBrush(crossBrush);
   painter.drawEllipse(200, 50, 100, 80);

   // 3. 线性渐变填充多边形
   QLinearGradient gradient(350, 50, 450, 130);
   gradient.setColorAt(0, Qt::red);
   gradient.setColorAt(1, Qt::blue);
   QBrush gradientBrush(gradient);
   painter.setBrush(gradientBrush);
   painter.drawPolygon(QPolygon({QPoint(350,50), QPoint(450,50), QPoint(400,130)}));
}

