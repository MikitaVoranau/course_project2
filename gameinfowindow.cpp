#include "gameinfowindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QJsonObject>
#include <QFont>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

GameInfoWindow::GameInfoWindow(QWidget *parent) : QDialog(parent), changesMade(false) {
    setWindowState(Qt::WindowMaximized); // Открытие окна на весь экран

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
    nameLabel->setStyleSheet("color: black;");
    descriptionLabel->setFont(font);
    descriptionLabel->setStyleSheet("color: black;");
    platformLabel->setFont(font);
    platformLabel->setStyleSheet("color: black;");
    genreLabel->setFont(font);
    genreLabel->setStyleSheet("color: black;");
    ratingLabel->setFont(font);
    ratingLabel->setStyleSheet("color: black;");
    releaseDateLabel->setFont(font);
    releaseDateLabel->setStyleSheet("color: black;");

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

    // Установка текстовых меток
    nameLabel->setText("Название: " + name);
    platformLabel->setText("Платформа: " + platforms);
    genreLabel->setText("Жанр: " + genre);
    ratingLabel->setText("Рейтинг: " + rating);
    releaseDateLabel->setText("Дата выхода: " + releaseDate);

    QLabel *developerLabel = new QLabel("Разработчик: " + developer, this);
    developerLabel->setFont(font);
    developerLabel->setStyleSheet("color: black;");

    QLabel *countryLabel = new QLabel("Страна: " + country, this);
    countryLabel->setFont(font);
    countryLabel->setStyleSheet("color: black;");

    // Создание кнопки для открытия видео
    QPushButton *videoButton = new QPushButton("Смотреть обзор", this);
    videoButton->setStyleSheet("background-color: red; "
                               "color: white; "
                               "border: 2px solid black; "
                               "border-radius: 10px;");
    videoButton->setFixedHeight(40); // Установка высоты кнопки
    videoButton->setFixedWidth(120); // Установка ширины кнопки

    // Создание горизонтального макета для названия и кнопки
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(nameLabel);
    nameLayout->addStretch(); // Добавление растяжки для отступа между текстом и кнопкой
    nameLayout->addWidget(videoButton); // Добавляем кнопку

    // Добавление меток в вертикальный макет
    textLayout->addLayout(nameLayout); // Добавляем новый горизонтальный макет в текстовый макет
    textLayout->addWidget(platformLabel);
    textLayout->addWidget(genreLabel);
    textLayout->addWidget(ratingLabel);
    textLayout->addWidget(releaseDateLabel);
    textLayout->addWidget(developerLabel);
    textLayout->addWidget(countryLabel);

    // Установка отступов между текстом и изображением
    textLayout->setContentsMargins(10, 0, 10, 0); // Уменьшение отступов
    textLayout->addSpacing(10); // Добавление отступа выше кнопки

    // Подключение сигнала кнопки
    connect(videoButton, &QPushButton::clicked, [this, videoId]() {
        if (!videoId.isEmpty()) {
            QString url = QString("https://www.youtube.com/watch?v=%1").arg(videoId);
            QDesktopServices::openUrl(QUrl(url));
        } else {
            QMessageBox::warning(this, "Ошибка", "ID видео отсутствует.");
        }
    });

    // Добавление текстового макета в горизонтальный макет
    infoLayout->addLayout(textLayout); // Добавляем текст справа от изображения
    infoLayout->setContentsMargins(0, 0, 20, 0); // Уменьшение отступов для всего макета

    // Добавление горизонтального макета в основной макет
    mainLayout->addLayout(infoLayout);

    // Добавление описания
    descriptionLabel->setText("Описание: " + description);
    mainLayout->addWidget(descriptionLabel);

    // Создание горизонтального макета для системных требований
    QHBoxLayout *requirementsLayout = new QHBoxLayout();

    // Форматирование системных требований
    QString minReq = "МИНИМАЛЬНЫЕ:\n";
    for (const auto &key : minimumRequirements.keys()) {
        minReq += key + ": " + minimumRequirements.value(key).toString() + "\n";
    }

    QString recReq = "РЕКОМЕНДУЕМЫЕ:\n";
    for (const auto &key : recommendedRequirements.keys()) {
        recReq += key + ": " + recommendedRequirements.value(key).toString() + "\n";
    }

    // Создание меток для минимальных и рекомендуемых требований
    QLabel *minLabel = new QLabel(minReq, this);
    minLabel->setFont(font);
    minLabel->setStyleSheet("color: black;");

    QLabel *recLabel = new QLabel(recReq, this);
    recLabel->setFont(font);
    recLabel->setStyleSheet("color: black;");

    requirementsLayout->addWidget(minLabel);
    requirementsLayout->addWidget(recLabel);

    // Добавление макета требований в основной макет
    mainLayout->addLayout(requirementsLayout);
}

void GameInfoWindow::onFormatButtonClicked() {
    // Логика для форматирования данных
    QString formattedInfo = QString("Название: %1\nОписание: %2")
                                .arg(nameLabel->text())
                                .arg(descriptionLabel->text());
    QMessageBox::information(this, "Отформатированная информация", formattedInfo);
}

