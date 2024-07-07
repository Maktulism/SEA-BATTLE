#include "network.h"
#include <QTcpSocket>
#include <QHostAddress>

Network::Network() {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Network::onReadyRead);
    connect(socket, &QTcpSocket::connected, this, &Network::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Network::onDisconnected);
}

void Network::connectToServer(const QString &address, int port) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
    }
    socket->connectToHost(QHostAddress(address), port);
}

void Network::disconnectFromServer() {
    socket->disconnectFromHost();
}

void Network::sendMessage(const QString &message) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = message.toUtf8();
        socket->write(data);
        socket->flush();
    }
}

QString Network::receiveMessage() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = socket->readAll();
        return QString::fromUtf8(data);
    }
    return QString();
}

void Network::onReadyRead() {
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    emit messageReceived(message);
}

void Network::onConnected() {
    emit connected();
}

void Network::onDisconnected() {
    emit disconnected();
}
