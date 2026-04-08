#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    kursSpin = new QSpinBox();
        kursSpin->setRange(1, 4);
        kursSpin->setSingleStep(1);

        gnahatakanSpin = new QSpinBox();
        gnahatakanSpin->setRange(0, 20);
        gnahatakanSpin->setSingleStep(1);

    QLabel *nameLabel = new QLabel("Azganun, anun:");
    nameEdit = new QLineEdit();

    QLabel *kursLabel = new QLabel("Kurs:");
    kursSpin = new QSpinBox();
    kursSpin->setRange(1, 4);
    kursSpin->setSingleStep(1);

    QLabel *gnahatakanLabel = new QLabel("Gnahatakan:");
    gnahatakanSpin = new QSpinBox();
    gnahatakanSpin->setRange(0, 20);
    gnahatakanSpin->setSingleStep(1);

    progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    percentLabel = new QLabel("0%");

    minimizeButton = new QPushButton("Minimize");

    QHBoxLayout *progressLayout = new QHBoxLayout();
    progressLayout->addWidget(progressBar);
    progressLayout->addWidget(percentLabel);

    QGridLayout *layout = new QGridLayout();

    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameEdit, 0, 1);

    layout->addWidget(kursLabel, 1, 0);
    layout->addWidget(kursSpin, 1, 1);

    layout->addWidget(gnahatakanLabel, 2, 0);
    layout->addWidget(gnahatakanSpin, 2, 1);

    layout->addLayout(progressLayout, 3, 0, 1, 2);

    layout->addWidget(minimizeButton, 4, 0, 1, 2);

    setLayout(layout);

    setFixedSize(300, 200);


    connect(gnahatakanSpin, SIGNAL(valueChanged(int)), this, SLOT(updateProgress(int)));
    connect(minimizeButton, &QPushButton::clicked, this, &QWidget::showMinimized);
}

Widget::~Widget()
{
}

void Widget::updateProgress(int value)
{
    int percent = (value * 100) / 20;
    progressBar->setValue(percent);
    percentLabel->setText(QString::number(percent) + "%");
}
