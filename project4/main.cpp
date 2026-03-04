#include "widget.h"
#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QMessageBox>
#include <QColorDialog>
#include <QSpinBox>
#include <QLCDNumber>
#include <QBoxLayout>


int main(int argc, char *argv[]) {



    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt");
    window.resize(300, 250);
    QSpinBox s;
    QLCDNumber n;
    QHBoxLayout l;
    l.addWidget(&s);
    l.addWidget(&n);
    window.setLayout(&l);
    QObject:: connect(&s,SIGNAL(valueChanged(int)),&n,SLOT(display(int)));

//    QVBoxLayout *layout = new QVBoxLayout(&window);

//    QLabel *label = new QLabel("1+1");
//    layout->addWidget(label);

//    QRadioButton *rb1 = new QRadioButton("3");
//    QRadioButton *rb2 = new QRadioButton("2");
//    QRadioButton *rb3 = new QRadioButton("1");
//    layout->addWidget(rb1);
//    layout->addWidget(rb2);
//    layout->addWidget(rb3);

//    QPushButton *btnCheck = new QPushButton("Check");
//    layout->addWidget(btnCheck);

//    QPushButton *btnColor = new QPushButton("Choose color");
//    layout->addWidget(btnColor);


    window.show();
        return app.exec();
    }

