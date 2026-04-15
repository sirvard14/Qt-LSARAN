#include "widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 400);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    point = event->pos();
    hasPoint = true;

    qDebug() << "X:" << point.x() << "Y:" << point.y();

    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);

    if (hasPoint) {
        painter.drawEllipse(point, 2, 2); // միայն 1 կետ
    }
}
