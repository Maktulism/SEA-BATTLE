#include "gameloop.h"

GameLoop::GameLoop(GameLogic* game) : QThread(), running(false), game(game) {}

void GameLoop::startLoop() {
    running = true;
    start();
}

void GameLoop::stopLoop() {
    running = false;
}

void GameLoop::run() {
    while (running) {
        game->update();
        QThread::msleep(16); // approximately 60 FPS
    }
}
