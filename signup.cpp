#include "signup.h"
#include "ui_signup.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QFile>
#include <QIODevice>

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::writeToJsonFile(const QString& filename, const QJsonObject& jsonObject) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        return;
    }

    QJsonDocument doc(jsonObject);
    file.write(doc.toJson());
    file.close();
}

QJsonObject signup::readFromJsonFile(const QString& filename) {
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

void signup::on_registerButton_clicked()
{
    // QString username = ui->usernameLineEdit->text();
    // QString password = ui->passwordLineEdit->text();
    // QString firstname = ui->firstnameLineEdit->text();
    // QString lastname = ui->lastnameLineEdit->text();
    // QString email = ui->emailLineEdit->text();

    // if (username.isEmpty() || password.isEmpty() || firstname.isEmpty() || lastname.isEmpty() || email.isEmpty()) {
    //     QMessageBox::warning(this, "Incomplete", "Please fill all fields.");
    //     return;
    // }

    // Load existing users
    QJsonObject usersJson = readFromJsonFile("users.json");
    QJsonArray usersArray = usersJson["users"].toArray();

    // Check if username is already taken
    // for (const QJsonValue& userValue : usersArray) {
    //     QJsonObject userObject = userValue.toObject();
    //     if (userObject["username"].toString() == username) {
    //         QMessageBox::warning(this, "Error", "Username is already taken. Please choose another one.");
    //         return;
    //     }
    // }

    // Create new user object
    // QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    // QJsonObject newUser;
    // newUser["username"] = username;
    // newUser["password"] = QString(passwordHash.toHex());
    // newUser["firstname"] = firstname;
    // newUser["lastname"] = lastname;
    // newUser["email"] = email;

    // Add new user to array and save to file
    // usersArray.append(newUser);
    // usersJson["users"] = usersArray;
    // writeToJsonFile("users.json", usersJson);

    QMessageBox::information(this, "Success", "User registered successfully.");
    close();
}
