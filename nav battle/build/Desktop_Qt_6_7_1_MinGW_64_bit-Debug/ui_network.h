/********************************************************************************
** Form generated from reading UI file 'network.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_H
#define UI_NETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *addressField;
    QLineEdit *portField;
    QPushButton *connectButton;

    void setupUi(QWidget *NetworkForm)
    {
        if (NetworkForm->objectName().isEmpty())
            NetworkForm->setObjectName("NetworkForm");
        NetworkForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(NetworkForm);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(NetworkForm);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        addressField = new QLineEdit(NetworkForm);
        addressField->setObjectName("addressField");

        verticalLayout->addWidget(addressField);

        portField = new QLineEdit(NetworkForm);
        portField->setObjectName("portField");

        verticalLayout->addWidget(portField);

        connectButton = new QPushButton(NetworkForm);
        connectButton->setObjectName("connectButton");

        verticalLayout->addWidget(connectButton);


        retranslateUi(NetworkForm);

        QMetaObject::connectSlotsByName(NetworkForm);
    } // setupUi

    void retranslateUi(QWidget *NetworkForm)
    {
        NetworkForm->setWindowTitle(QCoreApplication::translate("NetworkForm", "Network Settings", nullptr));
        label->setText(QCoreApplication::translate("NetworkForm", "Network Settings", nullptr));
        addressField->setPlaceholderText(QCoreApplication::translate("NetworkForm", "Enter server address", nullptr));
        portField->setPlaceholderText(QCoreApplication::translate("NetworkForm", "Enter port number", nullptr));
        connectButton->setText(QCoreApplication::translate("NetworkForm", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkForm: public Ui_NetworkForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_H
