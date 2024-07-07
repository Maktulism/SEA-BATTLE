#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QFontDatabase>
#include <QDebug>
#include <signup.h>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // بارگذاری فونت‌ها
    int fontId = QFontDatabase::addApplicationFont(":E:/Erfan/SeaLogin/images/seabattle.ttf");
    if (fontId == -1) {
        qDebug() << "Error loading seabattle.ttf";
    }

    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontFamily);

    // تنظیم فونت‌ها برای دکمه‌ها
    ui->loginButton->setFont(font);
    ui->signUpButton->setFont(font);
    ui->singlePlayerButton->setFont(font);
    ui->multiPlayerButton->setFont(font);
    ui->onlinePlayButton->setFont(font);

    // تنظیم تصویر پس زمینه لودینگ اسکرین
    QPixmap pixmap(":E:/Erfan/SeaLogin/images/LoadingScreenBackground.png");
    if (pixmap.isNull()) {
        qDebug() << "Error loading LoadingScreenBackground.png";
    } else {
        ui->backgroundLabel->setPixmap(pixmap);
    }

    // پخش موسیقی لودینگ
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:E:/Erfan/SeaLogin/musics/LoadingMusic.mp3"));
    audioOutput->setVolume(0.5);
    player->play();

    // شبیه‌سازی نوار لودینگ
    QTimer *loadingTimer = new QTimer(this);
    connect(loadingTimer, &QTimer::timeout, this, &MainWindow::updateLoadingProgressBar);
    loadingTimer->start(50); // هر 50 میلی‌ثانیه نوار لودینگ را به‌روزرسانی می‌کند

    // بعد از چند ثانیه به صفحه لاگین سوئیچ می‌کند
    QTimer::singleShot(3000, this, &MainWindow::showLoginScreen);

    // اتصال دکمه‌ها به اسلات‌های مناسب
    // اتصال دکمه‌ها به اسلات‌های مناسب
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->signUpButton, &QPushButton::clicked, this, &MainWindow::on_signUpButton_clicked);}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLoadingProgressBar()
{
    int currentValue = ui->loadingProgressBar->value();
    if (currentValue < 100) {
        ui->loadingProgressBar->setValue(currentValue + 1);
    }
}

void MainWindow::showLoginScreen()
{
    ui->stackedWidget->setCurrentWidget(ui->loginScreen);
}

void MainWindow::showGameMenu()
{
    ui->stackedWidget->setCurrentWidget(ui->gameMenu);
}

void MainWindow::on_signUpButton_clicked()
{

    sign = new signup();
    sign->show();
    this->hide();
    sign->exec();
    this->show();

}


void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Incomplete", "Please fill all fields.");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Load existing users
    QJsonObject usersJson = readFromJsonFile("users.json");
    QJsonArray usersArray = usersJson["users"].toArray();

    // Check if username and password match
    bool loginSuccess = false;
    for (const QJsonValue& userValue : usersArray) {
        QJsonObject userObject = userValue.toObject();
        if (userObject["username"].toString() == username &&
            userObject["password"].toString() == QString(passwordHash.toHex())) {
            loginSuccess = true;
            break;
        }
    }

    if (!loginSuccess) {
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    } else {
        QMessageBox::warning(this, "Success", "Login successful.");
        showGameMenu();
    }
}

QJsonObject MainWindow::readFromJsonFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Failed to open file for reading.");
        return QJsonObject();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(data));
    return doc.object();
}
