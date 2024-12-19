#ifndef ADDGAMEDIALOG_H
#define ADDGAMEDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QStringList>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
namespace Ui {
class AddGameDialog;
}

class AddGameDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddGameDialog(QWidget *parent = nullptr);
    ~AddGameDialog();
    QString getName() const;
    QString getDescription() const;
    QString getGenre() const;
    QStringList getPlatforms() const;
    QString getRating() const;
    QString getReleaseDate() const;
    QString getDeveloper() const;
    QString getCountry() const;
    QJsonObject getMinimumRequirements() const;
    QJsonObject getRecommendedRequirements() const;
    QString getVideoId() const;
    QString getImagePath() const;
private slots:
    void on_saveButton_clicked();

private:
    Ui::AddGameDialog *ui;
};

#endif // ADDGAMEDIALOG_H
