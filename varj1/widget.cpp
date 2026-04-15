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

    p.setRenderHint(QPainter::Antialiasing);


    QLinearGradient gradient(200, 150, 350, 300);
    gradient.setColorAt(0, Qt::cyan);
    gradient.setColorAt(1, Qt::blue);

    QBrush b(gradient);
    p.setBrush(b);

    QPen pen(Qt::white);
    pen.setWidth(3);
    p.setPen(pen);

    p.drawRect(200, 150, 150, 150);

    QBrush roofBrush(Qt::yellow);
    p.setBrush(roofBrush);

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
