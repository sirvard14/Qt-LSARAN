#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QSpinBox>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QFormLayout>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QHBoxLayout h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12;
    QVBoxLayout v;
    QLabel l1("Name"),l2("Surname"),l3("Age"),l4("Date of Birth"),l5("Gender"),l6("Faculty"),l7("MOG"),l8("Progress"),l9("Email");
    QLineEdit name,surname,email;
    QSpinBox age,mog;
    QDateEdit date;
    QRadioButton b1("Male"),b2("Female");
    QComboBox select;
    QProgressBar progress;
    QPushButton submit("Submit");
    h1.addWidget(&l1);
    h1.addWidget(&name);
    h2.addWidget(&l2);
    h2.addWidget(&surname);
    h3.addWidget(&l3);
    h3.addWidget(&age);
    h4.addWidget(&l4);
    h4.addWidget(&date);
    h5.addWidget(&l5);
    h5.addWidget(&b1);
    h5.addWidget(&b2);

    h6.addWidget(&l6);
    h6.addWidget(&select);
    h7.addWidget(&l7);
    h7.addWidget(&mog);
    h8.addWidget(&l8);
    h8.addWidget(&progress);
    h9.addWidget(&l9);
    h9.addWidget(&email);
    h10.addWidget(&submit);
    v.addLayout(&h1);
    v.addLayout(&h2);
    v.addLayout(&h3);
    v.addLayout(&h4);
    v.addLayout(&h5);
    v.addLayout(&h6);
    v.addLayout(&h7);
    v.addLayout(&h8);
    v.addLayout(&h9);
    v.addLayout(&h10);


    w.setStyleSheet("background-color:#43A5B3");
    l1.setStyleSheet("color:#ffffff; font-size: 14px;");
    l2.setStyleSheet("color:#ffffff; font-size: 14px;");
    l3.setStyleSheet("color:#ffffff; font-size: 14px;");
    l4.setStyleSheet("color:#ffffff; font-size: 14px;");
    l5.setStyleSheet("color:#ffffff; font-size: 14px;");
    l6.setStyleSheet("color:#ffffff; font-size: 14px;");
    l7.setStyleSheet("color:#ffffff; font-size: 14px;");
    l8.setStyleSheet("color:#ffffff; font-size: 14px;");
    l9.setStyleSheet("color:#ffffff; font-size: 14px;");

    name.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    surname.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    email.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    age.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    mog.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    date.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    select.setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 4px; padding: 6px;");
    progress.setStyleSheet("background-color: #e0f7fa; border: 1px solid #00bcd4; border-radius: 4px;");
    submit.setStyleSheet("background-color: #00bcd4; color: white; border: none; border-radius: 4px; padding: 10px 20px; font-size: 14px;");
    name.setStyleSheet("border-color:#ffffff");
    w.setStyleSheet("background-image:url(:/new/bgimages/programming.jpg)");
    w.setLayout(&v);
    w.resize(350,00);
    w.show();

    return a.exec();
}
