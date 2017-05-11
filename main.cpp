#include <QApplication>
#include <QGraphicsScene>
#include <snakehead.h>
#include <snakebodypart.h>
#include <border.h>
#include <food.h>
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <utility>
#include <QTimer>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game * game = new Game();

    game->snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
    game->snakeHead->setFocus();

    QGraphicsView * view = new QGraphicsView(game->scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);

    game->scene->setSceneRect(0,0,800,600);
    game->timer = new QTimer();
    QObject::connect(game->timer, SIGNAL(timeout()), game->snakeHead, SLOT(move()));
    QObject::connect(game->timer, SIGNAL(timeout()), game, SLOT(foodEaten()));
    QObject::connect(game->snakeHead, SIGNAL(spacePressed()), game, SLOT(gamePause()));

    game->timer->start(500);

    return a.exec();
}
