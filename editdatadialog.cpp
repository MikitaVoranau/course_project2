#include "EditDataDialog.h"
#include "gameinfowindow.h"
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>

EditDataDialog::EditDataDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Редактировать данные");
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    showMaximized(); // Открытие окна в максимальном размере

    // Создание области прокрутки
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget();
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    QFormLayout *formLayout = new QFormLayout(scrollWidget);
    nameEdit = new QLineEdit(this);
    descriptionEdit = new QLineEdit(this);
    platformEdit = new QLineEdit(this);
    genreEdit = new QLineEdit(this);
    ratingEdit = new QLineEdit(this);
    releaseDateEdit = new QLineEdit(this);
    developerEdit = new QLineEdit(this);
    countryEdit = new QLineEdit(this);
    minReqEdit = new QTextEdit(this);  // Поле для минимальных требований
    recReqEdit = new QTextEdit(this);  // Поле для рекомендуемых требований

    // Установка стиля для меток
    QString labelStyle = "color: white;";
    QLabel *nameLabel = new QLabel("Название:");
    nameLabel->setStyleSheet(labelStyle);
    formLayout->addRow(nameLabel, nameEdit);

    QLabel *descriptionLabel = new QLabel("Описание:");
    descriptionLabel->setStyleSheet(labelStyle);
    formLayout->addRow(descriptionLabel, descriptionEdit);

    QLabel *platformLabel = new QLabel("Платформа:");
    platformLabel->setStyleSheet(labelStyle);
    formLayout->addRow(platformLabel, platformEdit);

    QLabel *genreLabel = new QLabel("Жанр:");
    genreLabel->setStyleSheet(labelStyle);
    formLayout->addRow(genreLabel, genreEdit);

    QLabel *ratingLabel = new QLabel("Рейтинг:");
    ratingLabel->setStyleSheet(labelStyle);
    formLayout->addRow(ratingLabel, ratingEdit);

    QLabel *releaseDateLabel = new QLabel("Дата выхода:");
    releaseDateLabel->setStyleSheet(labelStyle);
    formLayout->addRow(releaseDateLabel, releaseDateEdit);

    QLabel *developerLabel = new QLabel("Разработчик:");
    developerLabel->setStyleSheet(labelStyle);
    formLayout->addRow(developerLabel, developerEdit);

    QLabel *countryLabel = new QLabel("Страна:");
    countryLabel->setStyleSheet(labelStyle);
    formLayout->addRow(countryLabel, countryEdit);

    QLabel *minReqLabel = new QLabel("Минимальные требования:");
    minReqLabel->setStyleSheet(labelStyle);
    formLayout->addRow(minReqLabel, minReqEdit);

    QLabel *recReqLabel = new QLabel("Рекомендуемые требования:");
    recReqLabel->setStyleSheet(labelStyle);
    formLayout->addRow(recReqLabel, recReqEdit);

    // Установка черного цвета текста для полей ввода
    QString inputStyle = "color: white;";
    nameEdit->setStyleSheet(inputStyle);
    descriptionEdit->setStyleSheet(inputStyle);
    platformEdit->setStyleSheet(inputStyle);
    genreEdit->setStyleSheet(inputStyle);
    ratingEdit->setStyleSheet(inputStyle);
    releaseDateEdit->setStyleSheet(inputStyle);
    developerEdit->setStyleSheet(inputStyle);
    countryEdit->setStyleSheet(inputStyle);
    minReqEdit->setStyleSheet(inputStyle);
    recReqEdit->setStyleSheet(inputStyle);

    // Кнопки "Сохранить" и "Отмена"
    QPushButton *saveButton = new QPushButton("Сохранить", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);

    // Стилизация кнопок
    QString buttonStyle = "QPushButton {"
                          "background-color: aqua;"
                          "color: black;"
                          "border: 2px solid black;"
                          "border-radius: 10px;"
                          "padding: 5px;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: lightblue;"
                          "}";
    saveButton->setStyleSheet(buttonStyle);
    cancelButton->setStyleSheet(buttonStyle);

    // Добавление кнопок в правый угол
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch(); // Добавляем растяжение для выравнивания кнопок вправо
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(saveButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea); // Добавление области прокрутки
    mainLayout->addLayout(buttonLayout); // Добавление горизонтального макета кнопок

    setLayout(mainLayout); // Установка основного макета

    // Подключение сигналов к слотам
    connect(saveButton, &QPushButton::clicked, this, &EditDataDialog::saveData);
    connect(cancelButton, &QPushButton::clicked, this, &EditDataDialog::reject);
}

void EditDataDialog::saveData() {
    // Формируем объект JSON с новыми данными
    QJsonObject newData;
    QString newName = nameEdit->text().trimmed();

    if (newName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Название игры не может быть пустым.");
        return;
    }

    newData["name"] = newName;
    newData["description"] = descriptionEdit->text();

    // Обработка платформ
    QStringList platforms = platformEdit->text().split(",");
    QJsonArray platformArray;
    for (const QString &platform : platforms) {
        platformArray.append(platform.trimmed());
    }
    newData["platform"] = platformArray;

    newData["genre"] = genreEdit->text();
    newData["rating"] = ratingEdit->text();
    newData["release_date"] = releaseDateEdit->text();
    newData["developer"] = developerEdit->text();
    newData["country"] = countryEdit->text();

    // Обработка минимальных требований
    QJsonDocument minReqDoc = QJsonDocument::fromJson(minReqEdit->toPlainText().toUtf8());
    if (minReqDoc.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Минимальные требования содержат некорректный JSON.");
        return;
    }
    newData["minimum_requirements"] = minReqDoc.object();

    // Обработка рекомендуемых требований
    QJsonDocument recReqDoc = QJsonDocument::fromJson(recReqEdit->toPlainText().toUtf8());
    if (recReqDoc.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Рекомендуемые требования содержат некорректный JSON.");
        return;
    }
    newData["recommended_requirements"] = recReqDoc.object();

    // Читаем текущий JSON-файл
    QFile file("D:/cource_project/cource_project/games.json");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray gamesArray;
    if (!doc.isNull() && doc.isArray()) {
        gamesArray = doc.array();
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат JSON-файла.");
        return;
    }

    // Поиск записи с оригинальным именем
    bool found = false;

    for (int i = 0; i < gamesArray.size(); ++i) {
        QJsonObject game = gamesArray[i].toObject();

        // Сравнение с оригинальным именем (устанавливается через setData)
        if (game.contains("name") && game["name"].toString() == originalName) {
            // Если найдена запись, копируем неизменённые поля
            if (game.contains("video-id")) {
                newData["video-id"] = game["video-id"];
            }
            if (game.contains("path-image")) {
                newData["path-image"] = game["path-image"];
            }

            // Замена найденной записи
            gamesArray[i] = newData;
            found = true;
            break;
        }
    }

    if (!found) {
        QMessageBox::information(this, "Информация", "Запись с таким именем не найдена. Проверьте имя игры.");
        return;
    }

    // Сохраняем обновлённый массив в JSON-файл
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    file.write(QJsonDocument(gamesArray).toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Успешно", "Данные были успешно обновлены.");
    emit dataSaved();
    accept(); // Закрываем окно
}



void EditDataDialog::setData(const QString &name, const QString &description, const QString &platforms,
                             const QString &genre, const QString &rating, const QString &releaseDate,
                             const QString &developer, const QString &country,
                             const QJsonObject &minimumRequirements, const QJsonObject &recommendedRequirements) {
    originalName = name;
    nameEdit->setText(name);
    descriptionEdit->setText(description);
    platformEdit->setText(platforms);
    genreEdit->setText(genre);
    ratingEdit->setText(rating);
    releaseDateEdit->setText(releaseDate);
    developerEdit->setText(developer);
    countryEdit->setText(country);

    // Установка минимальных и рекомендуемых требований
    minReqEdit->setPlainText(QString::fromUtf8(QJsonDocument(minimumRequirements).toJson()));
    recReqEdit->setPlainText(QString::fromUtf8(QJsonDocument(recommendedRequirements).toJson()));
}

QJsonObject EditDataDialog::getData() const {
    QJsonObject data;
    data["name"] = nameEdit->text();
    data["description"] = descriptionEdit->text();
    data["platform"] = platformEdit->text();
    data["genre"] = genreEdit->text();
    data["rating"] = ratingEdit->text();
    data["release_date"] = releaseDateEdit->text();
    data["developer"] = developerEdit->text();
    data["country"] = countryEdit->text();

    // Получаем минимальные и рекомендуемые требования
    data["minimum_requirements"] = QJsonDocument::fromJson(minReqEdit->toPlainText().toUtf8()).object();
    data["recommended_requirements"] = QJsonDocument::fromJson(recReqEdit->toPlainText().toUtf8()).object();

    return data;
}
