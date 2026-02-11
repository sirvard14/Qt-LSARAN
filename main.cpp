#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QVBoxLayout v;
    QHBoxLayout h1, h2, h3, h4, h5;


    QLabel l1("Name");
    QLabel l2("Surname");
    QLabel l3("Age");
    QLabel l4("MOG");
    QLabel l5("Progress");


    QLineEdit Name;
    QLineEdit Surname;
    QSpinBox Age;
    QLineEdit MOG;
    QProgressBar progress;

    h1.addWidget(&l1);
    h1.addWidget(&Name);
    h2.addWidget(&l2);
    h2.addWidget(&Surname);
    h3.addWidget(&l3);
    h3.addWidget(&Age);
    h4.addWidget(&l4);
    h4.addWidget(&MOG);
    h5.addWidget(&l5);
    h5.addWidget(&progress);

    v.addLayout(&h1);
    v.addLayout(&h2);
    v.addLayout(&h3);
    v.addLayout(&h4);
    v.addLayout(&h5);


    w.setLayout(&v);
    w.show();

    return a.exec();
}
