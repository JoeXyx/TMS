#include "addtaskform.h"
#include "ui_addtaskform.h"
#include"mainwindow.h"

AddTaskForm::AddTaskForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddTaskForm)
{
    ui->setupUi(this);

    //设置默认优先级和任务状态
    ui->low_radioButton->setChecked(true);
    ui->pending_radioButton->setChecked(true);

    //将子窗口与主窗口连接
    MainWindow *mainWindow= nullptr;
    foreach (QWidget *w, qApp->topLevelWidgets())
        if (MainWindow* mainWin = qobject_cast<MainWindow*>(w))
        {
            mainWindow= mainWin;
        }
    connect(this, &AddTaskForm::accepted, mainWindow, &MainWindow::showTasks);

}

AddTaskForm::~AddTaskForm()
{
    delete ui;
}

//取得添加任务时选择的日期
void AddTaskForm::setDate(QDate date)
{
    dateStr=date.toString("yyyy-MM-dd");
}

//关闭按钮
void AddTaskForm::on_pushButton_2_clicked()
{
    close();
}

//确认按钮
void AddTaskForm::on_pushButton_clicked()
{
    if(ui->title_lineEdit->text()=="")
    {
        QMessageBox::information(this,"提醒","标题输入不能为空！");
         return;
    }
    else
    {
        Event tmp;

        tmp.event_id=from_sql.size();
        tmp.title=ui->title_lineEdit->text();
        tmp.start_time=ui->st_spinBox->text()+":"+ui->st_spinBox_2->text();
        tmp.end_time=ui->et_spinBox->text()+":"+ui->et_spinBox_2->text();

        if(ui->et_spinBox->text().toInt()<ui->st_spinBox->text().toInt())
        {
            QMessageBox::information(this,"提醒","结束时间不能小于开始时间！");
            return;
        }
        else
        {
            if(ui->et_spinBox->text().toInt()==ui->st_spinBox->text().toInt())
            {
                if(ui->et_spinBox_2->text().toInt()<ui->st_spinBox_2->text().toInt())
                {
                    QMessageBox::information(this,"提醒","结束时间不能小于开始时间！");
                    return;
                }
            }
            tmp.created_at=this->dateStr;

            for(int i=0;i<from_sql.size();++i)
            {
                if(from_sql[i].created_at==tmp.created_at)
                {
                    if(from_sql[i].title==tmp.title&&from_sql[i].start_time==tmp.start_time&&from_sql[i].end_time==tmp.end_time)
                    {
                        QMessageBox::information(this,"提醒","事件重复！");
                        return;
                    }
                }
            }

            tmp.description=ui->textEdit->toPlainText();

            if (ui->high_radioButton->isChecked())
            {
                tmp.priority="High";
            }
            else if(ui->medium_radioButton->isChecked())
            {
                tmp.priority="Medium";
            }
            else
            {
                tmp.priority="Low";
            }

            if (ui->completed_radioButton->isChecked())
            {
                tmp.status="Completed";
            }
            else if(ui->in_progress_radioButton->isChecked())
            {
                tmp.status="In Progress";
            }
            else
            {
                tmp.status="Pending";
            }

            from_sql.push_back(tmp);

            close();

            emit accepted();

            QMessageBox::information(this,"提醒","添加成功。");
        }
    }
}
