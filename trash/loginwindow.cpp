#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "gamemenu.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowTitle("Login");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    // اینجا می‌توانید کد مربوط به ورود کاربر را اضافه کنید
    GameMenu *menu = new GameMenu();
    menu->show();
    this->close();
}

void LoginWindow::on_signUpButton_clicked()
{
    // اینجا می‌توانید کد مربوط به ثبت نام کاربر را اضافه کنید
}
