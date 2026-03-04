#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *label;
    QPushButton *button;
    QSpinBox *s;
    QVBoxLayout *l;

private slots:
    void calc();
};

#endif // WIDGET_H
