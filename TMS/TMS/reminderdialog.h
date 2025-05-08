#pragma once
#ifndef REMINDERDIALOG_H
#define REMINDERDIALOG_H

#include <QDialog>
#include "data_sql.h"  // 引入数据库操作类
#include <QList>
#include<QMessageBox>

namespace Ui {
class ReminderDialog;
}

class ReminderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReminderDialog(int event_id, QWidget *parent = nullptr);
    ~ReminderDialog();

private slots:
    void addReminder();     // 添加提醒
    void removeReminder();  // 删除选中的提醒
    void accept() override; // 确认保存
    void reject() override;

private:
    Ui::ReminderDialog *ui;
    int event_id; // 当前事件 ID
    QList<Reminder> reminders;  // 存储当前事件的提醒

    void loadReminders();  // 加载已有提醒
};

#endif // REMINDERDIALOG_H
