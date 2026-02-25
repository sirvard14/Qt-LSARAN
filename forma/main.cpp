#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QColorDialog>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Հարցում");
    window.resize(400, 300);
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Հարց
    QLabel *question = new QLabel("Ո՞րն է Հայաստանի մայրաքաղաքը։");
    layout->addWidget(question);

    // RadioButton-ներ
    QRadioButton *rb1 = new QRadioButton("Գյումրի");
    QRadioButton *rb2 = new QRadioButton("Վանաձոր");
    QRadioButton *rb3 = new QRadioButton("Երևան");

    layout->addWidget(rb1);
    layout->addWidget(rb2);
    layout->addWidget(rb3);

    QButtonGroup *group = new QButtonGroup(&window);
    group->addButton(rb1);
    group->addButton(rb2);
    group->addButton(rb3);

    // Ստուգել կոճակ
    QPushButton *checkBtn = new QPushButton("Ստուգել");
    layout->addWidget(checkBtn);

    QLabel *result = new QLabel("");
    layout->addWidget(result);

    // Color picker կոճակ
    QPushButton *colorBtn = new QPushButton("Ընտրել ֆոնի գույն");
    layout->addWidget(colorBtn);

    // Ստուգելու լոգիկա
    QObject::connect(checkBtn, &QPushButton::clicked, [&]() {
        if (rb3->isChecked()) {
            result->setText("Ճիշտ պատասխան ✓");
            result->setStyleSheet("color: green;");
        } else if (rb1->isChecked() || rb2->isChecked()) {
            result->setText("Սխալ պատասխան x");
            result->setStyleSheet("color: red;");
        } else {
            result->setText("Խնդրում ենք ընտրել պատասխան");
            result->setStyleSheet("color: orange;");
        }
    });

    // Ֆոնի գույնի փոփոխություն
    QObject::connect(colorBtn, &QPushButton::clicked, [&]() {
        QColor color = QColorDialog::getColor(Qt::white, &window, "Ընտրեք գույն");
        if (color.isValid()) {
            window.setStyleSheet("background-color: " + color.name());
        }
    });

    window.show();
    return app.exec();
}
