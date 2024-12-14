#include "mainwindow.h"

#include <QApplication>

#include <QLabel>

int main(int argc, char *argv[])
{
        // оркно должно переписываться, возвращать кнопку назад,
        // пофиксить фильтры

    QApplication a(argc, argv);
    a.setStyleSheet(
        "QPushButton {"
        "   background-color: red;"
        "   color: black;"
        "   border-color: black;"
        "   border-radius: 5px;"
        "}"
        );
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
