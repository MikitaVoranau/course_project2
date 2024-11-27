#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon appIcon("D:\\cource_project\\images\\game-console2.ico");
    setWindowIcon(appIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
