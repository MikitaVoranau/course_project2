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

private slots:
    void onFormatButtonClicked();
    void on_sortButton_clicked();
    void sortGames();
    void on_sortComboBox_currentIndexChanged(int index);

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
    void loadGames();
    void populateFilters();
    void updateGameButtons();
    void displayGames(const QVector<Game> &games); // Добавьте эту строку
    void filterGames();
};

#endif // MAINWINDOW_H
