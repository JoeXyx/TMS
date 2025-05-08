#include "CircularProgressBar.h"
#include <QPainter>
#include <QConicalGradient>
#include <QtMath>

CircularProgressBar::CircularProgressBar(QWidget *parent)
    : QWidget(parent), m_min(0), m_max(100), m_value(0)
{
    setMinimumSize(200, 200);
    setAttribute(Qt::WA_TranslucentBackground);
}

void CircularProgressBar::setRange(int min, int max)
{
    m_min = min;
    m_max = max;
    update();
}

void CircularProgressBar::setValue(int value)
{
    value = qBound(m_min, value, m_max);
    if (m_value != value) {
        m_value = value;
        update();
        emit valueChanged(m_value);
    }
}

void CircularProgressBar::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = height();
    int size = qMin(w, h) - 20;

    QPointF center(w / 2.0, h / 2.0);
    QRectF circleRect(center.x() - size / 2, center.y() - size / 2, size, size);

    // 背景圆环底座（浅灰色）
    QPen bgPen(QColor("#ECECEC"), 20);
    bgPen.setCapStyle(Qt::RoundCap);
    p.setPen(bgPen);
    p.setBrush(Qt::NoBrush);
    p.drawEllipse(circleRect);

    // 渐变颜色圆环
    QConicalGradient gradient(center, 90);  // 3点钟方向开始
    gradient.setColorAt(0.0, QColor("#3F8EFc"));   // 蓝
    gradient.setColorAt(0.5, QColor("#8B5CF6"));   // 紫
    gradient.setColorAt(1.0, QColor("#EF4444"));   // 红

    QPen progressPen(QBrush(gradient), 20);
    progressPen.setCapStyle(Qt::RoundCap);
    p.setPen(progressPen);

    int spanAngle = -360.0 * 16 * (m_value - m_min) / (m_max - m_min);
    p.drawArc(circleRect, 90 * 16, spanAngle);

    // 中央时间文字
    int seconds = m_value;
    int min = seconds / 60;
    int sec = seconds % 60;
    QString timeText = QString("%1:%2")
                           .arg(min, 2, 10, QLatin1Char('0'))
                           .arg(sec, 2, 10, QLatin1Char('0'));

    QFont font("Segoe UI", size / 6, QFont::Bold);
    p.setFont(font);
    p.setPen(QColor("#1F2937"));  // 深灰蓝
    p.drawText(circleRect, Qt::AlignCenter, timeText);
}
