
#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.setWindowTitle("Project");

    QVBoxLayout *v = new QVBoxLayout(&w);


    QHBoxLayout *h1 = new QHBoxLayout();
    QLabel *l1 = new QLabel("Full name");
    QLineEdit *fname = new QLineEdit();
    h1->addWidget(l1);
    h1->addWidget(fname);


    QHBoxLayout *h2 = new QHBoxLayout();
    QLabel *l2 = new QLabel("Age");
    QSlider *s = new QSlider(Qt::Horizontal);
    s->setRange(0, 100);
    h2->addWidget(l2);
    h2->addWidget(s);

    QHBoxLayout *h3 = new QHBoxLayout();
    QLabel *l3 = new QLabel("Age");
    QSpinBox *spin = new QSpinBox();
    spin->setRange(0, 100);
    h3->addWidget(l3);
    h3->addWidget(spin);


    QHBoxLayout *h4 = new QHBoxLayout();
    QLCDNumber *n = new QLCDNumber();
    n->setFixedSize(450,40);
    h4->addWidget(n);

    QHBoxLayout *h5 = new QHBoxLayout();
    QLabel *l4 = new QLabel("Label");
    h5->addWidget(l4);

    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    v->addLayout(h4);
    v->addLayout(h5);


    QObject::connect(s, SIGNAL(valueChanged(int)), spin, SLOT(setValue(int)));
    QObject::connect(spin, SIGNAL(valueChanged(int)), s, SLOT(setValue(int)));
    QObject::connect(s, SIGNAL(valueChanged(int)), n, SLOT(display(int)));
    QObject::connect(spin, SIGNAL(valueChanged(int)), n, SLOT(display(int)));

    w.resize(500,300);
    w.show();

    return a.exec();
}
