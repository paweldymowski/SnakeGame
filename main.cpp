#include <QApplication>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;
    game.startGame(500);

    return a.exec();
}
