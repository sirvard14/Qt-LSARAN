#include "widget.h"
#include <QLabel>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Օգտվողի տվյալներ");
    this->resize(400, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nameLabel = new QLabel("Անուն: Սիրվարդ");
    nameLabel->setStyleSheet("color: white; background-color: blue; font-size: 18px; font-weight: bold;");
    nameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(nameLabel);

    QLabel *surnameLabel = new QLabel("Ազգանուն: Փաշինյան");
    surnameLabel->setStyleSheet("color: black; background-color: lightgreen; font-size: 18px; font-weight: bold;");
    surnameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(surnameLabel);
}

Widget::~Widget()
{
}
