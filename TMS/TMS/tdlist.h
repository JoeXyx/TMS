#ifndef TDLIST_H
#define TDLIST_H

#include <QWidget>
#include<QVector>
#include<QMessageBox>
#include<QTableWidgetItem>
#include <QListWidget>
#include<QDate>

#pragma once
class MainWindow;

namespace Ui {
class tdlist;
}

class tdlist : public QWidget
{
    Q_OBJECT

    struct td_event
    {
        QString name;
        QString end_time;
    };

public:
    explicit tdlist(QWidget *parent = nullptr);
    ~tdlist();

    MainWindow *mainwindow;
    QVector<td_event>all;
    QList<QTableWidgetItem*> selectedItems;

    void add();
    void del();
    void tdshow();



private:
    Ui::tdlist *ui;
};

#endif // TDLIST_H
