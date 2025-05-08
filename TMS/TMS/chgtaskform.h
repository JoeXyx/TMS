#ifndef CHGTASKFORM_H
#define CHGTASKFORM_H

#include <QWidget>

namespace Ui {
class chgTaskForm;
}

class chgTaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit chgTaskForm(QWidget *parent = nullptr);
    ~chgTaskForm();
    void setEid(int e_id);

signals:
    void accepted();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::chgTaskForm *ui;
    int eid;
};

#endif // CHGTASKFORM_H
