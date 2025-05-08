#ifndef ADDTASKFORM_H
#define ADDTASKFORM_H

#include <QWidget>

#include"data_sql.h"

namespace Ui {
class AddTaskForm;
}

class AddTaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddTaskForm(QWidget *parent = nullptr);
    ~AddTaskForm();
    void setDate(QDate date);

signals:
    void accepted();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddTaskForm *ui;
    QString dateStr;
};

#endif // ADDTASKFORM_H
