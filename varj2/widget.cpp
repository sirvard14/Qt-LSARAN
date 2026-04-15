#include "widget.h"
#include <QPainter>
#include <QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent), state(0), counter(25)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateState);
    timer->start(1000);

    setFixedSize(200, 400);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.setBrush(Qt::black);
    p.drawRect(rect());

    drawLight(p, 50, 50, state == 0 ? Qt::red : Qt::darkRed);
    drawLight(p, 50, 150, state == 1 ? QColor(255,165,0) : QColor(100,70,0));
    drawLight(p, 50, 250, state == 2 ? Qt::green : Qt::darkGreen);


    p.setPen(Qt::white);
    p.setFont(QFont("Arial", 20, QFont::Bold));
    p.drawText(rect(), Qt::AlignBottom | Qt::AlignHCenter,
               QString::number(counter));
}

void Widget::drawLight(QPainter &p, int x, int y, QColor color)
{
    p.setBrush(color);
    p.drawEllipse(x, y, 100, 100);
}

void Widget::updateState()
{
    counter--;

    if (counter == 0) {
        state = (state + 1) % 3;

        if (state == 0) counter = 25;
        if (state == 1) counter = 2;
        if (state == 2) counter = 20;
    }

    update();
}
