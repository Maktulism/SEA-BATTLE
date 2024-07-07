/********************************************************************************
** Form generated from reading UI file 'create.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *gameNameField;
    QPushButton *createButton;

    void setupUi(QWidget *CreateForm)
    {
        if (CreateForm->objectName().isEmpty())
            CreateForm->setObjectName("CreateForm");
        CreateForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateForm);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CreateForm);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gameNameField = new QLineEdit(CreateForm);
        gameNameField->setObjectName("gameNameField");

        verticalLayout->addWidget(gameNameField);

        createButton = new QPushButton(CreateForm);
        createButton->setObjectName("createButton");

        verticalLayout->addWidget(createButton);


        retranslateUi(CreateForm);

        QMetaObject::connectSlotsByName(CreateForm);
    } // setupUi

    void retranslateUi(QWidget *CreateForm)
    {
        CreateForm->setWindowTitle(QCoreApplication::translate("CreateForm", "Create Game", nullptr));
        label->setText(QCoreApplication::translate("CreateForm", "Create a new game", nullptr));
        gameNameField->setPlaceholderText(QCoreApplication::translate("CreateForm", "Enter game name", nullptr));
        createButton->setText(QCoreApplication::translate("CreateForm", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateForm: public Ui_CreateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H
