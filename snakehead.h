#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <vector>
#include "snakebodypart.h"
#include "food.h"
#include "directions.h"

/*! Main part of snake, responsible for movement of the snake. */

class SnakeHead: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //! Constructor.
    SnakeHead();
    //! Destructor.
    ~SnakeHead();
    /*! direction of movement of the SnakeHead at given moment */
    directions direction;
    /*! informs if food was eaten in recent tick of timer */
    bool foodEaten;
    /*! informs if direction key was pressed in recent tick of timer */
    bool keyPressed;
    /*! Handles pressing of direction keys and space. Sets direction of SnakeHead */
    void keyPressEvent(QKeyEvent * event);
    /*! Creates new element of Snake tail if food was eaten. */
    void updateTail();
    /*! Deletes Snake`s tail. */
    void clearTail();
    //void makeNewSnakePartVisible();

    std::vector<SnakeBodyPart*> snakeTail; /*! Container for parts of snake tail. */

public slots:
    /*! Changes location of SnakeHead, detects if SnakeHeads goes behind game Border or colides with tail. */
    void move();
signals:
    //! Signals that space was pressed.
    void spacePressed();
    //! Signals that SnakeHead hit tail or hit board Border..
    void snakeIsDead();
};

#endif // SNAKEHEAD_H
