#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QLabel>
#include <QTableWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initlistwidget();

    inittablewidget();

    inittreewidget();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::initlistwidget()
{
    ui->listWidget->addItem("apple");
    //或ui->listWidget->addItem(new QListWidgetItem("apple"));
    ui->listWidget->addItem("banana");
    //或ui->listWidget->addItem(new QListWidgetItem("banana"));
    ui->listWidget->addItem("orange");
    //或ui->listWidget->addItem(new QListWidgetItem("oragne"));
}

void Widget::inittablewidget()
{
//    ui->tableWidget->insertRow(0);
//    ui->tableWidget->insertRow(1);
//    ui->tableWidget->insertRow(2);
//    ui->tableWidget->insertRow(3);

//    ui->tableWidget->insertColumn(0);
//    ui->tableWidget->insertColumn(1);
//    ui->tableWidget->insertColumn(2);
//    ui->tableWidget->insertColumn(3);


//    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("-1"));
//    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("0"));
//    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("1"));
//    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("P(X=x)"));

//    ui->tableWidget->setVerticalHeaderItem(0,new QTableWidgetItem("X \ Y"));
//    ui->tableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("0"));
//    ui->tableWidget->setVerticalHeaderItem(2,new QTableWidgetItem("1"));
//    ui->tableWidget->setVerticalHeaderItem(3,new QTableWidgetItem("P(Y=y)"));

//    ui->tableWidget->setItem(1,0,new QTableWidgetItem("0.1"));
//    ui->tableWidget->setItem(1,1,new QTableWidgetItem("0.2"));
//    ui->tableWidget->setItem(1,2,new QTableWidgetItem("0.1"));
//    ui->tableWidget->setItem(1,3,new QTableWidgetItem("0.4"));
//    ui->tableWidget->setItem(2,0,new QTableWidgetItem("0.2"));
//    ui->tableWidget->setItem(2,1,new QTableWidgetItem("0.3"));
//    ui->tableWidget->setItem(2,2,new QTableWidgetItem("0.1"));
//    ui->tableWidget->setItem(2,3,new QTableWidgetItem("0.6"));
//    ui->tableWidget->setItem(3,0,new QTableWidgetItem("0.3"));
//    ui->tableWidget->setItem(3,1,new QTableWidgetItem("0.5"));
//    ui->tableWidget->setItem(3,2,new QTableWidgetItem("0.2"));
//    ui->tableWidget->setItem(3,3,new QTableWidgetItem("1.0"));
       // 1. 创建3行
       ui->tableWidget->insertRow(0);
       ui->tableWidget->insertRow(1);
       ui->tableWidget->insertRow(2);

       // 2. 创建3列
       ui->tableWidget->insertColumn(0);
       ui->tableWidget->insertColumn(1);
       ui->tableWidget->insertColumn(2);

       // 3. 设置列名（表头）
       ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
       ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
       ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

       // 4. 设置初始单元格数据
       // 第0行
       ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1001"));
       ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
       ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));
       // 第1行
       ui->tableWidget->setItem(1, 0, new QTableWidgetItem("1002"));
       ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
       ui->tableWidget->setItem(1, 2, new QTableWidgetItem("21"));
       // 第2行
       ui->tableWidget->setItem(2, 0, new QTableWidgetItem("1003"));
       ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
       ui->tableWidget->setItem(2, 2, new QTableWidgetItem("19"));
}

void Widget::inittreewidget()
{
    // 1. 创建空的顶层节点
    QTreeWidgetItem *catItem = new QTreeWidgetItem();
    // 2. 设置第0列的文本（TreeWidget默认是1列，列索引从0开始）
    catItem->setText(0, "猫");
    // 3. 添加到TreeWidget中
    ui->treeWidget->addTopLevelItem(catItem);

    QTreeWidgetItem* dogItem=new QTreeWidgetItem();
    dogItem->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(dogItem);

    QTreeWidgetItem* fishItem=new QTreeWidgetItem();
    fishItem->setText(0,"鱼");
    ui->treeWidget->addTopLevelItem(fishItem);

    QTreeWidgetItem *catchild1 = new QTreeWidgetItem();
    catchild1->setText(0,"狸花猫");
    catItem->addChild(catchild1);
    QTreeWidgetItem *catchild2 = new QTreeWidgetItem();
    catchild2->setText(0,"缅因猫");
    catItem->addChild(catchild2);

    QTreeWidgetItem *dogchild1 = new QTreeWidgetItem();
    dogchild1->setText(0,"边牧");
    dogItem->addChild(dogchild1);
}

void Widget::on_pushButton_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
}

void Widget::on_pushButton_2_clicked()
{
    int pos=ui->listWidget->currentRow();
    ui->listWidget->takeItem(pos);
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current) qDebug()<<current->text()<<endl;
    if(previous) qDebug()<<previous->text()<<endl;
}

void Widget::on_pushButton_addRow_clicked()
{
    // 获取当前行数，在末尾插入新行
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}

void Widget::on_pushButton_delRow_clicked()
{
    // 获取当前选中的行号
    int curRow = ui->tableWidget->currentRow();
    // 存在选中行时才删除
    if (curRow >=0 ) {
        ui->tableWidget->removeRow(curRow);
    }
}

void Widget::on_pushButton_addCol_clicked()
{
    // 获取当前列数，在末尾插入新列
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);

    // 从输入框获取列名，设置新列表头
    const QString& name = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(name));
}

void Widget::on_pushButton_delCol_clicked()
{
    // 获取当前选中的列号
    int curCol = ui->tableWidget->currentColumn();
    // 存在选中列时才删除
    if (curCol != -1) {
        ui->tableWidget->removeColumn(curCol);
    }
}

void Widget::on_add_top_clicked()
{
    const QString& str=ui->lineEdit_2->text();
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,str);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_add_choose_clicked()
{
    QTreeWidgetItem* choosen=ui->treeWidget->currentItem();
    if(choosen==nullptr) return;
    const QString& str=ui->lineEdit_2->text();
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,str);
    choosen->addChild(item);
}

void Widget::on_del_choose_clicked()
{
    QTreeWidgetItem* choosen=ui->treeWidget->currentItem();
    if(choosen==nullptr) return;
    QTreeWidgetItem* parent=choosen->parent();
    if(parent==nullptr)//为顶层元素
    {
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(choosen));
    }
    else
    {
        parent->removeChild(choosen);
    }
}

void Widget::on_pushButton_3_clicked()
{
    QWidget* newwidget=new QWidget();
    int count=ui->tabWidget->count();
    ui->tabWidget->addTab(newwidget,QString::fromStdString("Tab "+std::to_string(count+1)));
    //增加一个标签
    QLabel* label=new QLabel("新标签页",newwidget);
    label->setGeometry(newwidget->x()+20,newwidget->y()+20,50,20);
    //指向创建好的标签页
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_4_clicked()
{
    int pos=ui->tabWidget->currentIndex();
    if(pos>=0)
    {
        ui->tabWidget->removeTab(pos);
    }
}
