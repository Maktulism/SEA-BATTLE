#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QMainWindow>

namespace Ui {
class GameMenu;
}

class GameMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = nullptr);
    ~GameMenu();

private slots:
    void on_singlePlayerButton_clicked();
    void on_multiPlayerButton_clicked();
    void on_onlinePlayButton_clicked();

private:
    Ui::GameMenu *ui;
};

#endif // GAMEMENU_H
