#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateState();

private:
    void drawLight(QPainter &p, int x, int y, QColor color);

    int state;      // 0=red, 1=yellow, 2=green
    int counter;    // countdown
    QTimer *timer;
};

#endif // WIDGET_H
