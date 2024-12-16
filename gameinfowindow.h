#ifndef GAMEINFOWINDOW_H
#define GAMEINFOWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QJsonObject>

class GameInfoWindow : public QDialog {
    Q_OBJECT

public:
    explicit GameInfoWindow(QWidget *parent = nullptr);

    void setGameInfo(const QString &name, const QString &description, const QString &platforms,
                     const QString &genre, const QString &rating, const QString &releaseDate,
                     const QString &developer, const QString &country,
                     const QJsonObject &minimumRequirements, const QJsonObject &recommendedRequirements,
                     const QString &imagePath, const QString &videoId);


private slots:
    void onFormatButtonClicked(); // Слот для обработки нажатия кнопки форматирования

private:
    QVBoxLayout *mainLayout;
    bool changesMade;             // Флаг, указывающий, были ли внесены изменения
    QPushButton *formatButton;    // Кнопка для форматирования данных
    QLineEdit *titleLineEdit;     // Поле для ввода названия игры
    QLineEdit *descriptionLineEdit; // Поле для ввода описания игры
    QLineEdit *platformLineEdit;  // Поле для ввода платформы
    QLineEdit *genreLineEdit;     // Поле для ввода жанра игры
    QLineEdit *ratingLineEdit;    // Поле для ввода рейтинга
    QLineEdit *releaseDateLineEdit; // Поле для ввода даты выхода

    QLabel *developerLabel; // Объявление developerLabel
    QLabel *countryLabel;   // Объявление countryLabel

    QLabel *nameLabel;            // Метка для названия игры
    QLabel *descriptionLabel;     // Метка для описания игры
    QLabel *platformLabel;        // Метка для платформы
    QLabel *genreLabel;           // Метка для жанра
    QLabel *ratingLabel;          // Метка для рейтинга
    QLabel *releaseDateLabel;     // Метка для даты выхода
    QLabel *imageLabel;           // Метка для изображения
};

#endif // GAMEINFOWINDOW_H
