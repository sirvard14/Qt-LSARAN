#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QSpinBox>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QHBoxLayout h1,h2,h3;
    QVBoxLayout v;
    QLabel l1("FULL Name"),l2,l3;
    QLineEdit fname;
    QSpinBox mog;
    QProgressBar progress;

    l2.setText("MOG");
    l3.setText("Progress");

    h1.addWidget(&l1);
    h1.addWidget(&fname);
    h2.addWidget(&l2);
    h2.addWidget(&mog);
    h3.addWidget(&l3);
    h3.addWidget(&progress);
    v.addLayout(&h1);
    v.addLayout(&h2);
    v.addLayout(&h3);

    w.setLayout(&v);
    w.setWindowTitle("My Progress");
    w.resize(400,400);
    w.show();

    return a.exec();
}
