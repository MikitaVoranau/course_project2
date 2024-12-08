#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QScrollArea>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

struct Game {
    QString name;
    QString platform;
    QString genre;
    QString rating;
    QString description;
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

private:
    Ui::MainWindow *ui;

    QVector<Game> games; // Список игр
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;

    QComboBox *platformBox;
    QComboBox *genreBox;
    QComboBox *ratingBox;
    QPushButton *resetButton;

    void loadGames();
    void populateFilters();
    void updateGameButtons();
    void displayGames(const QVector<Game> &games); // Добавьте эту строку
    void filterGames();
};

#endif // MAINWINDOW_H
