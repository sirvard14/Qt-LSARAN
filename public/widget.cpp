#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Layouts
    v1 = new QVBoxLayout(this);

    h1 = new QHBoxLayout();
    h2 = new QHBoxLayout();
    h3 = new QHBoxLayout();

    // Widgets
    l1 = new QLabel("minutes");
    l2 = new QLabel("timer");

    minutes = new QSpinBox();
    minutes->setRange(1, 999);

    lcd = new QLCDNumber();
    lcd->setDigitCount(5);
    lcd->display("00:00");

    ok = new QPushButton("OK");
    pause = new QPushButton("Pause");
    reset = new QPushButton("Reset");

    timer = new QTimer(this);

    totalSeconds = 0;
    remainingSeconds = 0;

    // -------- Layout setup --------
    h1->addWidget(l1);
    h1->addWidget(minutes);
    h1->addWidget(ok);

    h2->addWidget(lcd);

    h3->addWidget(pause);
    h3->addWidget(reset);

    v1->addLayout(h1);
    v1->addLayout(h2);
    v1->addLayout(h3);

    setLayout(v1);
    resize(400, 400);

    // -------- Connections --------
    connect(ok, &QPushButton::clicked, this, &Widget::startTimer);
    connect(pause, &QPushButton::clicked, this, &Widget::pauseTimer);
    connect(reset, &QPushButton::clicked, this, &Widget::resetTimer);
    connect(timer, &QTimer::timeout, this, &Widget::updateTimer);
}

Widget::~Widget()
{
}

// -------- Start timer --------
void Widget::startTimer()
{
    if (!timer->isActive()) {

        int min = minutes->value();
        totalSeconds = min * 60;
        remainingSeconds = totalSeconds;

        lcd->display("00:00");

        timer->start(1000);
    }
}

// -------- Update every second --------
void Widget::updateTimer()
{
    if (remainingSeconds > 0) {

        remainingSeconds--;

        int m = remainingSeconds / 60;
        int s = remainingSeconds % 60;

        lcd->display(
            QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'))
        );
    }
    else {
        timer->stop();
    }
}

// -------- Pause --------
void Widget::pauseTimer()
{
    timer->stop();
}

// -------- Reset --------
void Widget::resetTimer()
{
    timer->stop();

    remainingSeconds = totalSeconds;

    lcd->display("00:00");
}
