#include "widget.h"
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent), drawing(false)
{
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    startPoint = event->pos();
    endPoint = startPoint;
    drawing = true;
    update();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing) {
        endPoint = event->pos();
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    endPoint = event->pos();
    drawing = false;
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawRect(QRect(startPoint, endPoint));
}
