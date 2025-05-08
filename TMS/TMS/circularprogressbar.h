#ifndef CIRCULARPROGRESSBAR_H
#define CIRCULARPROGRESSBAR_H

#include <QWidget>

class CircularProgressBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit CircularProgressBar(QWidget *parent = nullptr);
    void setRange(int min, int max);
    void setValue(int value);
    int value() const { return m_value; }

signals:
    void valueChanged(int newValue);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_min;
    int m_max;
    int m_value;
};

#endif // CIRCULARPROGRESSBAR_H
