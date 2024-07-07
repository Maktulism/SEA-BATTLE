#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFontDatabase>
#include <QDebug>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = "C:\\Users\\BitWave icFixer.ir\\Desktop\\seabattle_project_abol\\images\\LoadingScreenBackground.png";
    QPixmap pixmap(path);
    if (pixmap.isNull()) {
        qDebug() << "Error loading LoadingScreenBackground.png";
    } else {
        ui->label->setPixmap(pixmap);
    }

    // // پخش موسیقی لودینگ
    // player = new QMediaPlayer(this);
    // audioOutput = new QAudioOutput(this);
    // player->setAudioOutput(audioOutput);
    // player->setSource(QUrl("qrc:/musics/LoadingMusic.mp3"));
    // audioOutput->setVolume(0.5);
    // player->play();

    // شبیه‌سازی نوار لودینگ
    loadingTimer = new QTimer(this);
    connect(loadingTimer, &QTimer::timeout, this, &MainWindow::updateLoadingProgressBar);
    loadingTimer->start(20); // هر 50 میلی‌ثانیه نوار لودینگ را به‌روزرسانی می‌کند

    // // بعد از چند ثانیه به صفحه لاگین سوئیچ می‌کند
    // QTimer::singleShot(3000, this, &MainWindow::showLoginScreen);

    // // اتصال دکمه‌ها به اسلات‌های مناسب
    // connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::showGameMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLoadingProgressBar()
{
    int currentValue = ui->progressBar->value();
    if (currentValue < 100) {
        ui->progressBar->setValue(currentValue + 1);
    }
}

// void MainWindow::showLoginScreen()
// {
//     ui->stackedWidget->setCurrentWidget(ui->loginScreen);
// }

// void MainWindow::showGameMenu()
// {
//     ui->stackedWidget->setCurrentWidget(ui->gameMenu);
// }
