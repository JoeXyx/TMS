#ifndef SRCCHGFORM_H
#define SRCCHGFORM_H

#include <QWidget>

namespace Ui {
class srcChgForm;
}

class srcChgForm : public QWidget
{
    Q_OBJECT

public:
    explicit srcChgForm(QWidget *parent = nullptr);
    ~srcChgForm();

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
    Ui::srcChgForm *ui;
    int evtid;
};

#endif // SRCCHGFORM_H
