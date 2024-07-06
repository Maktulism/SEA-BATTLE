#include "loadingscreen.h"
#include "ui_loadingscreen.h"
#include <QMovie>
#include <QMediaPlayer>
#include <QAudioOutput>

LoadingScreen::LoadingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingScreen)
{
    ui->setupUi(this);
    setWindowTitle("Loading");

    QPixmap pixmap(":/images/LoadingScreenBackground.png");
    ui->backgroundLabel->setPixmap(pixmap);

    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/musics/LoadingMusic.mp3"));
    audioOutput->setVolume(0.5);
    player->play();
}

LoadingScreen::~LoadingScreen()
{
    delete ui;
}
