#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::paintSquare(QPainter &p, int x, int y, int size)
{
    p.drawRect(x, y, size, size);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    int size = 50;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
                p.setBrush(Qt::white);
            else
                p.setBrush(Qt::black);

            paintSquare(p, j * size, i * size, size);
        }
    }
}
