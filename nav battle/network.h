#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>


class Network : public QObject {
    Q_OBJECT

public:
    Network();
    void connectToServer(const QString &address, int port);
    void disconnectFromServer();
    void sendMessage(const QString &message);
    QString receiveMessage();

signals:
    void messageReceived(const QString &message);
    void connected();
    void disconnected();

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    QTcpSocket *socket;
};

#endif // NETWORK_H
