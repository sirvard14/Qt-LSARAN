#include "widget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QDial>
#include <QProgressBar>
#include <QLCDNumber>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QScrollBar sc(Qt::Horizontal);
    QDial d;
    QProgressBar p;
    p.setRange(0,200);
    QLCDNumber l;
    QVBoxLayout v;
    QLabel la;
    la.setText("<h1>hello world</h1>");
    v.addWidget(&sc);
    v.addWidget(&d);
    v.addWidget(&p);
    v.addWidget(&l);
    v.addWidget(&la);
    QObject::connect(&sc,SIGNAL(valueChanged(int)),&p,SLOT(setValue(int)));
    QObject::connect(&d,SIGNAL(valueChanged(int)),&l,SLOT(display(int)));
    QObject::connect(&p,SIGNAL(valueChanged(int)),&l,SLOT(display(int)));
    QObject::connect(&d,SIGNAL(valueChanged(int)),&p,SLOT(setValue(int)));


    w.setLayout(&v);

    w.resize(300,200);
    w.show();


    return a.exec();
}
