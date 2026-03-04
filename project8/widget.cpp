#include "widget.h"
#include <QWidget>


Widget::Widget(QWidget *parent):
    QWidget(parent)
{
    button=new QPushButton("Click Me");
    label=new QLabel("Value: 0");
    s=new QSpinBox;
    l=new QVBoxLayout(this);


    s->setRange(0, 100);
       s->setValue(0);

       l->addWidget(s);
       l->addWidget(button);
       l->addWidget(label);

       connect(button, &QPushButton::clicked, this, &Widget::calc);
       setMinimumSize(120, 90);


}

Widget::~Widget()
{

}
void Widget::calc()
{

    int value = s->value();
    label->setText("Value: " + QString::number(value));
}
