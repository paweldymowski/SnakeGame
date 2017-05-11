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
    bool gamePaused;

public slots:
    void foodEaten();
    void gamePause();

};





#endif // GAME_H
