#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snakehead.h"
#include "border.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>

class Game: public QObject{
    Q_OBJECT

public:
    //! Constructor.
    Game();
    /*! Food for snake. */
    Food * food;
    /*! Snake. */
    SnakeHead * snakeHead;
    /*! Scene. */
    QGraphicsScene * scene;
    /*! Border of game board. */
    Border * border;
    /*! Creates new food and adds it to the scene. */
    void createNewFood();
    /*! Timer. */
    QTimer * timer;
    /*! Informs if game is paused. */
    bool gamePaused;
    /*! Informs if player is about to play first game sience application launch. */
    bool firstGame;
    /*! Holds player scores. */
    int scores;
    /*! Shows scores. */
    QGraphicsTextItem * scoreViewer;
    /*! Width of the board. */
    int boardWidth;
    /*! Height of the board. */
    int boardHeight;
    /*! Size of game elements. */
    int gameObiectsSize;
    /*! Scores for eating food. */
    int scoresForFood;

public slots:
    /*! Checks if position of SnakeHead is the same as position of Food. */
    void foodEaten();
    /*! Pauses game. */
    void gamePause();
    /*! Creates all obiects for the game and adds them to the scene. */
    void startGame();
    /*! Displays menu buttons. */
    void displayMenu();
    /*! Deletes obiects. */
    void clearGame();
    /*! Shuts down application. */
    void close();
};

#endif // GAME_H
