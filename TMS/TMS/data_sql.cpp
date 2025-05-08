#include "data_sql.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlError>

data_sql::data_sql(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("software");
    db.setUserName("root");
    db.setPassword("15200151926");
    bool ok = db.open();
    db.setConnectOptions("MYSQL_OPT_RECONNECT=1;CLIENT_MULTI_STATEMENTS=1;CHARSET=UTF8MB4");
    if (!ok){
         QMessageBox::information(NULL, "infor", "open failed");
    }

}

bool data_sql::addevent(Event info)
{
    QSqlQuery sql(db);
    QString strsql=QString("INSERT INTO events VALUES (%1, '%2', '%3','%4','%5','%6','%7','%8')").
                     arg(info.event_id).arg(info.title).arg(info.description).arg(info.start_time).arg(info.end_time).arg(info.priority)
                         .arg(info.status).arg(info.created_at);
    return sql.exec(strsql);
}

bool data_sql::delevent(int id)
{
    QSqlQuery sql(db);
    QString strsql=QString("delete from events where event_id = '%1'").
                     arg(id);
    return sql.exec(strsql);
}

bool data_sql::update(Event info)
{
    QSqlQuery sql(db);
    QString strsql=QString("update events set event_id=%1 ,title='%2' ,description='%3',start_time='%4',end_time='%5',priority='%6',status='%7',created_at='%8'").
                     arg(info.event_id).arg(info.title).arg(info.description).arg(info.start_time).arg(info.end_time).arg(info.priority)
                         .arg(info.status).arg(info.created_at);
    return sql.exec(strsql);
}

Event data_sql::search(int id)
{
    Event l;
    QSqlQuery sql(db);
    QString strsql=QString("select * from events where event_id=%1").arg(id);
    sql.exec(strsql) ;
    while(sql.next()){
       l.event_id=sql.value(0).toUInt();
        l.title=sql.value(1).toString();
        l.description=sql.value(2).toString();
        l.start_time=sql.value(3).toString();
        l.end_time=sql.value(4).toString();
        l.priority=sql.value(5).toString();
        l.status=sql.value(6).toString();
        l.created_at=sql.value(7).toString();
    }
    return l;
}

QList<Event> data_sql::getsql()
{
    QList<Event> l;
    QSqlQuery sql(db);
    QString strsql=QString("select * from events ");
    sql.exec(strsql) ;
    Event temp;
    int n=0;
    while(sql.next()){

        temp.event_id=n;
        temp.title=sql.value(1).toString();
        temp.description=sql.value(2).toString();
        temp.start_time=sql.value(3).toString();
        temp.end_time=sql.value(4).toString();
        temp.priority=sql.value(5).toString();
        temp.status=sql.value(6).toString();
        temp.created_at=sql.value(7).toString();
        l.push_back(temp);
        ++n;
    }
    return l;
}

void data_sql::updatesql(QList<Event> last)
{
    QSqlQuery sql(db);
    QString strsql=QString("delete from events ");
    sql.exec(strsql) ;
    QSqlQuery up_sql(db);
    for(int i=0;i<last.size();i++){
    QString up_strsql=QString("INSERT INTO events VALUES (%1, '%2', '%3','%4','%5','%6','%7','%8')").
                     arg(i).arg(last[i].title).arg(last[i].description).arg(last[i].start_time).arg(last[i].end_time).arg(last[i].priority)
                                .arg(last[i].status).arg(last[i].created_at);
        sql.exec(up_strsql);
    }
}

//事件提醒
QList<Reminder> data_sql::getAllReminders()
{
    QList<Reminder> reminders;
    QSqlQuery query("SELECT event_id, remind_before, remind_start, remind_end, is_shown_start, is_shown_deadline FROM reminders");

    while (query.next()) {
        Reminder r;
        r.event_id = query.value(0).toInt();
        r.remind_before = query.value(1).toInt();
        r.remind_start = query.value(2).toBool();
        r.remind_end = query.value(3).toBool();
        r.isShownStart = query.value(4).toBool();
        r.isShownDeadline = query.value(5).toBool();
        reminders.append(r);
    }
    return reminders;
}

bool data_sql::updateReminderShownFlags(int eventId, bool shownStart, bool shownDeadline) {
    QSqlQuery query;
    query.prepare("UPDATE reminders SET is_shown_start = ?, is_shown_deadline = ? WHERE event_id = ?");
    query.addBindValue(shownStart);
    query.addBindValue(shownDeadline);
    query.addBindValue(eventId);
    return query.exec();
}


QVector<Reminder> data_sql::getRemindersForEvent(int eventId) {
    QVector<Reminder> reminders;
    QSqlQuery query;

    query.prepare("SELECT remind_before, remind_start, remind_end, is_shown_start, is_shown_deadline FROM reminders WHERE event_id = ?");
    query.addBindValue(eventId);

    if (query.exec()) {
        while (query.next()) {
            Reminder reminder;
            reminder.event_id = eventId;
            reminder.remind_before = query.value(0).toInt();
            reminder.remind_start = query.value(1).toBool();
            reminder.remind_end = query.value(2).toBool();
            reminder.isShownStart = query.value(3).toBool();
            reminder.isShownDeadline = query.value(4).toBool();
            reminders.append(reminder);
        }
    } else {
        qDebug() << "数据库查询失败：" << query.lastError().text();
    }

    return reminders;
}

bool data_sql::clearRemindersForEvent(int eventId) {
    QSqlQuery query;
    query.prepare("DELETE FROM reminders WHERE event_id = ?");
    query.addBindValue(eventId);

    if (!query.exec()) {
        qDebug() << "删除提醒失败：" << query.lastError().text();
        return false;
    }
    return true;
}

bool data_sql::addReminder(const Reminder &reminder) {
    QSqlQuery query;
    query.prepare("INSERT INTO reminders (event_id, remind_before, remind_start, remind_end, is_shown_start, is_shown_deadline) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(reminder.event_id);
    query.addBindValue(reminder.remind_before);
    query.addBindValue(reminder.remind_start);
    query.addBindValue(reminder.remind_end);
    query.addBindValue(reminder.isShownStart);
    query.addBindValue(reminder.isShownDeadline);

    if (!query.exec()) {
        qDebug() << "添加提醒失败：" << query.lastError().text();
        return false;
    }
    return true;
}
