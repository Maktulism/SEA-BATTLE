#include "signup.h"
#include "ui_signup.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QRegularExpression>
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
bool signup::isValidUsername(const QString& username) {
    // عبارت باقاعده برای شرایط یوزرنیم
    QRegularExpression re(R"(^[a-zA-Z](?!.*[_.]{2})[a-zA-Z0-9._]*[a-zA-Z0-9]$)");
    QRegularExpressionMatch match = re.match(username);
    return match.hasMatch();
}
bool signup::isValidPassword(const QString& password) {
    QRegularExpression re(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*()-+=])[A-Za-z\d!@#$%^&*()-+=]{6,20}$)");
    QRegularExpressionMatch match = re.match(password);
    return match.hasMatch();
}

bool signup::isValidName(const QString& name) {
    QRegularExpression re("^[a-zA-Z]+$");
    QRegularExpressionMatch match = re.match(name);
    return match.hasMatch();
}

bool signup::isValidEmail(const QString& email) {
    QRegularExpression re(R"(^[a-zA-Z0-9._%+-]+@gmail\.com$)");
    QRegularExpressionMatch match = re.match(email);
    return match.hasMatch();
}

void signup::on_pushButton_clicked()
{

        QString username = ui->usernameLineEdit->text();
        QString password = ui->passwordLineEdit->text();
        QString firstname = ui->firstnameLineEdit->text();
        QString lastname = ui->lastnameLineEdit->text();
        QString email = ui->emailLineEdit->text();

        if (username.isEmpty() || password.isEmpty() || firstname.isEmpty() || lastname.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Incomplete", "Please fill all fields.");
            return;
        }
        if (!isValidUsername(username)) {
            QMessageBox::warning(this, "Invalid Username", "Username must start with a letter, can contain letters, digits, dots and underscores, cannot have two dots or underscores in a row, and cannot end with a dot or underscore.");
            return;
        }

        if (!isValidPassword(password)) {
            QMessageBox::warning(this, "Invalid Password", "Password must be 6-20 characters long, contain at least one lowercase letter, one uppercase letter, one digit, and one special character (!@#$%^&*()-+=).");
            return;
        }

        if (!isValidName(firstname)) {
            QMessageBox::warning(this, "Invalid First Name", "First name must only contain English letters.");
            return;
        }

        if (!isValidName(lastname)) {
            QMessageBox::warning(this, "Invalid Last Name", "Last name must only contain English letters.");
            return;
        }

        if (!isValidEmail(email)) {
            QMessageBox::warning(this, "Invalid Email", "Email must be in the format <username>@<domain>.com.");
            return;
        }
        // Load existing users
        QJsonObject usersJson = readFromJsonFile("users.json");
        QJsonArray usersArray = usersJson["users"].toArray();

        //Check if username is already taken
            for (const QJsonValue& userValue : usersArray) {
            QJsonObject userObject = userValue.toObject();
            if (userObject["username"].toString() == username) {
                QMessageBox::warning(this, "Error", "Username is already taken. Please choose another one.");
                return;
            }
        }

        //Create new user object
            QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
        QJsonObject newUser;
        newUser["username"] = username;
        newUser["password"] = QString(passwordHash.toHex());
        newUser["firstname"] = firstname;
        newUser["lastname"] = lastname;
        newUser["email"] = email;

        //Add new user to array and save to file
            usersArray.append(newUser);
        usersJson["users"] = usersArray;
        writeToJsonFile("users.json", usersJson);

        QMessageBox::information(this, "Success", "User registered successfully.");
        close();

}

