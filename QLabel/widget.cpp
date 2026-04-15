#include "widget.h"
#include <QPainter>
#include <QPaintEvent>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
}

void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);


    QPen pen(Qt::black);
    pen.setWidth(3);
    p.setPen(pen);

    QBrush b;
    b.setColor(Qt::blue);
    b.setStyle(Qt::SolidPattern);
    p.setBrush(b);

    p.drawRect(200, 150, 150, 150);

    QPoint triangle[3] = {
        QPoint(200, 150),
        QPoint(350, 150),
        QPoint(275, 100)
    };
    p.drawPolygon(triangle, 3);
}

MainWidget::~MainWidget()
{
}
