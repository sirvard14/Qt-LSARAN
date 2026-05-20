#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Ստեղծում ենք QTimeEdit՝ 4 նիշանոց ֆորմատով (MM:ss)
    timeSpinner = new QTimeEdit(this);
    timeSpinner->setDisplayFormat("mm:ss"); // Ցույց է տալիս միայն րոպե և վայրկյան
    timeSpinner->setTime(QTime(0, 1, 0));  // Լռելյայն դնում ենք 1 րոպե
    timeSpinner->setAlignment(Qt::AlignCenter);
    timeSpinner->setFont(QFont("Arial", 14)); // Մի քիչ մեծացնում ենք տառաչափը

    okButton = new QPushButton("OK", this);
    okButton->setFont(QFont("Arial", 12));

    timeLabel = new QLabel("Ընտրեք ժամանակը և սեղմեք OK", this);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setFont(QFont("Arial", 14, QFont::Bold));

    // Թայմերի ստեղծում
    countdownTimer = new QTimer(this);

    // Դասավորում ենք էլեմենտները
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(timeSpinner);
    layout->addWidget(okButton);
    layout->addWidget(timeLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle("4 Նիշանոց Թայմեր");
    resize(300, 200); // Պատուհանի չափսը

    // Միացնում ենք սլոթերը
    connect(okButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

MainWindow::~MainWindow() {}

void MainWindow::startTimer() {
    // Վերցնում ենք ընտրված ժամանակը
    QTime selectedTime = timeSpinner->time();

    // Հաշվում ենք ընդհանուր վայրկյանները (րոպե * 60 + վայրկյան)
    remainingSeconds = (selectedTime.minute() * 60) + selectedTime.second();

    // Եթե ժամանակ չի ընտրվել (00:00 է), թույլ չենք տալիս միացնել
    if (remainingSeconds <= 0) {
        QMessageBox::warning(this, "Ուշադրություն", "Խնդրում ենք ընտրել 0-ից մեծ ժամանակ:");
        return;
    }

    // Անջատում ենք էլեմենտները հաշվարկի ժամանակ
    okButton->setEnabled(false);
    timeSpinner->setEnabled(false);

    // Միացնում ենք թայմերը 1 վայրկյան ինտերվալով
    countdownTimer->start(1000);

    // Անմիջապես թարմացնում ենք էկրանը
    updateTimer();
}

void MainWindow::updateTimer() {
    if (remainingSeconds > 0) {
        int mins = remainingSeconds / 60;
        int secs = remainingSeconds % 60;

        // Ցույց է տալիս միշտ 4 նիշանոց (օրինակ՝ 05:09)
        timeLabel->setText(QString("%1:%2")
                           .arg(mins, 2, 10, QChar('0'))
                           .arg(secs, 2, 10, QChar('0')));
        remainingSeconds--;
    } else {
        // Երբ ժամանակն ավարտվում է
        countdownTimer->stop();
        timeLabel->setText("00:00");

        // Ակտիվացնում ենք էլեմենտները հետագա օգտագործման համար
        okButton->setEnabled(true);
        timeSpinner->setEnabled(true);

        // Ցույց ենք տալիս հաղորդագրություն
        QMessageBox::information(this, "Թայմեր", "Ժամանակը լրացավ:");
    }
}
