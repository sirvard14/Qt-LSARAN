                                                                                                                        #include <QApplication>#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QVBoxLayout *v = new QVBoxLayout;
    QHBoxLayout *h1 = new QHBoxLayout;
    QHBoxLayout *h2 = new QHBoxLayout;
    QHBoxLayout *h3 = new QHBoxLayout;
    QHBoxLayout *h4 = new QHBoxLayout;
    QHBoxLayout *h5 = new QHBoxLayout;

    QLabel *l1 = new QLabel("Name");
    QLabel *l2 = new QLabel("Surname");
    QLabel *l3 = new QLabel("Age");
    QLabel *l4 = new QLabel("MOG");
    QLabel *l5 = new QLabel("Progress");
    QLabel *dateLabel = new QLabel(QDate::currentDate().toString());

    QLineEdit *Name = new QLineEdit;
    QLineEdit *Surname = new QLineEdit;
    QSpinBox *Age = new QSpinBox;
    QLineEdit *MOG = new QLineEdit;
    QProgressBar *progress = new QProgressBar;

    // Configure widgets
    Age->setRange(0, 120);
    progress->setRange(0, 100);
    progress->setValue(50);
    progress->setStyleSheet("QProgressBar { border: 2px solid grey; border-radius: 5px; text-align: center; }"
                            "QProgressBar::chunk { background-color: green; width: 20px; }");

    // Assemble layouts
    h1->addWidget(l1); h1->addWidget(Name);
    h2->addWidget(l2); h2->addWidget(Surname);
    h3->addWidget(l3); h3->addWidget(Age);
    h4->addWidget(l4); h4->addWidget(MOG);
    h5->addWidget(l5); h5->addWidget(progress); h5->addWidget(dateLabel);

    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    v->addLayout(h4);
    v->addLayout(h5);

    // Style
    w.setStyleSheet("color: white; background-color: pink;");
    QLabel* anun[5] = { l1, l2, l3, l4, l5 };
    for (int i = 0; i < 5; i++) {
        anun[i]->setStyleSheet("color: yellow;");
    }

    w.setWindowTitle("My progress");
    w.setLayout(v);
    w.resize(800, 800);
    w.show();

    return a.exec();
}
