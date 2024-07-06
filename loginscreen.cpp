#include "LoginScreen.h"
#include "ui_LoginScreen.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    // تنظیم تصویر پس زمینه
    QPixmap bg(":/images/PaperBackground.png");
    ui->backgroundLabel->setPixmap(bg);
    ui->backgroundLabel->setScaledContents(true);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_loginButton_clicked()
{
    // پیاده‌سازی ورود
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // بررسی اطلاعات کاربر و ورود به برنامه
}

void LoginScreen::on_signupButton_clicked()
{
    // پیاده‌سازی ایجاد حساب کاربری
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();

    // ایجاد حساب کاربری جدید
}
