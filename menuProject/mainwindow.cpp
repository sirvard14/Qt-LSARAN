
#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPalette>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(300, 400);
    this->setAutoFillBackground(true);
    createMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::createMenu() {
    QMenuBar *mBar = this->menuBar();
    QMenu *file = mBar->addMenu("File");

    QMenu *submenu = file->addMenu("Submenu");
    QMenu *colorMenu = file->addMenu("Color");

    QAction *newAction = new QAction("New", this);
    QAction *openAction = new QAction("Open", this);
    QAction *exitAction = new QAction("Exit", this);
    QAction *child = new QAction("Child 1", this);

    QAction *green = new QAction("Green", this);
    green->setData(QColor(Qt::green));
    colorMenu->addAction(green);
    connect(green, &QAction::triggered, this, &MainWindow::changeColor);

    QAction *red = new QAction("Red", this);
    red->setData(QColor(Qt::red));
    colorMenu->addAction(red);
    connect(red, &QAction::triggered, this, &MainWindow::changeColor);

    QAction *pink = new QAction("Pink", this);
    pink->setData(QColor(255, 192, 203));
    colorMenu->addAction(pink);
    connect(pink, &QAction::triggered, this, &MainWindow::changeColor);

    file->addAction(newAction);
    file->addAction(openAction);
    file->addSeparator();
    file->addAction(exitAction);

    submenu->addAction(child);

    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}


void MainWindow::changeColor() {

    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        QColor color = action->data().value<QColor>();

        QPalette pal = this->palette();
        pal.setColor(QPalette::Window, color);
        this->setPalette(pal);
    }
}
