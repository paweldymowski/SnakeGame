#ifndef GAME_H
#define GAME_H

#include <food.h>
#include <snakehead.h>
#include <border.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>

class Game: public QObject{
    Q_OBJECT

public:
    Game();
    Food * food;
    SnakeHead * snakeHead;
    QGraphicsScene * scene;
    Border * border;
    void createNewFood();
    void startGame(int gameSpeed);
    QTimer * timer;
    bool gamePaused;
    int scores;
    QGraphicsTextItem * scoreViewer;
    int boardWidth;
    int boardHeight;
    int gameObiectsSize;

public slots:
    void foodEaten();
    void gamePause();

};





#endif // GAME_H
