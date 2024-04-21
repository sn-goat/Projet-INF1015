#include <QApplication>
#include "maingui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    chess_game::graphics::MainGui* gui = new chess_game::graphics::MainGui();

    gui->drawBoard();
    gui->startGame();
    gui->show();

    return a.exec();
}
