#ifndef DATA_SQL_H
#define DATA_SQL_H

#include <QObject>
#include<QSqlDatabase>
#include<QDateTime>

struct Event{
    int event_id;
    QString title;
    QString description;
    QString start_time;//小时:分钟
    QString end_time;//小时:分钟
    QString priority ;//优先级
    QString status;//状态
    QString created_at;//年-月-日

    Event& operator=(const Event& other)
    {
        event_id=other.event_id;
        title=other.title;
        start_time=other.start_time;
        end_time=other.end_time;
        priority=other.priority;
        status=other.status;
        created_at=other.created_at;
        description=other.description;
        return *this;
    }
};

struct Reminder {
    int event_id;
    int remind_before;
    bool remind_start;
    bool remind_end;

    bool isShownStart;  // 开始提醒是否已弹出
    bool isShownDeadline; // 截止提醒是否已弹出

    // 默认构造函数
    Reminder() : event_id(0), remind_before(0), remind_start(false), remind_end(false), isShownStart(false), isShownDeadline(false) {}

    // 添加构造函数
    Reminder(int id, int before, bool start, bool deadline)
        : event_id(id), remind_before(before), remind_start(start), remind_end(deadline), isShownStart(false), isShownDeadline(false) {}

};

class data_sql : public QObject
{
    Q_OBJECT
public:
    explicit data_sql(QObject *parent = nullptr);
    QSqlDatabase db;
    //增
    bool addevent(Event info);
    //删
    bool delevent(int id);
    //改
    bool update(Event info);
    //查
    Event search(int id);
    QList<Event>getsql();
    void updatesql(QList<Event> last);

    //事件提醒
    QVector<Reminder> getRemindersForEvent(int eventId);
    bool clearRemindersForEvent(int eventId);
    bool addReminder(const Reminder &reminder);
    QList<Reminder> getAllReminders();
    static bool updateReminderShownFlags(int eventId, bool shownStart, bool shownDeadline) ;
signals:
};

#endif // DATA_SQL_H
