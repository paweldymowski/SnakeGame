#ifndef GAME_H
#define GAME_H

#include <food.h>
#include <snakehead.h>
#include <border.h>
#include <QGraphicsScene>

class Game: public QObject{
    Q_OBJECT

public:
    //Game();
    Food * food;
    SnakeHead * snakeHead;
    QGraphicsScene * scene;
    Border * border;

public slots:
    void foodEaten();
    void makeNewSnakePartVisible();

};





#endif // GAME_H
