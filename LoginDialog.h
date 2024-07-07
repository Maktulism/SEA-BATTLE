#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;
    QJsonObject readFromJsonFile(const QString& filename);
};

#endif // LOGINDIALOG_H
