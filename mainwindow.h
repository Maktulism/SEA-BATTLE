#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include <QMediaPlayer>
// #include <QAudioOutput>
#include <QTimer>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateLoadingProgressBar();
    // void showLoginScreen();
    // void showGameMenu();

private:
    Ui::MainWindow *ui;
    // QMediaPlayer *player;
    // QAudioOutput *audioOutput;
    QTimer *loadingTimer;
};

#endif // MAINWINDOW_H
