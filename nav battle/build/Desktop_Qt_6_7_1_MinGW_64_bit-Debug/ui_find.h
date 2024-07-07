/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *gameNameField;
    QPushButton *findButton;

    void setupUi(QWidget *FindForm)
    {
        if (FindForm->objectName().isEmpty())
            FindForm->setObjectName("FindForm");
        FindForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(FindForm);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(FindForm);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gameNameField = new QLineEdit(FindForm);
        gameNameField->setObjectName("gameNameField");

        verticalLayout->addWidget(gameNameField);

        findButton = new QPushButton(FindForm);
        findButton->setObjectName("findButton");

        verticalLayout->addWidget(findButton);


        retranslateUi(FindForm);

        QMetaObject::connectSlotsByName(FindForm);
    } // setupUi

    void retranslateUi(QWidget *FindForm)
    {
        FindForm->setWindowTitle(QCoreApplication::translate("FindForm", "Find Game", nullptr));
        label->setText(QCoreApplication::translate("FindForm", "Find an existing game", nullptr));
        gameNameField->setPlaceholderText(QCoreApplication::translate("FindForm", "Enter game name", nullptr));
        findButton->setText(QCoreApplication::translate("FindForm", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindForm: public Ui_FindForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
