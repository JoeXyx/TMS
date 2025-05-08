#include "reminderdialog.h"
#include "ui_reminderdialog.h"
#include<QMessageBox>
#include"data_sql.h"
#include"mainwindow.h"

extern QList<Reminder> reminder_sql;

ReminderDialog::ReminderDialog(int event_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReminderDialog),
    event_id(event_id)  // 确保使用一致的成员变量名称
{
    ui->setupUi(this);

    connect(ui->btnAddReminder, &QPushButton::clicked, this, &ReminderDialog::addReminder);
    connect(ui->btnRemoveReminder, &QPushButton::clicked, this, &ReminderDialog::removeReminder);
    connect(ui->btnConfirm, &QPushButton::clicked, this, &ReminderDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &ReminderDialog::reject);

    loadReminders();
}

ReminderDialog::~ReminderDialog()
{
    delete ui;
}

// 加载数据库中的提醒
void ReminderDialog::loadReminders()
{
    data_sql db;
    reminders = db.getRemindersForEvent(event_id);  // **只读一次数据库**

    ui->listReminders->clear();  // **清空 UI 列表**
    for (const Reminder &r : reminders) {
        QString reminderText = QString("提前 %1 分钟 - %2%3")
                                   .arg(r.remind_before)
                                   .arg(r.remind_start ? "开始提醒 " : "")
                                   .arg(r.remind_end ? "截止提醒 " : "");
        ui->listReminders->addItem(reminderText);
    }
}


// 添加提醒
void ReminderDialog::addReminder()
{
    int minutesBefore = ui->spinMinutesBefore->value();
    bool remindStart = ui->checkRemindStart->isChecked();
    bool remindEnd = ui->checkRemindEnd->isChecked();

    if (minutesBefore <= 0) {
        QMessageBox::warning(this, "警告", "提醒时间必须大于 0 分钟！");
        return;
    }
    if (!remindStart && !remindEnd) {
        QMessageBox::warning(this, "警告", "请至少选择开始提醒或截止提醒！");
        return;
    }

    Reminder r = { event_id, minutesBefore, remindStart, remindEnd };
    qDebug() << "正在添加提醒，event_id = " << r.event_id;
    reminders.append(r);  // **只修改内存，不操作数据库**

    // 更新 UI 显示
    QString reminderText = QString("提前 %1 分钟 - %2%3")
                               .arg(minutesBefore)
                               .arg(remindStart ? "开始提醒 " : "")
                               .arg(remindEnd ? "截止提醒 " : "");
    ui->listReminders->addItem(reminderText);
}

// 删除选中的提醒
void ReminderDialog::removeReminder()
{
    int row = ui->listReminders->currentRow();
    if (row >= 0) {
        reminders.removeAt(row);  // **只修改内存，不操作数据库**
        delete ui->listReminders->takeItem(row);
    }
}


void ReminderDialog::accept()
{
    data_sql db;
    db.clearRemindersForEvent(event_id);  // **清空旧提醒**

    // **清理全局变量中该事件的旧提醒**
    for (int i = 0; i < reminder_sql.size(); ++i) {
        if (reminder_sql[i].event_id == event_id) {
            reminder_sql.removeAt(i);
            --i; // **确保索引正确**
        }
    }

    // **写入新提醒**
    for (const Reminder &r : reminders) {
        db.addReminder(r);
        reminder_sql.append(r);  // **同步到全局 reminder_sql**
    }

    qDebug() << "当前提醒列表:";
    for (const Reminder &r : reminder_sql) {
        qDebug() << "事件 ID:" << r.event_id << "提前:" << r.remind_before
                 << "分钟, 开始提醒:" << r.remind_start << " 截止提醒:" << r.remind_end;
    }


    QDialog::accept();  // **关闭对话框**
}


void ReminderDialog::reject()
{
    // 可以在这里添加代码来撤销所有未保存的更改
    QDialog::reject();
}

