#include "chgtaskform.h"
#include "ui_chgtaskform.h"
#include"mainwindow.h"

chgTaskForm::chgTaskForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chgTaskForm)
{
    ui->setupUi(this);

    //将子窗口与主窗口连接
    MainWindow *mainWindow= nullptr;
    foreach (QWidget *w, qApp->topLevelWidgets())
        if (MainWindow* mainWin = qobject_cast<MainWindow*>(w))
        {
            mainWindow= mainWin;
        }
    connect(this, &chgTaskForm::accepted, mainWindow, &MainWindow::showTasks);
}

chgTaskForm::~chgTaskForm()
{
    delete ui;
}

//取得修改任务时选择的事件号
void chgTaskForm::setEid(int e_id)
{
    this->eid=e_id;

    //通过事件号获取对应事件用于初始化窗口
    Event tmp=from_sql[eid];

    //获取事件开始时间
    QString st_str=tmp.start_time;
    int st_pos=-1;
    for(int i=0;i<st_str.size();++i)
    {
        if(st_str[i]==':')
        {
            st_pos=i;
            break;
        }
    }
    int st_hr=st_str.mid(0,st_pos).toInt();
    int st_min=st_str.mid(st_pos+1,st_str.size()-1-st_pos).toInt();
    //获取事件结束时间
    QString et_str=tmp.end_time;
    int et_pos=-1;
    for(int i=0;i<et_str.size();++i)
    {
        if(et_str[i]==':')
        {
            et_pos=i;
            break;
        }
    }
    int et_hr=et_str.mid(0,et_pos).toInt();
    int et_min=et_str.mid(et_pos+1,et_str.size()-1-et_pos).toInt();
    //获取事件优先级
    if(tmp.priority=="Low")
    {
        ui->low_radioButton->setChecked(true);
    }
    else if(tmp.priority=="Medium")
    {
        ui->medium_radioButton->setChecked(true);
    }
    else
    {
        ui->high_radioButton->setChecked(true);
    }
    //获取事件状态
    if(tmp.status=="Pending")
    {
        ui->pending_radioButton->setChecked(true);
    }
    else if(tmp.status=="In Progress")
    {
        ui->in_progress_radioButton->setChecked(true);
    }
    else
    {
        ui->completed_radioButton->setChecked(true);
    }
    //获取事件日期
    int date_year=tmp.created_at.mid(0,4).toInt();
    int date_month=tmp.created_at.mid(5,2).toInt();
    int date_day=tmp.created_at.mid(8,2).toInt();

    //初始化界面
    ui->title_lineEdit->setText(tmp.title);
    ui->st_spinBox->setValue(st_hr);
    ui->st_spinBox_2->setValue(st_min);
    ui->et_spinBox->setValue(et_hr);
    ui->et_spinBox_2->setValue(et_min);
    ui->year_spinBox->setValue(date_year);
    ui->month_spinBox->setValue(date_month);
    ui->day_spinBox->setValue(date_day);
    ui->textEdit->setText(tmp.description);
}

//关闭按钮
void chgTaskForm::on_pushButton_2_clicked()
{
    close();
}

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 判断日期是否合法
bool isValidDate(int year, int month, int day) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }
    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }
    return true;
}

//确认按钮
void chgTaskForm::on_pushButton_clicked()
{
    if(ui->title_lineEdit->text()=="")
    {
        QMessageBox::information(this,"提醒","标题输入不能为空！");
        return;
    }
    else
    {
        Event tmp;

        tmp.event_id=eid;
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
            int date_year=ui->year_spinBox->value();
            int date_month=ui->month_spinBox->value();
            int date_day=ui->day_spinBox->value();
            if(!isValidDate(date_year,date_month,date_day))
            {
                QMessageBox::information(this,"提醒","日期非法！");
                return;
            }
            QString str_month=QString::number(date_month);
            QString str_day=QString::number(date_day);
            if(date_month<10)
            {
                str_month='0'+QString::number(date_month);
            }
            if(date_day<10)
            {
                str_day='0'+QString::number(date_day);
            }
            tmp.created_at=QString::number(date_year)+'-'+str_month+'-'+str_day;

            for(int i=0;i<from_sql.size();++i)
            {
                if(i==eid)
                {
                    continue;
                }
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

            from_sql[eid]=tmp;

            emit accepted();
            close();

            QMessageBox::information(this,"提醒","修改成功。");
        }
    }
}
