#include "addgamedialog.h"
#include "ui_addgamedialog.h"
#include <QString>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QTextEdit>

AddGameDialog::AddGameDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddGameDialog) {
    ui->setupUi(this);
    setWindowTitle("Добавить Игру");
    setWindowFlags(Qt::Window);
    setWindowState(Qt::WindowMaximized);

    // Основной вертикальный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget(this);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    // Поля ввода для информации об игре
    scrollLayout->addWidget(new QLabel("Название игры:"));
    ui->nameEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->nameEdit);

    scrollLayout->addWidget(new QLabel("Описание:"));
    ui->descriptionEdit = new QTextEdit(this);
    scrollLayout->addWidget(ui->descriptionEdit);

    scrollLayout->addWidget(new QLabel("Жанр:"));
    ui->genreEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->genreEdit);

    scrollLayout->addWidget(new QLabel("Платформы:"));
    ui->platformEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->platformEdit);

    scrollLayout->addWidget(new QLabel("Рейтинг:"));
    ui->ratingEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->ratingEdit);

    scrollLayout->addWidget(new QLabel("Дата выпуска:"));
    ui->releaseDateEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->releaseDateEdit);

    scrollLayout->addWidget(new QLabel("Разработчик:"));
    ui->developerEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->developerEdit);

    scrollLayout->addWidget(new QLabel("Страна:"));
    ui->countryEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->countryEdit);

    // Минимальные системные требования
    scrollLayout->addWidget(new QLabel("Минимальные системные требования:"));
    scrollLayout->addWidget(new QLabel("ОС:"));
    ui->minOsEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minOsEdit);

    scrollLayout->addWidget(new QLabel("Процессор:"));
    ui->minProcessorEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minProcessorEdit);

    scrollLayout->addWidget(new QLabel("Оперативная память:"));
    ui->minRamEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minRamEdit);

    scrollLayout->addWidget(new QLabel("Графика:"));
    ui->minGraphicsEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minGraphicsEdit);

    scrollLayout->addWidget(new QLabel("DirectX:"));
    ui->minDirectXEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minDirectXEdit);

    scrollLayout->addWidget(new QLabel("Сеть:"));
    ui->minNetworkEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minNetworkEdit);

    scrollLayout->addWidget(new QLabel("Место на диске:"));
    ui->minDiskSpaceEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minDiskSpaceEdit);

    scrollLayout->addWidget(new QLabel("Дополнительно:"));
    ui->minAdditionalEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->minAdditionalEdit);

    // Рекомендованные системные требования
    scrollLayout->addWidget(new QLabel("Рекомендованные системные требования:"));
    scrollLayout->addWidget(new QLabel("ОС:"));
    ui->recOsEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recOsEdit);

    scrollLayout->addWidget(new QLabel("Процессор:"));
    ui->recProcessorEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recProcessorEdit);

    scrollLayout->addWidget(new QLabel("Оперативная память:"));
    ui->recRamEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recRamEdit);

    scrollLayout->addWidget(new QLabel("Графика:"));
    ui->recGraphicsEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recGraphicsEdit);

    scrollLayout->addWidget(new QLabel("DirectX:"));
    ui->recDirectXEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recDirectXEdit);

    scrollLayout->addWidget(new QLabel("Сеть:"));
    ui->recNetworkEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recNetworkEdit);

    scrollLayout->addWidget(new QLabel("Место на диске:"));
    ui->recDiskSpaceEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recDiskSpaceEdit);

    scrollLayout->addWidget(new QLabel("Дополнительно:"));
    ui->recAdditionalEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->recAdditionalEdit);

    // Поля для видео и изображения
    scrollLayout->addWidget(new QLabel("ID видео:"));
    ui->videoIdEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->videoIdEdit);

    scrollLayout->addWidget(new QLabel("Путь к изображению:"));
    ui->imagePathEdit = new QLineEdit(this);
    scrollLayout->addWidget(ui->imagePathEdit);

    // Устанавливаем основной layout для scrollWidget
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    // Добавляем scrollArea в основной layout
    mainLayout->addWidget(scrollArea);

    // Кнопки
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    mainLayout->addWidget(buttonBox);

    // Соединение сигналов и слотов
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddGameDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddGameDialog::reject);

    // Устанавливаем основной layout
    setLayout(mainLayout);

    // Стиль кнопок
    buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("background-color: #4CAF50; color: white; font-weight: bold;");
    buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("background-color: #f44336; color: white; font-weight: bold;");
}

AddGameDialog::~AddGameDialog() {
    delete ui;
}

// Реализация методов получения данных
QString AddGameDialog::getName() const {
    return ui->nameEdit->text();
}

QString AddGameDialog::getDescription() const {
    return ui->descriptionEdit->toPlainText();
}

QString AddGameDialog::getGenre() const {
    return ui->genreEdit->text();
}

QStringList AddGameDialog::getPlatforms() const {
    return ui->platformEdit->text().split(",");
}

QString AddGameDialog::getRating() const {
    return ui->ratingEdit->text();
}

QString AddGameDialog::getReleaseDate() const {
    return ui->releaseDateEdit->text();
}

QString AddGameDialog::getDeveloper() const {
    return ui->developerEdit->text();
}

QString AddGameDialog::getCountry() const {
    return ui->countryEdit->text();
}

QJsonObject AddGameDialog::getMinimumRequirements() const {
    QJsonObject minReq;
    minReq["OS"] = ui->minOsEdit->text();
    minReq["Processor"] = ui->minProcessorEdit->text();
    minReq["RAM"] = ui->minRamEdit->text();
    minReq["Graphics"] = ui->minGraphicsEdit->text();
    minReq["DirectX"] = ui->minDirectXEdit->text();
    minReq["Network"] = ui->minNetworkEdit->text();
    minReq["Disk_Space"] = ui->minDiskSpaceEdit->text();
    minReq["Additional"] = ui->minAdditionalEdit->text();
    return minReq;
}

QJsonObject AddGameDialog::getRecommendedRequirements() const {
    QJsonObject recReq;
    recReq["OS"] = ui->recOsEdit->text();
    recReq["Processor"] = ui->recProcessorEdit->text();
    recReq["RAM"] = ui->recRamEdit->text();
    recReq["Graphics"] = ui->recGraphicsEdit->text();
    recReq["DirectX"] = ui->recDirectXEdit->text();
    recReq["Network"] = ui->recNetworkEdit->text();
    recReq["Disk_Space"] = ui->recDiskSpaceEdit->text();
    recReq["Additional"] = ui->recAdditionalEdit->text();
    return recReq;
}

QString AddGameDialog::getVideoId() const {
    return ui->videoIdEdit->text();
}

QString AddGameDialog::getImagePath() const {
    return ui->imagePathEdit->text();
}

void AddGameDialog::on_saveButton_clicked() {
    // Проверьте корректность данных
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Пожалуйста, введите название игры.");
        return;
    }
    if (ui->descriptionEdit->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Пожалуйста, введите описание игры.");
        return;
    }

    // Другие проверки на корректность данных можно добавить здесь...

    // Закройте диалог с успешным статусом
    accept();
}
