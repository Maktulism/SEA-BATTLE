#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class LoadingScreen;
}

class LoadingScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingScreen(QWidget *parent = nullptr);
    ~LoadingScreen();

private slots:
    void onTimeout();

private:
    Ui::LoadingScreen *ui;
    QTimer *timer;
};

#endif // LOADINGSCREEN_H
