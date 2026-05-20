#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimeEdit>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startTimer();   // Կոճակի սեղմման սլոթ
    void updateTimer();  // Թայմերի ամեն վայրկյանի սլոթ

private:
    QTimeEdit *timeSpinner;   // 4 նիշանոց ժամանակի ընտրիչ (MM:ss)
    QPushButton *okButton;
    QLabel *timeLabel;
    QTimer *countdownTimer;

    int remainingSeconds;     // Մնացած վայրկյանները հետհաշվարկի համար
};

#endif // MAINWINDOW_H
