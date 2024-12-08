/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QComboBox *markBox;
    QComboBox *platformBox;
    QLabel *label_3;
    QComboBox *genresBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1014, 2260);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(3840, 2400));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #f0f0f2;\n"
""));
        MainWindow->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 996, 2096));
        scrollAreaWidgetContents->setMinimumSize(QSize(996, 2096));
        scrollAreaWidgetContents->setMaximumSize(QSize(996, 2096));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 1, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(200, 100));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("font: 800 15pt \"JetBrains Mono NL\";\n"
"color: rgb(0, 0, 0);\n"
"font-size: 20px;\n"
""));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("font: 800 15pt \"JetBrains Mono NL\";\n"
"color: rgb(0, 0, 0);\n"
"font-size: 20px;\n"
""));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        markBox = new QComboBox(widget);
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->setObjectName("markBox");
        markBox->setMinimumSize(QSize(0, 35));
        markBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: black\n"
""));

        gridLayout_2->addWidget(markBox, 1, 2, 1, 1);

        platformBox = new QComboBox(widget);
        platformBox->addItem(QString());
        platformBox->addItem(QString());
        platformBox->addItem(QString());
        platformBox->addItem(QString());
        platformBox->addItem(QString());
        platformBox->addItem(QString());
        platformBox->setObjectName("platformBox");
        platformBox->setMinimumSize(QSize(75, 35));
        platformBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color:black\n"
""));

        gridLayout_2->addWidget(platformBox, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setStyleSheet(QString::fromUtf8("font: 800 15pt \"JetBrains Mono NL\";\n"
"color: rgb(0, 0, 0);\n"
"font-size: 20px;\n"
""));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        genresBox = new QComboBox(widget);
        genresBox->addItem(QString());
        genresBox->addItem(QString());
        genresBox->addItem(QString());
        genresBox->addItem(QString());
        genresBox->addItem(QString());
        genresBox->addItem(QString());
        genresBox->setObjectName("genresBox");
        genresBox->setMinimumSize(QSize(0, 35));
        genresBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: black\n"
""));

        gridLayout_2->addWidget(genresBox, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(700, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        resetButton = new QPushButton(widget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(0, 35));
        resetButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: red;"));

        gridLayout_2->addWidget(resetButton, 1, 3, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1014, 19));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gamer\342\200\231s Guide", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\226\320\260\320\275\321\200</p></body></html>", nullptr));
        markBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\276\321\206\320\265\320\275\320\272\320\270", nullptr));
        markBox->setItemText(1, QCoreApplication::translate("MainWindow", "8 - 10", nullptr));
        markBox->setItemText(2, QCoreApplication::translate("MainWindow", "4 - 7", nullptr));
        markBox->setItemText(3, QCoreApplication::translate("MainWindow", "1 - 3", nullptr));

        platformBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\277\320\273\320\260\321\202\321\204\320\276\321\200\320\274\321\213", nullptr));
        platformBox->setItemText(1, QCoreApplication::translate("MainWindow", "PC", nullptr));
        platformBox->setItemText(2, QCoreApplication::translate("MainWindow", "Android", nullptr));
        platformBox->setItemText(3, QCoreApplication::translate("MainWindow", "iOS", nullptr));
        platformBox->setItemText(4, QCoreApplication::translate("MainWindow", "PlayStation", nullptr));
        platformBox->setItemText(5, QCoreApplication::translate("MainWindow", "Xbox One", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\236\321\206\320\265\320\275\320\272\320\260</p></body></html>", nullptr));
        genresBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\266\320\260\320\275\321\200\321\213", nullptr));
        genresBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\255\320\272\321\210\320\265\320\275", nullptr));
        genresBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\321\202\320\265\320\263\320\270\320\270", nullptr));
        genresBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        genresBox->setItemText(4, QCoreApplication::translate("MainWindow", "\320\245\320\276\321\200\321\200\320\276\321\200\321\213", nullptr));
        genresBox->setItemText(5, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\276\321\200\321\202\320\270\320\262\320\275\321\213\320\265", nullptr));

        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
