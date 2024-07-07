/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameForm
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QLabel *playerLabel;
    QLabel *botLabel;
    QTableWidget *playerBoardWidget;
    QTableWidget *botBoardWidget;
    QPushButton *endTurnButton;

    void setupUi(QWidget *GameForm)
    {
        if (GameForm->objectName().isEmpty())
            GameForm->setObjectName("GameForm");
        GameForm->resize(800, 600);
        gridLayout = new QGridLayout(GameForm);
        gridLayout->setObjectName("gridLayout");
        titleLabel = new QLabel(GameForm);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(32);
        titleLabel->setFont(font);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 2);

        playerLabel = new QLabel(GameForm);
        playerLabel->setObjectName("playerLabel");

        gridLayout->addWidget(playerLabel, 1, 0, 1, 1);

        botLabel = new QLabel(GameForm);
        botLabel->setObjectName("botLabel");

        gridLayout->addWidget(botLabel, 1, 1, 1, 1);

        playerBoardWidget = new QTableWidget(GameForm);
        playerBoardWidget->setObjectName("playerBoardWidget");
        playerBoardWidget->setRowCount(10);
        playerBoardWidget->setColumnCount(10);
        playerBoardWidget->setHorizontalHeaderVisible(false);
        playerBoardWidget->setVerticalHeaderVisible(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playerBoardWidget->sizePolicy().hasHeightForWidth());
        playerBoardWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(playerBoardWidget, 2, 0, 1, 1);

        botBoardWidget = new QTableWidget(GameForm);
        botBoardWidget->setObjectName("botBoardWidget");
        botBoardWidget->setRowCount(10);
        botBoardWidget->setColumnCount(10);
        botBoardWidget->setHorizontalHeaderVisible(false);
        botBoardWidget->setVerticalHeaderVisible(false);
        sizePolicy.setHeightForWidth(botBoardWidget->sizePolicy().hasHeightForWidth());
        botBoardWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(botBoardWidget, 2, 1, 1, 1);

        endTurnButton = new QPushButton(GameForm);
        endTurnButton->setObjectName("endTurnButton");

        gridLayout->addWidget(endTurnButton, 3, 0, 1, 2);


        retranslateUi(GameForm);

        QMetaObject::connectSlotsByName(GameForm);
    } // setupUi

    void retranslateUi(QWidget *GameForm)
    {
        GameForm->setWindowTitle(QCoreApplication::translate("GameForm", "Naval Battle", nullptr));
        titleLabel->setText(QCoreApplication::translate("GameForm", "Naval Battle", nullptr));
        playerLabel->setText(QCoreApplication::translate("GameForm", "Player", nullptr));
        botLabel->setText(QCoreApplication::translate("GameForm", "Bot", nullptr));
        endTurnButton->setText(QCoreApplication::translate("GameForm", "End Turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameForm: public Ui_GameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
