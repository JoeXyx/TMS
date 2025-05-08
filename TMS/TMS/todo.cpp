#include "todo.h"
#include "ui_todo.h"
#include"mainwindow.h"

todo::todo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::todo)
{
    ui->setupUi(this);
    ui->quicktodo->setColumnCount(3);   // 设置列标题
    ui->quicktodo->setHorizontalHeaderLabels(QStringList()<<"任务编号"<<"任务名称"<<"完成状态");
    ui->slowtodo->setColumnCount(3);
    ui->slowtodo->setHorizontalHeaderLabels(QStringList()<<"任务编号"<<"任务名称"<<"完成状态");

    //todo_show();
    connect(ui->todo_show,&QPushButton::clicked,this,&todo::todo_show);
    //connect(mainwindow,&MainWindow::open_todo,this,[=](){this->show();});
}

todo::~todo()
{
    delete ui;
}

void todo::todo_show()
{

    ui->quicktodo->clear();  // 清除所有内容和标题
    ui->quicktodo->setRowCount(0); // 移除所有行
    ui->slowtodo->clear();
    ui->slowtodo->setRowCount(0);
    double quick_undo_num=0,quick_done_num=0,slow_undo_num=0,slow_done_num=0;
    for(int i=0;i<from_sql.size();i++)
    {
        //需要一个计算优先级函数确定放入哪个todo表
        int tmp1=from_sql[i].event_id;
        QString tmp2=from_sql[i].title;
        QString tmp3=from_sql[i].status;
        QTableWidgetItem *newItem1=new QTableWidgetItem(QString::number(tmp1));
        QTableWidgetItem *newItem2=new QTableWidgetItem(tmp2);
        QTableWidgetItem *newItem3=new QTableWidgetItem(tmp3);

        if(tmp3=="Pending")
        {
            //newItem3->setForeground(QBrush(QColor(255, 0, 0)));        // 使用Qt预定义颜色
            newItem3->setBackground(Qt::red);
            if(from_sql[i].priority=="High") quick_undo_num++;
            else slow_undo_num++;
        }
        else
        {
            //newItem3->setForeground(QBrush(QColor(255, 0, 0)));
            newItem3->setBackground(Qt::green);
            if(from_sql[i].priority=="High")quick_done_num++;
            else slow_undo_num++;
        }

        if(from_sql[i].priority=="High")
        {
            int row1 = ui->quicktodo->rowCount();        // 插入新行
            ui->quicktodo->insertRow(row1);
            ui->quicktodo->setItem(row1, 0, newItem1);
            ui->quicktodo->setItem(row1, 1, newItem2);
            ui->quicktodo->setItem(row1,2,newItem3);
        }

        else
        {
            int row2 = ui->slowtodo->rowCount();        // 插入新行
            ui->slowtodo->insertRow(row2);
            ui->slowtodo->setItem(row2, 0, newItem1);
            ui->slowtodo->setItem(row2, 1, newItem2);
            ui->slowtodo->setItem(row2,2,newItem3);
        }
    }
    if(quick_undo_num+quick_done_num==0)
        ui->quick_doing->setText("无任务 ");
    else
        ui->quick_doing->setText("已完成: "+QString::number(quick_done_num*100/(quick_undo_num+quick_done_num))+"%");

    if(slow_undo_num+slow_undo_num==0)
        ui->slow_doing->setText("无任务 ");
    else
        ui->slow_doing->setText("已完成: "+QString::number(slow_done_num*100/(slow_undo_num+slow_done_num))+"%");
}
