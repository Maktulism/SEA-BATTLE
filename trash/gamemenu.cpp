#include "gamemenu.h"
#include "ui_gamemenu.h"

GameMenu::GameMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMenu)
{
    ui->setupUi(this);
    setWindowTitle("Game Menu");
}

GameMenu::~GameMenu()
{
    delete ui;
}

void GameMenu::on_singlePlayerButton_clicked()
{

}

void GameMenu::on_multiPlayerButton_clicked()
{
    //
}

void GameMenu::on_onlinePlayButton_clicked()
{
    //
}
