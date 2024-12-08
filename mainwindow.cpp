#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация элементов интерфейса
    platformBox = findChild<QComboBox*>("platformBox");
    genreBox = findChild<QComboBox*>("genresBox");
    ratingBox = findChild<QComboBox*>("markBox");
    resetButton = findChild<QPushButton*>("resetButton");

    // Создаем QScrollArea
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(this); // Виджет для содержимого scrollArea
    gridLayout = new QGridLayout(scrollWidget); // Создаем QGridLayout для размещения кнопок
    gridLayout->setVerticalSpacing(50); // Устанавливаем вертикальное расстояние между строками
    scrollWidget->setLayout(gridLayout);

    // Настройка scrollArea
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    // Добавляем scrollArea в gridLayout_3
    ui->gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1); // Убедитесь, что вы добавляете в нужную позицию

    // Загрузка игр
    loadGames();
    populateFilters();

    // Подключение сигналов
    connect(platformBox, &QComboBox::currentIndexChanged, this, &MainWindow::filterGames);
    connect(genreBox, &QComboBox::currentIndexChanged, this, &MainWindow::filterGames);
    connect(ratingBox, &QComboBox::currentIndexChanged, this, &MainWindow::filterGames);
    connect(resetButton, &QPushButton::clicked, [this]() {
        platformBox->setCurrentIndex(0);
        genreBox->setCurrentIndex(0);
        ratingBox->setCurrentIndex(0);
        updateGameButtons();
    });

    updateGameButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayGames(const QVector<Game> &games) {
    // Очистка текущего макета, если есть
    QLayout *layout = scrollWidget->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget(); // Удаляем виджеты
            delete item; // Удаляем элементы макета
        }
    }

    // Добавление кнопок для игр
    int row = 0, col = 0;
    for (const Game &game : games) {
        QPushButton *button = new QPushButton(game.name, this);

        // Связываем кнопку с обработчиком
        connect(button, &QPushButton::clicked, [game]() {
            QMessageBox::information(nullptr, "Информация об игре",
                                     "Название: " + game.name + "\n" +
                                         "Платформа: " + game.platform + "\n" +
                                         "Жанр: " + game.genre + "\n" +
                                         "Оценка: " + game.rating + "\n" +
                                         "Описание: " + game.description);
        });

        // Добавляем кнопку в сетку
        gridLayout->addWidget(button, row, col);

        // Перемещаемся на следующую позицию в сетке
        col++;
        if (col == 3) {  // Максимум 3 кнопки в ряд
            col = 0;
            row++;
        }
    }
}

void MainWindow::loadGames() {
    QFile file("D:/cource_project/cource_project/games.json"); // Укажите правильный путь
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull()) {
        qDebug() << "Ошибка разбора JSON.";
        return;
    }

    QJsonArray array = doc.array();
    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        Game game;
        game.name = obj["name"].toString();
        game.platform = obj["platform"].toString();
        game.genre = obj["genre"].toString();
        game.rating = obj["rating"].toString();
        game.description = obj["description"].toString();
        games.append(game);
    }
    qDebug() << "Number of games: " << games.size();
    for (const Game &game : games) {
        qDebug() << "Game: " << game.name;
    }
    // Отображаем игры
    displayGames(games);
}

void MainWindow::populateFilters() {
    platformBox->addItem("Все платформы");
    genreBox->addItem("Все жанры");
    ratingBox->addItem("Все оценки");

    for (const Game &game : games) {
        if (platformBox->findText(game.platform) == -1)
            platformBox->addItem(game.platform);
        if (genreBox->findText(game.genre) == -1)
            genreBox->addItem(game.genre);
        if (ratingBox->findText(game.rating) == -1)
            ratingBox->addItem(game.rating);
    }
}

void MainWindow::updateGameButtons() {
    // Очистка текущих кнопок
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Получение выбранных параметров
    QString selectedPlatform = platformBox->currentText();
    QString selectedGenre = genreBox->currentText();
    QString selectedRating = ratingBox->currentText();

    // Фильтрация и добавление кнопок
    int row = 0, col = 0;
    for (const Game &game : games) {
        // Условие: если выбран параметр "Все", он не должен фильтровать
        if ((selectedPlatform == "Все платформы" || game.platform == selectedPlatform) &&
            (selectedGenre == "Все жанры" || game.genre == selectedGenre) &&
            (selectedRating == "Все оценки" || game.rating == selectedRating)) {

            QPushButton *button = new QPushButton(game.name, this);
            button->setFixedSize(350, 450);
            button->setStyleSheet("background-color: red; color: white; border: none; padding: 10px 20px; border-radius: 10px;");
            connect(button, &QPushButton::clicked, [this, game]() {
                QMessageBox::information(this, game.name, game.description);
            });

            // Добавляем кнопку в сетку
            gridLayout->addWidget(button, row, col);
            col = (col + 1) % 3; // Переход к следующему столбцу
            if (col == 0) ++row; // Переход к следующей строке
        }
    }
}

void MainWindow::filterGames() {
    updateGameButtons();
}
