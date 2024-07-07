#ifndef BOT_H
#define BOT_H

#include "player.h"
#include "cell.h"
#include <QVector>
#include <QTableWidget>

class Bot : public Player {
public:
    Bot(const QString& name);
    void makeMove(QVector<QVector<Cell*>>& opponentBoard, QTableWidget* opponentBoardWidget);
};

#endif // BOT_H
