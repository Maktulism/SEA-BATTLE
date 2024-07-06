/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *loadingScreen;
    QVBoxLayout *verticalLayout_loading;
    QLabel *backgroundLabel;
    QProgressBar *loadingProgressBar;
    QWidget *loginScreen;
    QVBoxLayout *verticalLayout_login;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *signUpButton;
    QWidget *gameMenu;
    QVBoxLayout *verticalLayout_menu;
    QPushButton *singlePlayerButton;
    QPushButton *multiPlayerButton;
    QPushButton *onlinePlayButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loadingScreen = new QWidget();
        loadingScreen->setObjectName("loadingScreen");
        verticalLayout_loading = new QVBoxLayout(loadingScreen);
        verticalLayout_loading->setObjectName("verticalLayout_loading");
        backgroundLabel = new QLabel(loadingScreen);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_loading->addWidget(backgroundLabel);

        loadingProgressBar = new QProgressBar(loadingScreen);
        loadingProgressBar->setObjectName("loadingProgressBar");
        loadingProgressBar->setMinimum(0);
        loadingProgressBar->setMaximum(100);
        loadingProgressBar->setValue(0);
        loadingProgressBar->setTextVisible(false);

        verticalLayout_loading->addWidget(loadingProgressBar);

        stackedWidget->addWidget(loadingScreen);
        loginScreen = new QWidget();
        loginScreen->setObjectName("loginScreen");
        verticalLayout_login = new QVBoxLayout(loginScreen);
        verticalLayout_login->setObjectName("verticalLayout_login");
        usernameLabel = new QLabel(loginScreen);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout_login->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(loginScreen);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout_login->addWidget(usernameEdit);

        passwordLabel = new QLabel(loginScreen);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout_login->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(loginScreen);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_login->addWidget(passwordEdit);

        loginButton = new QPushButton(loginScreen);
        loginButton->setObjectName("loginButton");

        verticalLayout_login->addWidget(loginButton);

        signUpButton = new QPushButton(loginScreen);
        signUpButton->setObjectName("signUpButton");

        verticalLayout_login->addWidget(signUpButton);

        stackedWidget->addWidget(loginScreen);
        gameMenu = new QWidget();
        gameMenu->setObjectName("gameMenu");
        verticalLayout_menu = new QVBoxLayout(gameMenu);
        verticalLayout_menu->setObjectName("verticalLayout_menu");
        singlePlayerButton = new QPushButton(gameMenu);
        singlePlayerButton->setObjectName("singlePlayerButton");

        verticalLayout_menu->addWidget(singlePlayerButton);

        multiPlayerButton = new QPushButton(gameMenu);
        multiPlayerButton->setObjectName("multiPlayerButton");

        verticalLayout_menu->addWidget(multiPlayerButton);

        onlinePlayButton = new QPushButton(gameMenu);
        onlinePlayButton->setObjectName("onlinePlayButton");

        verticalLayout_menu->addWidget(onlinePlayButton);

        stackedWidget->addWidget(gameMenu);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sea Battle", nullptr));
        backgroundLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            background-image: url(:/images/LoadingScreenBackground.png);\n"
"            background-repeat: no-repeat;\n"
"            background-position: center;\n"
"           ", nullptr));
        loadingProgressBar->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QProgressBar {\n"
"                border: 1px solid black;\n"
"                border-radius: 5px;\n"
"                background: transparent;\n"
"                padding: 1px;\n"
"                text-align: center;\n"
"                background-image: url(:/images/LoadingScreenProgress.png);\n"
"                background-repeat: no-repeat;\n"
"                background-position: center;\n"
"            }\n"
"            QProgressBar::chunk {\n"
"                background-color: #05B8CC;\n"
"                width: 20px;\n"
"                margin: 0.5px;\n"
"            }\n"
"           ", nullptr));
        loginScreen->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"         background-image: url(:/images/desk.jpg);\n"
"         background-repeat: no-repeat;\n"
"         background-position: center;\n"
"        ", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        loginButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QPushButton {\n"
"                font-size: 18px;\n"
"                padding: 10px;\n"
"                border: 2px solid #4CAF50;\n"
"                border-radius: 10px;\n"
"                background-color: #4CAF50;\n"
"                color: white;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background-color: #45a049;\n"
"            }\n"
"           ", nullptr));
        signUpButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        signUpButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QPushButton {\n"
"                font-size: 18px;\n"
"                padding: 10px;\n"
"                border: 2px solid #008CBA;\n"
"                border-radius: 10px;\n"
"                background-color: #008CBA;\n"
"                color: white;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background-color: #007bb5;\n"
"            }\n"
"           ", nullptr));
        gameMenu->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"         background-image: url(:/images/desk.jpg);\n"
"         background-repeat: no-repeat;\n"
"         background-position: center;\n"
"        ", nullptr));
        singlePlayerButton->setText(QCoreApplication::translate("MainWindow", "Single Player", nullptr));
        singlePlayerButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QPushButton {\n"
"                font-size: 18px;\n"
"                padding: 10px;\n"
"                border: 2px solid #4CAF50;\n"
"                border-radius: 10px;\n"
"                background-color: #4CAF50;\n"
"                color: white;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background-color: #45a049;\n"
"            }\n"
"           ", nullptr));
        multiPlayerButton->setText(QCoreApplication::translate("MainWindow", "Multiplayer", nullptr));
        multiPlayerButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QPushButton {\n"
"                font-size: 18px;\n"
"                padding: 10px;\n"
"                border: 2px solid #008CBA;\n"
"                border-radius: 10px;\n"
"                background-color: #008CBA;\n"
"                color: white;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background-color: #007bb5;\n"
"            }\n"
"           ", nullptr));
        onlinePlayButton->setText(QCoreApplication::translate("MainWindow", "Online Play", nullptr));
        onlinePlayButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            QPushButton {\n"
"                font-size: 18px;\n"
"                padding: 10px;\n"
"                border: 2px solid #f44336;\n"
"                border-radius: 10px;\n"
"                background-color: #f44336;\n"
"                color: white;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background-color: #da190b;\n"
"            }\n"
"           ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
