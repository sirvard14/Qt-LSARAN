#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *l1, *lblBuy, *lblSell;
    QRadioButton *v1, *v2, *v3;
    QLineEdit *editBuy, *editSell;
    QPushButton *btnSubmit;
    QVBoxLayout *mainLayout;
    QHBoxLayout *h1, *hBuy, *hSell;
};

#endif
