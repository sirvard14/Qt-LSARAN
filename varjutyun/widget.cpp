#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 400);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int size = 8;

    int boardSize = qMin(width(), height());
    int cell = boardSize / size;

    int offsetX = (width() - boardSize) / 2;
    int offsetY = (height() - boardSize) / 2;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {

            if((i + j) % 2 == 0)
                painter.setBrush(Qt::white);
            else
                painter.setBrush(Qt::black);

            painter.drawRect(offsetX + j * cell,
                             offsetY + i * cell,
                             cell, cell);
        }
    }
}
