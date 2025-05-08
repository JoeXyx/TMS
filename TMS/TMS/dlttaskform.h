#ifndef DLTTASKFORM_H
#define DLTTASKFORM_H

#include <QWidget>

namespace Ui {
class DltTaskForm;
}

class DltTaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit DltTaskForm(QWidget *parent = nullptr);
    ~DltTaskForm();

signals:
    void accepted();
    void accepted_2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_opt_pushButton_clicked();
    void on_opt_pushButton_2_clicked();
    void on_opt_pushButton_3_clicked();
    void on_opt_pushButton_4_clicked();
    void on_opt_pushButton_5_clicked();
    void on_opt_pushButton_6_clicked();
    void on_opt_pushButton_7_clicked();
    void on_opt_pushButton_8_clicked();

private:
    Ui::DltTaskForm *ui;
    int evtid;
};

#endif // DLTTASKFORM_H
