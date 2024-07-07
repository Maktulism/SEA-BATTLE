
#include <QApplication>
#include "gamelogic.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GameLogic game;
    game.start();
    return app.exec();
}
