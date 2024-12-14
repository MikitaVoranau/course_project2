#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "gameinfowindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("D:/cource_project/cource_project/images/game-console2.ico"));


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
        ui->sortComboBox->setCurrentIndex(0);

        // Сбросить список игр к оригинальному
        games = originalGames; // Восстанавливаем оригинальные игры
        updateGameButtons(); // Обновляем интерфейс
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
                                         "Платформа: " + game.platform.join(", ") + "\n" +
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
    QFile file("D:/cource_project/cource_project/games.json");
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
    originalGames.clear(); // Очистите предыдущий список
    games.clear(); // Очистите текущий список

    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        Game game;

        // Заполнение всех полей
        game.name = obj["name"].toString();
        game.platform = obj["platform"].toVariant().toStringList(); // Если это массив
        game.genre = obj["genre"].toString();
        game.rating = obj["rating"].toString();
        game.description = obj["description"].toString();
        game.release_date = obj["release_date"].toString();
        game.developer = obj["developer"].toString();
        game.country = obj["country"].toString();
        game.minimum_requirements = obj["minimum_requirements"].toObject();
        game.recommended_requirements = obj["recommended_requirements"].toObject();
        game.imagePath = obj["path-image"].toString(); // Получаем путь к изображению
        game.videoId = obj["video-id"].toString(); // Исправлено на obj

        games.append(game);
        originalGames.append(game); // Сохраняем оригинал
    }

    displayGames(games);
}

void MainWindow::onFormatButtonClicked() {
    // Чтение данных из JSON
    QFile file("games.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл.";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonArray gamesArray = doc.array();

    // Пример форматирования данных
    for (int i = 0; i < gamesArray.size(); ++i) {
        QJsonObject gameObject = gamesArray[i].toObject();
        // Здесь вы можете изменять данные, например:
        gameObject["formatted"] = true; // Добавляем новое поле
        gamesArray[i] = gameObject; // Обновляем объект в массиве
    }

    // Записываем обратно в JSON
    QJsonDocument newDoc(gamesArray);
    saveToJson(newDoc.object());
}

void MainWindow::saveToJson(const QJsonObject &jsonData) {
    QFile file("games.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Не удалось открыть файл для записи.";
        return;
    }

    QJsonDocument doc(jsonData);
    file.write(doc.toJson());
    file.close();
    qDebug() << "Данные успешно сохранены.";
}

void MainWindow::populateFilters() {
    platformBox->addItem("Все платформы");
    genreBox->addItem("Все жанры");
    ratingBox->addItem("Все оценки");

    QSet<QString> platformsSet;
    QSet<QString> genresSet;
    QSet<QString> ratingsSet;

    for (const Game &game : games) {
        for (const QString &platform : game.platform) {
            platformsSet.insert(platform); // Добавление платформ
        }
        genresSet.insert(game.genre);
        ratingsSet.insert(game.rating);
    }

    for (const QString &platform : platformsSet) {
        platformBox->addItem(platform);
    }

    for (const QString &genre : genresSet) {
        genreBox->addItem(genre);
    }

    for (const QString &rating : ratingsSet) {
        ratingBox->addItem(rating);
    }
}

void MainWindow::updateGameButtons() {
    // Очистка текущих кнопок
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    QString selectedPlatform = platformBox->currentText();
    QString selectedGenre = genreBox->currentText();
    QString selectedRating = ratingBox->currentText();

    int row = 0, col = 0;
    for (const Game &game : games) {
        bool platformMatch = (selectedPlatform == "Все платформы" || game.platform.contains(selectedPlatform));
        bool genreMatch = (selectedGenre == "Все жанры" || game.genre == selectedGenre);
        bool ratingMatch = (selectedRating == "Все оценки" || game.rating == selectedRating);

        if (platformMatch && genreMatch && ratingMatch) {
            QPushButton *button = new QPushButton(game.name, this);
            button->setFixedSize(300, 455); // Установите размер кнопки

            // Установка фона кнопки с изображением
            if (!game.imagePath.isEmpty()) {
                button->setStyleSheet(QString("background-image: url(%1); "
                                              "color: white; "
                                              "background-repeat: no-repeat; "
                                              "background-position: center; "
                                              "border: none; "
                                              "padding: 10px 20px; "
                                              "border-radius: 10px; "
                                              "text-align: bottom; "
                                              "font-size: 16px;")
                                          .arg(game.imagePath));
            }

            // Подключение сигнала нажатия кнопки
            connect(button, &QPushButton::clicked, [this, game]() {
                GameInfoWindow *infoWindow = new GameInfoWindow(this);
                infoWindow->setGameInfo(
                    game.name,
                    game.description,
                    game.platform.join(", "),
                    game.genre,
                    game.rating,
                    game.release_date,
                    game.developer,
                    game.country,
                    game.minimum_requirements,
                    game.recommended_requirements,
                    game.imagePath, // Передаем путь к изображению
                    game.videoId
                    );
                infoWindow->exec(); // Открываем окно как модальное
            });

            // Добавление кнопки в сетку
            gridLayout->addWidget(button, row, col);
            col = (col + 1) % 3; // Переход к следующему столбцу
            if (col == 0) ++row; // Переход к следующей строке
        }
    }
}

void MainWindow::sortGames() {
    int index = ui->sortComboBox->currentIndex();

    if (index == 0) {
        // Не сортировать, просто обновить кнопки
        updateGameButtons();
        return;
    }

    if (index == 1) {
        // Сортировать по названию
        std::sort(games.begin(), games.end(), [](const Game &a, const Game &b) {
            return a.name < b.name;
        });
    } else if (index == 2) {
        // Сортировать по дате выхода
        std::sort(games.begin(), games.end(), [](const Game &a, const Game &b) {
            return a.release_date < b.release_date;
        });
    } else if (index == 3) {
        // Сортировать по рейтингу
        std::sort(games.begin(), games.end(), [](const Game &a, const Game &b) {
            // Если у вас числовые рейтинги, преобразуйте их в числа для корректного сравнения
            return a.rating < b.rating; // Здесь может потребоваться дополнительная обработка
        });
    }

    updateGameButtons();
}

void MainWindow::on_sortComboBox_currentIndexChanged(int index) {
    sortGames();  // Вызываем сортировку при изменении выбора
}

void MainWindow::filterGames() {
    updateGameButtons();
}

void MainWindow::on_sortButton_clicked() {
    sortGames();  // Correctly call the sortGames function
}

