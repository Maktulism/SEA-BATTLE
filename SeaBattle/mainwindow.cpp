#include "mainwindow.h"
#include "ui_MainWindow.h"
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
    int fontId = QFontDatabase::addApplicationFont(":/images/seabattle.ttf");
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
