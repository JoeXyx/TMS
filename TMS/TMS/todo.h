#ifndef TODO_H
#define TODO_H

#include <QWidget>
#include<QString>
#include <QPushButton>
#include <QMessageBox>
#include<QDialog>
#include <QTableWidgetItem>  // 提供 QTableWidgetItem 类
#include <QBrush>           // 用于设置颜色（Qt::red, QColor等）

#pragma once
class MainWindow;

namespace Ui {
class todo;
}

class todo : public QWidget
{
    Q_OBJECT

public:
    explicit todo(QWidget *parent = nullptr);
    ~todo();

    MainWindow *mainwindow;

    void todo_show();




private:
    Ui::todo *ui;
};

#endif // TODO_H
