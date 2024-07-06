/********************************************************************************
** Form generated from reading UI file 'gamemenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMENU_H
#define UI_GAMEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMenu
{
public:
    QPushButton *singlePlayerButton;
    QPushButton *multiPlayerButton;
    QPushButton *onlinePlayButton;

    void setupUi(QWidget *GameMenu)
    {
        if (GameMenu->objectName().isEmpty())
            GameMenu->setObjectName("GameMenu");
        GameMenu->resize(400, 300);
        singlePlayerButton = new QPushButton(GameMenu);
        singlePlayerButton->setObjectName("singlePlayerButton");
        singlePlayerButton->setGeometry(QRect(100, 40, 200, 40));
        multiPlayerButton = new QPushButton(GameMenu);
        multiPlayerButton->setObjectName("multiPlayerButton");
        multiPlayerButton->setGeometry(QRect(100, 100, 200, 40));
        onlinePlayButton = new QPushButton(GameMenu);
        onlinePlayButton->setObjectName("onlinePlayButton");
        onlinePlayButton->setGeometry(QRect(100, 160, 200, 40));

        retranslateUi(GameMenu);

        QMetaObject::connectSlotsByName(GameMenu);
    } // setupUi

    void retranslateUi(QWidget *GameMenu)
    {
        GameMenu->setWindowTitle(QCoreApplication::translate("GameMenu", "Game Menu", nullptr));
        singlePlayerButton->setText(QCoreApplication::translate("GameMenu", "Single Player", nullptr));
        multiPlayerButton->setText(QCoreApplication::translate("GameMenu", "Multiplayer", nullptr));
        onlinePlayButton->setText(QCoreApplication::translate("GameMenu", "Online Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMenu: public Ui_GameMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMENU_H
