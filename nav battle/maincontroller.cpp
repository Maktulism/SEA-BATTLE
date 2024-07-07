#include "maincontroller.h"
#include <QMessageBox>

MainController::MainController(QPushButton* startButton, QLineEdit* nameField, GameLogic* gameLogic)
    : startButton(startButton), nameField(nameField), gameLogic(gameLogic) {
    connect(startButton, &QPushButton::clicked, this, &MainController::handleStartButtonAction);
}

void MainController::handleStartButtonAction() {
    QString name = nameField->text();
    if (name.isEmpty()) {
        // Handle empty name field (e.g., show a message box to the user)
        QMessageBox::warning(nullptr, "Input Error", "Please enter your name.");
        return;
    }

    // Set the player's name
    gameLogic->setPlayerName(name);

    // Initialize game settings
    gameLogic->initializeGame();

    // Start the game
    gameLogic->start();
}
