#ifndef FOCUSDIALOG_H
#define FOCUSDIALOG_H

#include <QDialog>
#include <QTimer>
#include "CircularProgressBar.h"
#include <QStringList>
#include <QPropertyAnimation>

namespace Ui {
class FocusDialog;
}

class FocusDialog : public QDialog {
    Q_OBJECT

public:
    explicit FocusDialog(QWidget *parent = nullptr);
    ~FocusDialog();
    int getFocusMinutes() const;
    void setValueWithAnimation(int value);
    void scrollText();

private slots:
    void on_beginBtn_clicked();
    void on_cancelBtn_clicked();
    void updateTimer();

private:
    QTimer *scrollTimer;
    int scrollPos;
    void changeSlogan();
    void resetUI();

private:
    Ui::FocusDialog *ui;
    QTimer *countdownTimer = nullptr;
    CircularProgressBar* m_circularProgress = nullptr;
    int remainingTime = 0;
    int circuit = 0;

    QStringList slogans;
    static constexpr int SLOGAN_COUNT = 25;
};

#endif // FOCUSDIALOG_H
