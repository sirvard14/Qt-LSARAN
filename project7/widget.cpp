#include "widget.h"
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    s = new QSpinBox;
    d = new QDial;
    lcd = new QLCDNumber;
    button = new QPushButton("Calculate");
    label = new QLabel("Dial value is: 0");

    l = new QVBoxLayout;

    s->setRange(0, 100);
    d->setRange(0, 100);

    l->addWidget(s);
    l->addWidget(d);
    l->addWidget(lcd);
    l->addWidget(button);
    l->addWidget(label);

    setLayout(l);
    resize(300, 500);

    // use old-style connect to avoid overload ambiguity
    connect(s, SIGNAL(valueChanged(int)), d, SLOT(setValue(int)));
    connect(d, SIGNAL(valueChanged(int)), s, SLOT(setValue(int)));
    connect(button, SIGNAL(clicked()), this, SLOT(calc()));
    connect(d, SIGNAL(valueChanged(int)), this, SLOT(showDialValue()));
}

Widget::~Widget()
{
}

void Widget::calc()
{
    int x = s->value();
    int y = d->value();  // fixed semicolon
    lcd->display(x);
}

void Widget::showDialValue()
{
    int z = d->value();
    label->setText(QString("Dial value is: %1").arg(z));
}
