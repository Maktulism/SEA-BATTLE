#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <signup.h>
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
    void showLoginScreen();
    void showGameMenu();
    void updateLoadingProgressBar();
    void on_signUpButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    signup * sign;
    QJsonObject readFromJsonFile(const QString& filename);

};
#endif // MAINWINDOW_H
