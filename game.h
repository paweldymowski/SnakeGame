#ifndef GAME_H
#define GAME_H

#include <food.h>
#include <snakehead.h>
#include <border.h>
#include <QGraphicsScene>
#include <QTimer>

class Game: public QObject{
    Q_OBJECT

public:
    Game();
    Food * food;
    SnakeHead * snakeHead;
    QGraphicsScene * scene;
    Border * border;
    void createNewFood();
    QTimer * timer;

public slots:
    void foodEaten();
};





#endif // GAME_H
