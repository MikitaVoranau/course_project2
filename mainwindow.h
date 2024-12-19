#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QScrollArea>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QJsonObject>

struct Game {
    QString name;
    QStringList platform;
    QString genre;
    QString rating;
    QString description;
    QString release_date;
    QString developer;
    QString country;
    QJsonObject minimum_requirements;
    QJsonObject recommended_requirements;
    QString imagePath; // Поле для хранения пути к изображению
    QString videoId;
            Game(const QString &name, const QString &description, const QString &genre,
                 const QStringList &platforms, const QString &rating,
                 const QString &releaseDate, const QString &developer,
                 const QString &country, const QJsonObject &minReq,
                 const QJsonObject &recReq, const QString &videoId,
                 const QString &imagePath)
        : name(name), description(description), genre(genre),
        platform(platforms), rating(rating), release_date(releaseDate),
        developer(developer), country(country), minimum_requirements(minReq),
        recommended_requirements(recReq), videoId(videoId), imagePath(imagePath) {}

    Game() = default;  // Добавляет конструктор по умолчанию
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QJsonArray loadExistingGames(); // Объявление функции
    QJsonObject gameToJson(const Game &game); // Объявление функции
    void saveGames(); // Объявление функции
    void addGame(const Game &game);  // Объявление метода
    void saveGames(const QJsonArray &gamesArray);
public slots:
    void loadGames();

private slots:
    void onFormatButtonClicked();
    void on_sortButton_clicked();
    void sortGames();
    void on_sortComboBox_currentIndexChanged(int index);
    void on_addGameButton_clicked();
    void on_sortComboBox_activated(int index);

    void on_leaveButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *formatButton;
    QVector<Game> games;
    QVector<Game> originalGames;
    QMap<QString, QString> imageMap;// Список игр
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;
    QComboBox *platformBox;
    QComboBox *genreBox;
    QComboBox *ratingBox;
    QPushButton *resetButton;

    void saveToJson(const QJsonObject &jsonData);
    void populateFilters();
    void updateGameButtons();
    void displayGames(const QVector<Game> &games); // Добавьте эту строку
    void filterGames();
    void setButtonStyle(QPushButton *button, const Game &game);
    void updateGameListDisplay();
};

#endif // MAINWINDOW_H
