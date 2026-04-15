#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint point;   // մեկ կետ
    bool hasPoint = false; // կա՞ կետ
};

#endif // WIDGET_H
