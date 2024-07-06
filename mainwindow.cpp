#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QFontDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // بارگذاری فونت‌ها
    int fontId1 = QFontDatabase::addApplicationFont(":/images/seabattle.ttf");
    if (fontId1 == -1) {
        qDebug() << "Error loading seabattle.ttf";
    }
    int fontId2 = QFontDatabase::addApplicationFont(":/images/seabattle_asia.ttf");
    if (fontId2 == -1) {
        qDebug() << "Error loading seabattle_asia.ttf";
    }
    int fontId3 = QFontDatabase::addApplicationFont(":/images/rouble.otf");
    if (fontId3 == -1) {
        qDebug() << "Error loading rouble.otf";
    }

    QString fontFamily1;
    QString fontFamily2;
    QString fontFamily3;

    if (fontId1 != -1) {
        fontFamily1 = QFontDatabase::applicationFontFamilies(fontId1).at(0);
    }
    if (fontId2 != -1) {
        fontFamily2 = QFontDatabase::applicationFontFamilies(fontId2).at(0);
    }
    if (fontId3 != -1) {
        fontFamily3 = QFontDatabase::applicationFontFamilies(fontId3).at(0);
    }

    QFont font1(fontFamily1);
    QFont font2(fontFamily2);
    QFont font3(fontFamily3);

    // تنظیم فونت‌ها برای دکمه‌ها
    ui->loginButton->setFont(font1);
    ui->signUpButton->setFont(font2);
    ui->singlePlayerButton->setFont(font1);
    ui->multiPlayerButton->setFont(font2);
    ui->onlinePlayButton->setFont(font3);

    // تنظیم تصویر پس زمینه لودینگ اسکرین
    QPixmap pixmap(":/images/LoadingScreenBackground.png");
    if (pixmap.isNull()) {
        qDebug() << "Error loading LoadingScreenBackground.png";
    } else {
        ui->backgroundLabel->setPixmap(pixmap);
    }

    // پخش موسیقی لودینگ
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/musics/LoadingMusic.mp3"));
    audioOutput->setVolume(0.5);
    player->play();

    // شبیه‌سازی نوار لودینگ
    QTimer *loadingTimer = new QTimer(this);
    connect(loadingTimer, &QTimer::timeout, this, &MainWindow::updateLoadingProgressBar);
    loadingTimer->start(50); // هر 50 میلی‌ثانیه نوار لودینگ را به‌روزرسانی می‌کند

    // بعد از چند ثانیه به صفحه لاگین سوئیچ می‌کند
    QTimer::singleShot(3000, this, &MainWindow::showLoginScreen);

    // اتصال دکمه‌ها به اسلات‌های مناسب
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::showGameMenu);
}

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

void MainWindow::startSinglePlayer()
{
    // کد مربوط به شروع بازی تک‌نفره
}

void MainWindow::startLocalPlayer()
{
    // کد مربوط به شروع بازی چندنفره محلی
}

void MainWindow::startOnlinePlayer()
{
    // کد مربوط به شروع بازی آنلاین
}
