/********************************************************************************
** Form generated from reading UI file 'loadingscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGSCREEN_H
#define UI_LOADINGSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingScreen
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *backgroundLabel;

    void setupUi(QWidget *LoadingScreen)
    {
        if (LoadingScreen->objectName().isEmpty())
            LoadingScreen->setObjectName("LoadingScreen");
        LoadingScreen->resize(640, 480);
        verticalLayout = new QVBoxLayout(LoadingScreen);
        verticalLayout->setObjectName("verticalLayout");
        backgroundLabel = new QLabel(LoadingScreen);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(backgroundLabel);


        retranslateUi(LoadingScreen);

        QMetaObject::connectSlotsByName(LoadingScreen);
    } // setupUi

    void retranslateUi(QWidget *LoadingScreen)
    {
        LoadingScreen->setWindowTitle(QCoreApplication::translate("LoadingScreen", "Loading Screen", nullptr));
        backgroundLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingScreen: public Ui_LoadingScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGSCREEN_H
