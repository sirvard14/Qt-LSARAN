#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void calc();
    void showDialValue();

private:
    QSpinBox *s;
    QDial *d;
    QLCDNumber *lcd;
    QPushButton *button;
    QLabel *label;
    QVBoxLayout *l;
};

#endif // WIDGET_H
