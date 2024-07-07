#include "waiting.h"

Waiting::Waiting(Network* network, QLabel* statusLabel, QObject* parent)
    : QObject(parent), network(network), statusLabel(statusLabel) {
    connect(network, &Network::connected, this, &Waiting::onConnected);
    connect(network, &Network::messageReceived, this, &Waiting::onMessageReceived);
    connect(network, &Network::disconnected, this, &Waiting::cancelWaiting);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Waiting::onTimeout);
}

void Waiting::waitForOpponent() {
    statusLabel->setText("Waiting for opponent...");
    network->connectToServer("server_address", 12345); // Replace with actual server address and port
    timer->start(30000); // Wait for 30 seconds before timing out
}

void Waiting::cancelWaiting() {
    statusLabel->setText("Waiting cancelled. Please try again.");
    network->disconnectFromServer();
    timer->stop();
    emit waitingCancelled();
}

void Waiting::onConnected() {
    statusLabel->setText("Connected. Waiting for opponent...");
}

void Waiting::onMessageReceived(const QString &message) {
    if (message == "opponent_connected") {
        statusLabel->setText("Opponent connected. Starting game...");
        timer->stop();
        emit opponentConnected();
    } else {
        // Handle other messages if necessary
        statusLabel->setText("Message received: " + message);
    }
}

void Waiting::onTimeout() {
    statusLabel->setText("Timeout. Could not find opponent.");
    cancelWaiting();
}
