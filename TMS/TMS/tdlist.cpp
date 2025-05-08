#include "tdlist.h"
#include "ui_tdlist.h"
#include"mainwindow.h"

tdlist::tdlist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tdlist)
{
    ui->setupUi(this);
    ui->tdl_weight->setColumnCount(2);
    ui->tdl_weight->setHorizontalHeaderLabels(QStringList()<<"任务名称"<<"截止日期");

    // 隐藏垂直标题（行标）
    ui->tdl_weight->verticalHeader()->setHidden(true);

    connect(ui->td_add,&QPushButton::clicked,this,&tdlist::add);
    connect(ui->td_del,&QPushButton::clicked,this,&tdlist::del);
}

tdlist::~tdlist()
{
    delete ui;
}

void tdlist::add()
{
    td_event e;
    e.name=ui->tname->text();
    QDate date = ui->td_ddl->date();
    e.end_time= date.toString("yyyy-MM-dd");
    for(int i=0;i<all.size();i++)
    {
        if(all[i].name==e.name)
        {
            QMessageBox::information(this, "警告", "您添加了重复名称的事件，请修改");
            return;
        }
    }
    all.push_back(e);
    tdshow();
}

void tdlist::del()
{
    if(ui->td_del->text()=="删除")
    {
        QMessageBox::information(this, "提示", "请您直接选中要删除的任务名称单元格(按住ctrl键可以多选），然后点击确认删除");
        ui->td_del->setText("确认删除");
    }
    else
    {
        selectedItems = ui->tdl_weight->selectedItems();
        for (QTableWidgetItem* item : selectedItems)
        {
            for(int i=0;i<all.size();i++)
            {
                if(all[i].name==item->text())
                {
                    all.remove(i);
                }
            }
            // int row = item->row(); // 获取行号
            // ui->tdl_weight->removeRow(row);
        }
        selectedItems.clear();  // 仅清空指针列表，不删除item对象

        ui->td_del->setText("删除");
        tdshow();

    }
}

void tdlist::tdshow()
{
    ui->tdl_weight->clear();
    ui->tdl_weight->setRowCount(0);
    ui->tdl_weight->setColumnCount(2);
    ui->tdl_weight->setHorizontalHeaderLabels(QStringList()<<"任务名称"<<"截止日期");
    QDate currentDate = QDate::currentDate();
    for(int i=0;i<all.size();i++)
    {
        ui->tdl_weight->insertRow(i);
        QDate sd = QDate::fromString(all[i].end_time, "yyyy-MM-dd");
        // 判断是否过期
        QTableWidgetItem *item1 = new QTableWidgetItem(all[i].name);
        QTableWidgetItem *item2 = new QTableWidgetItem(all[i].end_time);
        if (sd< currentDate)
        {
            item1->setBackground(Qt::red);
            item2->setBackground(Qt::red);
        }
        else if (sd == currentDate)
        {
            item1->setBackground(Qt::yellow);
            item2->setBackground(Qt::yellow);
        }

        ui->tdl_weight->setItem(i,0,item1);
        ui->tdl_weight->setItem(i,1,item2);
    }
}
