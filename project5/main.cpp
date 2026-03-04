#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QLCDNumber>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QLabel l1("Full Name"),l2("Age"),l3("Age"),l4;
    QLineEdit in1;
    QSlider s(Qt::Horizontal);
    QSpinBox sp;
    QLCDNumber lsd;
    QHBoxLayout h1,h2,h3,h4,h5;
    QVBoxLayout v;
    h1.addWidget(&l1);
    h1.addWidget(&in1);
    h2.addWidget(&l2);
    h2.addWidget(&s);
    h3.addWidget(&l3);
    h3.addWidget(&sp);
    h4.addWidget(&lsd);
    h5.addWidget(&l4);
    v.addLayout(&h1);
    v.addLayout(&h2);
    v.addLayout(&h3);
    v.addLayout(&h4);
    v.addLayout(&h5);
    QObject::connect(&in1,SIGNAL(textChanged(QString)),&l4,SLOT(setText(QString)));
    QObject::connect(&s,SIGNAL(valueChanged(int)),&lsd,SLOT(display(int)));
    QObject::connect(&sp,SIGNAL(valueChanged(int)),&lsd,SLOT(display(int)));
    QObject::connect(&sp,SIGNAL(valueChanged(int)),&s,SLOT(setValue(int)));
    QObject::connect(&s,SIGNAL(valueChanged(int)),&sp,SLOT(setValue(int)));


    w.setLayout(&v);
    w.setWindowTitle("Functions");
    w.resize(300,250);
    w.show();

    return a.exec();
}
