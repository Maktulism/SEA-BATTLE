#include "logindialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QJsonObject LoginDialog::readFromJsonFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for reading.");
        return QJsonObject();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(data));
    return doc.object();
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Incomplete", "Please fill all fields.");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Load existing users
    QJsonObject usersJson = readFromJsonFile("users.json");
    QJsonArray usersArray = usersJson["users"].toArray();

    // Check if username and password match
    bool loginSuccess = false;
    for (const QJsonValue& userValue : usersArray) {
        QJsonObject userObject = userValue.toObject();
        if (userObject["username"].toString() == username &&
            userObject["password"].toString() == QString(passwordHash.toHex())) {
            loginSuccess = true;
            break;
        }
    }

    if (!loginSuccess) {
        QMessageBox::critical(this, "Error", "Invalid username or password.");
    } else {
        QMessageBox::information(this, "Success", "Login successful.");
        close();
    }
}
