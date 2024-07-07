#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include "gamelogic.h"

class MainController : public QObject {
    Q_OBJECT

public:
    MainController(QPushButton* startButton, QLineEdit* nameField, GameLogic* gameLogic);

private slots:
    void handleStartButtonAction();

private:
    QPushButton* startButton;
    QLineEdit* nameField;
    GameLogic* gameLogic;
};

#endif // MAINCONTROLLER_H
