#ifndef EDITDATADIALOG_H
#define EDITDATADIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QJsonObject>
#include "gameinfowindow.h"

class EditDataDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditDataDialog(QWidget *parent = nullptr);
    void setData(const QString &name, const QString &description, const QString &platforms,
                 const QString &genre, const QString &rating, const QString &releaseDate,
                 const QString &developer, const QString &country,
                 const QJsonObject &minimumRequirements, const QJsonObject &recommendedRequirements);
    QJsonObject getData() const;

private:
    QLineEdit *nameEdit;
    QLineEdit *descriptionEdit;
    QLineEdit *platformEdit;
    QLineEdit *genreEdit;
    QLineEdit *ratingEdit;
    QLineEdit *releaseDateEdit;
    QLineEdit *developerEdit;
    QLineEdit *countryEdit;
    QTextEdit *minReqEdit;
    QTextEdit *recReqEdit;
    QString originalName;
    void saveData(); // Объявление метода saveData
};

#endif // EDITDATADIALOG_H
