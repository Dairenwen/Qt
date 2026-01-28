#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include "dialog.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QDebug>
#include <QFontDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialog()
{
//    QDialog* dialog=new QDialog(this);
//   //继承QWidget的接口设置标题和大小
//   dialog->setWindowTitle("这是一个对话框");
//   dialog->resize(500,200);
//   //设置show
//   dialog->show();
//   //设置关闭时释放内存，防止内存泄漏
//   dialog->setAttribute(Qt::WA_DeleteOnClose);


   Dialog* dialog=new Dialog(this);
   //继承QWidget的接口设置标题和大小
   dialog->setWindowTitle("这是一个对话框");
   dialog->resize(500,200);
   //设置show
   dialog->show();
   //dialog->exec();
   //设置关闭时释放内存，防止内存泄漏
   dialog->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::messagebox()
{
    QMessageBox* messagebox=new QMessageBox(this);
    messagebox->setText("对话框文本");
    messagebox->setWindowTitle("对话框标题");
    messagebox->setIcon(QMessageBox::Question);
   // messagebox->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    messagebox->addButton(new QPushButton("按钮",messagebox),QMessageBox::AcceptRole);

    messagebox->show();

    messagebox->setAttribute(Qt::WA_DeleteOnClose);

    int ret=QMessageBox::question(this,"对话框标题","对话框文本",QMessageBox::Ok|QMessageBox::Cancel);
}

void MainWindow::colordialog()
{
    QColor color=QColorDialog::getColor(QColor(0,0,0),this,"选择颜色");
    this->setStyleSheet(QString(
          "QWidget { background-color: rgb(%1, %2, %3); }"
                            ).arg(color.red()).arg(color.green()).arg(color.blue()));
}

void MainWindow::filedialog()
{
    QString str=QFileDialog::getOpenFileName(this,"选择一个文件","C:/");
    qDebug()<<str<<endl;
}

void MainWindow::fontdialog()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok);
    if(ok==true)//用户选择OK
    {
        qDebug()<<"选中字体"<<endl;
        qDebug()<<font.family()<<endl;
        qDebug()<<font.pointSize()<<endl;
        qDebug()<<font.bold()<<endl;
        qDebug()<<font.italic()<<endl;
    }
    else//用户选择cancel
    {
        qDebug()<<"初始字体"<<endl;
        qDebug()<<font.family()<<endl;
        qDebug()<<font.pointSize()<<endl;
        qDebug()<<font.bold()<<endl;
        qDebug()<<font.italic()<<endl;
    }
}

void MainWindow::inputdialog()
{
    double ret=QInputDialog::getDouble(this,"获取浮点数","输入数值",0,0);
    qDebug()<<ret<<endl;

    double ret1=QInputDialog::getInt(this,"获取整数","输入数值",0,0);
    qDebug()<<ret1<<endl;

    QStringList list={"选项1","选项2","选项3"};
    QString ret3=QInputDialog::getItem(this,"获取条目列表","输入选项",list,0);
    qDebug()<<ret3<<endl;


}


void MainWindow::on_pushButton_clicked()
{
    QProgressDialog progress("正在处理数据...", "取消", 0, 100, this);
      progress.setMinimumDuration(500); // 500ms后再显示
      progress.setWindowModality(Qt::WindowModal); // 模态（阻塞父窗口）

      for (int i = 0; i <= 100; ++i) {
          progress.setValue(i);
          QCoreApplication::processEvents(); // 刷新界面

          if (progress.wasCanceled()) { // 检测是否取消
              qDebug() << "任务被取消";
              break;
          }
          QThread::msleep(50); // 模拟耗时操作
      }

    inputdialog();

}
