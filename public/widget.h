#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QSpinBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QHBoxLayout *h1, *h2, *h3;
    QVBoxLayout *V1;

    QLabel *l1, *l2;

    QSpinBox *minutes;

    QLCDNumber *LCD;

    QPushButton *ok;

    QTimer *timer;

    int minutesLeft;
    int secondsLeft;

public slots:
    void startTimer();
    void updateTimer();
};

#endif // WIDGET_H
