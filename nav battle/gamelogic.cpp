#include "gamelogic.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QHeaderView>

GameLogic::GameLogic(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Naval Battle");
    player = new Player("Human Player");
    bot = new Bot("Computer Bot");
    setupUI();
    applyStyles();
}

void GameLogic::start() {
    show();
}

void GameLogic::update() {
    // Logic for updating the game state
    // This could include checking for win conditions, updating the UI, etc.
    if (checkWin(botBoard)) {
        QMessageBox::information(this, "Game Over", "Player wins!");
    } else if (checkWin(playerBoard)) {
        QMessageBox::information(this, "Game Over", "Bot wins!");
    }
}

void GameLogic::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    QLabel *label = new QLabel("Naval Battle", this);
    QFont font = label->font();
    font.setPointSize(32);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(label, 0, 0, 1, 2);

    playerBoardWidget = new QTableWidget(10, 10, this);
    botBoardWidget = new QTableWidget(10, 10, this);

    playerBoardWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    playerBoardWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    botBoardWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    botBoardWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    gridLayout->addWidget(playerBoardWidget, 1, 0);
    gridLayout->addWidget(botBoardWidget, 1, 1);

    endTurnButton = new QPushButton("End Turn", this);
    gridLayout->addWidget(endTurnButton, 2, 0, 1, 2);

    setCentralWidget(centralWidget);

    connect(endTurnButton, &QPushButton::clicked, this, [this]() {
        makeMove(player, botBoard);
        makeMove(bot, playerBoard);
        update();
    });
}

void GameLogic::applyStyles() {
    QFile file(":/styles/game.css");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    }
}

void GameLogic::setPlayerName(const QString &name) {
    if (player) {
        delete player;
    }
    player = new Player(name);
}

void GameLogic::initializeGame() {
    const int boardSize = 10;
    playerBoard = QVector<QVector<Cell*>>(boardSize, QVector<Cell*>(boardSize, nullptr));
    botBoard = QVector<QVector<Cell*>>(boardSize, QVector<Cell*>(boardSize, nullptr));
    
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            playerBoard[i][j] = new Cell(i, j);
            botBoard[i][j] = new Cell(i, j);
        }
    }

    placeShips(player, playerBoard);
    placeShips(bot, botBoard);

    updateBoardUI(playerBoardWidget, playerBoard);
    updateBoardUI(botBoardWidget, botBoard);
}

void GameLogic::placeShips(Player* player, QVector<QVector<Cell*>>& board) {
    // Example: place multiple ships of different sizes and orientations
    // This logic can be replaced with more sophisticated ship placement

    // Place 3 ships of size 3 horizontally for simplicity
    for (int k = 0; k < 3; ++k) {
        int x = QRandomGenerator::global()->bounded(10);
        int y = QRandomGenerator::global()->bounded(8); // Ensure ship fits horizontally
        for (int i = 0; i < 3; ++i) {
            board[x][y + i]->setOccupied(true);
        }
    }
}

void GameLogic::makeMove(Player* player, QVector<QVector<Cell*>>& opponentBoard) {
    int x = QRandomGenerator::global()->bounded(10);
    int y = QRandomGenerator::global()->bounded(10);
    if (opponentBoard[x][y]->isOccupied()) {
        opponentBoard[x][y]->setOccupied(false); // Simulate hit
        botBoardWidget->item(x, y)->setBackground(Qt::red);
    } else {
        botBoardWidget->item(x, y)->setBackground(Qt::blue); // Miss
    }
}

bool GameLogic::checkWin(QVector<QVector<Cell*>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j]->isOccupied()) {
                return false; // There are still ships left
            }
        }
    }
    return true; // All ships are hit
}

void GameLogic::updateBoardUI(QTableWidget* boardWidget, QVector<QVector<Cell*>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            if (board[i][j]->isOccupied()) {
                item->setBackground(Qt::gray); // Ship is present
            } else {
                item->setBackground(Qt::white); // Empty cell
            }
            boardWidget->setItem(i, j, item);
        }
    }
}
