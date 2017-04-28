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

    game->scene = new QGraphicsScene();
    game->snakeHead = new SnakeHead();
    game->food = new Food();

    game->border = new Border();


    game->scene->addItem(game->snakeHead);
    game->scene->addItem(game->food);
    game->scene->addItem(game->border);


    std::vector<SnakeBodyPart*>::iterator it = game->snakeHead->snakeTail.begin();

    while (it != game->snakeHead->snakeTail.end()){
        game->scene->addItem(*it);
        it++;
    }
    qDebug() << "elementy dodane";

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

    game->timer->start(500);

    return a.exec();
}
