/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QLabel *backgroundLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *emailLineEdit;

    void setupUi(QWidget *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName("LoginScreen");
        LoginScreen->resize(800, 600);
        backgroundLabel = new QLabel(LoginScreen);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(0, 0, 800, 600));
        backgroundLabel->setScaledContents(true);
        usernameLineEdit = new QLineEdit(LoginScreen);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(300, 200, 200, 30));
        passwordLineEdit = new QLineEdit(LoginScreen);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(300, 250, 200, 30));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(LoginScreen);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(300, 300, 200, 30));
        signupButton = new QPushButton(LoginScreen);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(300, 350, 200, 30));
        firstNameLineEdit = new QLineEdit(LoginScreen);
        firstNameLineEdit->setObjectName("firstNameLineEdit");
        firstNameLineEdit->setGeometry(QRect(300, 50, 200, 30));
        lastNameLineEdit = new QLineEdit(LoginScreen);
        lastNameLineEdit->setObjectName("lastNameLineEdit");
        lastNameLineEdit->setGeometry(QRect(300, 100, 200, 30));
        emailLineEdit = new QLineEdit(LoginScreen);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(300, 150, 200, 30));

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QWidget *LoginScreen)
    {
        LoginScreen->setWindowTitle(QCoreApplication::translate("LoginScreen", "Login Screen", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginScreen", "Login", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginScreen", "Sign Up", nullptr));
        firstNameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginScreen", "First Name", nullptr));
        lastNameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginScreen", "Last Name", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("LoginScreen", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
