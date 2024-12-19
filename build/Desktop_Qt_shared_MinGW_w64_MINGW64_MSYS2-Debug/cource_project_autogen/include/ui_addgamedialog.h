/********************************************************************************
** Form generated from reading UI file 'addgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGAMEDIALOG_H
#define UI_ADDGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddGameDialog
{
public:
    QLineEdit *nameEdit;
    QTextEdit *descriptionEdit;
    QLineEdit *genreEdit;
    QLineEdit *platformEdit;
    QLineEdit *ratingEdit;
    QLineEdit *releaseDateEdit;
    QLineEdit *developerEdit;
    QLineEdit *countryEdit;
    QLineEdit *minOsEdit;
    QLineEdit *minProcessorEdit;
    QLineEdit *minRamEdit;
    QLineEdit *minGraphicsEdit;
    QLineEdit *minDirectXEdit;
    QLineEdit *minNetworkEdit;
    QLineEdit *minDiskSpaceEdit;
    QLineEdit *minAdditionalEdit;
    QLineEdit *recGraphicsEdit;
    QLineEdit *recDiskSpaceEdit;
    QLineEdit *recOsEdit;
    QLineEdit *recAdditionalEdit;
    QLineEdit *recRamEdit;
    QLineEdit *recProcessorEdit;
    QLineEdit *recDirectXEdit;
    QLineEdit *recNetworkEdit;
    QLineEdit *videoIdEdit;
    QLineEdit *imagePathEdit;
    QPushButton *saveButton;

    void setupUi(QDialog *AddGameDialog)
    {
        if (AddGameDialog->objectName().isEmpty())
            AddGameDialog->setObjectName("AddGameDialog");
        AddGameDialog->resize(498, 509);
        nameEdit = new QLineEdit(AddGameDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(40, 40, 113, 22));
        descriptionEdit = new QTextEdit(AddGameDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setGeometry(QRect(40, 80, 104, 64));
        genreEdit = new QLineEdit(AddGameDialog);
        genreEdit->setObjectName("genreEdit");
        genreEdit->setGeometry(QRect(40, 170, 113, 22));
        platformEdit = new QLineEdit(AddGameDialog);
        platformEdit->setObjectName("platformEdit");
        platformEdit->setGeometry(QRect(40, 210, 113, 22));
        ratingEdit = new QLineEdit(AddGameDialog);
        ratingEdit->setObjectName("ratingEdit");
        ratingEdit->setGeometry(QRect(40, 250, 113, 22));
        releaseDateEdit = new QLineEdit(AddGameDialog);
        releaseDateEdit->setObjectName("releaseDateEdit");
        releaseDateEdit->setGeometry(QRect(40, 290, 113, 22));
        developerEdit = new QLineEdit(AddGameDialog);
        developerEdit->setObjectName("developerEdit");
        developerEdit->setGeometry(QRect(40, 330, 113, 22));
        countryEdit = new QLineEdit(AddGameDialog);
        countryEdit->setObjectName("countryEdit");
        countryEdit->setGeometry(QRect(270, 40, 113, 22));
        minOsEdit = new QLineEdit(AddGameDialog);
        minOsEdit->setObjectName("minOsEdit");
        minOsEdit->setGeometry(QRect(200, 110, 113, 22));
        minProcessorEdit = new QLineEdit(AddGameDialog);
        minProcessorEdit->setObjectName("minProcessorEdit");
        minProcessorEdit->setGeometry(QRect(200, 150, 113, 22));
        minRamEdit = new QLineEdit(AddGameDialog);
        minRamEdit->setObjectName("minRamEdit");
        minRamEdit->setGeometry(QRect(200, 190, 113, 22));
        minGraphicsEdit = new QLineEdit(AddGameDialog);
        minGraphicsEdit->setObjectName("minGraphicsEdit");
        minGraphicsEdit->setGeometry(QRect(200, 220, 113, 22));
        minDirectXEdit = new QLineEdit(AddGameDialog);
        minDirectXEdit->setObjectName("minDirectXEdit");
        minDirectXEdit->setGeometry(QRect(200, 250, 113, 22));
        minNetworkEdit = new QLineEdit(AddGameDialog);
        minNetworkEdit->setObjectName("minNetworkEdit");
        minNetworkEdit->setGeometry(QRect(200, 290, 113, 22));
        minDiskSpaceEdit = new QLineEdit(AddGameDialog);
        minDiskSpaceEdit->setObjectName("minDiskSpaceEdit");
        minDiskSpaceEdit->setGeometry(QRect(200, 320, 113, 22));
        minAdditionalEdit = new QLineEdit(AddGameDialog);
        minAdditionalEdit->setObjectName("minAdditionalEdit");
        minAdditionalEdit->setGeometry(QRect(200, 350, 113, 22));
        recGraphicsEdit = new QLineEdit(AddGameDialog);
        recGraphicsEdit->setObjectName("recGraphicsEdit");
        recGraphicsEdit->setGeometry(QRect(360, 220, 113, 22));
        recDiskSpaceEdit = new QLineEdit(AddGameDialog);
        recDiskSpaceEdit->setObjectName("recDiskSpaceEdit");
        recDiskSpaceEdit->setGeometry(QRect(360, 320, 113, 22));
        recOsEdit = new QLineEdit(AddGameDialog);
        recOsEdit->setObjectName("recOsEdit");
        recOsEdit->setGeometry(QRect(360, 110, 113, 22));
        recAdditionalEdit = new QLineEdit(AddGameDialog);
        recAdditionalEdit->setObjectName("recAdditionalEdit");
        recAdditionalEdit->setGeometry(QRect(360, 350, 113, 22));
        recRamEdit = new QLineEdit(AddGameDialog);
        recRamEdit->setObjectName("recRamEdit");
        recRamEdit->setGeometry(QRect(360, 190, 113, 22));
        recProcessorEdit = new QLineEdit(AddGameDialog);
        recProcessorEdit->setObjectName("recProcessorEdit");
        recProcessorEdit->setGeometry(QRect(360, 150, 113, 22));
        recDirectXEdit = new QLineEdit(AddGameDialog);
        recDirectXEdit->setObjectName("recDirectXEdit");
        recDirectXEdit->setGeometry(QRect(360, 250, 113, 22));
        recNetworkEdit = new QLineEdit(AddGameDialog);
        recNetworkEdit->setObjectName("recNetworkEdit");
        recNetworkEdit->setGeometry(QRect(360, 290, 113, 22));
        videoIdEdit = new QLineEdit(AddGameDialog);
        videoIdEdit->setObjectName("videoIdEdit");
        videoIdEdit->setGeometry(QRect(70, 450, 113, 22));
        imagePathEdit = new QLineEdit(AddGameDialog);
        imagePathEdit->setObjectName("imagePathEdit");
        imagePathEdit->setGeometry(QRect(220, 450, 113, 22));
        saveButton = new QPushButton(AddGameDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(400, 450, 80, 21));

        retranslateUi(AddGameDialog);

        QMetaObject::connectSlotsByName(AddGameDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGameDialog)
    {
        AddGameDialog->setWindowTitle(QCoreApplication::translate("AddGameDialog", "Dialog", nullptr));
        nameEdit->setText(QString());
        saveButton->setText(QCoreApplication::translate("AddGameDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGameDialog: public Ui_AddGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGAMEDIALOG_H
