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
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QHBoxLayout *h1, *h2, *h3;
    QVBoxLayout *v1;

    QLabel *l1, *l2;

    QSpinBox *minutes;
    QLCDNumber *lcd;

    QPushButton *ok;
    QPushButton *pause;
    QPushButton *reset;

    QTimer *timer;

    int totalSeconds;
    int remainingSeconds;

private slots:
    void startTimer();
    void updateTimer();
    void pauseTimer();
    void resetTimer();
};

#endif // WIDGET_H
