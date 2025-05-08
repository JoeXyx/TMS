#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDate>
#include"data_sql.h"

#include<QMessageBox>
#include<QTimer>
#include"addtaskform.h"
#include"chgtaskform.h"
#include"srcchgform.h"
#include"srctaskform.h"
#include"dlttaskform.h"
#include"reminderdialog.h"
#include"todo.h"

extern QList<Event>from_sql;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void selectDate(const QDate &date);
    void showTasks();
    void addTask();
    void chgTask();
    void chgTask_2();
    void delTask();
    void delTask_2();
    void srcTask();
    void flushCalendar();
    void emphasizeCalendar();
    void todo_clicked();

    void showDate(QString tempDate);

    //事件提醒
    void showReminderDialogForSelectedItem();
    void startReminderCheck();
    void showReminder(const Event &event, const Reminder &reminder, bool isStartReminder);
protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_pushButton_clicked();

    void on_tdlistButton_clicked();

    void on_concentrateBtn_clicked();

private:
    Ui::MainWindow *ui;
    data_sql my_sql;
    QDate selectedDate;
    QMap<QDate, QStringList> tasks;

    //事件提醒
    QTimer *reminderTimer;
    void checkReminders();  // 检查提醒的函数
};
#endif // MAINWINDOW_H
