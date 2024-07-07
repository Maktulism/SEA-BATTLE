#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>
#include "player.h"
#include "bot.h"
#include "cell.h"
#include <QPushButton>

class GameLogic : public QMainWindow {
    Q_OBJECT

public:
    GameLogic(QWidget *parent = nullptr);
    void start();
    void update();
    void setPlayerName(const QString &name);
    void initializeGame();

private:
    Player* player;
    Bot* bot;
    QVector<QVector<Cell*>> playerBoard;
    QVector<QVector<Cell*>> botBoard;
    QTableWidget* playerBoardWidget;
    QTableWidget* botBoardWidget;
    QPushButton* endTurnButton;

    void setupUI();
    void applyStyles();
    void placeShips(Player* player, QVector<QVector<Cell*>>& board);
    void makeMove(Player* player, QVector<QVector<Cell*>>& opponentBoard);
    bool checkWin(QVector<QVector<Cell*>>& board);
    void updateBoardUI(QTableWidget* boardWidget, QVector<QVector<Cell*>>& board);
};

#endif // GAMELOGIC_H
