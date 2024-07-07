#include "bot.h"
#include <QRandomGenerator>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QColor>

Bot::Bot(const QString& name) : Player(name) {}

void Bot::makeMove(QVector<QVector<Cell*>>& opponentBoard, QTableWidget* opponentBoardWidget) {
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

    if (opponentBoard[x][y]->isOccupied()) {
        // Hit
        opponentBoard[x][y]->setOccupied(false); // Simulate hit by setting to unoccupied
        opponentBoardWidget->item(x, y)->setBackground(Qt::red);
    } else {
        // Miss
        opponentBoardWidget->item(x, y)->setBackground(Qt::blue);
    }
}
