#include "processing.h"
#include <QRandomGenerator>
#include <QColor>
#include <QTableWidgetItem>

Processing::Processing(QObject *parent) : QObject(parent) {}

void Processing::processMove(Player* player, QVector<QVector<Cell*>>& opponentBoard, QTableWidget* opponentBoardWidget) {
    int x, y;
    bool validMove = false;

    // Loop until a valid move is found
    while (!validMove) {
        x = QRandomGenerator::global()->bounded(10);
        y = QRandomGenerator::global()->bounded(10);

        if (opponentBoard[x][y]->isOccupied() || opponentBoardWidget->item(x, y)->background() == QColor(Qt::white)) {
            // This cell has already been targeted, find another one
            continue;
        } else {
            validMove = true;
        }
    }

    bool hit = opponentBoard[x][y]->isOccupied();
    if (hit) {
        // Hit
        opponentBoard[x][y]->setOccupied(false); // Simulate hit by setting to unoccupied
        opponentBoardWidget->item(x, y)->setBackground(Qt::red);
    } else {
        // Miss
        opponentBoardWidget->item(x, y)->setBackground(Qt::blue);
    }

    emit moveProcessed(hit, x, y);
}
