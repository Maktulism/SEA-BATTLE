/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QPushButton *loginButton;
    QPushButton *signUpButton;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 300);
        labelUsername = new QLabel(LoginWindow);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setGeometry(QRect(30, 40, 60, 30));
        labelPassword = new QLabel(LoginWindow);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(30, 80, 60, 30));
        lineEditUsername = new QLineEdit(LoginWindow);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(100, 40, 200, 30));
        lineEditPassword = new QLineEdit(LoginWindow);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(100, 80, 200, 30));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(100, 120, 100, 30));
        signUpButton = new QPushButton(LoginWindow);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setGeometry(QRect(200, 120, 100, 30));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        labelUsername->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
