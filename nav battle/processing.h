#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QVector>
#include "cell.h"
#include "player.h"
#include "bot.h"
#include <QTableWidget>

class Processing : public QObject {
    Q_OBJECT

public:
    Processing(QObject *parent = nullptr);
    void processMove(Player* player, QVector<QVector<Cell*>>& opponentBoard, QTableWidget* opponentBoardWidget);

signals:
    void moveProcessed(bool hit, int x, int y);
};

#endif // PROCESSING_H
