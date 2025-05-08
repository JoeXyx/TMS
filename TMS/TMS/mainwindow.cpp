#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <FocusDialog.h>
#include <QGraphicsDropShadowEffect>
#include<qinputdialog.h>
#include"bst.h"
#include "tdlist.h"

void turnintoBtn(QPushButton* btn){
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(15);         // 模糊程度
    shadow->setOffset(0, 4);           // 阴影偏移（X,Y）
    shadow->setColor(QColor(0, 0, 0, 80));
    btn->setGraphicsEffect(shadow);
}

void turnintoWid(QWidget* wid){
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(15);         // 模糊程度
    shadow->setOffset(0, 4);           // 阴影偏移（X,Y）
    shadow->setColor(QColor(0, 0, 0, 80));
    wid->setGraphicsEffect(shadow);
}

//全局变量（事件数组）
QList<Event>from_sql;
QList<Reminder> reminder_sql;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    from_sql=my_sql.getsql();
    ui->setupUi(this);

    // 允许透明背景
    setAttribute(Qt::WA_TranslucentBackground);

    setWindowIcon(QIcon(":/assets/Icon.png"));

    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::selectDate);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->chgTaskButton, &QPushButton::clicked, this, &MainWindow::chgTask);
    connect(ui->srcChgButton, &QPushButton::clicked, this, &MainWindow::chgTask_2);
    connect(ui->delTaskButton, &QPushButton::clicked, this, &MainWindow::delTask);
    connect(ui->srcTaskButton, &QPushButton::clicked, this, &MainWindow::srcTask);
    connect(ui->delTaskButton_2, &QPushButton::clicked, this, &MainWindow::delTask_2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    turnintoWid(ui->calendarWidget);
    turnintoWid(ui->tableWidget);
    turnintoBtn(ui->addTaskButton);
    turnintoBtn(ui->chgTaskButton);
    turnintoBtn(ui->delTaskButton);
    turnintoBtn(ui->delTaskButton_2);
    turnintoBtn(ui->srcTaskButton);
    turnintoBtn(ui->pushButton);
    turnintoBtn(ui->srcTaskButton);
    turnintoBtn(ui->srcChgButton);
    turnintoBtn(ui->tdlistButton);
    turnintoBtn(ui->concentrateBtn);

    //事件提醒
    // **读取提醒数据**
    reminder_sql = my_sql.getAllReminders();
    // 启动定时检查提醒的功能
    startReminderCheck();
    // 设置表格的选中行为和模式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // 连接双击信号到槽
    connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &MainWindow::showReminderDialogForSelectedItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectDate(const QDate &date) {
    selectedDate = date;
    showTasks();
}

//重写窗口关闭函数
void MainWindow::closeEvent(QCloseEvent* event)
{
    //在退出程序前更新数据库
    my_sql.updatesql(from_sql);
    QWidget::closeEvent(event);
}

// 显示任务列表
void MainWindow::showTasks() {
    //flushCalendar();
    ui->tableWidget->clearContents();
    QString dateStr=this->selectedDate.toString("yyyy-MM-dd");
    int n=0;
    for(int i=0;i<from_sql.size();++i)
    {
        if(from_sql[i].created_at==dateStr)
        {
            ui->tableWidget->setItem(n,0,new QTableWidgetItem(QString::number(from_sql[i].event_id)));
            ui->tableWidget->setItem(n,1,new QTableWidgetItem(from_sql[i].title));
            ui->tableWidget->setItem(n,2,new QTableWidgetItem(from_sql[i].start_time));
            ui->tableWidget->setItem(n,3,new QTableWidgetItem(from_sql[i].end_time));
            ui->tableWidget->setItem(n,4,new QTableWidgetItem(from_sql[i].priority));
            ui->tableWidget->setItem(n,5,new QTableWidgetItem(from_sql[i].status));
            ui->tableWidget->setItem(n,6,new QTableWidgetItem(from_sql[i].description));
            ++n;
        }
    }
    bst.deleteBST();
    bst.Build_BST(from_sql,from_sql.size());
    emphasizeCalendar();
}

// 添加任务
void MainWindow::addTask() {
    if (!selectedDate.isValid()) return;

    flushCalendar();

    AddTaskForm*ad=new AddTaskForm();
    ad->show();
    ad->setDate(this->selectedDate);
}

//修改任务
void MainWindow::chgTask(){
    if (!selectedDate.isValid()) return;
    int currentRow=ui->tableWidget->currentRow();
    if(currentRow == -1||!ui->tableWidget->item(currentRow,0))
    {
        QMessageBox::information(this,"提醒","必须选择一个事件进行修改！");
    }
    else {
        flushCalendar();
        int e_id=ui->tableWidget->item(currentRow,0)->text().toInt();
        chgTaskForm*ch=new chgTaskForm();
        ch->setEid(e_id);
        ch->show();
    }
}

void MainWindow::chgTask_2()
{
    srcChgForm*sc=new srcChgForm();
    sc->show();
}

//删除任务
void MainWindow::delTask(){
    if (!selectedDate.isValid()) return;
    int currentRow=ui->tableWidget->currentRow();
    if(currentRow == -1||!ui->tableWidget->item(currentRow,0))
    {
        QMessageBox::information(this,"提醒","必须选择一个事件进行删除！");
        return;
    }
    else {
        flushCalendar();
        int e_id=ui->tableWidget->item(currentRow,0)->text().toInt();
        int n=from_sql.size();
        if(e_id==n-1)
        {
            from_sql.pop_back();
            showTasks();
            QMessageBox::information(this,"提醒","删除成功！");
            return;
        }
        for(int i=e_id;i<n-1;++i)
        {
            from_sql[i]=from_sql[i+1];
            from_sql[i].event_id=i;
        }
        from_sql.pop_back();
        showTasks();
        //emphasizeCalendar();

        QMessageBox::information(this,"提醒","删除成功！");
        return;
    }
}

void MainWindow::delTask_2()
{
   DltTaskForm*dl=new DltTaskForm();
    dl->show();
}

//查询任务
void MainWindow::srcTask(){
    SrcTaskForm*sr=new SrcTaskForm();
    sr->show();
}

void MainWindow::flushCalendar(){
    for(int i = 0;i < from_sql.size();i++){
        QDate date = QDate::fromString(from_sql[i].created_at, "yyyy-MM-dd");
        ui->calendarWidget->setDateTextFormat(date, ui->calendarWidget->dateTextFormat(QDate()));
    }
}

void MainWindow::emphasizeCalendar(){
    QList<Event> from_sql2 = from_sql;

    sort(from_sql2.begin(),from_sql2.end(),[=](Event e1, Event e2){
        QString e1_priority = e1.priority;
        QString e2_priority = e2.priority;
        int i = -1;
        int j = -1;
        if(e1_priority == "Low")
            {
            i = 0;
        }
        else if(e1_priority == "Medium"){
            i = 1;
        }
        else if(e1_priority == "High"){
            i = 2;
        }
        if(e2_priority == "Low")
        {
            j = 0;
        }
        else if(e2_priority == "Medium"){
            j = 1;
        }
        else if(e2_priority == "High"){
            j = 2;
        }
        return i < j;
    });

    QTextCharFormat format;
    format.setForeground(Qt::red);    // 设置文字颜色

    for(int i = 0;i < from_sql2.size();i++){
        QDate date = QDate::fromString(from_sql2[i].created_at, "yyyy-MM-dd");

        if(from_sql2[i].priority == "Low"){
            format.setBackground(Qt::green);
        }
        else if(from_sql2[i].priority == "Medium"){
                format.setBackground(Qt::yellow);
            }
        else if(from_sql2[i].priority == "High")
        {
                format.setForeground(Qt::black);
                format.setBackground(Qt::red);
            }
        ui->calendarWidget->setDateTextFormat(date, format);
    }

}

void MainWindow::showDate(QString tempDate)
{
    QDate dt = QDate::fromString(tempDate, "yyyy-MM-dd");
    selectedDate=dt;
    ui->calendarWidget->setSelectedDate(dt);
    ui->calendarWidget->showSelectedDate();
    showTasks();
}

//事件提醒
void MainWindow::showReminderDialogForSelectedItem() {
    // 获取当前选中的行
    int row = ui->tableWidget->currentRow();
    if (row == -1) return; // 没有选中行

    // 获取该行的 event_id
    int eventId = ui->tableWidget->item(row, 0)->text().toInt(); // 假设 event_id 在第0列

    // 创建并显示 ReminderDialog
    ReminderDialog *dialog = new ReminderDialog(eventId, this); // 创建对话框
    dialog->exec(); // 以模态方式显示对话框
}

void MainWindow::startReminderCheck()
{
    reminderTimer = new QTimer(this);
    connect(reminderTimer, &QTimer::timeout, this, &MainWindow::checkReminders);
    reminderTimer->start(1000); // 每 1 秒检查一次
}

void MainWindow::checkReminders()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    qDebug() << "checkReminders() 运行, 当前时间:" << currentTime.toString("yyyy-MM-dd HH:mm:ss");

    for (const Event &event : from_sql) {
        qDebug() << "检查事件 ID:" << event.event_id << " 开始时间:" << event.start_time << " 结束时间:" << event.end_time;

        // **保证 start_time 和 end_time 都是 "HH:mm" 格式**
        QString formattedStartTime = event.start_time;
        QString formattedEndTime = event.end_time;

        // 确保小时和分钟是两位数
        QStringList startParts = formattedStartTime.split(":");
        QStringList endParts = formattedEndTime.split(":");

        if (startParts.size() == 2) {
            formattedStartTime = QString("%1:%2")
            .arg(startParts[0].rightJustified(2, '0'))
                .arg(startParts[1].rightJustified(2, '0'));
        }

        if (endParts.size() == 2) {
            formattedEndTime = QString("%1:%2")
            .arg(endParts[0].rightJustified(2, '0'))
                .arg(endParts[1].rightJustified(2, '0'));
        }

        QDate eventDate = QDate::currentDate();
        QTime eventStartTime = QTime::fromString(formattedStartTime, "HH:mm");
        QTime eventEndTime = QTime::fromString(formattedEndTime, "HH:mm");

        if (!eventStartTime.isValid() || !eventEndTime.isValid()) {
            qDebug() << "事件时间解析失败，跳过";
            continue;
        }

        QDateTime eventStart(eventDate, eventStartTime);
        QDateTime eventEnd(eventDate, eventEndTime);
        qDebug() << "解析后的事件开始时间:" << eventStart.toString("yyyy-MM-dd HH:mm:ss");
        qDebug() << "解析后的事件截止时间:" << eventEnd.toString("yyyy-MM-dd HH:mm:ss");

        for (Reminder &r : reminder_sql) {
            if (r.event_id != event.event_id) continue;

            // **开始提醒**
            if (r.remind_start) {
                QDateTime startReminderTime = eventStart.addSecs(-r.remind_before * 60);
                qDebug() << "开始提醒时间:" << startReminderTime.toString("yyyy-MM-dd HH:mm:ss");

                if (!r.isShownStart && currentTime >= startReminderTime && currentTime <= startReminderTime.addSecs(60)) {
                    qDebug() << "开始提醒触发!";
                    showReminder(event, r, true); // true 表示是“开始提醒”
                    r.isShownStart = true; // 记录已弹出，防止重复
                    data_sql::updateReminderShownFlags(r.event_id, true, r.isShownDeadline);
                }
            }

            // **截止提醒**
            if (r.remind_end) {
                QDateTime deadlineReminderTime = eventEnd.addSecs(-r.remind_before * 60);
                qDebug() << "截止提醒时间:" << deadlineReminderTime.toString("yyyy-MM-dd HH:mm:ss");

                if (!r.isShownDeadline && currentTime >= deadlineReminderTime && currentTime <= deadlineReminderTime.addSecs(60)) {
                    qDebug() << "截止提醒触发!";
                    showReminder(event, r, false); // false 表示是“截止提醒”
                    r.isShownDeadline = true; // 记录已弹出，防止重复
                    data_sql::updateReminderShownFlags(r.event_id, r.isShownStart, true);
                }
            }
        }
    }
}

void MainWindow::showReminder(const Event &event, const Reminder &reminder, bool isStartReminder)
{
    // 确保 start_time 格式正确
    QDateTime eventStartTime = QDateTime::fromString(event.start_time, "yyyy-MM-dd HH:mm:ss");
    QString timeStr = eventStartTime.isValid() ? eventStartTime.toString("yyyy-MM-dd HH:mm") : event.start_time;

    // **提醒类型**
    QString reminderType = isStartReminder ? "开始提醒" : "截止提醒";

    // **弹窗提醒**
    QString message = QString("提醒：%1\n事件: %2\n时间: %3\n距离事件%4还有 %5 分钟")
                          .arg(reminderType)
                          .arg(event.title)
                          .arg(timeStr)
                          .arg(isStartReminder ? "开始" : "截止")
                          .arg(reminder.remind_before);

    QMessageBox::information(this, "事件提醒", message);
}

void MainWindow::on_pushButton_clicked()
{
    todo *todoWindow=new todo();
    todoWindow->show();
}


void MainWindow::on_tdlistButton_clicked()
{
    tdlist *tdlistWindow=new tdlist();
    tdlistWindow->show();
}


void MainWindow::on_concentrateBtn_clicked()
{
    FocusDialog dlg(nullptr);
    dlg.exec();

}

