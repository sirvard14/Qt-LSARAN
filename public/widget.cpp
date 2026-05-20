#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    l1 = new QLabel("Minutes:");
    l2 = new QLabel("Timer:");

    minutes = new QSpinBox;
    minutes->setRange(1, 60);

    ok = new QPushButton("OK");

    LCD = new QLCDNumber;

    timer = new QTimer(this);

    h1 = new QHBoxLayout;
    h2 = new QHBoxLayout;
    h3 = new QHBoxLayout;

    V1 = new QVBoxLayout;

    h1->addWidget(l1);
    h1->addWidget(minutes);

    h2->addWidget(ok);

    h3->addWidget(l2);
    h3->addWidget(LCD);

    V1->addLayout(h1);
    V1->addLayout(h2);
    V1->addLayout(h3);

    setLayout(V1);

    connect(ok, &QPushButton::clicked,
            this, &Widget::startTimer);

    connect(timer, &QTimer::timeout,
            this, &Widget::updateTimer);
}

void Widget::startTimer()
{
    minutesLeft = minutes->value();
    secondsLeft = 0;

    LCD->display(minutesLeft * 60 + secondsLeft);

    timer->start(1000);
}

void Widget::updateTimer()
{
    if (minutesLeft == 0 && secondsLeft == 0)
    {
        timer->stop();
        return;
    }

    if (secondsLeft == 0)
    {
        if (minutesLeft > 0)
        {
            minutesLeft--;
            secondsLeft = 59;
        }
    }
    else
    {
        secondsLeft--;
    }

    LCD->display(minutesLeft * 60 + secondsLeft);
}

Widget::~Widget()
{
}
