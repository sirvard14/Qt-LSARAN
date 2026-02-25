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

    // Labels
    QLabel *l1 = new QLabel("Name");
    QLabel *l2 = new QLabel("Surname");
    QLabel *l3 = new QLabel("Age");
    QLabel *l4 = new QLabel("MOG");
    QLabel *l5 = new QLabel("Progress");

    // Inputs
    QLineEdit *name = new QLineEdit;
    QLineEdit *surname = new QLineEdit;
    QSpinBox *age = new QSpinBox;
    QLineEdit *mog = new QLineEdit;
    QProgressBar *progress = new QProgressBar;

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *h1 = new QHBoxLayout;
    h1->addWidget(l1);
    h1->addWidget(name);

    QHBoxLayout *h2 = new QHBoxLayout;
    h2->addWidget(l2);
    h2->addWidget(surname);

    QHBoxLayout *h3 = new QHBoxLayout;
    h3->addWidget(l3);
    h3->addWidget(age);

    QHBoxLayout *h4 = new QHBoxLayout;
    h4->addWidget(l4);
    h4->addWidget(mog);

    QHBoxLayout *h5 = new QHBoxLayout;
    h5->addWidget(l5);
    h5->addWidget(progress);

    mainLayout->addLayout(h1);
    mainLayout->addLayout(h2);
    mainLayout->addLayout(h3);
    mainLayout->addLayout(h4);
    mainLayout->addLayout(h5);

    w.setLayout(mainLayout);
    w.show();

    return a.exec();
}

