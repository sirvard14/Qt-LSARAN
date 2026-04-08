// widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLineEdit;
class QSpinBox;
class QPushButton;
class QProgressBar;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void updateProgress(int value);

private:
    QLineEdit *nameEdit;
    QSpinBox *kursSpin;
    QSpinBox *gnahatakanSpin;
    QProgressBar *progressBar;
    QLabel *percentLabel;
    QPushButton *minimizeButton;
};

#endif // WIDGET_H
