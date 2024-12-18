#include "gameinfowindow.h"
#include "editdatadialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QJsonObject>
#include <QFont>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QScrollArea>
GameInfoWindow::GameInfoWindow(QWidget *parent) : QDialog(parent), changesMade(false) {
    setWindowState(Qt::WindowMaximized); // Открытие окна на весь экран
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    mainLayout = new QVBoxLayout(this); // Хранение основного макета

    // Создание горизонтального макета для изображения и текста
    QHBoxLayout *infoLayout = new QHBoxLayout();

    // Инициализация меток
    imageLabel = new QLabel(this); // Метка для изображения
    nameLabel = new QLabel(this);
    descriptionLabel = new QLabel(this);
    platformLabel = new QLabel(this);
    genreLabel = new QLabel(this);
    ratingLabel = new QLabel(this);
    releaseDateLabel = new QLabel(this);

    // Установка стиля текста
    QFont font;
    font.setBold(true);
    font.setPointSize(12); // Увеличенный размер шрифта

    // Применяем шрифт и цвет ко всем меткам
    nameLabel->setFont(font);
    nameLabel->setStyleSheet("color: white;");
    descriptionLabel->setFont(font);
    descriptionLabel->setStyleSheet("color: white;");
    platformLabel->setFont(font);
    platformLabel->setStyleSheet("color: white;");
    genreLabel->setFont(font);
    genreLabel->setStyleSheet("color: white;");
    ratingLabel->setFont(font);
    ratingLabel->setStyleSheet("color: white;");
    releaseDateLabel->setFont(font);
    releaseDateLabel->setStyleSheet("color: white;");

    // Добавление меток в горизонтальный макет
    infoLayout->addSpacing(20); // Отступ слева
    infoLayout->addWidget(imageLabel); // Сначала добавляем изображение
    infoLayout->addSpacing(20); // Отступ между изображением и текстом

    QVBoxLayout *textLayout = new QVBoxLayout(); // Вертикальный макет для текста
    textLayout->addWidget(nameLabel);
    textLayout->addWidget(descriptionLabel);
    textLayout->addWidget(platformLabel);
    textLayout->addWidget(genreLabel);
    textLayout->addWidget(ratingLabel);
    textLayout->addWidget(releaseDateLabel);

    infoLayout->addLayout(textLayout); // Добавляем текстовый макет справа
    mainLayout->addLayout(infoLayout); // Добавляем основной макет

    setLayout(mainLayout); // Устанавливаем основной макет
}

QHBoxLayout *nameLayout = new QHBoxLayout();

void GameInfoWindow::setGameInfo(const QString &name, const QString &description, const QString &platforms,
                                 const QString &genre, const QString &rating, const QString &releaseDate,
                                 const QString &developer, const QString &country,
                                 const QJsonObject &minimumRequirements, const QJsonObject &recommendedRequirements,
                                 const QString &imagePath, const QString &videoId) {
    // Установка шрифта
    QFont font;
    font.setBold(true);
    font.setPointSize(12); // Увеличенный размер шрифта

    // Создание области прокрутки
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true); // Установка автоматической подстройки размера
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключение горизонтальной прокрутки

    // Создание виджета для содержимого
    QWidget *contentWidget = new QWidget();
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget); // Вертикальный макет для содержимого

    // Установка изображения
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(450, 555, Qt::KeepAspectRatio)); // Установка размера изображения
    } else {
        imageLabel->setText("Изображение не найдено."); // Сообщение об ошибке
    }
    imageLabel->setAlignment(Qt::AlignCenter); // Центрирование изображения

    // Создание горизонтального макета для изображения и текстовой информации
    QHBoxLayout *infoLayout = new QHBoxLayout();
    infoLayout->addWidget(imageLabel); // Добавление изображения

    // Создание вертикального макета для текста
    QVBoxLayout *textLayout = new QVBoxLayout();

    // Установка текстовых меток с переносом слов
    nameLabel->setText("Название: " + name);
    //nameLabel->setWordWrap(true); // Включение переноса слов

    platformLabel->setText("Платформа: " + platforms);
    platformLabel->setWordWrap(true);

    genreLabel->setText("Жанр: " + genre);
    genreLabel->setWordWrap(true);

    ratingLabel->setText("Рейтинг: " + rating);
    ratingLabel->setWordWrap(true);

    releaseDateLabel->setText("Дата выхода: " + releaseDate);
    releaseDateLabel->setWordWrap(true);

    QLabel *developerLabel = new QLabel("Разработчик: " + developer, this);
    developerLabel->setFont(font);
    developerLabel->setStyleSheet("color: white;");
    developerLabel->setWordWrap(true);

    QLabel *countryLabel = new QLabel("Страна: " + country, this);
    countryLabel->setFont(font);
    countryLabel->setStyleSheet("color: white;");
    countryLabel->setWordWrap(true);

    // Кнопка "Смотреть обзор"
    QPushButton *videoButton = new QPushButton("Смотреть обзор", this);
    videoButton->setStyleSheet("background-color: red; "
                               "color: white; "
                               "border: 2px solid black; "
                               "border-radius: 10px;");
    videoButton->setFixedHeight(40);
    videoButton->setFixedWidth(120);

    // Кнопка "Редактировать данные"
    QPushButton *editButton = new QPushButton("Редактировать данные", this);
    editButton->setStyleSheet("background-color: blue; "
                              "color: white; "
                              "border: 2px solid black; "
                              "border-radius: 10px;");
    editButton->setFixedHeight(40);
    editButton->setFixedWidth(120);

    // Кнопка "Вернуться"
    QPushButton *backButton = new QPushButton("Вернуться", this);
    backButton->setStyleSheet("background-color: gray; "
                              "color: white; "
                              "border: 2px solid black; "
                              "border-radius: 10px;");
    backButton->setFixedHeight(40);
    backButton->setFixedWidth(120);

    // Подключение сигнала кнопки "Вернуться"
    connect(backButton, &QPushButton::clicked, this, &QDialog::reject);

    // Создание горизонтального макета для названия и кнопок
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(nameLabel);
    nameLayout->addStretch(); // Отступ между текстом и кнопками
    nameLayout->addWidget(videoButton); // Добавляем кнопку просмотра
    nameLayout->addWidget(editButton); // Добавляем кнопку редактирования
    nameLayout->addWidget(backButton); // Добавляем кнопку "Вернуться"

    // Добавление меток в вертикальный макет
    textLayout->addLayout(nameLayout);
    textLayout->addWidget(platformLabel);
    textLayout->addWidget(genreLabel);
    textLayout->addWidget(ratingLabel);
    textLayout->addWidget(releaseDateLabel);
    textLayout->addWidget(developerLabel);
    textLayout->addWidget(countryLabel);

    // Установка отступов
    textLayout->setContentsMargins(10, 0, 10, 0);
    textLayout->addSpacing(10); // Отступ выше кнопок

    // Подключение сигнала кнопки "Смотреть обзор"
    connect(videoButton, &QPushButton::clicked, [this, videoId]() {
        if (!videoId.isEmpty()) {
            QString url = QString("https://www.youtube.com/watch?v=%1").arg(videoId);
            QDesktopServices::openUrl(QUrl(url));
        } else {
            QMessageBox::warning(this, "Ошибка", "ID видео отсутствует.");
        }
    });

    // Подключение сигнала кнопки "Редактировать данные"
    connect(editButton, &QPushButton::clicked, [this, name, description, platforms, genre, rating, releaseDate, developer, country, minimumRequirements, recommendedRequirements]() {
        EditDataDialog *editDialog = new EditDataDialog(this);
        editDialog->setData(name, description, platforms, genre, rating, releaseDate, developer, country, minimumRequirements, recommendedRequirements);

        connect(editDialog, &EditDataDialog::dataSaved, this, &GameInfoWindow::reject);

        if (editDialog->exec() == QDialog::Accepted) {
            // Получение обновлённых данных
            QJsonObject updatedData = editDialog->getData();
            // Обновление информации в текущем окне (здесь можно добавить логику для обновления)
            // Например, можно вызвать снова setGameInfo с новыми данными
            setGameInfo(updatedData["name"].toString(), updatedData["description"].toString(),
                        updatedData["platform"].toString(), updatedData["genre"].toString(),
                        updatedData["rating"].toString(), updatedData["release_date"].toString(),
                        updatedData["developer"].toString(), updatedData["country"].toString(),
                        updatedData["minimum_requirements"].toObject(), updatedData["recommended_requirements"].toObject(),
                        updatedData["path-image"].toString(), updatedData["video-id"].toString());
        }
    });

    // Добавление текстового макета в горизонтальный макет
    infoLayout->addLayout(textLayout);
    infoLayout->setContentsMargins(0, 0, 20, 0);

    // Добавление в основной макет
    contentLayout->addLayout(infoLayout);

    // Добавление описания
    descriptionLabel->setText("Описание: " + description);
    descriptionLabel->setWordWrap(true);
    contentLayout->addWidget(descriptionLabel);

    // Создание горизонтального макета для системных требований
    QHBoxLayout *requirementsLayout = new QHBoxLayout();
    QString minReq = "МИНИМАЛЬНЫЕ:\n";
    for (const auto &key : minimumRequirements.keys()) {
        minReq += key + ": " + minimumRequirements.value(key).toString() + "\n";
    }

    QString recReq = "РЕКОМЕНДУЕМЫЕ:\n";
    for (const auto &key : recommendedRequirements.keys()) {
        recReq += key + ": " + recommendedRequirements.value(key).toString() + "\n";
    }

    QLabel *minLabel = new QLabel(minReq, this);
    minLabel->setFont(font);
    minLabel->setStyleSheet("color: white;");
    minLabel->setWordWrap(true);

    QLabel *recLabel = new QLabel(recReq, this);
    recLabel->setFont(font);
    recLabel->setStyleSheet("color: white;");
    recLabel->setWordWrap(true);

    requirementsLayout->addWidget(minLabel);
    requirementsLayout->addWidget(recLabel);

    // Добавление макета требований в основной макет
    contentLayout->addLayout(requirementsLayout);

    // Установка содержимого в область прокрутки
    scrollArea->setWidget(contentWidget);
    mainLayout->addWidget(scrollArea); // Добавляем область прокрутки в основной макет
}

void GameInfoWindow::onFormatButtonClicked() {
    // Логика для форматирования данных
    QString formattedInfo = QString("Название: %1\nОписание: %2")
                                .arg(nameLabel->text())
                                .arg(descriptionLabel->text());
    QMessageBox::information(this, "Отформатированная информация", formattedInfo);
}
