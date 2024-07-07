#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class signup; }
QT_END_NAMESPACE

class signup : public QDialog
{
    Q_OBJECT

public:
    signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
    void writeToJsonFile(const QString& filename, const QJsonObject& jsonObject);
    QJsonObject readFromJsonFile(const QString& filename);
    bool isValidUsername(const QString& username);
    bool isValidPassword(const QString& password);
    bool isValidName(const QString& name);
    bool isValidEmail(const QString& email);
};

#endif // SIGNUP_H
