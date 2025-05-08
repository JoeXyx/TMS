#ifndef SRCTASKFORM_H
#define SRCTASKFORM_H

#include <QWidget>

namespace Ui {
class SrcTaskForm;
}

class SrcTaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit SrcTaskForm(QWidget *parent = nullptr);
    ~SrcTaskForm();

signals:
    void accepted();

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
    Ui::SrcTaskForm *ui;
    int evtid;
    QString tempDate;
};

#endif // SRCTASKFORM_H
