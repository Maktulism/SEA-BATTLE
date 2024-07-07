#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QThread>
#include "gamelogic.h"

class GameLoop : public QThread {
    Q_OBJECT

public:
    GameLoop(GameLogic* game);
    void startLoop();
    void stopLoop();

protected:
    void run() override;

private:
    bool running;
    GameLogic* game;
};

#endif // GAMELOOP_H
