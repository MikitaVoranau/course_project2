#include "mainwindow.h"

#include <QApplication>

#include <QLabel>

int main(int argc, char *argv[])
{
        // оркно должно переписываться, возвращать кнопку назад,
        //игры не появляются в scroll area настроить сами игры
        //добавить иконку к играм
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
