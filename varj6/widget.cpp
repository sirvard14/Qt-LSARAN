#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 700);
}

Widget::~Widget()
{
}

QPolygon Widget::paintSquare(int x, int y)
{
    QPolygon square;
    square << QPoint(x, y)<< QPoint(x, y + 10)<< QPoint(x + 10, y + 10) << QPoint(x + 10, y);

    return square;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::green);
    p.setPen(pen);

    int size = 80;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            QPolygon square = paintSquare(j * size, i * size);

            if ((i + j) % 2 == 0)
                p.setBrush(Qt::white);
            else
                p.setBrush(Qt::black);

            p.drawPolygon(square);
        }
    }
}
