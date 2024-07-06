#include "LoadingScreen.h"
#include "ui_LoadingScreen.h"
#include <QMovie>

LoadingScreen::LoadingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingScreen)
{
    ui->setupUi(this);

    // تنظیم تصویر پس زمینه
    QPixmap bg(":/images/LoadingScreenBackground.png");
    ui->backgroundLabel->setPixmap(bg);
    ui->backgroundLabel->setScaledContents(true);

    // تنظیم انیمیشن لودینگ
    QMovie *movie = new QMovie(":/images/LoadingScreenProgress.png");
    ui->loadingLabel->setMovie(movie);
    movie->start();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoadingScreen::onTimeout);
    timer->start(3000); // تنظیم زمان بارگذاری به 3 ثانیه
}

LoadingScreen::~LoadingScreen()
{
    delete ui;
}

void LoadingScreen::onTimeout()
{
    timer->stop();
    this->close();
    // انتقال به صفحه ورود
    emit loadingFinished();
}
