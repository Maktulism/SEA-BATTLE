#ifndef WAITING_H
#define WAITING_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include "network.h"

class Waiting : public QObject {
    Q_OBJECT

public:
    Waiting(Network* network, QLabel* statusLabel, QObject* parent = nullptr);
    void waitForOpponent();
    void cancelWaiting();

signals:
    void opponentConnected();
    void waitingCancelled();

private slots:
    void onConnected();
    void onMessageReceived(const QString &message);
    void onTimeout();

private:
    Network* network;
    QLabel* statusLabel;
    QTimer* timer;
};

#endif // WAITING_H
